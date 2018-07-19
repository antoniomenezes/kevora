/****************************************************************************
**
** Author: Antonio Marcio A Menezes.
**
** This file is part of the Kevora IDE.
**
** This file may be used under the terms of the GNU General Public
** License version 2.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#include <QMessageBox>
#include "kvsqlsession.h"

KvSqlSession::KvSqlSession(QObject * parent): QObject(parent)
{
    toBeDisconnected = false;
    inTransactionState = false;
    databaseObjectTypeNames = QStringList();
    queryModels = QMap<QString, QSqlQueryModel *>();
}

KvSqlSession::~KvSqlSession()
{
    disconnectDatabase();
}

bool KvSqlSession::isValidDb()
{
    return QSqlDatabase::database(sessionConnectionName).isValid();
}

bool KvSqlSession::isOpen()
{
    return QSqlDatabase::database(sessionConnectionName).isOpen();
}

QString KvSqlSession::getDriver()
{
    return QSqlDatabase::database(sessionConnectionName).driverName();
}

bool KvSqlSession::showFormatedError(QString title, QSqlError error) {
    // returns true if an error really happened
    if (error.type() != QSqlError::NoError) {
        QMessageBox::critical(0, title, error.text());
        return true;
    }
    else {
        if (error.text().contains(tr("driver not loaded"), Qt::CaseInsensitive)) {
            QMessageBox::critical(0, tr("Plugin Error"), error.text());
            return true;
        }
        else
            return false;
    }
}

QSqlError KvSqlSession::connectDatabase(const QString &session, const QString &driver, const QString &dbName,
                                        const QString &host, const QString &user, const QString &passwd, int port)
{
    QSqlError err;

    qDebug() << QSqlDatabase::connectionNames();

    qDebug() << "Before queryModels.isEmpty()";
    if (!queryModels.isEmpty()) {
        qDebug() << "Before queryModels.clear()";
        queryModels.clear();
    }
    qDebug() << "After queryModels.isEmpty()";

    if (QSqlDatabase::contains(session)) {
        QSqlDatabase::removeDatabase(session);
    }

    if (QSqlDatabase::contains(session)) {
        qDebug() << "Session "+session+" is already in active session list";
        sessionDatabase = QSqlDatabase::database(session);
    }
    else {
        qDebug() << "Try to add database";

        if (!QSqlDatabase::drivers().contains(driver))
            qDebug() << "driver not available";
        else
            qDebug() << "driver available";

        qDebug() << "driver" << driver;
        qDebug() << "session" << session;

        sessionDatabase = QSqlDatabase::addDatabase(driver, session);

        qDebug() << "database added";
        sessionDatabase.setHostName(host);
        sessionDatabase.setPort(port);
        sessionDatabase.setDatabaseName(dbName);
        // Set user and password to store this information on sessionDatabase
        sessionDatabase.setUserName(user);
        sessionDatabase.setPassword(passwd);

        qDebug() << "Auth OK";

        /*if (driver.compare("QMYSQL", Qt::CaseInsensitive) == 0)
            sessionDatabase.setConnectOptions("CLIENT_IGNORE_SPACE=1");*/
        //sessionDatabase.setConnectOptions("MYSQL_OPT_CONNECT_TIMEOUT(5)");

        // Calling sessionDatabase.open(user, passwd) does not store this information on object QSqlDatabase (sessionDatabase)
        if (sessionDatabase.open(user, passwd) && sessionDatabase.isValid()) {
            sessionConnectionName = session;
            sessionUserName = user;
            sessionDatabase.setNumericalPrecisionPolicy(QSql::HighPrecision);
            setObjectTypeNames();
            setObjectTypeOrder();
            qDebug() << "Connected OK";
        }
        else {
            err = sessionDatabase.lastError();
            sessionDatabase = QSqlDatabase();
            QSqlDatabase::removeDatabase(session);
        }
    }
    return err;
}

void KvSqlSession::disconnectDatabase()
{
    toBeDisconnected = true;
    queryModels.clear();
    QString sessionName = getSessionName();
    if ((sessionDatabase.isValid()) && (sessionDatabase.isOpen()))
        sessionDatabase.close();
    sessionName = "";
    /*if (! sessionDatabase.isOpen())
        QSqlDatabase::removeDatabase(sessionName);*/
}

int KvSqlSession::queryCount(QString sqlStatement)
{
    QSqlQuery qryCount;
    int result = -1;

    if ((sessionDatabase.isValid()) && (sessionDatabase.isOpen())) {
        if ((sqlStatement.trimmed().indexOf("explain", 0, Qt::CaseInsensitive) == 0) || (sqlStatement.trimmed().indexOf("pragma", 0, Qt::CaseInsensitive) == 0)) {
            qryCount = QSqlQuery(sqlStatement, sessionDatabase);
            QSqlQueryModel qryModel;
            qryModel.setQuery(qryCount);
            while (qryModel.canFetchMore()) {
                qryModel.fetchMore();
                // Avoiding eternal looping when returning no records from sqlite pragma statements
                if (qryModel.rowCount() == 0)
                    break;
            }
            result = qryModel.rowCount();
        }
        else {
            qryCount = QSqlQuery("SELECT COUNT(1) FROM ( "+sqlStatement.remove(";",Qt::CaseInsensitive)+" )", sessionDatabase);
            if (qryCount.first()) {
                result = qryCount.value( 0 ).toInt();
            }
            else {
                result = 0;
            }
        }
    }
    else
        result = -1;
    return result;
}

int KvSqlSession::queryExec(QString sqlStatement, QString sqlStatementId)
{
    if ((sessionDatabase.isValid()) && (sessionDatabase.isOpen())) {
        QSqlError err;
        //queryModels.clear();
        //lastQueryModel.clear();
        // Removes the last occurrence of ";"

        QString sqlStatementTmp = sqlStatement;
        if (sqlStatementTmp.contains(QRegExp(";(?![.*\\*\\/|.*\\'])")))
            sqlStatementTmp = sqlStatementTmp.remove(sqlStatement.lastIndexOf(";"), 1);

        if (! sqlStatementTmp.trimmed().isEmpty()) {
            // Start transaction if possible...
            //if (sessionDatabase.driver()->hasFeature(QSqlDriver::Transactions))
            if (!inTransactionState)
                inTransactionState = sessionDatabase.transaction();
            QSqlQueryModel *queryModel;

            if (queryModels.contains(sqlStatementId))
                queryModel = queryModels.value(sqlStatementId);
            else {
                queryModel = new QSqlQueryModel(this);
                queryModels.insert(sqlStatementId, queryModel);
            }

            queryModel->setQuery(sqlStatementTmp, sessionDatabase);
            //lastQueryModel.setQuery(sqlStatementTmp, sessionDatabase);
            //qDebug() << "KvSqlSession::queryExec :";
            //qDebug() << sqlStatementTmp;

            //if (lastQueryModel.lastError().type() == QSqlError::NoError) {
            if (queryModel->lastError().type() == QSqlError::NoError) {
                QString firstStatementWord = queryModel->query().lastQuery().split(" ", QString::SkipEmptyParts).first();
                bool isPragmaStatement = (firstStatementWord.compare("PRAGMA", Qt::CaseInsensitive) == 0);
                if (queryModel->query().isSelect() || isPragmaStatement) {
                    if ((!sessionDatabase.driver()->hasFeature(QSqlDriver::QuerySize)) || (isPragmaStatement))
                        return queryCount(sqlStatementTmp);
                    else
                        return queryModel->query().size();
                }
                else
                    return queryModel->query().numRowsAffected();
            }
            else {
                err = queryModel->lastError();
                if (err.number() > 0)
                    return err.number()*(-1);
                else
                    return err.number();
            }
        }
        else {
            return -1;
        }
    }
    else
        return -1;

}


