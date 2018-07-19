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

#ifndef KVSQLSESSIONMYSQL_H
#define KVSQLSESSIONMYSQL_H
#include "kvsqlsession.h"

/**
  Sql Session for MySql:
  This class will provide the methods to interact to databases.
  It is a super class. Each database kind supported by Kevora will need a child class of Sql Session,
  so there will be an Oracle Sql Session class, a PostgreSql Session class and so on.
*/
class KvSqlSessionMySql : public KvSqlSession
{
    Q_OBJECT
public:
    explicit KvSqlSessionMySql(QObject * parent = 0);
    QString databaseForDriver(const QString &driver);
    QString nameForDriver(const QString &driver);
    static QString getDriverComments(const QString &driver);
    QString getDbmsTypeName();
    QMap<QString,QString> getSessionInfo();
    QStringList getTables(const QString &schema);
    QStringList getViews(const QString &schema);
    QStringList getSchemas();
    QStringList getSchemasWithTables();
    QStringList getSchemasWithViews();
    QStringList getSqlBlocks(QStringList sqlLines, int fromPosition = -1, int toPosition = -1);
    QList< QPair< QPair<QString, QString>, QPair<QString, QString> > > getRelationsWithTables(const QList< QPair<QString, QString> > &tables);
    QList< QPair<QString, QString> > getParentTables(const QString &schema, const QString &table);
    QList< QPair<QString, QString> > getChildTables(const QString &schema, const QString &table);
    int getColumns(QTableWidget *tableWidget, QString schemaName, QString tableName);
    int getPrivileges(QTableWidget *tableWidget, QString schemaName, QString tableName, bool dbaRoleEnabled);
    bool isDbaRoleEnabled();
    QList< KvTableConstraintInfo > getUniqueConstraints(QString schemaName, QString tableName);
    QStringList describe(const QString &schema, const QString &table);
    void setObjectTypeNames();
    void setObjectTypeOrder();
signals:
    void sendTablesOfSchema(QTreeWidgetItem *item, const QString &schema, QStringList tables);
public slots:
    void getTablesOfSchema(QTreeWidgetItem *item, const QString &connectionName, const QString &schema);
};

#endif // KVSQLSESSIONMYSQL_H
