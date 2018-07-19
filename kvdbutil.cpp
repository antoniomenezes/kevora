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

#include "kvdbutil.h"
#include <QMessageBox>

bool KvDbUtil::isValidDb(QString connectionName) 
{
    return QSqlDatabase::database(connectionName).isValid();
}

QStringList KvDbUtil::getSupportedDatabases() {
    QStringList databases;
    databases.append("Cubrid");
    databases.append("Firebird/Interbase");
    databases.append("MySql");
    databases.append("ODBC");
    databases.append("Oracle");
    databases.append("PostgreSql");
    databases.append("Sqlite");
    return databases;
}

QStringList KvDbUtil::getActiveDrivers() {
    QStringList drivers = QSqlDatabase::drivers();
    return drivers;
}

QString KvDbUtil::getDriver(QString connectionName) 
{
    return QSqlDatabase::database(connectionName).driverName();
}

KvDbUtil::Databases KvDbUtil::databaseForDriver(const QString &driver) {
    if (driver.contains("QMYSQL"))
        return KvDbUtil::MySql;
    else if ((driver.contains("QOpenOCCI")) || (driver.contains("QOCI")))
        return KvDbUtil::Oracle;
    else if (driver.contains("QPSQL"))
        return KvDbUtil::PostgreSql;
    else if (driver.contains("QSQLITE"))
        return KvDbUtil::Sqlite;
    else if (driver.contains("QIBASE"))
        return KvDbUtil::Firebird;
    else if (driver.contains("QCUBRID"))
        return KvDbUtil::Cubrid;
    else if (driver.contains("QODBC"))
        return KvDbUtil::Unknown;    
    else
        return KvDbUtil::Unknown;
}

QString KvDbUtil::driverForDatabase(const QString &dbType) {
    if (dbType.contains("MySql"))
        return "QMYSQL";
    else if (dbType.contains("Oracle"))
        return "QOCI";
    else if (dbType.contains("PostgreSql"))
        return "QPSQL";
    else if (dbType.contains("Sqlite"))
        return "QSQLITE";
    else if (dbType.contains("Firebird"))
        return "QIBASE";
    else if (dbType.contains("Cubrid"))
        return "QCUBRID";
    else if (dbType.contains("ODBC"))
        return "QODBC";
    else
        return "";
}

QStringList KvDbUtil::driversForDatabase(const QString &dbType) {
    QStringList drivers;
    if (dbType.contains("MySql"))
        drivers << "QMYSQL" << "QMYSQL3";
    else if (dbType.contains("Oracle"))
        drivers << "QOCI" << "QOCI8" << "QOpenOCCI";
    else if (dbType.contains("PostgreSql"))
        drivers << "QPSQL" << "QPSQL7";
    else if (dbType.contains("Sqlite"))
        drivers << "QSQLITE" << "QSQLITE2";
    else if (dbType.contains("Firebird"))
        drivers << "QIBASE";
    else if (dbType.contains("Cubrid"))
        drivers << "QCUBRID";
    else if (dbType.contains("ODBC"))
        drivers << "QODBC" << "QODBC3";

    return drivers;
}

QString KvDbUtil::nameForDriver(const QString &driver)
{
    if (driver == "QMYSQL")
        return "MySql";
    else if (driver == "QODBC")
        return "ODBC";
    else if (driver == "QOpenOCCI")
        return "Oracle (QOpenOCCI)";
    else if (driver == "QOCI")
        return "Oracle (QOCI)";
    else if (driver == "QPSQL")
        return "PostgreSql";
    else if (driver == "QSQLITE")
        return "Sqlite";
    else if (driver == "QIBASE")
        return "Firebird/Interbase";
    else if (driver == "QCUBRID")
        return "Cubrid";
    else
        return "";
}

QString KvDbUtil::getDriverComments(const QString &driver) {
    if (driver == "QMYSQL")
        return "QMYSQL: "+tr("This plugin supports MySQL 4 and higher.");
    else if (driver == "QMYSQL3")
        return "QMYSQL3: "+tr("This plugin supports MySQL 3.x and MySQL 4.x.");
    else if (driver == "QODBC")
        return "QODBC: "+tr("This plugin needs an ODBC compliant driver manager. ODBC is a general interface that allows you to connect to multiple DBMSs using a common interface. The QODBC driver allows you to connect to an ODBC driver manager and access the available data sources. Note that you also need to install and configure ODBC drivers for the ODBC driver manager that is installed on your system.");
    else if (driver == "QODBC3")
        return "QODBC3: "+tr("This plugin needs an ODBC compliant driver manager version 2.0 or later to work. It can be used, for example, to access a Microsoft SQL Server database.");
    else if (driver == "QOpenOCCI")
        return "QOpenOCCI: "+tr("Oracle Call Interface Driver. This is a GPL plugin developed by Andrew White and it supports Oracle 9i, 10g and higher.");
    else if (driver == "QOCI")
        return "QOCI: "+tr("Oracle Call Interface Driver. This plugin supports Oracle 9i, 10g and higher. After connecting to the Oracle server, the plugin will auto-detect the database version and enable features accordingly.");
    else if (driver == "QOCI8")
        return "QOCI8: "+tr("Oracle Call Interface Driver. This plugin supports both Oracle 8 and Oracle 9. After connecting to the Oracle server, the plugin will auto-detect the database version and enable features accordingly.");
    else if (driver == "QPSQL")
        return "QPSQL: "+tr("This plugin supports version 7.3 and higher of the PostgreSQL server.");
    else if (driver == "QPSQL7")
        return "QPSQL7: "+tr("This plugin supports both version 6 and 7 of PostgreSQL.");
    else if (driver == "QSQLITE")
        return "QSQLITE: "+tr("This plugin supports SQLite 3 and above. SQLite is an in-process database, it is not necessary to have a database server. SQLite operates on a single file, which must be set as the database name when opening a connection. If the file does not exist, SQLite will try to create it. SQLite also supports in-memory databases, simply pass \":memory:\" as the database name.");
    else if (driver == "QSQLITE2")
        return "QSQLITE2: "+tr("This plugin is offered for compatibility. It supports SQLite Version 2.");
    else if (driver == "QIBASE")
        return "QIBASE: "+tr("This plugin makes it possible to access the InterBase and Firebird databases. InterBase can either be used as a client/server or without a server in which case it operates on local files.");
    else if (driver == "QCUBRID")
        return "QCUBRID: "+tr("This plugin makes it possible to access the Cubrid database.");
    else
        return "";
}

QString KvDbUtil::getDbmsTypeName(const QString &connectionName) {
    if (KvDbUtil::nameForDriver(KvDbUtil::getDriver(connectionName)).contains("Oracle"))
        return "Oracle";
    else
        return KvDbUtil::nameForDriver(KvDbUtil::getDriver(connectionName));
}

bool KvDbUtil::showFormatedError(QString title, QSqlError error) {
    // returns true if an error really happened
    if (error.type() != QSqlError::NoError) {
        QMessageBox::critical(0, title, error.text());
        return true;
    }
    else {
        if (error.text().contains("driver not loaded", Qt::CaseInsensitive)) {
            QMessageBox::critical(0, "Plugin Error", error.text());
            return true;
        }
        else
            return false;
    }
}

int KvDbUtil::recordCountForFetch()
{
    // Get this parameter from User Settings
    return 25;
}

