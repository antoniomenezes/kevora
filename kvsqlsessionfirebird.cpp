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

#include "kvsqlsessionfirebird.h"

KvSqlSessionFirebird::KvSqlSessionFirebird(QObject * parent): KvSqlSession(parent)
{
}

QString KvSqlSessionFirebird::databaseForDriver(const QString &driver) {
    if (driver.contains("QIBASE"))
        return "Firebird/Interbase";
    else
        return "";
}

QString KvSqlSessionFirebird::nameForDriver(const QString &driver)
{
    if (driver == "QIBASE")
        return "Firebird/Interbase";
    else
        return "";
}

QString KvSqlSessionFirebird::getDriverComments(const QString &driver) {
    if (driver == "QIBASE")
        return "QIBASE: "+tr("This plugin makes it possible to access the InterBase and Firebird databases. InterBase can either be used as a client/server or without a server in which case it operates on local files.");
    else
        return "";;
}

QString KvSqlSessionFirebird::getDbmsTypeName() {
    return "Firebird/Interbase";
}

QStringList KvSqlSessionFirebird::getTables(const QString &schema)
{
    QStringList result;
    QString systemCondition;

    if (schema.compare("PUBLIC", Qt::CaseInsensitive) == 0)
        systemCondition = "(rdb$system_flag IS NULL OR rdb$system_flag = 0)";
    else if (schema.compare("SYSTEM", Qt::CaseInsensitive) == 0)
        systemCondition = "rdb$system_flag > 0";

    QSqlQuery query("SELECT rdb$relation_name FROM rdb$relations WHERE rdb$view_blr IS NULL AND "+systemCondition+" ORDER BY rdb$relation_name", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString().trimmed();
    }
    return result;
}

QStringList KvSqlSessionFirebird::getViews(const QString &schema)
{
    QStringList result;
    QString systemCondition;

    if (schema.compare("PUBLIC", Qt::CaseInsensitive) == 0)
        systemCondition = "(rdb$system_flag IS NULL OR rdb$system_flag = 0)";
    else if (schema.compare("SYSTEM", Qt::CaseInsensitive) == 0)
        systemCondition = "rdb$system_flag > 0";

    QSqlQuery query("SELECT rdb$relation_name FROM rdb$relations WHERE rdb$view_blr IS NOT NULL AND "+systemCondition+" ORDER BY rdb$relation_name", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString().trimmed();
    }
    return result;
}

QList< QPair<QString, QString> > KvSqlSessionFirebird::getProgramsWithStatus(const QString &schema, const QString &type)
{
    QList< QPair<QString, QString> > result;
    QSqlQuery query(sessionDatabase);
    QString systemCondition;

    if (schema.compare("PUBLIC", Qt::CaseInsensitive) == 0)
        systemCondition = "(rdb$system_flag IS NULL OR rdb$system_flag = 0)";
    else if (schema.compare("SYSTEM", Qt::CaseInsensitive) == 0)
        systemCondition = "rdb$system_flag > 0";


    if (type.compare("TRIGGER", Qt::CaseInsensitive) == 0) {
        query.exec(QString("SELECT RDB$TRIGGER_NAME, 'Y' FROM RDB$TRIGGERS WHERE ")+
                   "RDB$RELATION_NAME IN (SELECT rdb$relation_name FROM rdb$relations WHERE "+systemCondition+") "+
                   "ORDER BY RDB$TRIGGER_NAME");
    }
    else if (type.compare("FUNCTION", Qt::CaseInsensitive) == 0) {
        query.exec("SELECT RDB$FUNCTION_NAME, 'Y' FROM RDB$FUNCTIONS WHERE "+systemCondition+" ORDER BY RDB$FUNCTION_NAME");
    }
    else if (type.compare("PROCEDURE", Qt::CaseInsensitive) == 0) {
        query.exec("SELECT RDB$PROCEDURE_NAME, 'Y' FROM RDB$PROCEDURES WHERE "+systemCondition+" ORDER BY RDB$PROCEDURE_NAME");
    }
    while (query.next()) {
        QPair<QString, QString> pair;
        pair.first = query.value(0).toString().trimmed();
        pair.second = query.value(1).toString();
        result << pair;
    }
    return result;
}

QList< QPair<QString, QString> > KvSqlSessionFirebird::getEtcWithStatus(const QString &schema, const QString &type)
{
    QString queryEtc;
    QList< QPair<QString, QString> > result;
    QString systemCondition;

    if (schema.compare("PUBLIC", Qt::CaseInsensitive) == 0)
        systemCondition = "(rdb$system_flag IS NULL OR rdb$system_flag = 0)";
    else if (schema.compare("SYSTEM", Qt::CaseInsensitive) == 0)
        systemCondition = "rdb$system_flag > 0";

    if (type.compare("DOMAIN", Qt::CaseInsensitive) == 0) {
        queryEtc = "SELECT RDB$FIELD_NAME FROM RDB$FIELDS WHERE "+systemCondition+" ORDER BY RDB$FIELD_NAME";
    }
    else if (type.compare("EXCEPTION", Qt::CaseInsensitive) == 0) {
        queryEtc = "SELECT RDB$EXCEPTION_NAME, 'Y' FROM RDB$EXCEPTIONS WHERE "+systemCondition+" ORDER BY RDB$EXCEPTION_NAME";
    }
    else if (type.compare("GENERATOR", Qt::CaseInsensitive) == 0) {
        queryEtc = "SELECT RDB$GENERATOR_NAME, 'Y' FROM RDB$GENERATORS WHERE "+systemCondition+" ORDER BY RDB$GENERATOR_NAME";
    }
    else if (type.compare("INDEX", Qt::CaseInsensitive) == 0) {
        queryEtc = "SELECT RDB$INDEX_NAME, 'Y' FROM RDB$INDICES WHERE "+systemCondition+" ORDER BY RDB$INDEX_NAME";
    }
    else if (type.compare("ROLE", Qt::CaseInsensitive) == 0) {
        queryEtc = "SELECT RDB$ROLE_NAME, 'Y' FROM RDB$ROLES WHERE "+systemCondition+" ORDER BY RDB$ROLE_NAME";
    }

    QSqlQuery query(queryEtc, sessionDatabase);
    while (query.next()) {
        QPair<QString, QString> pair;
        pair.first = query.value(0).toString().trimmed();
        pair.second = query.value(1).toString();
        result << pair;
    }
    return result;
}

QStringList KvSqlSessionFirebird::getSqlBlocks(QStringList sqlLines, int fromPosition, int toPosition)
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

QStringList KvSqlSessionFirebird::getDdlFromObject(QString schema, QString objectName, QString objectType, bool showSchema, KvSqlSession::DdlTypes ddlType)
{
    bool hasShownSchema = false;
    QStringList result;

    if ( (objectType.compare("FUNCTION", Qt::CaseInsensitive) == 0) || (objectType.compare("PACKAGE", Qt::CaseInsensitive) == 0) ||
         (objectType.compare("PACKAGE BODY", Qt::CaseInsensitive) == 0) || (objectType.compare("PROCEDURE", Qt::CaseInsensitive) == 0) ||
         (objectType.compare("TYPE", Qt::CaseInsensitive) == 0) ||
         (objectType.compare("TYPE BODY", Qt::CaseInsensitive) == 0) )
    {
        QString sqlStatement = "SELECT TEXT, LINE FROM _SOURCE WHERE OWNER = '"+schema+"' AND "+
                               "NAME = '"+objectName+"' AND "+
                               "TYPE = '"+objectType+"' ORDER BY LINE";
        QSqlQuery query(sqlStatement, sessionDatabase);
        while (query.next()) {
            QString lineString = query.value(0).toString();

            if (query.value(1).toInt() == 1) {
                lineString = "CREATE OR REPLACE "+lineString;
            }
            //lineString = lineString.replace(QString('\"'+schema+'\"'), Qt::CaseInsensitive, schema);
            //lineString = lineString.replace(QString('\"'+objectName+'\"'), Qt::CaseInsensitive, objectName);

            if (lineString.contains(schema+"."+objectName, Qt::CaseInsensitive) && (!showSchema)) {
                lineString.replace(schema+"."+objectName, objectName, Qt::CaseInsensitive);
            }
            else if (!lineString.contains(schema+"."+objectName, Qt::CaseInsensitive) &&
                     (lineString.contains(objectName, Qt::CaseInsensitive)) && (showSchema) && (!hasShownSchema)) {
                lineString.replace(objectName, schema+"."+objectName, Qt::CaseInsensitive);
                hasShownSchema = true;
            }
            result << lineString;
        }
        if (result.count() > 0)
            result.insert(0, "-- "+tr("CREATE")+" "+objectType);
    }
    else if (objectType.compare("TRIGGER", Qt::CaseInsensitive) == 0)
    {
        QString sqlStatement = QString("SELECT ")+
                               "RDB$TRIGGER_NAME AS trigger_name, "+
                               "RDB$RELATION_NAME AS table_name, "+
                               "RDB$TRIGGER_SOURCE AS trigger_body, "+
                               "CASE RDB$TRIGGER_TYPE "+
                               "  WHEN 1 THEN 'BEFORE' "+
                               "  WHEN 2 THEN 'AFTER' "+
                               "  WHEN 3 THEN 'BEFORE' "+
                               "  WHEN 4 THEN 'AFTER' "+
                               "  WHEN 5 THEN 'BEFORE' "+
                               "  WHEN 6 THEN 'AFTER' END AS trigger_type, "+
                               "CASE RDB$TRIGGER_TYPE "+
                               "  WHEN 1 THEN 'INSERT' "+
                               "  WHEN 2 THEN 'INSERT' "+
                               "  WHEN 3 THEN 'UPDATE' "+
                               "  WHEN 4 THEN 'UPDATE' "+
                               "  WHEN 5 THEN 'DELETE' "+
                               "  WHEN 6 THEN 'DELETE' END AS trigger_event, "+
                               "CASE RDB$TRIGGER_INACTIVE "+
                               "  WHEN 1 THEN 0 ELSE 1 END AS trigger_enabled, "+
                               "RDB$DESCRIPTION AS trigger_comment "+
                               "FROM RDB$TRIGGERS WHERE RDB$TRIGGER_NAME = '"+objectName+"'";
        QSqlQuery query(sqlStatement, sessionDatabase);
        QStringList lines;
        QString triggerTable;
        QString triggerType;
        while (query.next()) {
            if (!query.value(2).isNull()) {
                foreach(QString lineString, query.value(2).toString().split('\n')) {
                    lines << lineString.trimmed();
                }
                QString lastLine = lines.last()+";";
                lines.removeLast();
                lines << lastLine;
            }
            triggerTable = query.value(1).toString().trimmed();
            triggerType = query.value(3).toString().trimmed()+" "+query.value(4).toString().trimmed();
        }
        if (lines.count() == 0) {
            result << "-- "+tr("Code Not Available");
        }
        else {
            result.insert(0, "-- "+tr("CREATE")+" "+objectType);
            result << "CREATE TRIGGER "+objectName+" FOR "+triggerTable+" ";
            result << triggerType+" ";
            //lineString = lineString.replace("BEGIN","BEGIN"+'/n',Qt::CaseInsensitive);
            result.append(lines);
        }
    }
    else if (objectType.compare("TABLE", Qt::CaseInsensitive) == 0)
    {
        /*QString describeStatement;
        QString createTableStatement;
        describeStatement = "SELECT COLUMN_NAME, NULLABLE, DATA_TYPE, DATA_LENGTH, DATA_PRECISION, DATA_SCALE, DATA_DEFAULT FROM "+adminViewPrefix+"_TAB_COLUMNS WHERE OWNER = '"+schema+"' AND TABLE_NAME = '"+objectName+"' ORDER BY COLUMN_ID";
        if (showSchema)
            createTableStatement = "CREATE TABLE "+schema+"."+objectName+" (";
        else
            createTableStatement = "CREATE TABLE "+objectName+" (";

        QSqlQuery query(describeStatement, sessionDatabase);
        result << "-- "+tr("CREATE TABLE");
        result << createTableStatement;
        while (query.next()) {
            QString columnName = query.value(0).toString().trimmed();
            QString columnNullable;
            if (query.value(1).toString() == "Y")
                columnNullable = "NULL";
            else
                columnNullable = "NOT NULL";
            QString columnType = query.value(2).toString().trimmed();
            QString columnSize;
            if (columnType.contains("CHAR"))
                columnSize = "("+query.value(3).toString()+")";
            else if (query.value(4).toInt()>0) {
                columnSize = "("+query.value(4).toString();
                if (query.value(5).toInt()>0)
                    columnSize += ","+query.value(5).toString();
                columnSize+=")";
            }
            columnType = columnType.trimmed();
            columnSize = columnSize.trimmed();
            columnType = (columnType+columnSize).trimmed();
            QString columnDefault;
            if (query.value(6).toString().trimmed().isEmpty())
                columnDefault = "";
            else
                columnDefault = " DEFAULT "+query.value(6).toString().trimmed();
            result.append("  "+columnName+" "+columnType+columnDefault+" "+columnNullable+",");
        }
        QString lastColumnText = result.last();
        lastColumnText = lastColumnText.left(lastColumnText.length()-1);
        result.removeLast();
        result.append(lastColumnText);
        result.append(");");

        // TABLE CONSTRAINTS AND COMMENTS
        result.append("");
        result.append( getConstraints(schema, objectName) );
        result.append("");
        result.append( getTableComments(schema, objectName) );

        // INDEXES OF TABLE
        QString sqlIndexStatement = "SELECT OWNER, INDEX_NAME FROM "+adminViewPrefix+"_INDEXES WHERE TABLE_OWNER = :C_OWNER AND TABLE_NAME = :C_TABLE AND "+
                                    "INDEX_NAME NOT IN ( SELECT CONSTRAINT_NAME FROM "+adminViewPrefix+"_CONSTRAINTS WHERE OWNER = :C_OWNER AND TABLE_NAME = :C_TABLE AND CONSTRAINT_TYPE IN ('U','P')) "
                                    "ORDER BY DECODE(UNIQUENESS, 'UNIQUE', 1, 2), INDEX_NAME";
        QSqlQuery queryIndexes(sqlIndexStatement, sessionDatabase);
        queryIndexes.bindValue(":C_OWNER", schema);
        queryIndexes.bindValue(":C_TABLE", objectName);
        queryIndexes.exec();
        while (queryIndexes.next()) {
            if (! result.contains("-- "+tr("INDEX(ES)"))) {
                result << "";
                result << "-- "+tr("INDEX(ES)");
            }
            QStringList indexDdl = getIndex(queryIndexes.value(0).toString().trimmed(), queryIndexes.value(1).toString().trimmed(), showSchema);
            if (indexDdl.first().contains("-- "+tr("CREATE INDEX")))
                indexDdl.removeFirst();
            result.append( indexDdl );
            result << "";
        }*/
    }
    else if (objectType.compare("VIEW", Qt::CaseInsensitive) == 0)
    {
        /*QString viewTextStatement;
        QString createViewStatement;
        viewTextStatement = "SELECT TEXT FROM _VIEWS WHERE OWNER = '"+schema+"' AND VIEW_NAME = '"+objectName+"'";
        if (showSchema)
            createViewStatement = "CREATE OR REPLACE VIEW "+schema+"."+objectName+" AS ";
        else
            createViewStatement = "CREATE OR REPLACE VIEW "+objectName+" AS ";

        QSqlQuery query(viewTextStatement, sessionDatabase);
        while (query.next()) {
            if (! result.contains(tr("CREATE VIEW")))
                result << "-- "+tr("CREATE VIEW");
            if (! result.contains(createViewStatement))
                result << createViewStatement;
            QStringList viewLinesDef = query.value(0).toString().split('\n', QString::SkipEmptyParts);
            foreach(QString line, viewLinesDef)
                if (!line.trimmed().isEmpty())
                    result << line;
        }
        QString lastResultLine = result.last();
        result.removeLast();
        result << lastResultLine + ";";*/
    }
    else if (objectType.compare("INDEX", Qt::CaseInsensitive) == 0) {
        result.append( getIndex(schema, objectName, showSchema) );
    }
    else if (objectType.compare("SEQUENCE", Qt::CaseInsensitive) == 0) {
        QString sqlStatement = QString("SELECT SEQUENCE_OWNER, SEQUENCE_NAME, MIN_VALUE, MAX_VALUE, INCREMENT_BY, CYCLE_FLAG, ORDER_FLAG, ")+
                               "CACHE_SIZE, LAST_NUMBER+1 "+
                               "FROM _SEQUENCES WHERE SEQUENCE_OWNER = :C_OWNER AND SEQUENCE_NAME = :C_SEQUENCE ";
        QSqlQuery query(sqlStatement, sessionDatabase);
        query.bindValue(":C_OWNER", schema);
        query.bindValue(":C_SEQUENCE", objectName);
        query.exec();
        while (query.next()) {
            if (! result.contains("-- "+tr("CREATE SEQUENCE"))) {
                result << "-- "+tr("CREATE SEQUENCE");
            }
            if (showSchema)
                result << "CREATE SEQUENCE "+query.value(0).toString()+"."+query.value(1).toString();
            else
                result << "CREATE SEQUENCE "+query.value(1).toString();
            result << "INCREMENT BY "+query.value(4).toString();
            result << "START WITH "+query.value(8).toString();
            result << "MAXVALUE "+query.value(3).toString();
            result << "MINVALUE "+query.value(2).toString();
            if (query.value(5).toString().contains("Y"))
                result << "CYCLE";
            else
                result << "NOCYCLE";
            if (query.value(7).toString().compare("0", Qt::CaseInsensitive) == 0)
                result << "NOCACHE";
            else
                result << "CACHE "+query.value(7).toString();
            if (query.value(6).toString().contains("Y"))
                result << "ORDER;";
            else
                result << "NOORDER;";
            result << "";
        }
    }
    /*
    if (objectType.contains("TABLE") || objectType.contains("VIEW") ||
        objectType.contains("FUNCTION") || objectType.contains("PACKAGE") ||
        objectType.contains("PROCEDURE") || objectType.contains("TYPE") ||
        objectType.contains("SEQUENCE")) {
        result.append("");
        result.append( getPrivileges(schema, objectName, objectType) );
    }*/
    return result;
}

QStringList KvSqlSessionFirebird::getSchemas()
{
    QStringList result;
    QSqlQuery query("SELECT 'PUBLIC' FROM RDB$DATABASE UNION ALL SELECT 'SYSTEM' FROM RDB$DATABASE", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString().trimmed();
    }
    return result;
}

QStringList KvSqlSessionFirebird::getSchemasWithTables()
{
    return getSchemas();
}

QStringList KvSqlSessionFirebird::getSchemasWithViews()
{
    return getSchemasWithTables();
}

QStringList KvSqlSessionFirebird::getSchemasWithPrograms()
{
    return getSchemasWithTables();
}

QStringList KvSqlSessionFirebird::getSchemasWithEtc()
{
    return getSchemasWithTables();
}

QStringList KvSqlSessionFirebird::getProgramsTypes()
{
    QStringList result;
    result << "FUNCTION" << "PROCEDURE" << "TRIGGER";
    return result;
}

QStringList KvSqlSessionFirebird::getEtcTypes()
{
    QStringList result;
    result << "DOMAIN" << "EXCEPTION";
    result << "GENERATOR" << "INDEX" << "ROLE";

    return result;
}

QList< QPair< QPair<QString, QString>, QPair<QString, QString> > > KvSqlSessionFirebird::getRelationsWithTables(const QList< QPair<QString, QString> > &tables)
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

QList< QPair<QString, QString> > KvSqlSessionFirebird::getParentTables(const QString &schema, const QString &table)
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

QList< QPair<QString, QString> > KvSqlSessionFirebird::getChildTables(const QString &schema, const QString &table) {
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

int KvSqlSessionFirebird::getColumns(QTableWidget *tableWidget, QString schemaName, QString tableName) {
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

int KvSqlSessionFirebird::getPrivileges(QTableWidget *tableWidget, QString schemaName, QString tableName, bool dbaRoleEnabled)
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

bool KvSqlSessionFirebird::isDbaRoleEnabled() {
    bool result = false;
    QSqlQuery queryDBATables("SELECT 1 FROM DBA_TABLES WHERE ROWNUM<=1", sessionDatabase);
    if (queryDBATables.lastError().text().trimmed().isEmpty()) {
        result = true;
    }
    return result;
}

QList< KvTableConstraintInfo > KvSqlSessionFirebird::getUniqueConstraints(QString schemaName, QString tableName) {
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

QStringList KvSqlSessionFirebird::describe(const QString &schema, const QString &table) {
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

void KvSqlSessionFirebird::getTablesOfSchema(QTreeWidgetItem *item, const QString &connectionName, const QString &schema)
{
    QStringList tables = getTables(schema);
    emit sendTablesOfSchema(item, schema, tables);
}

QMap<QString,QString> KvSqlSessionFirebird::getSessionInfo()
{
    QMap<QString,QString> result;
    QString sqlStatement = QString("SELECT 'MON$ATTACHMENT_ID', MON$ATTACHMENT_ID FROM MON$ATTACHMENTS WHERE MON$ATTACHMENT_ID = CURRENT_CONNECTION UNION ALL ")+
                           "SELECT 'MON$SERVER_PID', MON$SERVER_PID FROM MON$ATTACHMENTS WHERE MON$ATTACHMENT_ID = CURRENT_CONNECTION UNION ALL "+
                           "SELECT 'MON$STATE', MON$STATE FROM MON$ATTACHMENTS WHERE MON$ATTACHMENT_ID = CURRENT_CONNECTION UNION ALL "+
                           "SELECT 'MON$ATTACHMENT_NAME', MON$ATTACHMENT_NAME FROM MON$ATTACHMENTS WHERE MON$ATTACHMENT_ID = CURRENT_CONNECTION UNION ALL "+
                           "SELECT 'MON$USER', MON$USER FROM MON$ATTACHMENTS WHERE MON$ATTACHMENT_ID = CURRENT_CONNECTION UNION ALL "+
                           "SELECT 'MON$ROLE', MON$ROLE FROM MON$ATTACHMENTS WHERE MON$ATTACHMENT_ID = CURRENT_CONNECTION UNION ALL "+
                           "SELECT 'MON$REMOTE_PROTOCOL', MON$REMOTE_PROTOCOL FROM MON$ATTACHMENTS WHERE MON$ATTACHMENT_ID = CURRENT_CONNECTION UNION ALL "+
                           "SELECT 'MON$REMOTE_ADDRESS', MON$REMOTE_ADDRESS FROM MON$ATTACHMENTS WHERE MON$ATTACHMENT_ID = CURRENT_CONNECTION UNION ALL "+
                           "SELECT 'MON$REMOTE_PID', MON$REMOTE_PID FROM MON$ATTACHMENTS WHERE MON$ATTACHMENT_ID = CURRENT_CONNECTION UNION ALL "+
                           "SELECT 'MON$CHARACTER_SET_ID', MON$CHARACTER_SET_ID FROM MON$ATTACHMENTS WHERE MON$ATTACHMENT_ID = CURRENT_CONNECTION UNION ALL "+
                           "SELECT 'MON$TIMESTAMP', MON$TIMESTAMP FROM MON$ATTACHMENTS WHERE MON$ATTACHMENT_ID = CURRENT_CONNECTION UNION ALL "+
                           "SELECT 'MON$GARBAGE_COLLECTION', MON$GARBAGE_COLLECTION FROM MON$ATTACHMENTS WHERE MON$ATTACHMENT_ID = CURRENT_CONNECTION UNION ALL "+
                           "SELECT 'MON$REMOTE_PROCESS', MON$REMOTE_PROCESS FROM MON$ATTACHMENTS WHERE MON$ATTACHMENT_ID = CURRENT_CONNECTION UNION ALL "+
                           "SELECT 'MON$STAT_ID', MON$STAT_ID FROM MON$ATTACHMENTS WHERE MON$ATTACHMENT_ID = CURRENT_CONNECTION";
    QSqlQuery query(sqlStatement, sessionDatabase);
    query.exec();
    while (query.next()) {
        result.insert(query.value(0).toString(), query.value(1).toString());
    }

    return result;
}

void KvSqlSessionFirebird::setObjectTypeNames()
{
    databaseObjectTypeNames << "TABLE" << "VIEW";
    databaseObjectTypeNames << getProgramsTypes();
    databaseObjectTypeNames << getEtcTypes();
    databaseObjectTypeNames.sort();
}

void KvSqlSessionFirebird::setObjectTypeOrder()
{
    databaseObjectTypeOrder << "TABLE" << "VIEW";
    databaseObjectTypeOrder << getProgramsTypes();
    databaseObjectTypeOrder << getEtcTypes();
}
