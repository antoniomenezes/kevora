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

#ifndef KVSQLSESSIONPOSTGRESQL_H
#define KVSQLSESSIONPOSTGRESQL_H
#include "kvsqlsession.h"

/**
  Sql Session for PostgreSql:
  This class will provide the methods to interact to databases.
  It is a super class. Each database kind supported by Kevora will need a child class of Sql Session,
  so there will be an Oracle Sql Session class, a PostgreSql Session class and so on.
*/
class KvSqlSessionPostgreSql : public KvSqlSession
{
    Q_OBJECT
public:
    explicit KvSqlSessionPostgreSql(QObject * parent = 0);
    QString databaseForDriver(const QString &driver);
    QString nameForDriver(const QString &driver);
    static QString getDriverComments(const QString &driver);
    QString getDbmsTypeName();
    QMap<QString,QString> getSessionInfo();
    QStringList getTables(const QString &schema);
    QStringList getViews(const QString &schema);
    QStringList getPrograms(const QString &schema, const QString &type);
    QList< QPair<QString, QString> > getProgramsWithStatus(const QString &schema, const QString &type);
    QStringList getEtc(const QString &schema, const QString &type);
    QList< QPair<QString, QString> > getEtcWithStatus(const QString &schema, const QString &type);
    QStringList getSqlBlocks(QStringList sqlLines, int fromPosition = -1, int toPosition = -1);
    QStringList getDdlFromObject(QString schema, QString objectName, QString objectType, bool showSchema = true, KvSqlSession::DdlTypes ddlType = KvSqlSession::CompleteDdl);

    //QStringList extractConsistentDataSql(QString sqlStatement);
    //QList<KvRecordIdentifier> extractConsistentData(QString sqlStatement);

    QStringList getDependentSql(QString sqlStatement);
    void getChildRecords(QString schema, QString table, QString recordClause, QMap<QString, KvRecordIdentifier> *mapRecordIds, QMap<QString, QList<KvTableColumn> > *mapTablesIdColumns, QMap<QString, QList<KvTableDependency> > *mapTablesDependencies);
    //void getParentRecords(QString schema, QString table, QString recordClause, QMap<QString, KvRecordIdentifier> *mapRecordIds, QMap<QString, QList<KvTableColumn> > *mapTablesIdColumns, QMap<QString, QList<KvTableDependency> > *mapTablesDependencies);
    QList<KvTableDependency> getTableChildRelationships(QString schema, QString table);
    QList<KvTableDependency> getTableParentRelationships(QString schema, QString table);

    //QList< QPair<QString, QMap<QString,QString> > > getExecPlan(QString sqlStatement, QString StatementId = "default");
    QString findObjectStatement(QString fullObjectName, QString typeName = QString());
    //QMap<QString, QList< QPair<QString, QString> > > getObjectParents(const QStringList objectList);

    QStringList getSchemas();
    QStringList getSchemasWithTables();
    QStringList getSchemasWithViews();
    QStringList getSchemasWithPrograms();
    QStringList getSchemasWithEtc();
    QStringList getProgramsTypes();
    QStringList getEtcTypes();
    QList< QPair< QPair<QString, QString>, QPair<QString, QString> > > getRelationsWithTables(const QList< QPair<QString, QString> > &tables);
    QList< QPair<QString, QString> > getParentTables(const QString &schema, const QString &table);
    QList< QPair<QString, QString> > getChildTables(const QString &schema, const QString &table);
    int getColumns(QTableWidget *tableWidget, QString schemaName, QString tableName);

    QList<KvColumnInfo> getColumns(QString schemaName, QString tableName);

    QList<KvTableColumn> getTableIdentityColumns(QString schemaName, QString tableName);

    QStringList getTableComments(QString schemaName, QString tableName);
    QString getOnlyTableComments(QString schemaName, QString tableName);

    QStringList getPrivileges(QString schemaName, QString objectName, QString objectType);
    int getPrivileges(QTableWidget *tableWidget, QString schemaName, QString tableName, bool dbaRoleEnabled);
    bool isDbaRoleEnabled();

    QStringList getConstraints(QString schemaName, QString tableName, KvSqlSession::ConstraintsTypes constraintsTypes = KvSqlSession::AllConstraints);

    QList< KvTableConstraintInfo > getUniqueConstraints(QString schemaName, QString tableName);

    QList< KvTableConstraintInfo > getRelationshipConstraints(QString schemaName, QString tableName);

    QStringList describe(const QString &schema, const QString &table);

    QStringList getIndex(QString schema, QString indexName, bool showSchema);

    void setObjectTypeNames();
    void setObjectTypeOrder();
signals:
    void sendTablesOfSchema(QTreeWidgetItem *item, const QString &schema, QStringList tables);
public slots:
    void getTablesOfSchema(QTreeWidgetItem *item, const QString &connectionName, const QString &schema);
};

#endif // KVSQLSESSIONPOSTGRESQL_H
