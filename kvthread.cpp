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

#include <QtCore>
#include <QMessageBox>
#include <iostream>

#include "kvthread.h"

KvThread::KvThread(QObject * parent): QThread(parent) {
    threadWorker = NULL;
    //connect(this, SIGNAL(started()), this, SLOT(startedThreadSlot()));
    threadHasOpenConnection = false;
    stopped = false;
}

KvThread::~KvThread() {
    if (threadWorker != NULL)
        delete threadWorker;
}

void KvThread::stop() {
    stopped = true;
}

void KvThread::openDbConnectionSlot(QString sessionName, QString alias, QString connDriver, QString connDb, QString connDbMachine, QString connUser, QString connPass, int connDbPort)
{ 
    if (isRunning() && (sessionName.compare(threadSessionName, Qt::CaseSensitive)==0)) {
        emit openDbConnectionSignal(sessionName, connDriver, connDb, connDbMachine, connUser, connPass, connDbPort);
    }

}

void KvThread::cloneSessionSlot(WId windowId, QString sessionName)
{
    if (sessionName.compare(threadSessionName, Qt::CaseInsensitive) == 0) {
        emit cloneSessionSignal(windowId, sessionName);
    }
}

void KvThread::getSchemasWithTablesSlot(QString sessionName) {
    if (isRunning() && (sessionName.compare(threadSessionName,Qt::CaseSensitive)==0)) {
        emit getSchemasWithTablesSignal(sessionName);
    }
}

void KvThread::getSchemasWithViewsSlot(QString sessionName) {
    if (isRunning() && (sessionName.compare(threadSessionName,Qt::CaseSensitive)==0)) {
        emit getSchemasWithViewsSignal(sessionName);
    }
}

void KvThread::getSchemasWithProgramsSlot(QString sessionName) {
    if (isRunning() && (sessionName.compare(threadSessionName,Qt::CaseSensitive)==0)) {
        emit getSchemasWithProgramsSignal(sessionName);
    }
}

void KvThread::getSchemasWithEtcSlot(QString sessionName) {
    if (isRunning() && (sessionName.compare(threadSessionName,Qt::CaseSensitive)==0)) {
        emit getSchemasWithEtcSignal(sessionName);
    }
}

void KvThread::getTablesOfSchemaSlot(QTreeWidgetItem *item, const QString &sessionName, const QString &schema) {
    if (isRunning() && (sessionName.compare(threadSessionName,Qt::CaseSensitive)==0)) {
        emit getTablesOfSchemaSignal(item, sessionName, schema);
    }
}

void KvThread::getViewsOfSchemaSlot(QTreeWidgetItem *item, const QString &sessionName, const QString &schema) {
    if (isRunning() && (sessionName.compare(threadSessionName,Qt::CaseSensitive)==0)) {
        emit getViewsOfSchemaSignal(item, sessionName, schema);
    }
}

void KvThread::getProgramTypesOfSchemaSlot(QTreeWidgetItem *item, const QString &sessionName, const QString &schema) {
    if (isRunning() && (sessionName.compare(threadSessionName,Qt::CaseSensitive)==0)) {
        emit getProgramTypesOfSchemaSignal(item, sessionName, schema);
    }
}

void KvThread::getProgramsOfSchemaSlot(QTreeWidgetItem *item, const QString &sessionName, const QString &schema, const QString &type) {
    if (isRunning() && (sessionName.compare(threadSessionName,Qt::CaseSensitive)==0)) {
        emit getProgramsOfSchemaSignal(item, sessionName, schema, type);
    }
}

void KvThread::getEtcTypesOfSchemaSlot(QTreeWidgetItem *item, const QString &sessionName, const QString &schema) {
    if (isRunning() && (sessionName.compare(threadSessionName,Qt::CaseSensitive)==0)) {
        emit getEtcTypesOfSchemaSignal(item, sessionName, schema);
    }
}

void KvThread::getEtcOfSchemaSlot(QTreeWidgetItem *item, const QString &sessionName, const QString &schema, const QString &type) {
    if (isRunning() && (sessionName.compare(threadSessionName,Qt::CaseSensitive)==0)) {
        emit getEtcOfSchemaSignal(item, sessionName, schema, type);
    }
}

void KvThread::closeDbConnectionSlot(QString sessionName)
{
    if (isRunning() && (sessionName.compare(threadSessionName,Qt::CaseSensitive)==0))
        emit closeDbConnectionSignal(sessionName);
}

void KvThread::closedDbConnectionSlot(QString sessionName)
{
    if (isRunning())
        emit closedDbConnectionSignal(sessionName);
}


void KvThread::run()
{
    threadWorker = new KvThreadWorker(this);
    qRegisterMetaType<QSqlError>("QSqlError");
    qRegisterMetaType<QStringList>("QStringList");
    qRegisterMetaType<QTreeWidgetItem>("QTreeWidgetItem");
    qRegisterMetaType< QList< QPair<QString,QString> > >("QList< QPair<QString,QString> >");
    qRegisterMetaType< QList<QSqlRecord> >("QList<QSqlRecord>");
    qRegisterMetaType< QList< QPair<QString, QMap<QString,QString> > > >("QList< QPair<QString, QMap<QString,QString> > >");
    qRegisterMetaType<KvSqlSession::DdlTypes>("KvSqlSession::DdlTypes");
    qRegisterMetaType<KvTableInfo>("KvTableInfo");
    qRegisterMetaType<KvColumnInfo>("KvColumnInfo");
    qRegisterMetaType< QList<KvColumnInfo> >("QList<KvColumnInfo>");
    qRegisterMetaType< QList<KvTableConstraintInfo> >("QList<KvTableConstraintInfo>");

    connect(this, SIGNAL(openDbConnectionSignal(QString,QString,QString,QString,QString,QString,int)),
            threadWorker, SLOT(openDbConnectionSlot(QString,QString,QString,QString,QString,QString,int)));
    connect(threadWorker, SIGNAL(openedDbConnectionSignal(QString, QString, QString, QSqlError)),
            this, SLOT(openedDbConnectionSlot(QString, QString, QString, QSqlError)));

    connect(this, SIGNAL(cloneSessionSignal(WId, QString)), threadWorker, SLOT(cloneSessionSlot(WId, QString)));
    connect(threadWorker, SIGNAL(clonedSessionSignal(WId, QString,QString,QString,int,QString,QString,QString)),
            this, SIGNAL(clonedSessionSignal(WId, QString,QString,QString,int,QString,QString,QString)));

    connect(this, SIGNAL(closeDbConnectionSignal(QString)), threadWorker, SLOT(closeDbConnectionSlot(QString)));
    connect(threadWorker, SIGNAL(closedDbConnectionSignal(QString)), this, SLOT(closedDbConnectionSlot(QString)));

    connect(this, SIGNAL(getSessionInfoSignal(QString)), threadWorker, SLOT(getSessionInfoSlot(QString)));
    connect(threadWorker, SIGNAL(gotSessionInfoSignal(QString,QMap<QString,QString>)), this, SIGNAL(gotSessionInfoSignal(QString,QMap<QString,QString>)));

    connect(this, SIGNAL(getSchemasWithTablesSignal(QString)), threadWorker, SLOT(getSchemasWithTablesSlot(QString)));
    connect(threadWorker, SIGNAL(gotSchemasWithTablesSignal(QString,QString,QStringList)), this, SIGNAL(gotSchemasWithTablesSignal(QString,QString,QStringList)));

    connect(this, SIGNAL(getSchemasWithViewsSignal(QString)), threadWorker, SLOT(getSchemasWithViewsSlot(QString)));
    connect(threadWorker, SIGNAL(gotSchemasWithViewsSignal(QString,QString,QStringList)), this, SIGNAL(gotSchemasWithViewsSignal(QString,QString,QStringList)));

    connect(this, SIGNAL(getSchemasWithProgramsSignal(QString)), threadWorker, SLOT(getSchemasWithProgramsSlot(QString)));
    connect(threadWorker, SIGNAL(gotSchemasWithProgramsSignal(QString,QString,QStringList)), this, SIGNAL(gotSchemasWithProgramsSignal(QString,QString,QStringList)));

    connect(this, SIGNAL(getSchemasWithEtcSignal(QString)), threadWorker, SLOT(getSchemasWithEtcSlot(QString)));
    connect(threadWorker, SIGNAL(gotSchemasWithEtcSignal(QString,QString,QStringList)), this, SIGNAL(gotSchemasWithEtcSignal(QString,QString,QStringList)));

    connect(this, SIGNAL(getTablesOfSchemaSignal(QTreeWidgetItem*,QString,QString)), threadWorker, SLOT(getTablesOfSchemaSlot(QTreeWidgetItem*,QString,QString)));
    connect(threadWorker, SIGNAL(gotTablesOfSchemaSignal(QTreeWidgetItem*,QString,QStringList)), this, SIGNAL(gotTablesOfSchemaSignal(QTreeWidgetItem*,QString,QStringList)));

    connect(this, SIGNAL(getViewsOfSchemaSignal(QTreeWidgetItem*,QString,QString)), threadWorker, SLOT(getViewsOfSchemaSlot(QTreeWidgetItem*,QString,QString)));
    connect(threadWorker, SIGNAL(gotViewsOfSchemaSignal(QTreeWidgetItem*,QString,QStringList)), this, SIGNAL(gotViewsOfSchemaSignal(QTreeWidgetItem*,QString,QStringList)));

    connect(this, SIGNAL(getProgramTypesOfSchemaSignal(QTreeWidgetItem*,QString,QString)), threadWorker, SLOT(getProgramTypesOfSchemaSlot(QTreeWidgetItem*,QString,QString)));
    connect(threadWorker, SIGNAL(gotProgramTypesOfSchemaSignal(QTreeWidgetItem*,QString,QStringList)), this, SIGNAL(gotProgramTypesOfSchemaSignal(QTreeWidgetItem*,QString,QStringList)));

    connect(this, SIGNAL(getProgramsOfSchemaSignal(QTreeWidgetItem*,QString,QString,QString)), threadWorker, SLOT(getProgramsOfSchemaSlot(QTreeWidgetItem*,QString,QString,QString)));
    connect(threadWorker, SIGNAL(gotProgramsOfSchemaSignal(QTreeWidgetItem*,QString,QString,QList< QPair<QString,QString> >)), this, SIGNAL(gotProgramsOfSchemaSignal(QTreeWidgetItem*,QString,QString,QList< QPair<QString,QString> >)));

    connect(this, SIGNAL(getEtcTypesOfSchemaSignal(QTreeWidgetItem*,QString,QString)), threadWorker, SLOT(getEtcTypesOfSchemaSlot(QTreeWidgetItem*,QString,QString)));
    connect(threadWorker, SIGNAL(gotEtcTypesOfSchemaSignal(QTreeWidgetItem*,QString,QStringList)), this, SIGNAL(gotEtcTypesOfSchemaSignal(QTreeWidgetItem*,QString,QStringList)));

    connect(this, SIGNAL(getEtcOfSchemaSignal(QTreeWidgetItem*,QString,QString,QString)), threadWorker, SLOT(getEtcOfSchemaSlot(QTreeWidgetItem*,QString,QString,QString)));
    connect(threadWorker, SIGNAL(gotEtcOfSchemaSignal(QTreeWidgetItem*,QString,QString,QList< QPair<QString,QString> >)), this, SIGNAL(gotEtcOfSchemaSignal(QTreeWidgetItem*,QString,QString,QList< QPair<QString,QString> >)));

    connect(this, SIGNAL(executeQuerySignal(QString, QString)), threadWorker, SLOT(executeQuerySlot(QString, QString)));
    connect(threadWorker, SIGNAL(executedQuerySignal(QString,QList<QSqlRecord>,int,QSqlError,QString)), this, SIGNAL(executedQuerySignal(QString,QList<QSqlRecord>,int,QSqlError,QString)));

    connect(this, SIGNAL(getSqlBlocksSignal(QStringList,int,int)), threadWorker, SLOT(getSqlBlocksSlot(QStringList,int,int)));
    connect(threadWorker, SIGNAL(gotSqlBlocksSignal(QStringList,int,int)), this, SIGNAL(gotSqlBlocksSignal(QStringList,int,int)));

    connect(this, SIGNAL(getFindObjectStatementSignal(QString, QString)), threadWorker, SLOT(getFindObjectStatementSlot(QString, QString)));
    connect(threadWorker, SIGNAL(gotFindObjectStatementSignal(QString,QString)), this, SIGNAL(gotFindObjectStatementSignal(QString,QString)));

    connect(this, SIGNAL(getNextRecordsSignal(QString,int,bool,QString)), threadWorker, SLOT(getNextRecordsSlot(QString,int,bool,QString)));
    connect(threadWorker, SIGNAL(gotNextRecordsSignal(QString,QList<QSqlRecord>,int,QSqlError,bool,QString)),
            this, SIGNAL(gotNextRecordsSignal(QString,QList<QSqlRecord>,int,QSqlError,bool,QString)));

    connect(this, SIGNAL(commitTransactionSignal()), threadWorker, SLOT(commitTransactionSlot()));
    connect(this, SIGNAL(rollbackTransactionSignal()), threadWorker, SLOT(rollbackTransactionSlot()));

    connect(this, SIGNAL(getDdlFromObjectSignal(QString,QString,QString,bool,KvSqlSession::DdlTypes)), threadWorker, SLOT(getDdlFromObjectSlot(QString,QString,QString,bool,KvSqlSession::DdlTypes)));
    connect(threadWorker, SIGNAL(gotDdlFromObjectSignal(QString,QString,QString,QString,bool,QStringList,KvSqlSession::DdlTypes)), this, SIGNAL(gotDdlFromObjectSignal(QString,QString,QString,QString,bool,QStringList,KvSqlSession::DdlTypes)) );

    connect(this, SIGNAL(getExtractConsistentDataSqlSignal(QString)), threadWorker, SLOT(getExtractConsistentDataSqlSlot(QString)));
    connect(threadWorker, SIGNAL(gotExtractConsistentDataSqlSignal(QString,QStringList)), this, SIGNAL(gotExtractConsistentDataSqlSignal(QString,QStringList)));

    connect(this, SIGNAL(getDependentSqlSignal(QString)), threadWorker, SLOT(getDependentSqlSlot(QString)));
    connect(threadWorker, SIGNAL(gotDependentSqlSignal(QString,QStringList)), this, SIGNAL(gotDependentSqlSignal(QString,QStringList)));

    connect(this, SIGNAL(getPlanSignal(QString,QString)), threadWorker, SLOT(getPlanSlot(QString,QString)));
    connect(threadWorker, SIGNAL(gotPlanSignal(QString,QString,QList<QPair<QString,QMap<QString,QString> > >)),
            this, SIGNAL(gotPlanSignal(QString,QString,QList<QPair<QString,QMap<QString,QString> > >)));

    connect(this, SIGNAL(getExportedDataSignal(QString,QString,bool,QString)), threadWorker, SLOT(getExportedDataSlot(QString,QString,bool,QString)));
    connect(threadWorker, SIGNAL(gotExportedDataSignal(QString,QString,QString,bool,QString,bool,QString)), this, SIGNAL(gotExportedDataSignal(QString,QString,QString,bool,QString,bool,QString)));

    connect(this, SIGNAL(getDatabaseObjectTypesSignal()), threadWorker, SLOT(getDatabaseObjectTypesSlot()));
    connect(threadWorker, SIGNAL(gotDatabaseObjectTypesSignal(QStringList, QStringList)), this, SIGNAL(gotDatabaseObjectTypesSignal(QStringList, QStringList)));

    connect(this, SIGNAL(getTableAndColumnsInfoSignal(QString,QString)), threadWorker, SLOT(getTableAndColumnsInfoSlot(QString,QString)));
    connect(threadWorker, SIGNAL(gotTableAndColumnsInfoSignal(QString,QString,KvTableInfo,QList<KvColumnInfo>,QList<KvTableConstraintInfo>)),
            this, SIGNAL(gotTableAndColumnsInfoSignal(QString,QString,KvTableInfo,QList<KvColumnInfo>,QList<KvTableConstraintInfo>)));

    // Emit started thread signal only after all other signal-slots connections are ready
    startedThreadSlot();

    if (stopped)
        return;

    exec();
}

void KvThread::startedThreadSlot()
{
    emit startedThreadSignal(threadSessionName);
}

void KvThread::openedDbConnectionSlot(QString session, QString connUser, QString connDb, QSqlError error)
{
    // if there is no error, database connection must be opened
    threadHasOpenConnection = (error.type() == QSqlError::NoError);
    emit openedDbConnectionSignal(session, connUser, connDb, error);
}

// KvThreadWorker Methods

KvThreadWorker::KvThreadWorker(QObject* parent) {
    sqlSession = NULL;
}

KvThreadWorker::~KvThreadWorker() {

    if (sqlSession != NULL) {
        delete sqlSession;
        sqlSession = NULL;
    }
}

void KvThreadWorker::openDbConnectionSlot(QString session, QString connDriver, QString connDb, QString connDbMachine, QString connUser, QString connPass, int connDbPort)
{
    if (sqlSession != NULL)
        delete sqlSession;

    if (KvDbUtil::databaseForDriver(connDriver) == KvDbUtil::Firebird)
        sqlSession = new KvSqlSessionFirebird(this);
    else if (KvDbUtil::databaseForDriver(connDriver) == KvDbUtil::MySql)
        sqlSession = new KvSqlSessionMySql(this);
    else if (KvDbUtil::databaseForDriver(connDriver) == KvDbUtil::Oracle)
        sqlSession = new KvSqlSessionOracle(this);
    else if (KvDbUtil::databaseForDriver(connDriver) == KvDbUtil::PostgreSql)
        sqlSession = new KvSqlSessionPostgreSql(this);
    else if (KvDbUtil::databaseForDriver(connDriver) == KvDbUtil::Sqlite)
        sqlSession = new KvSqlSessionSqlite(this);
    else if (KvDbUtil::databaseForDriver(connDriver) == KvDbUtil::Cubrid)
        sqlSession = new KvSqlSessionCubrid(this);
    else
        qWarning() << "No sqldriver identified to initialize sqlSession";


    connect(this, SIGNAL(destroyed()), sqlSession, SLOT(deleteLater()));
    qDebug() << "Signals-Slots Connections OK";

    error = sqlSession->connectDatabase(session, connDriver, connDb, connDbMachine, connUser, connPass, connDbPort);
    qDebug() << "Connected Thread OK";
    emit openedDbConnectionSignal(session, connUser, connDb, error);
}

void KvThreadWorker::cloneSessionSlot(WId windowId, QString sessionName)
{
    QString session = sqlSession->getDatabase().connectionName();
    QString driver = sqlSession->getDriver();
    QString hostname = sqlSession->getDatabase().hostName();
    int port = sqlSession->getDatabase().port();
    QString database = sqlSession->getDatabase().databaseName();
    QString username = sqlSession->getDatabase().userName();
    QString password = sqlSession->getDatabase().password();
    emit clonedSessionSignal(windowId, session, driver, hostname, port, database, username, password);
}

void KvThreadWorker::getSchemasWithTablesSlot(QString session) {
    QStringList items = sqlSession->getSchemasWithTables();
    emit gotSchemasWithTablesSignal(sqlSession->getConnectionName(), sqlSession->getConnectionUserName(), items);
}

void KvThreadWorker::getSchemasWithViewsSlot(QString session) {
    QStringList items = sqlSession->getSchemasWithViews();
    emit gotSchemasWithViewsSignal(sqlSession->getConnectionName(), sqlSession->getConnectionUserName(), items);
}

void KvThreadWorker::getSchemasWithProgramsSlot(QString session) {
    QStringList items = sqlSession->getSchemasWithPrograms();
    emit gotSchemasWithProgramsSignal(sqlSession->getConnectionName(), sqlSession->getConnectionUserName(), items);
}

void KvThreadWorker::getSchemasWithEtcSlot(QString session) {
    QStringList items = sqlSession->getSchemasWithEtc();
    emit gotSchemasWithEtcSignal(sqlSession->getConnectionName(), sqlSession->getConnectionUserName(), items);
}

void KvThreadWorker::getTablesOfSchemaSlot(QTreeWidgetItem *item, const QString &session, const QString &schema) {
    QStringList items = sqlSession->getTables(schema);
    emit gotTablesOfSchemaSignal(item, schema, items);
}

void KvThreadWorker::getViewsOfSchemaSlot(QTreeWidgetItem *item, const QString &session, const QString &schema) {
    QStringList items = sqlSession->getViews(schema);
    emit gotViewsOfSchemaSignal(item, schema, items);
}

void KvThreadWorker::getProgramTypesOfSchemaSlot(QTreeWidgetItem *item, const QString &session, const QString &schema) {
    QStringList items = sqlSession->getProgramsTypes();
    emit gotProgramTypesOfSchemaSignal(item, schema, items);
}

void KvThreadWorker::getProgramsOfSchemaSlot(QTreeWidgetItem *item, const QString &session, const QString &schema, const QString &type) {
    QList< QPair<QString, QString> > items = sqlSession->getProgramsWithStatus(schema, type);

    emit gotProgramsOfSchemaSignal(item, schema, type, items);
}

void KvThreadWorker::getEtcTypesOfSchemaSlot(QTreeWidgetItem *item, const QString &session, const QString &schema) {
    QStringList items = sqlSession->getEtcTypes();
    emit gotEtcTypesOfSchemaSignal(item, schema, items);
}

void KvThreadWorker::getEtcOfSchemaSlot(QTreeWidgetItem *item, const QString &session, const QString &schema, const QString &type) {
    QList< QPair<QString, QString> > items = sqlSession->getEtcWithStatus(schema, type);

    emit gotEtcOfSchemaSignal(item, schema, type, items);
}

void KvThreadWorker::closeDbConnectionSlot(QString session)
{
    sqlSession->disconnectDatabase();
    emit closedDbConnectionSignal(session);
}

void KvThreadWorker::executeQuerySlot(QString sqlStatement, QString sqlStatementId)
{
    if ((sqlSession->isValidDb()) && (sqlSession->isOpen())) {

        if (mapLastSqlRecordsCount.contains(sqlStatementId))
            mapLastSqlRecordsCount.remove(sqlStatementId);

        mapLastSqlRecordsCount.insert(sqlStatementId, sqlSession->queryExec(sqlStatement, sqlStatementId));

        QList<QSqlRecord> records;
        int recordCount;
        if (mapLastSqlRecordsCount.value(sqlStatementId) < KvDbUtil::recordCountForFetch())
            recordCount = mapLastSqlRecordsCount.value(sqlStatementId);
        else
            recordCount = KvDbUtil::recordCountForFetch();

        for (int r=0; r <= recordCount; r++) {
            records.append(sqlSession->queryModels.value(sqlStatementId)->record(r));
        }
        if ((sqlSession->isValidDb()) && (sqlSession->isOpen()))
            emit executedQuerySignal(sqlStatement, records, mapLastSqlRecordsCount.value(sqlStatementId), sqlSession->queryModels.value(sqlStatementId)->lastError(), sqlStatementId);
    }
}

void KvThreadWorker::getSqlBlocksSlot(QStringList sqlLines, int fromPosition, int toPosition)
{
    if ((sqlSession->isValidDb()) && (sqlSession->isOpen())) {
        QStringList sqlBlocks = sqlSession->getSqlBlocks(sqlLines, fromPosition, toPosition);
        emit gotSqlBlocksSignal(sqlBlocks, fromPosition, toPosition);
    }
}

void KvThreadWorker::getFindObjectStatementSlot(QString fullObjectName, QString typeName)
{
    if ((sqlSession->isValidDb()) && (sqlSession->isOpen())) {
        QString statement = sqlSession->findObjectStatement(fullObjectName, typeName);
        emit gotFindObjectStatementSignal(fullObjectName, statement);
    }
}

void KvThreadWorker::getNextRecordsSlot(QString sqlStatement, int fromRecordNumber, bool allRecords, QString sqlStatementId)
{
    if ((sqlSession->isValidDb()) && (sqlSession->isOpen())) {
        QList<QSqlRecord> records;
        int recordCount;
        if (mapLastSqlRecordsCount.value(sqlStatementId) - fromRecordNumber < KvDbUtil::recordCountForFetch())
            recordCount = mapLastSqlRecordsCount.value(sqlStatementId) - fromRecordNumber;
        else
            recordCount = KvDbUtil::recordCountForFetch();

        if (sqlSession->queryModels.contains(sqlStatementId)) {
            for (int r=fromRecordNumber; r < recordCount + fromRecordNumber; r++) {
                records.append(sqlSession->queryModels.value(sqlStatementId)->record(r));
            }

            if ((sqlSession->isValidDb()) && (sqlSession->isOpen()))
                emit gotNextRecordsSignal(sqlStatement, records, mapLastSqlRecordsCount.value(sqlStatementId), sqlSession->queryModels.value(sqlStatementId)->lastError(), allRecords, sqlStatementId);
        }
    }
}

void KvThreadWorker::commitTransactionSlot()
{
    sqlSession->commitTransaction();
}

void KvThreadWorker::rollbackTransactionSlot()
{
    sqlSession->rollbackTransaction();
}

void KvThreadWorker::getDdlFromObjectSlot(QString schema, QString objectName, QString objectType, bool showSchema, KvSqlSession::DdlTypes ddlType)
{
    QStringList result;
    result = sqlSession->getDdlFromObject(schema, objectName, objectType, showSchema, ddlType);
    emit gotDdlFromObjectSignal(sqlSession->getSessionName(), schema, objectName, objectType, showSchema, result, ddlType);
}

void KvThreadWorker::getDependentSqlSlot(QString sqlStatement)
{
    QStringList dependentSqlStatements = sqlSession->getDependentSql(sqlStatement);
    emit gotDependentSqlSignal(sqlStatement, dependentSqlStatements);
}

void KvThreadWorker::getExtractConsistentDataSqlSlot(QString sqlStatement)
{
    QStringList consistentDataSql = sqlSession->extractConsistentDataSql(sqlStatement);
    emit gotExtractConsistentDataSqlSignal(sqlStatement, consistentDataSql);
}

void KvThreadWorker::getPlanSlot(QString sqlStatement, QString sqlStatementId)
{
    QList< QPair<QString, QMap<QString,QString> > > result;
    result = sqlSession->getExecPlan(sqlStatement, sqlStatementId);
    emit gotPlanSignal(sqlStatement, sqlStatementId, result);
}

void KvThreadWorker::getExportedDataSlot(QString schema, QString tableName, bool showSchema, QString sqlStatementId)
{
    QString result;
    QString columns;
    QString values;
    int recordCount = sqlSession->queryExec("SELECT * FROM "+schema+"."+tableName, sqlStatementId);
    for (int r=0; r < recordCount; r++) {
        if (columns.isEmpty()) {
            columns = "(";
            for(int c=0; c < sqlSession->queryModels.value(sqlStatementId)->columnCount(); c++)
                columns += sqlSession->queryModels.value(sqlStatementId)->record().fieldName(c)+",";
            columns = columns.left(columns.length()-1);
            columns += ")";
        }
        values = "(";
        for(int c=0; c < sqlSession->queryModels.value(sqlStatementId)->columnCount(); c++)
            values += sqlSession->queryModels.value(sqlStatementId)->record(r).value(c).toString()+",";
        values = values.left(values.length()-1);
        values += ");";
        result = "INSERT INTO "+schema+"."+tableName+" "+columns+" VALUES "+values;
        bool isTheEnd = ((r == recordCount-1) || sqlSession->toBeDisconnected);
        emit gotExportedDataSignal(sqlSession->getSessionName(), schema, tableName, showSchema, result, isTheEnd, sqlStatementId);
    }
}

void KvThreadWorker::getDatabaseObjectTypesSlot()
{
    QStringList objectTypeNames = sqlSession->getObjectTypeNames();
    QStringList objectTypeOrder = sqlSession->getObjectTypeOrder();
    emit gotDatabaseObjectTypesSignal(objectTypeNames, objectTypeOrder);
}

void KvThreadWorker::getSessionInfoSlot(QString sessionName)
{
    QMap<QString,QString> info;
    QString session = sqlSession->getDatabase().connectionName();
    if (session.compare(sessionName, Qt::CaseSensitive) == 0) {
        info = sqlSession->getSessionInfo();
    }
    emit gotSessionInfoSignal(sessionName, info);
}

void KvThreadWorker::getTableAndColumnsInfoSlot(QString schemaName, QString tableName)
{
    KvTableInfo tableInfo;
    QList<KvColumnInfo> columnsInfo = QList<KvColumnInfo>();
    QList<KvTableConstraintInfo> constraintsInfo = QList<KvTableConstraintInfo>();

    tableInfo.tableSchema = schemaName;
    tableInfo.tableName = tableName;
    tableInfo.tableComments = sqlSession->getOnlyTableComments(schemaName, tableName);
    columnsInfo = sqlSession->getColumns(schemaName, tableName);
    constraintsInfo << sqlSession->getUniqueConstraints(schemaName, tableName);
    constraintsInfo << sqlSession->getRelationshipConstraints(schemaName, tableName);

    emit gotTableAndColumnsInfoSignal(schemaName, tableName, tableInfo, columnsInfo, constraintsInfo);
}


