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

#ifndef KVDBUTIL_H
#define KVDBUTIL_H

#include <QtGui>
#include <QtSql>
#include <QPair>

/*struct KvTableInfo {
        QString schema;
        QString table;
};*/

class KvDbUtil: public QObject {
    Q_OBJECT
public:
    enum DbmsHighlightTypes { HtCubrid, HtFirebird, HtMySql, HtOracle, HtODBC, HtPostgreSql, HtSqlite, HtSql92, HtTnsNames, HtOthers };
    enum Databases { Cubrid, Firebird, MySql, Oracle, PostgreSql, Sqlite, Unknown };
    
    static bool showFormatedError(QString title, QSqlError error);
    static bool isValidDb(QString connectionName);
    static QStringList getSupportedDatabases();
    static QStringList getActiveDrivers();
    static QString getDriver(QString connectionName);
    static KvDbUtil::Databases databaseForDriver(const QString &driver);
    static QString driverForDatabase(const QString &dbType);
    static QStringList driversForDatabase(const QString &dbType);
    static QString nameForDriver(const QString &driver);
    static QString getDriverComments(const QString &driver);
    static QString getDbmsTypeName(const QString &connectionName);
    static int recordCountForFetch();
};

#endif // KVDBUTIL_H
