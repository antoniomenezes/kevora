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

#ifndef KVTHREAD_H
#define KVTHREAD_H

#include <QtSql>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QTreeWidgetItem>
#include "kvdbutil.h"
#include "kvsqlsession.h"
#include "kvsqlsessionfirebird.h"
#include "kvsqlsessionmysql.h"
#include "kvsqlsessionoracle.h"
#include "kvsqlsessionpostgresql.h"
#include "kvsqlsessionsqlite.h"
#include "kvsqlsessioncubrid.h"

class KvThreadWorker; // forward declaration

/**
  Kevora Thread:
  This represents an isolated thread to submit sql operations.
*/
class KvThread : public QThread 
{
    Q_OBJECT
public:
    explicit KvThread(QObject * parent = 0);
    ~KvThread();
    void setSessionName(QString sessionName) { threadSessionName = sessionName; }
    QString getSessionName() { return threadSessionName; }
    bool hasOpenConnection() { return threadHasOpenConnection; }

public slots:
    void openDbConnectionSlot(QString sessionName, QString alias, QString connDriver, QString connDb, QString connDbMachine, QString connUser, QString connPass, int connDbPort);
    void openedDbConnectionSlot(QString sessionName, QString connUser, QString connDb, QSqlError error);
    void cloneSessionSlot(WId windowId, QString sessionName);
    void getSchemasWithTablesSlot(QString sessionName);
    void getSchemasWithViewsSlot(QString sessionName);
    void getSchemasWithProgramsSlot(QString sessionName);
    void getSchemasWithEtcSlot(QString sessionName);
    void getTablesOfSchemaSlot(QTreeWidgetItem *item, const QString &sessionName, const QString &schema);
    void getViewsOfSchemaSlot(QTreeWidgetItem *item, const QString &sessionName, const QString &schema);
    void getProgramTypesOfSchemaSlot(QTreeWidgetItem *item, const QString &sessionName, const QString &schema);
    void getProgramsOfSchemaSlot(QTreeWidgetItem *item, const QString &sessionName, const QString &schema, const QString &type);
    void getEtcTypesOfSchemaSlot(QTreeWidgetItem *item, const QString &sessionName, const QString &schema);
    void getEtcOfSchemaSlot(QTreeWidgetItem *item, const QString &sessionName, const QString &schema, const QString &type);
    void closeDbConnectionSlot(QString sessionName);
    void closedDbConnectionSlot(QString sessionName);
    void startedThreadSlot();
    void stop();

protected:
    void run();

private:
    //QMap<QString, KvThreadWorker*> threadWorkerMap;
    KvThreadWorker* threadWorker;
    QString threadSessionName;
    bool threadHasOpenConnection;
    bool stopped;
    
signals:
    void startedThreadSignal(QString);
    void openDbConnectionSignal(QString, QString, QString, QString, QString, QString, int);
    void openedDbConnectionSignal(QString, QString, QString, QSqlError);
    void getSessionInfoSignal(QString);
    void gotSessionInfoSignal(QString, QMap<QString,QString>);

    void cloneSessionSignal(WId, QString);
    // clonedSession: session, driver, hostname, port, database, username, password
    void clonedSessionSignal(WId, QString, QString, QString, int, QString, QString, QString);

    void getSchemasWithTablesSignal(QString);
    void gotSchemasWithTablesSignal(QString, QString, QStringList);
    void getSchemasWithViewsSignal(QString);
    void gotSchemasWithViewsSignal(QString, QString, QStringList);
    void getSchemasWithProgramsSignal(QString);
    void gotSchemasWithProgramsSignal(QString, QString, QStringList);
    void getSchemasWithEtcSignal(QString);
    void gotSchemasWithEtcSignal(QString, QString, QStringList);
    void getTablesOfSchemaSignal(QTreeWidgetItem*, QString, QString);
    void gotTablesOfSchemaSignal(QTreeWidgetItem*, QString, QStringList);
    void getViewsOfSchemaSignal(QTreeWidgetItem*, QString, QString);
    void gotViewsOfSchemaSignal(QTreeWidgetItem*, QString, QStringList);

    void getProgramTypesOfSchemaSignal(QTreeWidgetItem*, QString, QString);
    void gotProgramTypesOfSchemaSignal(QTreeWidgetItem*, QString, QStringList);
    void getProgramsOfSchemaSignal(QTreeWidgetItem*, QString, QString, QString);
    void gotProgramsOfSchemaSignal(QTreeWidgetItem*, QString, QString, QList< QPair<QString,QString> >);

    void getEtcTypesOfSchemaSignal(QTreeWidgetItem*, QString, QString);
    void gotEtcTypesOfSchemaSignal(QTreeWidgetItem*, QString, QStringList);
    void getEtcOfSchemaSignal(QTreeWidgetItem*, QString, QString, QString);
    void gotEtcOfSchemaSignal(QTreeWidgetItem*, QString, QString, QList< QPair<QString,QString> >);

    void closeDbConnectionSignal(QString);
    void closedDbConnectionSignal(QString);

    void executeQuerySignal(QString, QString sqlStatementId = "default");
    void getSqlBlocksSignal(QStringList, int, int);
    void getNextRecordsSignal(QString, int, bool allRecords = false, QString sqlStatementId = "default");
    void executedQuerySignal(QString, QList<QSqlRecord>, int, QSqlError, QString sqlStatementId = "default");
    void gotSqlBlocksSignal(QStringList, int, int);
    void getFindObjectStatementSignal(QString, QString = QString());
    void gotFindObjectStatementSignal(QString, QString);
    void gotNextRecordsSignal(QString, QList<QSqlRecord>, int, QSqlError, bool allRecords = false, QString sqlStatementId = "default");

    void commitTransactionSignal();
    void rollbackTransactionSignal();
    void getDdlFromObjectSignal(QString, QString, QString, bool, KvSqlSession::DdlTypes);
    void gotDdlFromObjectSignal(QString, QString, QString, QString, bool, QStringList, KvSqlSession::DdlTypes);
    void getDependentSqlSignal(QString);
    void gotDependentSqlSignal(QString, QStringList);

    void getExtractConsistentDataSqlSignal(QString);
    void gotExtractConsistentDataSqlSignal(QString, QStringList);

    void getPlanSignal(QString, QString);
    void gotPlanSignal(QString, QString, QList< QPair<QString, QMap<QString,QString> > >);

    void getExportedDataSignal(QString,QString,bool,QString);
    void gotExportedDataSignal(QString,QString,QString,bool,QString,bool,QString);

    void getDatabaseObjectTypesSignal();
    void gotDatabaseObjectTypesSignal(QStringList, QStringList);
    void getTableAndColumnsInfoSignal(QString schemaName, QString tableName);
    void gotTableAndColumnsInfoSignal(QString, QString, KvTableInfo, QList<KvColumnInfo>, QList<KvTableConstraintInfo>);
};

/**
  Kevora Thread Worker:
  The worker class to perform sql operations.
  KvThreadWorker is linked to KvThread by Signals-Slots Connection Mechanism.
*/
class KvThreadWorker : public QObject
{
    Q_OBJECT

public:
    explicit KvThreadWorker( QObject* parent = 0);
    ~KvThreadWorker();

public slots:
    void openDbConnectionSlot(QString session, QString connDriver, QString connDb, QString connDbMachine, QString connUser, QString connPass, int connDbPort);
    void cloneSessionSlot(WId windowId, QString sessionName);
    void getSessionInfoSlot(QString sessionName);

    void getSchemasWithTablesSlot(QString session);
    void getSchemasWithViewsSlot(QString session);
    void getSchemasWithProgramsSlot(QString session);
    void getSchemasWithEtcSlot(QString session);
    void getTablesOfSchemaSlot(QTreeWidgetItem *item, const QString &session, const QString &schema);
    void getViewsOfSchemaSlot(QTreeWidgetItem *item, const QString &session, const QString &schema);

    void getProgramTypesOfSchemaSlot(QTreeWidgetItem *item, const QString &session, const QString &schema);
    void getProgramsOfSchemaSlot(QTreeWidgetItem *item, const QString &session, const QString &schema, const QString &type);

    void getEtcTypesOfSchemaSlot(QTreeWidgetItem *item, const QString &session, const QString &schema);
    void getEtcOfSchemaSlot(QTreeWidgetItem *item, const QString &session, const QString &schema, const QString &type);
    void closeDbConnectionSlot(QString session);
    void executeQuerySlot(QString sqlStatement, QString sqlStatementId = "default");
    void getSqlBlocksSlot(QStringList sqlLines, int fromPosition = -1, int toPosition = -1);
    void getFindObjectStatementSlot(QString fullObjectName, QString typeName = QString());
    void getNextRecordsSlot(QString sqlStatement, int fromRecordNumber, bool allRecords = false, QString sqlStatementId = "default");
    void commitTransactionSlot();
    void rollbackTransactionSlot();
    void getDdlFromObjectSlot(QString schema, QString objectName, QString objectType, bool showSchema = true, KvSqlSession::DdlTypes = KvSqlSession::CompleteDdl);
    void getDependentSqlSlot(QString sqlStatement);
    void getExtractConsistentDataSqlSlot(QString sqlStatement);
    void getPlanSlot(QString sqlStatement, QString sqlStatementId = "default");
    void getExportedDataSlot(QString schema, QString tableName, bool showSchema, QString sqlStatementId);
    void getDatabaseObjectTypesSlot();
    void getTableAndColumnsInfoSlot(QString schemaName, QString tableName);

signals:
    void openedDbConnectionSignal(QString, QString, QString, QSqlError);
    void clonedSessionSignal(WId, QString, QString, QString, int, QString, QString, QString);
    void gotSessionInfoSignal(QString, QMap<QString,QString>);
    void gotSchemasWithTablesSignal(QString, QString, QStringList);
    void gotSchemasWithViewsSignal(QString, QString, QStringList);
    void gotSchemasWithProgramsSignal(QString, QString, QStringList);
    void gotSchemasWithEtcSignal(QString, QString, QStringList);
    void gotTablesOfSchemaSignal(QTreeWidgetItem*, QString, QStringList);
    void gotViewsOfSchemaSignal(QTreeWidgetItem*, QString, QStringList);
    void gotProgramTypesOfSchemaSignal(QTreeWidgetItem*, QString, QStringList);
    void gotProgramsOfSchemaSignal(QTreeWidgetItem*, QString, QString, QList< QPair<QString,QString> >);
    void gotEtcTypesOfSchemaSignal(QTreeWidgetItem*, QString, QStringList);
    void gotEtcOfSchemaSignal(QTreeWidgetItem*, QString, QString, QList< QPair<QString,QString> >);
    void closedDbConnectionSignal(QString);
    void executedQuerySignal(QString, QList<QSqlRecord>, int, QSqlError, QString sqlStatementId = "default");
    void gotSqlBlocksSignal(QStringList, int, int);
    void gotFindObjectStatementSignal(QString, QString);
    void gotNextRecordsSignal(QString, QList<QSqlRecord>, int, QSqlError, bool allRecords = false, QString sqlStatementId = "default");
    void gotDdlFromObjectSignal(QString, QString, QString, QString, bool, QStringList, KvSqlSession::DdlTypes);
    void gotExtractConsistentDataSqlSignal(QString, QStringList);
    void gotDependentSqlSignal(QString, QStringList);
    void gotPlanSignal(QString, QString, QList< QPair<QString, QMap<QString,QString> > >);
    void gotExportedDataSignal(QString,QString,QString,bool,QString,bool,QString);
    void gotDatabaseObjectTypesSignal(QStringList, QStringList);
    void gotTableAndColumnsInfoSignal(QString, QString, KvTableInfo, QList<KvColumnInfo>, QList<KvTableConstraintInfo>);

private:
    KvSqlSession *sqlSession;
    QSqlError error;
    int lastSqlRecordsCount;
    QMap<QString, int> mapLastSqlRecordsCount;
};

#endif
