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

#include "kvsqlsessionmysql.h"

KvSqlSessionMySql::KvSqlSessionMySql(QObject * parent): KvSqlSession(parent)
{
}

QString KvSqlSessionMySql::databaseForDriver(const QString &driver) {
    if (driver.contains("QMYSQL"))
        return "MySql";
    else
        return "";
}

QString KvSqlSessionMySql::nameForDriver(const QString &driver)
{
    if (driver == "QMYSQL")
        return "MySql";
    else if (driver == "QMYSQL3")
        return "MySql";
    else
        return "";
}

QString KvSqlSessionMySql::getDriverComments(const QString &driver) {
    if (driver == "QMYSQL")
        return "QMYSQL: "+tr("This plugin supports MySQL 4 and higher.");
    else if (driver == "QMYSQL3")
        return "QMYSQL3: "+tr("This plugin supports MySQL 3.x and MySQL 4.x.");
    else
        return "";
}

QString KvSqlSessionMySql::getDbmsTypeName() {
    return "MySql";
}

QStringList KvSqlSessionMySql::getTables(const QString &schema)
{
    QStringList result;
    QSqlQuery query("SELECT TABLE_NAME FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_SCHEMA = '"+schema+"' ORDER BY TABLE_NAME", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionMySql::getViews(const QString &schema)
{
    QStringList result;
    QSqlQuery query("SELECT VIEW_NAME FROM INFORMATION_SCHEMA.VIEWS WHERE VIEW_SCHEMA = '"+schema+"' ORDER BY VIEW_NAME", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionMySql::getSchemas()
{
    QStringList result;
    QSqlQuery query("SELECT SCHEMA_NAME FROM INFORMATION_SCHEMA.SCHEMATA ORDER BY SCHEMA_NAME", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionMySql::getSchemasWithTables()
{
    QStringList result;
    QSqlQuery query("SELECT SCHEMA_NAME FROM INFORMATION_SCHEMA.SCHEMATA ORDER BY SCHEMA_NAME", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionMySql::getSchemasWithViews()
{
    QStringList result;
    QSqlQuery query("SELECT SCHEMA_NAME FROM INFORMATION_SCHEMA.SCHEMATA ORDER BY SCHEMA_NAME", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionMySql::getSqlBlocks(QStringList sqlLines, int fromPosition, int toPosition)
{
    QStringList result = QStringList();
    // A list of sql blocks (a block is composed by its first position, last position and its text)
    QMap<int, KvSqlBlock> bufferMap = QMap<int, KvSqlBlock>();

    QRegExp minimalRegExp = QRegExp("--.*\\n");
    minimalRegExp.setMinimal(true);

    QStringList newSqlLines = QStringList();
    foreach(QString line, sqlLines) {
        if (line.indexOf(minimalRegExp) != 0) {
            newSqlLines.append(line);
        }
        else {
            newSqlLines.append(line.replace(";",",")); // .remove(";"));
        }
    }

    QString buffer = newSqlLines.join(QString());

    int firstPosition = 0;
    int lastPosition = 0;

    if (fromPosition == -1)
        firstPosition == 0;
    else
        firstPosition = fromPosition;

    if (toPosition == -1)
        lastPosition = buffer.size();
    else
        lastPosition = toPosition;

    // Grouping all SQL blocks according to Oracle Syntax
    if ((buffer.toUpper().count(QRegExp("BEGIN(?![.*\\*\\/|.*\\'])")) > 0) ||
            (buffer.toUpper().count(QRegExp("END(?![.*\\*\\/|.*\\'])")) > 0)) {

    }

    // Semicolon is the simple SQL statement separator (except when it is commented or quoted)
    // |[(?![--.*]);.*$]
    QStringList simpleStatements = buffer.split(QRegExp(";(?![.*\\*\\/|.*\\'])"), QString::SkipEmptyParts);
    QStringList newSimpleStatements = QStringList();

    /*
    for(int i = 0; i < simpleStatements.size(); i++) {
        QString theItem = simpleStatements.at(i);
        QRegExp regExpMinimal = QRegExp("(--).*(?!\\n)");
        regExpMinimal.setMinimal(true);
        if (simpleStatements.at(i).indexOf(regExpMinimal) >= 0) {
            QString nextLine = QString("");
            if (i+1 < simpleStatements.size()) {
                qDebug() << "i+1 =" << simpleStatements.at(i+1);
                qDebug() << "index of \\n in simpleStatements.at(i+1) =" << simpleStatements.at(i+1).indexOf(QRegExp("\\n"));
            }
            if ((i+1 < simpleStatements.size()) && (simpleStatements.at(i+1).indexOf(QRegExp("\\n")) == 0)) {
                qDebug() << "simpleStatements.at(i+1).at(0) == '\\n'";
                nextLine = simpleStatements.at(i+1);
            }
            theItem = theItem + nextLine;
            i++;
        }
        newSimpleStatements.append(theItem);
    }
    simpleStatements.clear();
    simpleStatements = newSimpleStatements;
    buffer = simpleStatements.join("");
    */

    int lastTextPosition = 0;
    foreach(QString text, simpleStatements) {
        QString newText = text;
        newText = newText.remove(minimalRegExp).simplified().trimmed();
        if (newText.size() != 0) {
            KvSqlBlock block;
            lastTextPosition = buffer.indexOf(text, lastTextPosition);
            block.first = lastTextPosition;
            block.last = lastTextPosition + (text.size()-1);
            block.text = text;
            bufferMap.insert(block.first, block);
            lastTextPosition = block.last;
        }
    }

    if (firstPosition == lastPosition) {
        // Just the SQL block at that position will be returned...
        foreach(int key, bufferMap.keys()) {
            // First and Last Position inside a Sql Text Block
            if ((bufferMap.value(key).first <= firstPosition) && (lastPosition <= bufferMap.value(key).last)) {
                QString bufferText = bufferMap.value(key).text;
                bufferText = bufferText.remove(minimalRegExp).simplified().trimmed();
                if (bufferText.size() != 0)
                    result.append(bufferMap.value(key).text);
            }
        }
    }
    else {
        // The SQL blocks from firstPosition to LastPosition will be returned...
        foreach(int key, bufferMap.keys()) {
            // Sql Text Blocks inside a First and Last Position Interval
            if ((firstPosition <= bufferMap.value(key).first) && (bufferMap.value(key).last <= lastPosition)) {
                QString bufferText = bufferMap.value(key).text;
                bufferText = bufferText.remove(minimalRegExp).simplified().trimmed();
                if (bufferText.size() != 0)
                    result.append(bufferMap.value(key).text);
            }
        }
    }
    return result;
}

QList< QPair< QPair<QString, QString>, QPair<QString, QString> > > KvSqlSessionMySql::getRelationsWithTables(const QList< QPair<QString, QString> > &tables)
{
    QList< QPair< QPair<QString, QString>, QPair<QString, QString> > > result;
    QString querySql =	"SELECT DISTINCT C2.OWNER, C2.TABLE_NAME, C1.OWNER, C1.TABLE_NAME FROM ALL_CONSTRAINTS C1, ALL_CONSTRAINTS C2 WHERE C1.R_CONSTRAINT_NAME = C2.CONSTRAINT_NAME AND C1.R_OWNER = C2.OWNER AND ";
    QString tablesOr =	"";
    for (int t = 0; t < tables.size(); ++t) {
        QString tableOwner	= "C1.OWNER = '"+tables.at(t).first+"'";
        QString tableName	= "C1.TABLE_NAME = '"+tables.at(t).second+"'";
        QString tableAnd	= "( "+tableOwner+" AND "+tableName+" )";
        tablesOr += tableAnd + " OR ";
    }
    QString tablesOr2 =	"";
    for (int t2 = 0; t2 < tables.size(); ++t2) {
        QString tableOwner	= "C2.OWNER = '"+tables.at(t2).first+"'";
        QString tableName	= "C2.TABLE_NAME = '"+tables.at(t2).second+"'";
        QString tableAnd	= "( "+tableOwner+" AND "+tableName+" )";
        tablesOr2 += tableAnd + " OR ";
    }
    if (! (tablesOr.isEmpty() && tablesOr2.isEmpty()) ) {
        tablesOr	=	tablesOr.left(tablesOr.length()-4);
        tablesOr2	=	tablesOr2.left(tablesOr2.length()-4);
        querySql	+=	"( ("+tablesOr+") OR ("+tablesOr2+") ) ORDER BY C2.OWNER, C2.TABLE_NAME";

        QSqlQuery query(querySql, sessionDatabase);
        while (query.next()) {
            QPair<QString, QString> parentTable;
            QPair<QString, QString> childTable;
            parentTable.first	= query.value(0).toString();
            parentTable.second	= query.value(1).toString();
            childTable.first	= query.value(2).toString();
            childTable.second	= query.value(3).toString();
            QPair< QPair<QString, QString>, QPair<QString, QString> > relation;
            relation.first = parentTable;
            relation.second = childTable;
            result.append(relation);
        }


    }
    return result;
}

QList< QPair<QString, QString> > KvSqlSessionMySql::getParentTables(const QString &schema, const QString &table)
{
    QList< QPair<QString, QString> > result;
    QSqlQuery query("SELECT DISTINCT C2.OWNER, C2.TABLE_NAME FROM ALL_CONSTRAINTS C1, ALL_CONSTRAINTS C2 WHERE C1.OWNER = '"+schema+"' AND C1.TABLE_NAME = '"+table+"' AND "+
                    "C1.R_CONSTRAINT_NAME = C2.CONSTRAINT_NAME AND C1.R_OWNER = C2.OWNER ORDER BY C2.OWNER, C2.TABLE_NAME", sessionDatabase);
    while (query.next()) {
        QPair<QString, QString> parentTable;
        parentTable.first	= query.value(0).toString();
        parentTable.second	= query.value(1).toString();
        result << parentTable;
    }
    return result;
}

QList< QPair<QString, QString> > KvSqlSessionMySql::getChildTables(const QString &schema, const QString &table) {
    QList< QPair<QString, QString> > result;
    QSqlQuery query("SELECT DISTINCT C1.OWNER, C1.TABLE_NAME FROM ALL_CONSTRAINTS C1, ALL_CONSTRAINTS C2 WHERE C2.OWNER = '"+schema+"' AND C2.TABLE_NAME = '"+table+"' AND "+
                    "C1.R_CONSTRAINT_NAME = C2.CONSTRAINT_NAME AND C1.R_OWNER = C2.OWNER ORDER BY C1.OWNER, C1.TABLE_NAME", sessionDatabase);
    while (query.next()) {
        QPair<QString, QString> childTable;
        childTable.first	= query.value(0).toString();
        childTable.second	= query.value(1).toString();
        result << childTable;
    }
    return result;
}

int KvSqlSessionMySql::getColumns(QTableWidget *tableWidget, QString schemaName, QString tableName) {
    QSqlError err;
    QString sqlStatement;

    tableWidget->setRowCount(0);

    sqlStatement = "SELECT COLUMN_NAME, DATA_TYPE, DATA_LENGTH, DATA_PRECISION, DATA_SCALE, NULLABLE, DATA_DEFAULT FROM ALL_TAB_COLUMNS WHERE OWNER = '"+
                   schemaName+"' AND TABLE_NAME = '"+tableName+"' ORDER BY COLUMN_ID";

    QSqlQuery query(sqlStatement, sessionDatabase);
    int r = 0;
    while (query.next()) {
        tableWidget->insertRow(r);
        QTableWidgetItem *itemColumnName = new QTableWidgetItem(query.value(0).toString());
        QTableWidgetItem *itemDataType = new QTableWidgetItem(query.value(1).toString());
        QString dataLength;
        QString dataDigits;
        if (query.value(1).toString().contains("NUMBER")) {
            dataLength = query.value(3).toString();
            dataDigits = query.value(4).toString();
        }
        else {
            dataLength = query.value(2).toString();
            dataDigits = "";
        }
        QTableWidgetItem *itemDataLength = new QTableWidgetItem(dataLength);
        QTableWidgetItem *itemDataDigits = new QTableWidgetItem(dataDigits);
        QTableWidgetItem *itemNullable = new QTableWidgetItem();
        if (query.value(5).toString() == "Y") {
            itemNullable->setCheckState(Qt::Checked);
        }
        else {
            itemNullable->setCheckState(Qt::Unchecked);
        }

        QTableWidgetItem *itemDataDefault = new QTableWidgetItem(query.value(6).toString());
        tableWidget->setItem(r, 0, itemColumnName);
        tableWidget->setItem(r, 1, itemDataType);
        tableWidget->setItem(r, 2, itemDataLength);
        tableWidget->setItem(r, 3, itemDataDigits);
        tableWidget->setItem(r, 4, itemNullable);
        tableWidget->setItem(r, 5, itemDataDefault);
        r++;
    }

    tableWidget->resizeColumnsToContents();
    return 0;
}

int KvSqlSessionMySql::getPrivileges(QTableWidget *tableWidget, QString schemaName, QString tableName, bool dbaRoleEnabled)
{
    QSqlError err;
    QString sqlStatement;

    tableWidget->setRowCount(0);

    if (dbaRoleEnabled) {
        sqlStatement = "SELECT GRANTEE, PRIVILEGE, GRANTABLE FROM DBA_TAB_PRIVS WHERE OWNER = '"+
                       schemaName+"' AND TABLE_NAME = '"+tableName+"' ORDER BY GRANTEE, PRIVILEGE";
    }
    else {
        sqlStatement = "SELECT GRANTEE, PRIVILEGE, GRANTABLE FROM ALL_TAB_PRIVS WHERE TABLE_SCHEMA = '"+
                       schemaName+"' AND TABLE_NAME = '"+tableName+"' ORDER BY GRANTEE, PRIVILEGE";
    }
    QSqlQuery query(sqlStatement, sessionDatabase);
    int r = 0;
    while (query.next()) {
        tableWidget->insertRow(r);

        QTableWidgetItem *itemGrantee = new QTableWidgetItem(query.value(0).toString());
        QTableWidgetItem *itemPrivilege = new QTableWidgetItem(query.value(1).toString());
        QTableWidgetItem *itemGrantable = new QTableWidgetItem();
        if (query.value(2).toString().at(0) == 'Y') {
            itemGrantable->setCheckState(Qt::Checked);
        }
        else {
            itemGrantable->setCheckState(Qt::Unchecked);
        }
        tableWidget->setItem(r, 0, itemGrantee);
        tableWidget->setItem(r, 1, itemPrivilege);
        tableWidget->setItem(r, 2, itemGrantable);
        r++;
    }

    tableWidget->resizeColumnsToContents();
    return 0;
}

bool KvSqlSessionMySql::isDbaRoleEnabled() {
    bool result = false;
    QSqlQuery queryDBATables("SELECT 1 FROM DBA_TABLES WHERE ROWNUM<=1", sessionDatabase);
    if (queryDBATables.lastError().text().trimmed().isEmpty()) {
        result = true;
    }
    return result;
}

QList< KvTableConstraintInfo > KvSqlSessionMySql::getUniqueConstraints(QString schemaName, QString tableName) {
    QSqlError err;
    QString sqlStatementForTable;
    QString sqlStatementForColumns;
    QList< KvTableConstraintInfo > result;


    sqlStatementForTable = QString("SELECT C.OWNER, C.CONSTRAINT_NAME, C.TABLE_NAME, C.CONSTRAINT_TYPE, C.STATUS FROM DBA_CONSTRAINTS C WHERE ")+
                           "C.OWNER = '"+schemaName+"' AND C.TABLE_NAME = '"+tableName+"' AND "+
                           "C.CONSTRAINT_TYPE IN ('P','U') ORDER BY C.CONSTRAINT_TYPE, C.CONSTRAINT_NAME";

    sqlStatementForColumns = QString("SELECT CC.COLUMN_NAME FROM DBA_CONS_COLUMNS CC WHERE ")+
                             "CC.OWNER = ':C_OWNER' AND CC.CONSTRAINT_NAME = ':C_CONSTRAINT_NAME' "+
                             "ORDER BY CC.POSITION";
    QSqlQuery queryForTable(sqlStatementForTable, sessionDatabase);
    while (queryForTable.next()) {
        KvTableConstraintInfo constraint;
        constraint.constraintSchema	= queryForTable.value(0).toString();
        constraint.constraintName	= queryForTable.value(1).toString();
        constraint.constraintTable	= queryForTable.value(2).toString();
        constraint.constraintType	= queryForTable.value(3).toString();
        constraint.constraintStatus	= queryForTable.value(4).toString();

        QSqlQuery queryForColumns(sqlStatementForColumns, sessionDatabase);
        queryForColumns.bindValue("C_OWNER", constraint.constraintSchema);
        queryForColumns.bindValue("C_CONSTRAINT_NAME", constraint.constraintName);
        while (queryForColumns.next()) {
            constraint.constraintColumns.append(queryForColumns.value(0).toString());
        }
        result.append(constraint);
    }

    return result;
}

QStringList KvSqlSessionMySql::describe(const QString &schema, const QString &table) {
    QStringList result;
    QString maxSizeStatement;
    QString describeStatement;
    int maxColumnSize = 0;

    QString admViewName  = "";
    QString schemaClause = "";
    if (isDbaRoleEnabled())
        admViewName = "DBA_TAB_COLUMNS";
    else
        admViewName = "ALL_TAB_COLUMNS";

    if (! schema.trimmed().isEmpty())
        schemaClause = " AND OWNER = '"+schema+"'";

    maxSizeStatement  = "SELECT MAX(LENGTH(COLUMN_NAME)) FROM "+admViewName+" WHERE TABLE_NAME = '"+table+"'"+schemaClause;
    describeStatement = "SELECT COLUMN_NAME, NULLABLE, DATA_TYPE, DATA_LENGTH, DATA_PRECISION, DATA_SCALE, DATA_DEFAULT FROM "+admViewName+" WHERE TABLE_NAME = '"+table+"'"+schemaClause+" ORDER BY COLUMN_ID";

    QSqlQuery queryMaxSize(maxSizeStatement, sessionDatabase);
    if (queryMaxSize.next()) {
        maxColumnSize = queryMaxSize.value(0).toInt();
        result.append(tr("Name").leftJustified(maxColumnSize, ' ')+" "+tr("Null?").leftJustified(8, ' ')+" "+tr("Type").leftJustified(30, ' ')+" "+tr("Default"));
        result.append(QString("").leftJustified(maxColumnSize, '-')+" "+QString("").leftJustified(8, '-')+" "+QString("").leftJustified(30, '-')+" "+QString("").leftJustified(30, '-'));
    }

    QSqlQuery queryForDescribe(describeStatement, sessionDatabase);
    while (queryForDescribe.next()) {
        QString columnName = queryForDescribe.value(0).toString().leftJustified(maxColumnSize, ' ')+" ";

        QString columnNullable;
        if (queryForDescribe.value(1).toString() == "Y")
            columnNullable = QString("NULL").leftJustified(8,' ')+" ";
        else
            columnNullable = QString("NOT NULL").leftJustified(8,' ')+" ";
        QString columnType = queryForDescribe.value(2).toString();
        QString columnSize;
        if (columnType.contains("CHAR"))
            columnSize = "("+queryForDescribe.value(3).toString()+")";
        else if (queryForDescribe.value(4).toInt()>0) {
            columnSize = "("+queryForDescribe.value(4).toString();
            if (queryForDescribe.value(5).toInt()>0)
                columnSize += ","+queryForDescribe.value(5).toString();
            columnSize+=")";
        }
        columnType = (columnType+columnSize).leftJustified(30, ' ');
        QString columnDefault = " "+queryForDescribe.value(6).toString();
        result.append(columnName+columnNullable+columnType+columnDefault);
    }
    return result;
}

void KvSqlSessionMySql::getTablesOfSchema(QTreeWidgetItem *item, const QString &connectionName, const QString &schema)
{
    QStringList tables = getTables(schema);
    emit sendTablesOfSchema(item, schema, tables);
}

QMap<QString,QString> KvSqlSessionMySql::getSessionInfo()
{
    return QMap<QString,QString>();
}

void KvSqlSessionMySql::setObjectTypeNames()
{
    databaseObjectTypeNames << "TABLE" << "VIEW";
    databaseObjectTypeNames << getProgramsTypes();
    databaseObjectTypeNames << getEtcTypes();
    databaseObjectTypeNames.sort();
}

void KvSqlSessionMySql::setObjectTypeOrder()
{
    databaseObjectTypeOrder << "TABLE" << "VIEW";
    databaseObjectTypeOrder << getProgramsTypes();
    databaseObjectTypeOrder << getEtcTypes();
}
