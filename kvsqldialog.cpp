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

#include "kvsqldialog.h"
#include "ui_kvsqldialog.h"

KvSqlDialog::KvSqlDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::KvSqlDialog)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    tempThread = NULL;
    thread = NULL;
    hasOpenConnection = false;
    openConnectionAndExecute = false;
    openConnectionAndExecuteDdl = false;
    openConnectionAndExportData = false;
    databaseObjTypeNames = QStringList();
    databaseObjTypeOrder = QStringList();
    isClosing = false;
}

KvSqlDialog::~KvSqlDialog()
{
    isClosing = true;
    deleteThreadSlot();
    //deleteTempThreadSlot();
    delete ui;
}

void KvSqlDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void KvSqlDialog::startedThreadSlot(QString sessionName)
{
    if (sessionName.compare(thread->getSessionName(), Qt::CaseInsensitive) == 0) {
        
        QString originalSessionName = sessionName.left(sessionName.indexOf("+"));
        if (!sessionName.isEmpty())
            emit cloneSessionSignal(winId(), originalSessionName);
    }
}

// Retrieves all the parameters to clone an active session
void KvSqlDialog::clonedSessionSlot(WId windowId, QString sessionName, QString driver, QString hostName, int port, QString databaseName, QString userName, QString password)
{
    //if (sessionName.compare(thread->getSessionName(), Qt::CaseInsensitive) == 0) {
    if (windowId == winId()) {
        int pos = sessionName.indexOf("@", 0, Qt::CaseSensitive);
        QString alias = sessionName.mid(pos+1, (sessionName.length() - (pos+1)));
        emit openDbConnectionSignal(sessionName+"+"+QString::number((int)this->winId()), alias, driver, databaseName, hostName, userName, password, port);
    }
}

void KvSqlDialog::setActiveSessions(QStringList sessions)
{
    activeSessions = sessions;
}

void KvSqlDialog::setCurrentSession(QString sessionName)
{
    QString currentSession = "";

    if ((thread != NULL) && (sessionName.isEmpty()))
            emit closeDbConnectionSignal(thread->getSessionName());
    else {

        if (thread != NULL)
            currentSession = thread->getSessionName();
        
        if (sessionName.compare(currentSession, Qt::CaseInsensitive) != 0) {
            if (thread != NULL) {
                deleteThreadSlot();
            }
            
            thread = new KvThread(this);
            
            if (sessionName.contains("+"))
                thread->setSessionName(sessionName);
            else
                thread->setSessionName(sessionName+"+"+QString::number((int)this->winId()));
            
            connect(thread, SIGNAL(startedThreadSignal(QString)), this, SLOT(startedThreadSlot(QString)));
            //connect(thread, SIGNAL(terminated()), this, SLOT(deleteThreadSlot()));
            
            connect(this, SIGNAL(openDbConnectionSignal(QString,QString,QString,QString,QString,QString,QString,int)),
                    thread, SLOT(openDbConnectionSlot(QString,QString,QString,QString,QString,QString,QString,int)));
            
            qRegisterMetaType<QSqlError>("QSqlError");
            qRegisterMetaType< QList< QPair<QString,QString> > >("QList< QPair<QString,QString> >");
            qRegisterMetaType< QMap<QString,QString> >("QMap<QString,QString>");
            qRegisterMetaType<KvSqlSession::DdlTypes>("KvSqlSession::DdlTypes");
            
            connect(thread, SIGNAL(openedDbConnectionSignal(QString,QString,QString,QSqlError)),
                    this, SLOT(openedDbConnectionSlot(QString,QString,QString,QSqlError)));

            connect(this, SIGNAL(getSessionInfoSignal(QString)), thread, SIGNAL(getSessionInfoSignal(QString)));
            connect(thread, SIGNAL(gotSessionInfoSignal(QString,QMap<QString,QString>)), this, SLOT(gotSessionInfoSlot(QString,QMap<QString,QString>)));
            
            //connect(this, SIGNAL(closeDbConnectionSignal(QString)), thread, SLOT(closeDbConnectionSlot(QString)));
            //connect(thread, SIGNAL(closedDbConnectionSignal(QString)), this, SLOT(closedDbConnectionSlot(QString)));
            
            connect(this, SIGNAL(executeQuerySignal(QString, QString)), thread, SIGNAL(executeQuerySignal(QString, QString)));
            connect(thread, SIGNAL(executedQuerySignal(QString, QList<QSqlRecord>, int, QSqlError, QString)), this, SLOT(executedQuerySlot(QString,QList<QSqlRecord>,int,QSqlError, QString)));

            connect(this, SIGNAL(getSqlBlocksSignal(QStringList,int,int)), thread, SIGNAL(getSqlBlocksSignal(QStringList,int,int)));
            connect(thread, SIGNAL(gotSqlBlocksSignal(QStringList,int,int)), this, SLOT(gotSqlBlocksSlot(QStringList,int,int)));

            connect(this, SIGNAL(getFindObjectStatementSignal(QString, QString)), thread, SIGNAL(getFindObjectStatementSignal(QString, QString)));
            connect(thread, SIGNAL(gotFindObjectStatementSignal(QString,QString)), this, SLOT(gotFindObjectStatementSlot(QString,QString)));

            connect(this, SIGNAL(getNextRecordsSignal(QString,int,bool,QString)), thread, SIGNAL(getNextRecordsSignal(QString,int,bool,QString)));
            connect(thread, SIGNAL(gotNextRecordsSignal(QString,QList<QSqlRecord>,int,QSqlError,bool,QString)),
                    this, SLOT(gotNextRecordsSlot(QString,QList<QSqlRecord>,int,QSqlError,bool,QString)));
            
            connect(this, SIGNAL(commitTransactionSignal()), thread, SIGNAL(commitTransactionSignal()));
            connect(this, SIGNAL(rollbackTransactionSignal()), thread, SIGNAL(rollbackTransactionSignal()));

            connect(this, SIGNAL(getDdlFromObjectSignal(QString,QString,QString,bool,KvSqlSession::DdlTypes)),
                    thread, SIGNAL(getDdlFromObjectSignal(QString,QString,QString,bool,KvSqlSession::DdlTypes)));
            connect(thread, SIGNAL(gotDdlFromObjectSignal(QString,QString,QString,QString,bool,QStringList,KvSqlSession::DdlTypes)),
                    this, SLOT(gotDdlFromObjectSlot(QString,QString,QString,QString,bool,QStringList,KvSqlSession::DdlTypes)));

            connect(this, SIGNAL(getDependentSqlSignal(QString)), thread, SIGNAL(getDependentSqlSignal(QString)));
            connect(thread, SIGNAL(gotDependentSqlSignal(QString,QStringList)), this, SLOT(gotDependentSqlSlot(QString,QStringList)));

            connect(this, SIGNAL(getExtractConsistentDataSqlSignal(QString)), thread, SIGNAL(getExtractConsistentDataSqlSignal(QString)));
            connect(thread, SIGNAL(gotExtractConsistentDataSqlSignal(QString,QStringList)), this, SLOT(gotExtractConsistentDataSqlSlot(QString,QStringList)));

            connect(this, SIGNAL(getPlanSignal(QString,QString)), thread, SIGNAL(getPlanSignal(QString,QString)));
            connect(thread, SIGNAL(gotPlanSignal(QString,QString,QList<QPair<QString,QMap<QString,QString> > >)),
                    this, SLOT(gotPlanSlot(QString,QString,QList<QPair<QString,QMap<QString,QString> > >)));

            connect(this, SIGNAL(getExportedDataSignal(QString,QString,bool,QString)),
                    thread, SIGNAL(getExportedDataSignal(QString,QString,bool,QString)));
            connect(thread, SIGNAL(gotExportedDataSignal(QString,QString,QString,bool,QString,bool,QString)),
                    this, SLOT(gotExportedDataSlot(QString,QString,QString,bool,QString,bool,QString)));

            connect(this, SIGNAL(getDatabaseObjectTypesSignal()), thread, SIGNAL(getDatabaseObjectTypesSignal()));
            connect(thread, SIGNAL(gotDatabaseObjectTypesSignal(QStringList, QStringList)), this, SLOT(gotDatabaseObjectTypesSlot(QStringList, QStringList)));

            connect(this, SIGNAL(getTableAndColumnsInfoSignal(QString,QString)), thread, SIGNAL(getTableAndColumnsInfoSignal(QString,QString)));
            connect(thread, SIGNAL(gotTableAndColumnsInfoSignal(QString,QString,KvTableInfo,QList<KvColumnInfo>,QList<KvTableConstraintInfo>)),
                    this, SLOT(gotTableAndColumnsInfoSlot(QString,QString,KvTableInfo,QList<KvColumnInfo>,QList<KvTableConstraintInfo>)));

            thread->start(QThread::HighPriority);
        }
    }
}

void KvSqlDialog::addActiveSession(QString sessionName)
{
    if (! activeSessions.contains(sessionName, Qt::CaseSensitive))
        activeSessions.append(sessionName);
}

void KvSqlDialog::removeActiveSession(QString sessionName)
{
    activeSessions.removeOne(sessionName);
    if ((sessionName.trimmed().isEmpty()) && (thread != NULL))
        emit closeDbConnectionSignal(thread->getSessionName());
}

void KvSqlDialog::openedDbConnectionSlot(QString sessionName, QString connUser, QString connDb, QSqlError error)
{
    hasOpenConnection = true;
    emit getSessionInfoSignal(sessionName);
    emit getDatabaseObjectTypesSignal();
}

void KvSqlDialog::closedDbConnectionSlot(QString sessionName)
{
    hasOpenConnection = false;
    databaseObjTypeNames.clear();
    databaseObjTypeOrder.clear();
}

void KvSqlDialog::deleteThreadSlot()
{
    if (thread != NULL) {
        tempThread = thread;
        connect(tempThread, SIGNAL(finished()), this, SLOT(deleteTempThreadSlot()));
        tempThread->stop();
        tempThread->quit();
        tempThread->wait();
        thread = NULL;
    }
}

void KvSqlDialog::deleteTempThreadSlot()
{
    while ((tempThread != NULL) && (tempThread->isRunning())) {
        // nothing
    }
    if (tempThread != NULL) {
        if (tempThread)
            delete tempThread;
        tempThread = NULL;
    }
}

void KvSqlDialog::getDdlFromObjectSlot(QString schema, QString objectName, QString objectType, bool showSchema, KvSqlSession::DdlTypes ddlType)
{
    if (hasOpenConnection) {
        emit getDdlFromObjectSignal(schema, objectName, objectType, showSchema, ddlType);
    }
}

void KvSqlDialog::getDependentSqlSlot(QString sqlStatement)
{
    if (hasOpenConnection) {
        emit getDependentSqlSignal(sqlStatement);
    }
}

void KvSqlDialog::getPlanSlot(QString sqlStatement, QString sqlStatementId)
{
    if (hasOpenConnection) {
        emit getPlanSignal(sqlStatement, sqlStatementId);
    }
}

void KvSqlDialog::gotSessionInfoSlot(QString sessionName, QMap<QString,QString> info)
{
    mapSessionInfo = info;
}

void KvSqlDialog::getExportedDataSlot(QString schema, QString tableName, bool showSchema, QString sqlStatementId)
{
    if (hasOpenConnection) {
        emit getExportedDataSignal(schema, tableName, showSchema, sqlStatementId);
    }
}

void KvSqlDialog::gotDatabaseObjectTypesSlot(QStringList objTypeNames, QStringList objTypeOrder)
{
    databaseObjTypeNames.clear();
    databaseObjTypeOrder.clear();
    databaseObjTypeNames = objTypeNames;
    databaseObjTypeOrder = objTypeOrder;
}

QString KvSqlDialog::getFileName()
{
    return currentFileName;
}

void KvSqlDialog::setFileName(QString fullName)
{
    currentFileName = fullName;
}
