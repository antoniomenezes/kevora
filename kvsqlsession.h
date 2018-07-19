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

#ifndef KVSQLSESSION_H
#define KVSQLSESSION_H

#include <QObject>
#include <QtGui>
#include <QtSql>
#include <QPair>
#include <QStringList>
#include <QTableWidget>
#include <QTreeWidgetItem>


struct KvTableInfo {
    QString tableSchema;
    QString	tableName;
    QString	tableComments;
};

struct KvColumnInfo {
    KvTableInfo columnTable;
    QString	    columnName;
    QString	    columnType;
    QString	    columnSize;
    bool        columnNullable;
    QString     columnDefault;
    QString     columnComments;
};

struct KvTableConstraintInfo {
    QString	    constraintSchema;
    QString	    constraintName;
    QString	    constraintTable;
    QString     constraintType;
    QString     constraintStatus;
    bool        constraintOptional;
    QStringList constraintColumns;
    QString     constraintRefOwner;
    QString     constraintRefTable;
    QStringList constraintRefColumns;
};

struct KvTableIndexInfo {
    QString             indexSchema;
    QString             indexName;
    KvTableInfo         indexTable;
    QString             indexType;
    QList<KvColumnInfo> indexColumns;
};

struct KvTablePrivilege {
    KvTableInfo privilegeTable;
    QString     privilegeOperation;
    QString     privilegeOption;
    QString     privilegeGrantee;
};

struct KvRecordIdentifier {
    QString recordSchema;
    QString recordTable;
    QString recordKeyClause;
};

struct KvTableDependency {
    QString                             parentSchema;
    QString                             parentTable;
    QString                             childSchema;
    QString                             childTable;
    QString                             constraintName;
    bool                                optional;
    QList< QPair<QString, QString> >    columnsPair;
};

struct KvTableColumn {
    QString columnSchema;
    QString columnTable;
    QString	columnName;
    QString	columnType;
};

typedef struct {
    int first;
    int last;
    QString text;
} KvSqlBlock;



/**
  Sql Session:
  This class will provide the methods for databases interaction.
  It is a super class. Each database kind supported by Kevora will need a child class of Sql Session,
  so there will be an Oracle Sql Session class, a PostgreSql Session class and so on.
*/
class KvSqlSession : public QObject
{
    Q_OBJECT
public:
    enum DdlTypes { CompleteDdl, PartialDdl, ReferentialDdl, CommentsDdl, IndexesDdl, PrivilegesDdl };
    enum ConstraintsTypes { AllConstraints, PrimaryUniqueConstraints, CheckConstraints, ReferentialConstraints };

    explicit KvSqlSession(QObject * parent = 0);
    ~KvSqlSession();
    bool showFormatedError(QString title, QSqlError error);
    bool isValidDb();
    bool isOpen();
    QSqlDatabase getDatabase() { return sessionDatabase; }
    QString getDriver();
    QString databaseForDriver();
    QString nameForDriver(QString driverName);
    QString getDriverComments();
    QString getDbmsTypeName();
    QSqlError connectDatabase(const QString &session, const QString &driver, const QString &dbName, const QString &host, const QString &user, const QString &passwd, int port = -1);
    QString getSessionName() { return sessionDatabase.connectionName(); }
    virtual QMap<QString,QString> getSessionInfo() { return QMap<QString,QString>(); }
    QString getConnectionName() { return sessionConnectionName; }
    QString getConnectionUserName() { return sessionUserName; }
    QString setConnectionName(const QString &connectionName);
    //QSqlQueryModel getQueryModel() { return lastQueryModel; }
    void disconnectDatabase();
    int queryCount(QString sqlStatement);
    int queryExec(QString sqlStatement, QString StatementId = "default");
    virtual QStringList getSqlBlocks(QStringList sqlLines, int fromPosition = -1, int toPosition = -1) { return QStringList(); }
    virtual QStringList getDdlFromObject(QString schema, QString objectName, QString objectType, bool showSchema = true, KvSqlSession::DdlTypes ddlType = KvSqlSession::CompleteDdl) { return QStringList(); }

    virtual QStringList extractConsistentDataSql(QString sqlStatement) { return QStringList(); }
    virtual QList<KvRecordIdentifier> extractConsistentData(QString sqlStatement) { return QList<KvRecordIdentifier>(); }
    virtual QStringList getDependentSql(QString sqlStatement) { return QStringList(); }
    virtual void getChildRecords(QString schema, QString table, QString recordClause, QMap<QString, KvRecordIdentifier> *mapRecordIds, QMap<QString, QList<KvTableColumn> > *mapTablesIdColumns, QMap<QString, QList<KvTableDependency> > *mapTablesDependencies) { }
    virtual void getParentRecords(QString schema, QString table, QString recordClause, QMap<QString, KvRecordIdentifier> *mapRecordIds, QMap<QString, QList<KvTableColumn> > *mapTablesIdColumns, QMap<QString, QList<KvTableDependency> > *mapTablesDependencies) { }
    virtual QList<KvTableDependency> getTableChildRelationships(QString schema, QString table) { return QList<KvTableDependency>(); }
    virtual QList<KvTableDependency> getTableParentRelationships(QString schema, QString table) { return QList<KvTableDependency>(); }

    // This method will get the plan lines for a sql statement. Each plan line has a map of column names and their values
    virtual QList< QPair<QString, QMap<QString,QString> > > getExecPlan(QString sqlStatement, QString StatementId = "default") { return QList< QPair<QString, QMap<QString,QString> > >(); }
    virtual QString findObjectStatement(QString fullObjectName, QString typeName = QString()) { return QString(); }
    virtual QMap<QString, QList< QPair<QString, QString> > > getObjectParents(const QStringList objectList) { return QMap<QString, QList< QPair<QString, QString> > >(); }
    void showTable(const QString &table);
    void showMetaData(const QString &table);
    virtual QStringList getSchemas(bool refreshSchemaList = false) { return QStringList(); }
    virtual QStringList getSchemasWithTables() { return QStringList(); }
    virtual QStringList getSchemasWithViews() { return QStringList(); }
    virtual QStringList getSchemasWithPrograms() { return QStringList(); }
    virtual QStringList getSchemasWithEtc() { return QStringList(); }
    virtual QStringList getProgramsTypes() { return QStringList(); }
    virtual QStringList getEtcTypes() { return QStringList(); }
    virtual QStringList getTables(const QString &schema) { return QStringList(); }
    virtual QStringList getViews(const QString &schema) { return QStringList(); }
    virtual QStringList getPrograms(const QString &schema, const QString &type) { return QStringList(); }
    virtual QList< QPair<QString, QString> > getProgramsWithStatus(const QString &schema, const QString &type) { return QList< QPair<QString,QString> >(); }
    virtual QStringList getEtc(const QString &schema, const QString &type) { return QStringList(); }
    virtual QList< QPair<QString, QString> > getEtcWithStatus(const QString &schema, const QString &type) { qDebug() << "etcWithStatus - Parent"; return QList< QPair<QString,QString> >(); }
    QList< QPair< QPair<QString, QString>, QPair<QString, QString> > > getRelationsWithTables(const QList< QPair<QString, QString> > &tables);
    QList< QPair<QString, QString> > getParentTables(const QString &schema, const QString &table);
    QList< QPair<QString, QString> > getChildTables(const QString &schema, const QString &table);
    int getColumns(QTableWidget *tableWidget, QString schemaName, QString tableName);
    virtual QList<KvColumnInfo> getColumns(QString schemaName, QString tableName) { return QList<KvColumnInfo>(); }
    // Table Identity Columns can be Primary Key Columns or Row identifiers
    virtual QList<KvTableColumn> getTableIdentityColumns(QString schemaName, QString tableName) { return QList<KvTableColumn>(); }
    virtual QStringList getTableComments(QString schemaName, QString tableName) { return QStringList(); }
    // This second method only retrieves the comments of a table (not its columns' comments)
    virtual QString getOnlyTableComments(QString schemaName, QString tableName) { return QString(); }
    virtual QStringList getPrivileges(QString schemaName, QString objectName, QString objectType) { return QStringList(); }
    int getPrivileges(QTableWidget *tableWidget, QString schemaName, QString tableName, bool dbaRoleEnabled = false);
    virtual bool isDbaRoleEnabled() { return false; }
    virtual QStringList getConstraints(QString schemaName, QString tableName, KvSqlSession::ConstraintsTypes constraintsTypes = KvSqlSession::AllConstraints) { return QStringList(); }
    virtual QList< KvTableConstraintInfo > getUniqueConstraints(QString schemaName, QString tableName) { return QList< KvTableConstraintInfo >(); }
    virtual QList< KvTableConstraintInfo > getRelationshipConstraints(QString schemaName, QString tableName) { return QList< KvTableConstraintInfo >(); }
    QStringList describe(const QString &schema, const QString &table);
    virtual QStringList getIndex(QString schema, QString indexName, bool showSchema) { return QStringList(); }
    QSqlQueryModel lastQueryModel;
    QMap<QString, QSqlQueryModel *> queryModels;
    bool toBeDisconnected;
    bool inTransactionState;
    virtual void setObjectTypeNames() { }
    virtual void setObjectTypeOrder() { }
    QStringList getObjectTypeNames() { return databaseObjectTypeNames; }
    QStringList getObjectTypeOrder() { return databaseObjectTypeOrder; }
protected:
    QSqlDatabase sessionDatabase;
    QString sessionConnectionName;
    QString sessionUserName;
    //QSqlQuery *lastQuery;
    //QSqlQueryModel lastQueryModel;
    QStringList schemas;
    QStringList databaseObjectTypeNames;
    QStringList databaseObjectTypeOrder;
signals:
    void sendTablesOfSchema(QTreeWidgetItem *item, const QString &schema, QStringList tables);
public slots:
    virtual void getTablesOfSchema(QTreeWidgetItem *item, const QString &connectionName, const QString &schema) = 0;
    void commitTransaction() { sessionDatabase.commit(); inTransactionState = false; }
    void rollbackTransaction() { sessionDatabase.rollback(); inTransactionState = false; }    
};

#endif // KVSQLSESSION_H
