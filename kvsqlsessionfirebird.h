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

#ifndef KVSQLSESSIONFIREBIRD_H
#define KVSQLSESSIONFIREBIRD_H
#include "kvsqlsession.h"

/**
  Sql Session for FireBird:
  This class will provide the methods to interact to databases.
  It is a super class. Each database kind supported by Kevora will need a child class of Sql Session,
  so there will be an Oracle Sql Session class, a PostgreSql Session class and so on.
*/
class KvSqlSessionFirebird : public KvSqlSession
{
    Q_OBJECT
public:
    explicit KvSqlSessionFirebird(QObject * parent = 0);
    QString databaseForDriver(const QString &driver);
    QString nameForDriver(const QString &driver);
    static QString getDriverComments(const QString &driver);
    QString getDbmsTypeName();
    QMap<QString,QString> getSessionInfo();
    QStringList getTables(const QString &schema);
    QStringList getViews(const QString &schema);
    QList< QPair<QString, QString> > getProgramsWithStatus(const QString &schema, const QString &type);
    QList< QPair<QString, QString> > getEtcWithStatus(const QString &schema, const QString &type);
    QStringList getSqlBlocks(QStringList sqlLines, int fromPosition = -1, int toPosition = -1);
    QStringList getDdlFromObject(QString schema, QString objectName, QString objectType, bool showSchema = true, KvSqlSession::DdlTypes ddlType = KvSqlSession::CompleteDdl);
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

#endif // KVSQLSESSIONFIREBIRD_H
