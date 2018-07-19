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

#ifndef KVSQLDIALOG_H
#define KVSQLDIALOG_H

#include <QDialog>
#include <QSqlQueryModel>
#include "kvthread.h"

namespace Ui {
    class KvSqlDialog;
}

class KvSqlDialog : public QDialog {
    Q_OBJECT
public:
    explicit KvSqlDialog(QWidget *parent = 0);
    ~KvSqlDialog();

public slots:
    void deleteTempThreadSlot();
    void setActiveSessions(QStringList sessionNames);
    void setCurrentSession(QString sessionName);
    void addActiveSession(QString sessionName);
    void removeActiveSession(QString sessionName);
    void clonedSessionSlot(WId windowId, QString sessionName, QString driver, QString hostName, int port, QString databaseName, QString userName, QString password);
    void openedDbConnectionSlot(QString sessionName, QString connUser, QString connDb, QSqlError error);
    void closedDbConnectionSlot(QString sessionName);
    void gotSessionInfoSlot(QString sessionName, QMap<QString,QString> info);
    virtual void executedQuerySlot(QString sqlStatement, QList<QSqlRecord> records, int recordCount, QSqlError error) { }
    virtual void gotSqlBlocksSlot(QStringList sqlBlocks, int fromPosition, int toPosition) { }
    virtual void gotFindObjectStatementSlot(QString fullObjectName, QString statement) { }
    virtual void gotNextRecordsSlot(QString sqlStatement, QList<QSqlRecord> records, int recordCount, QSqlError error, bool allRecords = false) { }
    void getDdlFromObjectSlot(QString schema, QString objectName, QString objectType, bool showSchema = true, KvSqlSession::DdlTypes ddlType = KvSqlSession::CompleteDdl);
    virtual void gotDdlFromObjectSlot(QString sessionName, QString schema, QString objectName, QString objectType, bool showSchema, QStringList result, KvSqlSession::DdlTypes) { }
    void getDependentSqlSlot(QString sqlStatement);
    virtual void gotDependentSqlSlot(QString sqlStatement, QStringList dependentSqlStatements) { }
    virtual void gotExtractConsistentDataSqlSlot(QString sqlStatement, QStringList consistentSqlStatements) { }
    void getPlanSlot(QString sqlStatement, QString sqlStatementId);
    virtual void gotPlanSlot(QString sqlStatement, QString sqlStatementId, QList< QPair<QString, QMap<QString,QString> > > result) { }
    void getExportedDataSlot(QString schema, QString tableName, bool showSchema, QString sqlStatementId);
    virtual void gotExportedDataSlot(QString sessionName, QString schema, QString tableName, bool showSchema, QString resultLine, bool isTheEnd, QString sqlStatementId) { }
    void gotDatabaseObjectTypesSlot(QStringList objTypeNames, QStringList objTypeOrder);
    virtual void gotTableAndColumnsInfoSlot(QString objSchema, QString objTable, KvTableInfo tableInfo, QList<KvColumnInfo> columns, QList<KvTableConstraintInfo> constraints) { }
    QString getFileName();
    void setFileName(QString fullName);

protected:
    void changeEvent(QEvent *e);
    QStringList activeSessions;
    KvThread *thread;
    KvThread *tempThread;
    bool hasOpenConnection;
    bool openConnectionAndExecute;
    bool openConnectionAndExecuteDdl;
    bool openConnectionAndExportData;
    QString ddlSchemaName;
    QString ddlObjectName;
    QString ddlObjectType;
    bool ddlShowSchema;
    QMap<QString,QString> mapSessionInfo;
    QStringList databaseObjTypeNames;
    QStringList databaseObjTypeOrder;
    bool isClosing;
    QString currentFileName;

private:
    Ui::KvSqlDialog *ui;

private slots:
    void startedThreadSlot(QString sessionName);
    void deleteThreadSlot();

signals:
    void cloneSessionSignal(WId, QString);
    void openDbConnectionSignal(QString, QString, QString, QString, QString, QString, QString, int);
    void closeDbConnectionSignal(QString);
    void getSessionInfoSignal(QString);
    void executeQuerySignal(QString, QString sqlStatementId = "default");
    void getSqlBlocksSignal(QStringList, int fromPosition = -1, int toPosition = -1);
    void getFindObjectStatementSignal(QString, QString = QString());
    void getNextRecordsSignal(QString, int, bool allRecords = false, QString sqlStatementId = "default");
    void commitTransactionSignal();
    void rollbackTransactionSignal();
    void getDdlFromObjectSignal(QString, QString, QString, bool, KvSqlSession::DdlTypes);
    void getDependentSqlSignal(QString);
    void getExtractConsistentDataSqlSignal(QString);
    void getPlanSignal(QString, QString);
    void getExportedDataSignal(QString, QString, bool,QString);
    void getDatabaseObjectTypesSignal();
    void getTableAndColumnsInfoSignal(QString schemaName, QString tableName);
};

#endif // KVSQLDIALOG_H
