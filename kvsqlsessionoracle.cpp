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

#include "kvsqlsessionoracle.h"

KvSqlSessionOracle::KvSqlSessionOracle(QObject * parent): KvSqlSession(parent)
{
}

QString KvSqlSessionOracle::databaseForDriver(const QString &driver) {
    if ((driver.contains("QOpenOCCI")) || (driver.contains("QOCI")))
        return "Oracle";
    else
        return "";
}

QString KvSqlSessionOracle::nameForDriver(const QString &driver)
{
    if (driver == "QOpenOCCI")
        return "Oracle (QOpenOCCI)";
    else if (driver == "QOCI")
        return "Oracle (QOCI)";
    else
        return "";
}

QString KvSqlSessionOracle::getDriverComments(const QString &driver) {
    if (driver == "QOpenOCCI")
        return "QOpenOCCI: "+tr("Oracle Call Interface Driver. This is a GPL plugin developed by Andrew White and it supports Oracle 9i, 10g and higher.");
    else if (driver == "QOCI")
        return "QOCI: "+tr("Oracle Call Interface Driver. This plugin supports Oracle 9i, 10g and higher. After connecting to the Oracle server, the plugin will auto-detect the database version and enable features accordingly.");
    else if (driver == "QOCI8")
        return "QOCI8: "+tr("Oracle Call Interface Driver. This plugin supports both Oracle 8 and Oracle 9. After connecting to the Oracle server, the plugin will auto-detect the database version and enable features accordingly.");
    else
        return "";
}

QString KvSqlSessionOracle::getDbmsTypeName() {
    return "Oracle";
}

QStringList KvSqlSessionOracle::getTables(const QString &schema)
{
    QStringList result;
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QSqlQuery query("SELECT TABLE_NAME FROM "+adminViewPrefix+"_TABLES WHERE OWNER = '"+schema+"' ORDER BY TABLE_NAME", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionOracle::getViews(const QString &schema)
{
    QStringList result;
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QSqlQuery query("SELECT VIEW_NAME FROM "+adminViewPrefix+"_VIEWS WHERE OWNER = '"+schema+"' ORDER BY VIEW_NAME", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionOracle::getPrograms(const QString &schema, const QString &type)
{
    QStringList result;
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QSqlQuery query("SELECT OBJECT_NAME FROM "+adminViewPrefix+"_OBJECTS WHERE OWNER = '"+schema+"' AND OBJECT_TYPE = '"+type+"' ORDER BY OBJECT_NAME", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionOracle::getEtc(const QString &schema, const QString &type)
{
    QStringList result;
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QSqlQuery query("SELECT OBJECT_NAME FROM "+adminViewPrefix+"_OBJECTS WHERE OWNER = '"+schema+"' AND OBJECT_TYPE = '"+type+"' ORDER BY OBJECT_NAME", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QList< QPair<QString, QString> > KvSqlSessionOracle::getProgramsWithStatus(const QString &schema, const QString &type)
{
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QList< QPair<QString, QString> > result;
    QSqlQuery query("SELECT OBJECT_NAME, DECODE(STATUS,'VALID','Y','INVALID','N') FROM "+adminViewPrefix+"_OBJECTS WHERE OWNER = '"+schema+"' AND OBJECT_TYPE = '"+type+"' ORDER BY OBJECT_NAME", sessionDatabase);
    while (query.next()) {
        QPair<QString, QString> pair;
        pair.first = query.value(0).toString();
        pair.second = query.value(1).toString();
        result << pair;
    }
    return result;
}

QList< QPair<QString, QString> > KvSqlSessionOracle::getEtcWithStatus(const QString &schema, const QString &type)
{
    QString queryEtc;
    QList< QPair<QString, QString> > result;

    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    if (type.compare("ROLE", Qt::CaseSensitive) == 0) {
        if (schema.compare("SYS", Qt::CaseSensitive) == 0) {
            queryEtc = "SELECT ROLE, 'Y' FROM "+adminViewPrefix+"_ROLES ORDER BY ROLE";
        }
        else {
            queryEtc = "SELECT GRANTED_ROLE, 'Y' FROM "+adminViewPrefix+"_ROLE_PRIVS WHERE GRANTEE = '"+schema+"' ORDER BY GRANTED_ROLE";
        }
    }
    else if (type.compare("PUBLIC SYNONYM", Qt::CaseSensitive) == 0) {
        if (schema.compare("PUBLIC", Qt::CaseSensitive) != 0) {
            queryEtc = QString("SELECT S.SYNONYM_NAME, DECODE(O.STATUS,'VALID','Y','INVALID','N') FROM "+adminViewPrefix+"_SYNONYMS S, "+adminViewPrefix+"_OBJECTS O ")+
                    "WHERE O.OBJECT_TYPE = 'SYNONYM' AND O.OWNER = 'PUBLIC' AND S.OWNER=O.OWNER AND "+
                    "S.SYNONYM_NAME = O.OBJECT_NAME AND S.TABLE_OWNER = '"+schema+"'  ORDER BY S.SYNONYM_NAME";
        }
    }
    else if (type.compare("SYNONYM", Qt::CaseSensitive) == 0) {
        if (schema.compare("PUBLIC", Qt::CaseSensitive) == 0) {
            return result;
        }
        else {
            queryEtc = "SELECT OBJECT_NAME, DECODE(STATUS,'VALID','Y','INVALID','N') FROM "+adminViewPrefix+"_OBJECTS WHERE OWNER = '"+schema+"' AND OBJECT_TYPE = '"+type+"' ORDER BY OBJECT_NAME";
        }
    }
    else if (type.compare("RECYCLE BIN", Qt::CaseSensitive) == 0) {
        queryEtc = "SELECT ORIGINAL_NAME, 'Y' FROM "+adminViewPrefix+"_RECYCLEBIN WHERE OWNER = '"+schema+"' ORDER BY ORIGINAL_NAME";
    }
    else if (type.compare("TABLESPACE", Qt::CaseSensitive) == 0) {
        queryEtc = QString("SELECT DISTINCT t.TABLESPACE_NAME, 'Y' FROM "+adminViewPrefix+"_TABLESPACES t, "+adminViewPrefix+"_SEGMENTS s ")+
                "WHERE s.TABLESPACE_NAME = t.TABLESPACE_NAME AND s.OWNER = '"+schema+"' UNION "+
                "SELECT DEFAULT_TABLESPACE, 'Y' FROM DBA_USERS WHERE USERNAME = '"+schema+"' UNION "+
                "SELECT TEMPORARY_TABLESPACE, 'Y' FROM DBA_USERS WHERE USERNAME = '"+schema+"'";
    }
    else {
        queryEtc = "SELECT OBJECT_NAME, DECODE(STATUS,'VALID','Y','INVALID','N') FROM "+adminViewPrefix+"_OBJECTS WHERE OWNER = '"+schema+"' AND OBJECT_TYPE = '"+type+"' ORDER BY OBJECT_NAME";
    }

    QSqlQuery query(queryEtc, sessionDatabase);
    while (query.next()) {
        QPair<QString, QString> pair;
        pair.first = query.value(0).toString();
        pair.second = query.value(1).toString();
        result << pair;
    }
    return result;
}

QStringList KvSqlSessionOracle::getSqlBlocks(QStringList sqlLines, int fromPosition, int toPosition)
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
    // QStringList simpleStatements = buffer.split(QRegExp(";(?![.*\\*\\/|[.*|\s*]\\'])"), QString::SkipEmptyParts);
    // QStringList simpleStatements = buffer.split(QRegExp(";(?![.*\\*\\/|[.*|\s*](?!\n)\\'])"), QString::SkipEmptyParts);
    QStringList simpleStatements = buffer.split(QRegExp(";(?![.*\\*\\/|.*\\'])"), QString::SkipEmptyParts);
    qDebug() << simpleStatements;
    QStringList newSimpleStatements = QStringList();

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

QStringList KvSqlSessionOracle::getDdlFromObject(QString schema, QString objectName, QString objectType, bool showSchema, KvSqlSession::DdlTypes ddlType)
{
    bool hasShownSchema = false;
    QStringList result;
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    if ( (objectType.compare("FUNCTION", Qt::CaseInsensitive) == 0) || (objectType.compare("PACKAGE", Qt::CaseInsensitive) == 0) ||
         (objectType.compare("PACKAGE BODY", Qt::CaseInsensitive) == 0) || (objectType.compare("PROCEDURE", Qt::CaseInsensitive) == 0) ||
         (objectType.compare("TRIGGER", Qt::CaseInsensitive) == 0) || (objectType.compare("TYPE", Qt::CaseInsensitive) == 0) ||
         (objectType.compare("TYPE BODY", Qt::CaseInsensitive) == 0) )
    {
        QString sqlStatement = "SELECT TEXT, LINE FROM "+adminViewPrefix+"_SOURCE WHERE OWNER = '"+schema+"' AND "+
                "NAME = '"+objectName+"' AND "+
                "TYPE = '"+objectType+"' ORDER BY LINE";
        QSqlQuery query(sqlStatement, sessionDatabase);
        while (query.next()) {
            QString lineString = query.value(0).toString();

            if (query.value(1).toInt() == 1) {
                lineString = "CREATE OR REPLACE "+lineString.replace("\"","");
            }
            //lineString = lineString.replace(QString('\"'+schema+'\"'), Qt::CaseInsensitive, schema);
            //lineString = lineString.replace(QString('\"'+objectName+'\"'), Qt::CaseInsensitive, objectName);

            if (lineString.contains(schema+"."+objectName, Qt::CaseInsensitive) && (!showSchema)) {
                lineString.replace(schema+"."+objectName, objectName.trimmed(), Qt::CaseInsensitive);
            }
            else if (!lineString.contains(schema+"."+objectName, Qt::CaseInsensitive) &&
                     (lineString.contains(objectName, Qt::CaseInsensitive)) && (showSchema) && (!hasShownSchema)) {
                lineString.replace(objectName, schema.trimmed()+"."+objectName.trimmed(), Qt::CaseInsensitive);
                hasShownSchema = true;
            }
            result << lineString;
        }
        if (result.count() > 0) {
            result.insert(0, "-- "+tr("CREATE")+" "+objectType);
            result << "/";
        }
    }
    else if (objectType.compare("TABLE", Qt::CaseInsensitive) == 0)
    {
        if ((ddlType == KvSqlSession::CompleteDdl) || (ddlType == KvSqlSession::PartialDdl)) {
            QString describeStatement;
            QString createTableStatement;
            describeStatement = QString("SELECT COLUMN_NAME, NULLABLE, DATA_TYPE, DATA_LENGTH, DATA_PRECISION, DATA_SCALE, DATA_DEFAULT, CHAR_USED, CHAR_LENGTH ")+
                    "FROM "+adminViewPrefix+"_TAB_COLUMNS WHERE OWNER = '"+schema+"' AND TABLE_NAME = '"+objectName+"' ORDER BY COLUMN_ID";
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

                if (columnType.contains("CHAR")) {
                    QString columnCharUsed = query.value(7).toString().trimmed();
                    if (columnCharUsed.at(0) != 'C')
                        columnSize = "("+query.value(3).toString()+")";
                    else
                        columnSize = "("+query.value(8).toString()+" CHAR)";
                }
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

            // Primary and Unique Key Constraints
            result.append("");
            result.append( getConstraints(schema, objectName, KvSqlSession::PrimaryUniqueConstraints) );

            // Check Constraints
            result.append("");
            result.append( getConstraints(schema, objectName, KvSqlSession::CheckConstraints) );

        }

        if ((ddlType == KvSqlSession::CompleteDdl) || (ddlType == KvSqlSession::ReferentialDdl)) {
            // TABLE REFERENTIAL CONSTRAINTS
            result.append("");
            result.append( getConstraints(schema, objectName, KvSqlSession::ReferentialConstraints) );
        }

        if ((ddlType == KvSqlSession::CompleteDdl) || (ddlType == KvSqlSession::PartialDdl)) {
            // Table Comments
            result.append("");
            result.append( getTableComments(schema, objectName) );

            // Table Indexes
            QString sqlIndexStatement = "SELECT OWNER, INDEX_NAME FROM "+adminViewPrefix+"_INDEXES I WHERE TABLE_OWNER = :C_OWNER AND TABLE_NAME = :C_TABLE AND "+
                    "INDEX_NAME NOT IN ( SELECT CONSTRAINT_NAME FROM "+adminViewPrefix+"_CONSTRAINTS WHERE OWNER = :C_OWNER AND TABLE_NAME = :C_TABLE AND CONSTRAINT_TYPE IN ('U','P')) AND "+
                    "NOT EXISTS (SELECT 1 FROM "+adminViewPrefix+"_SEGMENTS S WHERE I.INDEX_NAME = S.SEGMENT_NAME AND S.SEGMENT_TYPE = 'LOBINDEX' AND S.OWNER = I.OWNER) "+
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
            }
        }
    }
    else if (objectType.compare("VIEW", Qt::CaseInsensitive) == 0)
    {
        QString viewTextStatement;
        QString createViewStatement;
        viewTextStatement = "SELECT TEXT FROM "+adminViewPrefix+"_VIEWS WHERE OWNER = '"+schema+"' AND VIEW_NAME = '"+objectName+"'";
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
        result << lastResultLine + ";";
    }
    else if (objectType.compare("INDEX", Qt::CaseInsensitive) == 0) {
        result.append( getIndex(schema, objectName, showSchema) );
    }
    else if (objectType.compare("SEQUENCE", Qt::CaseInsensitive) == 0) {
        QString sqlStatement = QString("SELECT SEQUENCE_OWNER, SEQUENCE_NAME, MIN_VALUE, MAX_VALUE, INCREMENT_BY, CYCLE_FLAG, ORDER_FLAG, ")+
                "CACHE_SIZE, LAST_NUMBER+1 "+
                "FROM "+adminViewPrefix+"_SEQUENCES WHERE SEQUENCE_OWNER = :C_OWNER AND SEQUENCE_NAME = :C_SEQUENCE ";
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
    else if (objectType.compare("DATABASE LINK", Qt::CaseInsensitive) == 0) {
        bool firstQueryOK = false;
        QString passwordValue = QString();

        QString sqlStatement = QString("SELECT OWNER, DB_LINK, ")+
                "SUBSTR(DDL_LINK, ( INSTR(UPPER(DDL_LINK),START_STRING) + LENGTH(START_STRING) ), "+
                "( (INSTR(UPPER(DDL_LINK),END_STRING)) - (INSTR(UPPER(DDL_LINK),START_STRING)+LENGTH(START_STRING)) ) "+
                ") ENCRIPTED_PASSWORD, "+
                "DDL_LINK "+
                "FROM (SELECT A.OWNER, "+
                "        A.DB_LINK, 'IDENTIFIED BY VALUES ' START_STRING, "+
                "        'USING ' END_STRING, "+
                "        DBMS_METADATA.GET_DDL('DB_LINK',A.DB_LINK,A.OWNER) DDL_LINK "+
                "      FROM DBA_DB_LINKS A "+
                "      WHERE A.OWNER = '"+schema+"' "+
                "        AND A.DB_LINK = '"+objectName+"' "+
                ") "+
                "WHERE NVL(INSTR(UPPER(DDL_LINK),START_STRING),0)>0 "+
                "AND NVL(INSTR(UPPER(DDL_LINK),END_STRING),0)>0 ";

        //QString sqlStatement = QString("SELECT replace(replace(DBMS_METADATA.GET_DDL('DB_LINK', '"+objectName+"', '"+schema+"'), '\"', ''), '   ', ' ') FROM DUAL");
        QSqlQuery query(sqlStatement, sessionDatabase);
        //query.bindValue(":C_OWNER", schema);
        //query.bindValue(":C_DBLINK", objectName);
        query.exec();
        query.first();

        if ((query.isValid()) && (!query.value(2).isNull()) && (query.value(2).isValid())) {
            passwordValue = query.value(2).toString();
            firstQueryOK = true;
        }

        sqlStatement = QString("SELECT OWNER, DB_LINK, USERNAME, HOST ")+
                "FROM "+adminViewPrefix+"_DB_LINKS WHERE OWNER = :C_OWNER AND DB_LINK = :C_DBLINK ";
        query.exec(sqlStatement);
        query.bindValue(":C_OWNER", schema);
        query.bindValue(":C_DBLINK", objectName);
        query.exec();

        while (query.next()) {
            if (! result.contains("-- "+tr("CREATE DATABASE LINK"))) {
                result << "-- "+tr("CREATE DATABASE LINK");
            }
            if (showSchema)
                result << "CREATE DATABASE LINK "+query.value(0).toString()+"."+query.value(1).toString();
            else
                result << "CREATE DATABASE LINK "+query.value(1).toString();
            result << "CONNECT TO "+query.value(2).toString();
            if (firstQueryOK)
                result << "IDENTIFIED BY VALUES "+passwordValue;
            else
                result << "IDENTIFIED BY ???";
            result << "USING '"+query.value(3).toString()+"';";
            result << "";
        }
    }
    // Extracting Privileges Commands
    if (/*(ddlType == KvSqlSession::CompleteDdl) &&*/ (objectType.contains("TABLE") || objectType.contains("VIEW") ||
                                                       objectType.contains("FUNCTION") || objectType.contains("PACKAGE") ||
                                                       objectType.contains("PROCEDURE") || objectType.contains("TYPE") ||
                                                       objectType.contains("SEQUENCE"))) {
        if ((ddlType == KvSqlSession::CompleteDdl) || (ddlType == KvSqlSession::PrivilegesDdl)) {
            result.append("");
            result.append( getPrivileges(schema, objectName, objectType) );
        }
    }
    return result;
}

QStringList KvSqlSessionOracle::extractConsistentDataSql(QString sqlStatement)
{
    QStringList result = QStringList();
    QList<KvRecordIdentifier> records = extractConsistentData(sqlStatement);

    for(int i=0; i<records.count(); i++)
        result << "INSERT INTO "+records.at(i).recordSchema+"."+records.at(i).recordTable+" SELECT * FROM "+records.at(i).recordSchema+"."+records.at(i).recordTable+" WHERE "+records.at(i).recordKeyClause+";";

    return result;
}

QList<KvRecordIdentifier> KvSqlSessionOracle::extractConsistentData(QString sqlStatement)
{
    QStringList result = QStringList();
    QString statementsByFrom = QString();
    QString statementsByWhere = QString();
    QString fullTableName, tableName, schemaName;

    QMap<QString, KvRecordIdentifier> mapChildRecordIds = QMap<QString, KvRecordIdentifier>();
    QMap<QString, KvRecordIdentifier> mapParentRecordIds = QMap<QString, KvRecordIdentifier>();
    QList<KvRecordIdentifier> recordIds = QList<KvRecordIdentifier>();

    QMap<QString, QList<KvTableColumn> > mapTablesIdColumns = QMap<QString, QList<KvTableColumn> >();
    QMap<QString, QList<KvTableDependency> > mapTablesDependencies = QMap<QString, QList<KvTableDependency> >();
    QMap<QString, QList<KvTableDependency> > mapTablesParentDependencies = QMap<QString, QList<KvTableDependency> >();

    int fromIndex = sqlStatement.toUpper().indexOf("FROM");
    int whereIndex = sqlStatement.toUpper().indexOf("WHERE");

    statementsByFrom = sqlStatement.left(fromIndex - 1);
    if (whereIndex != -1)
        statementsByWhere = sqlStatement.right(sqlStatement.length() - (whereIndex + 6));
    fullTableName = sqlStatement.toUpper().mid(fromIndex+4, whereIndex-(fromIndex+4)).trimmed();
    if (fullTableName.contains(".")) {
        schemaName = fullTableName.split(".").at(0);
        tableName = fullTableName.split(".").at(1);
    }
    else {
        schemaName = QString();
        tableName = fullTableName;
    }

    QString operation = statementsByFrom.split(" ").at(0).toUpper();

    getChildRecords(schemaName, tableName, statementsByWhere, &mapChildRecordIds, &mapTablesIdColumns, &mapTablesDependencies);

    // Maybe this can be removed, it only enables the parent search to start from initial "where clause"
    getParentRecords(schemaName, tableName, statementsByWhere, &mapParentRecordIds, &mapTablesIdColumns, &mapTablesParentDependencies);

    // For each identified record, find all of its parent records
    foreach(QString recordString, mapChildRecordIds.keys()) {
        KvRecordIdentifier recordId = mapChildRecordIds.value(recordString);
        getParentRecords(recordId.recordSchema, recordId.recordTable, recordId.recordKeyClause, &mapParentRecordIds, &mapTablesIdColumns, &mapTablesParentDependencies);
    }

    foreach(QString recordIdString, mapParentRecordIds.keys()) {
        if (!mapChildRecordIds.contains(recordIdString))
            mapChildRecordIds.insert(recordIdString, mapParentRecordIds.value(recordIdString));
    }

    for(int i=0; i<mapChildRecordIds.count(); i++)
        recordIds << mapChildRecordIds.values().at(i);

    // Sort record Ids according to dependency order

    return recordIds;
}


QStringList KvSqlSessionOracle::getDependentSql(QString sqlStatement)
{
    QStringList result = QStringList();
    QString statementsByFrom = QString();
    QString statementsByWhere = QString();
    QString fullTableName, tableName, schemaName;

    QMap<QString, KvRecordIdentifier> mapRecordIds = QMap<QString, KvRecordIdentifier>();
    QList<KvRecordIdentifier> recordIds = QList<KvRecordIdentifier>();

    QMap<QString, QList<KvTableColumn> > mapTablesIdColumns = QMap<QString, QList<KvTableColumn> >();
    QMap<QString, QList<KvTableDependency> > mapTablesDependencies = QMap<QString, QList<KvTableDependency> >();

    int fromIndex = sqlStatement.toUpper().indexOf("FROM");
    int whereIndex = sqlStatement.toUpper().indexOf("WHERE");

    statementsByFrom = sqlStatement.left(fromIndex - 1);
    if (whereIndex != -1)
        statementsByWhere = sqlStatement.right(sqlStatement.length() - (whereIndex + 6));
    fullTableName = sqlStatement.toUpper().mid(fromIndex+4, whereIndex-(fromIndex+4)).trimmed();
    if (fullTableName.contains(".")) {
        schemaName = fullTableName.split(".").at(0);
        tableName = fullTableName.split(".").at(1);
    }
    else {
        schemaName = QString();
        tableName = fullTableName;
    }

    QString operation = statementsByFrom.split(" ").at(0).toUpper();

    //    qDebug() << "fullTableName" << fullTableName;
    //    qDebug() << "schemaName" << schemaName;
    //    qDebug() << "tableName" << tableName;
    //    qDebug() << "statementsByWhere" << statementsByWhere;
    //    qDebug() << "operation" << operation;

    if (operation.compare("DELETE") == 0) {

        getChildRecords(schemaName, tableName, statementsByWhere, &mapRecordIds, &mapTablesIdColumns, &mapTablesDependencies);

        for(int i=0; i<mapRecordIds.count(); i++)
            recordIds << mapRecordIds.values().at(i);

        // Sort record Ids according to dependency order

        for(int i=0; i<recordIds.count(); i++) {
            QString statement = QString("DELETE FROM ")+
                    recordIds.at(i).recordSchema+"."+recordIds.at(i).recordTable+" WHERE "+recordIds.at(i).recordKeyClause+";";
            result << statement;
        }
    }

    return result;
}

void KvSqlSessionOracle::getChildRecords(QString schema, QString table, QString recordClause,
                                         QMap<QString, KvRecordIdentifier> *mapRecordIds,
                                         QMap<QString, QList<KvTableColumn> > *mapTablesIdColumns,
                                         QMap<QString, QList<KvTableDependency> > *mapTablesDependencies)
{
    QList<KvRecordIdentifier> newRecords = QList<KvRecordIdentifier>();
    QList<KvRecordIdentifier> newRecordsFormated = QList<KvRecordIdentifier>();

    QString schemaClause = QString();

    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    if (schema.isEmpty()) {
        QString schemaByPublicSynonym = QString();
        QString schemaByPrivateSynonym = QString();
        QString schemaSelfUser = QString();
        QString sqlSchemaStatement;

        sqlSchemaStatement = QString("SELECT OWNER FROM ")+adminViewPrefix+"_OBJECTS WHERE OBJECT_TYPE = 'TABLE' AND OBJECT_NAME = '"+table+"' AND OWNER = '"+sessionDatabase.userName().toUpper()+"'";
        QSqlQuery schemaQuery(sqlSchemaStatement, sessionDatabase);
        while (schemaQuery.next()) {
            schemaSelfUser = schemaQuery.value(0).toString();
        }
        //        qDebug() << sqlSchemaStatement;
        //        qDebug() << schemaSelfUser;

        if (schemaSelfUser.isEmpty()) {
            sqlSchemaStatement = QString("SELECT TABLE_OWNER FROM ")+adminViewPrefix+"_SYNONYMS WHERE TABLE_NAME = '"+table+"' AND OWNER = '"+sessionDatabase.userName().toUpper()+"'";
            QSqlQuery schemaQuery(sqlSchemaStatement, sessionDatabase);
            while (schemaQuery.next()) {
                schemaByPrivateSynonym = schemaQuery.value(0).toString();
            }
            //            qDebug() << sqlSchemaStatement;
            //            qDebug() << schemaByPrivateSynonym;

            if (schemaByPrivateSynonym.isEmpty()) {

                sqlSchemaStatement = QString("SELECT TABLE_OWNER FROM ")+adminViewPrefix+"_SYNONYMS WHERE TABLE_NAME = '"+table+"' AND OWNER = 'PUBLIC'";
                QSqlQuery schemaQuery(sqlSchemaStatement, sessionDatabase);
                while (schemaQuery.next()) {
                    schemaByPublicSynonym = schemaQuery.value(0).toString();
                }
                //                qDebug() << sqlSchemaStatement;
                //                qDebug() << schemaByPublicSynonym;
                if (!schemaByPublicSynonym.isEmpty())
                    schemaClause = schemaByPublicSynonym;
            }
            else
                schemaClause = schemaByPrivateSynonym;
        }
        else
            schemaClause = schemaSelfUser;
    }
    else
        schemaClause = schema.toUpper();

    QList<KvTableColumn> parentTableColumns;
    if (mapTablesIdColumns->contains(schemaClause+"."+table))
        parentTableColumns = mapTablesIdColumns->value(schemaClause+"."+table);
    else {
        parentTableColumns = getTableIdentityColumns(schemaClause, table);
        mapTablesIdColumns->insert(schemaClause+"."+table, parentTableColumns);
    }
    QStringList parentTableIdentityColumns = QStringList();
    for(int cc=0; cc<parentTableColumns.count(); cc++)
        parentTableIdentityColumns << parentTableColumns.at(cc).columnName;

    QString parentTableIdentityColumnClause = parentTableIdentityColumns.join(",");


    // Identify the first records to start the depth search...
    QString parentSqlStatement;
    if (!recordClause.isEmpty())
        parentSqlStatement = "SELECT "+parentTableIdentityColumnClause+" FROM "+schemaClause+"."+table+" WHERE "+recordClause;
    else
        parentSqlStatement = "SELECT "+parentTableIdentityColumnClause+" FROM "+schemaClause+"."+table;

    //    qDebug() << parentSqlStatement;
    // Identify all records from schema.table where recordClause is true
    QSqlQuery parentQuery(parentSqlStatement, sessionDatabase);
    //QString parentRecordSql = "SELECT "+parentTableIdentityColumnClause+" FROM "+schemaClause+table+" WHERE ";
    QString whereClause, whereClauseFormated;

    QList<KvTableDependency> dependencies = QList<KvTableDependency>();

    if (mapTablesDependencies->contains(schemaClause+"."+table))
        dependencies = mapTablesDependencies->value(schemaClause+"."+table);
    else {
        dependencies = getTableChildRelationships(schemaClause, table);
        mapTablesDependencies->insert(schemaClause+"."+table, dependencies);
    }

    while (parentQuery.next()) {

        KvRecordIdentifier recordId, recordIdFormated;
        whereClause = QString();
        whereClauseFormated = QString();

        for(int f=0; f<parentTableIdentityColumns.count(); f++) {
            QString fieldName = parentTableIdentityColumns.at(f);
            QString value;

            if (parentQuery.value(parentTableIdentityColumns.indexOf(fieldName)).toString().isEmpty()) {
                // Only Valid to Unique Key Column Null Values
                value = "NULL";

                if (whereClause.isEmpty()) {
                    whereClause = fieldName + " IS NULL";
                    whereClauseFormated = "B."+fieldName + " IS NULL";
                }
                else {
                    whereClause = whereClause + " AND " + fieldName + " IS NULL";
                    whereClauseFormated = whereClauseFormated + " AND B." + fieldName + " IS NULL";
                }
            }
            else {
                if ((parentTableColumns.at(f).columnType == "CHAR") ||
                        (parentTableColumns.at(f).columnType == "VARCHAR2") ||
                        (parentTableColumns.at(f).columnType == "NVARCHAR2") ||
                        (parentTableColumns.at(f).columnType == "ROWID"))
                    value = "'"+parentQuery.value(parentTableIdentityColumns.indexOf(fieldName)).toString().replace("'","''")+"'";
                else if (parentTableColumns.at(f).columnType == "DATE")
                    value = "TO_DATE('"+parentQuery.value(parentTableIdentityColumns.indexOf(fieldName)).toDateTime().toString("yyyy-MM-dd hh:mm:ss")+"','YYYY-MM-DD HH24:MI:SS')";
                else if ((parentTableColumns.at(f).columnType == "NUMBER") ||
                         (parentTableColumns.at(f).columnType == "INTEGER")
                         )
                    value = parentQuery.value(parentTableIdentityColumns.indexOf(fieldName)).toString();

                if (whereClause.isEmpty()) {
                    whereClause = fieldName + " = " + value;
                    whereClauseFormated = "B."+fieldName + " = " + value;
                }
                else {
                    whereClause = whereClause + " AND " + fieldName + " = " + value;
                    whereClauseFormated = whereClauseFormated + " AND B." + fieldName + " = " + value;
                }
            }
        }

        recordId.recordSchema = schemaClause;
        recordId.recordTable = table;
        recordId.recordKeyClause = whereClause;

        recordIdFormated.recordSchema = schemaClause;
        recordIdFormated.recordTable = table;
        recordIdFormated.recordKeyClause = whereClauseFormated;

        if (! mapRecordIds->contains(recordId.recordSchema+"."+recordId.recordTable+"."+recordId.recordKeyClause)) {
            newRecords << recordId;
            newRecordsFormated << recordIdFormated;
            mapRecordIds->insert(recordId.recordSchema+"."+recordId.recordTable+"."+recordId.recordKeyClause, recordId);
        }
    }

    //    for(int r=0; r<newRecords.count(); r++)
    //        qDebug() << newRecords.at(r).recordSchema + "." + newRecords.at(r).recordTable + "." + newRecords.at(r).recordKeyClause;

    // Join each dependent table
    for(int d=0; d<dependencies.count(); d++) {
        KvTableDependency dependency = dependencies.at(d);

        QList<KvTableColumn> childTableColumns;
        if (mapTablesIdColumns->contains(dependency.childSchema+"."+dependency.childTable))
            childTableColumns = mapTablesIdColumns->value(dependency.childSchema+"."+dependency.childTable);
        else {
            childTableColumns = getTableIdentityColumns(dependency.childSchema, dependency.childTable);
            mapTablesIdColumns->insert(dependency.childSchema+"."+dependency.childTable, childTableColumns);
        }
        QStringList childColumns = QStringList();
        for(int cc=0; cc<childTableColumns.count(); cc++)
            childColumns << childTableColumns.at(cc).columnName;

        QStringList childKeyColumns = childColumns;
        for(int c=0; c<childColumns.count(); c++)
            childColumns.replace(c, QString("A.")+childColumns.at(c));

        QString joinClause = QString();
        for(int jc=0; jc<dependency.columnsPair.count(); jc++) {
            if (joinClause.isEmpty())
                joinClause = "B."+dependency.columnsPair.at(jc).first+" = A."+dependency.columnsPair.at(jc).second;
            else
                joinClause = joinClause + " AND B."+dependency.columnsPair.at(jc).first+" = A."+dependency.columnsPair.at(jc).second;
        }

        QString joinStatement = QString("SELECT ")+
                childColumns.join(",")+" FROM "+
                dependency.childSchema+"."+dependency.childTable+" A, "+
                dependency.parentSchema+"."+dependency.parentTable+" B WHERE "+joinClause+" AND ";

        for(int i=0; i<newRecords.count(); i++) {
            QString parentKeysClause = newRecordsFormated.at(i).recordKeyClause;

            QSqlQuery joinQuery(joinStatement+parentKeysClause, sessionDatabase);
            //            qDebug() << joinStatement+parentKeysClause;
            while (joinQuery.next()) {
                QString childKeyClause = QString();
                for(int k = 0; k<childKeyColumns.count(); k++) {
                    QString value;

                    if (joinQuery.value(k).toString().isEmpty()) {
                        // Only Valid to Unique Key Column Null Values
                        value = "NULL";

                        if (childKeyClause.isEmpty())
                            childKeyClause = childKeyColumns.at(k) + " IS NULL";
                        else
                            childKeyClause = childKeyClause + " AND " + childKeyColumns.at(k) + " IS NULL";
                    }
                    else {
                        if ((childTableColumns.at(k).columnType == "CHAR") ||
                                (childTableColumns.at(k).columnType == "VARCHAR2") ||
                                (childTableColumns.at(k).columnType == "NVARCHAR2") ||
                                (childTableColumns.at(k).columnType == "ROWID"))
                            value = "'"+joinQuery.value(k).toString().replace("'","''")+"'";
                        else if (childTableColumns.at(k).columnType == "DATE")
                            value = "TO_DATE('"+joinQuery.value(k).toDateTime().toString("yyyy-MM-dd hh:mm:ss")+"','YYYY-MM-DD HH24:MI:SS')";
                        else if ((childTableColumns.at(k).columnType == "NUMBER") ||
                                 (childTableColumns.at(k).columnType == "INTEGER")
                                 )
                            value = joinQuery.value(k).toString();

                        if (childKeyClause.isEmpty())
                            childKeyClause = childKeyColumns.at(k) + " = " + value;
                        else
                            childKeyClause = childKeyClause + " AND " + childKeyColumns.at(k) + " = " + value;
                    }
                }

                getChildRecords(dependency.childSchema, dependency.childTable, childKeyClause, mapRecordIds, mapTablesIdColumns, mapTablesDependencies);
            }
        }
    }
}


void KvSqlSessionOracle::getParentRecords(QString schema, QString table, QString recordClause,
                                          QMap<QString, KvRecordIdentifier> *mapRecordIds,
                                          QMap<QString, QList<KvTableColumn> > *mapTablesIdColumns,
                                          QMap<QString, QList<KvTableDependency> > *mapTablesDependencies)
{
    QList<KvRecordIdentifier> newRecords = QList<KvRecordIdentifier>();
    QList<KvRecordIdentifier> newRecordsFormated = QList<KvRecordIdentifier>();

    QString schemaClause = QString();

    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    if (schema.isEmpty()) {
        QString schemaByPublicSynonym = QString();
        QString schemaByPrivateSynonym = QString();
        QString schemaSelfUser = QString();
        QString sqlSchemaStatement;

        sqlSchemaStatement = QString("SELECT OWNER FROM ")+adminViewPrefix+"_OBJECTS WHERE OBJECT_TYPE = 'TABLE' AND OBJECT_NAME = '"+table+"' AND OWNER = '"+sessionDatabase.userName().toUpper()+"'";
        QSqlQuery schemaQuery(sqlSchemaStatement, sessionDatabase);
        while (schemaQuery.next()) {
            schemaSelfUser = schemaQuery.value(0).toString();
        }
        //        qDebug() << sqlSchemaStatement;
        //        qDebug() << schemaSelfUser;

        if (schemaSelfUser.isEmpty()) {
            sqlSchemaStatement = QString("SELECT TABLE_OWNER FROM ")+adminViewPrefix+"_SYNONYMS WHERE TABLE_NAME = '"+table+"' AND OWNER = '"+sessionDatabase.userName().toUpper()+"'";
            QSqlQuery schemaQuery(sqlSchemaStatement, sessionDatabase);
            while (schemaQuery.next()) {
                schemaByPrivateSynonym = schemaQuery.value(0).toString();
            }
            //            qDebug() << sqlSchemaStatement;
            //            qDebug() << schemaByPrivateSynonym;

            if (schemaByPrivateSynonym.isEmpty()) {

                sqlSchemaStatement = QString("SELECT TABLE_OWNER FROM ")+adminViewPrefix+"_SYNONYMS WHERE TABLE_NAME = '"+table+"' AND OWNER = 'PUBLIC'";
                QSqlQuery schemaQuery(sqlSchemaStatement, sessionDatabase);
                while (schemaQuery.next()) {
                    schemaByPublicSynonym = schemaQuery.value(0).toString();
                }
                //                qDebug() << sqlSchemaStatement;
                //                qDebug() << schemaByPublicSynonym;
                if (!schemaByPublicSynonym.isEmpty())
                    schemaClause = schemaByPublicSynonym;
            }
            else
                schemaClause = schemaByPrivateSynonym;
        }
        else
            schemaClause = schemaSelfUser;
    }
    else
        schemaClause = schema.toUpper();

    QList<KvTableColumn> childTableColumns;
    if (mapTablesIdColumns->contains(schemaClause+"."+table))
        childTableColumns = mapTablesIdColumns->value(schemaClause+"."+table);
    else {
        childTableColumns = getTableIdentityColumns(schemaClause, table);
        mapTablesIdColumns->insert(schemaClause+"."+table, childTableColumns);
    }
    QStringList childTableIdentityColumns = QStringList();
    for(int cc=0; cc<childTableColumns.count(); cc++)
        childTableIdentityColumns << childTableColumns.at(cc).columnName;

    QString childTableIdentityColumnClause = childTableIdentityColumns.join(",");


    // Identify the first records to start the depth search...
    QString childSqlStatement;
    if (!recordClause.isEmpty())
        childSqlStatement = "SELECT "+childTableIdentityColumnClause+" FROM "+schemaClause+"."+table+" WHERE "+recordClause;
    else
        childSqlStatement = "SELECT "+childTableIdentityColumnClause+" FROM "+schemaClause+"."+table;

    // qDebug() << childSqlStatement;
    // Identify all records from schema.table where recordClause is true
    QSqlQuery childQuery(childSqlStatement, sessionDatabase);
    //QString parentRecordSql = "SELECT "+parentTableIdentityColumnClause+" FROM "+schemaClause+table+" WHERE ";
    QString whereClause, whereClauseFormated;

    QList<KvTableDependency> dependencies = QList<KvTableDependency>();

    if (mapTablesDependencies->contains(schemaClause+"."+table))
        dependencies = mapTablesDependencies->value(schemaClause+"."+table);
    else {
        dependencies = getTableParentRelationships(schemaClause, table);
        mapTablesDependencies->insert(schemaClause+"."+table, dependencies);
    }

    for(int d=0; d<dependencies.count(); d++) {
        //        qDebug() << "PARENT" << dependencies.at(d).parentSchema << dependencies.at(d).parentTable;
        //        qDebug() << "CHILD" << dependencies.at(d).childSchema << dependencies.at(d).childTable;
    }

    while (childQuery.next()) {

        KvRecordIdentifier recordId, recordIdFormated;
        whereClause = QString();
        whereClauseFormated = QString();

        for(int f=0; f<childTableIdentityColumns.count(); f++) {
            QString fieldName = childTableIdentityColumns.at(f);
            QString value;

            if (childQuery.value(childTableIdentityColumns.indexOf(fieldName)).toString().isEmpty()) {
                // Only Valid to Unique Key Column Null Values
                value = "NULL";

                if (whereClause.isEmpty()) {
                    whereClause = fieldName + " IS NULL";
                    whereClauseFormated = "B."+fieldName + " IS NULL";
                }
                else {
                    whereClause = whereClause + " AND " + fieldName + " IS NULL";
                    whereClauseFormated = whereClauseFormated + " AND B." + fieldName + " IS NULL";
                }
            }
            else {
                if ((childTableColumns.at(f).columnType == "CHAR") ||
                        (childTableColumns.at(f).columnType == "VARCHAR2") ||
                        (childTableColumns.at(f).columnType == "NVARCHAR2") ||
                        (childTableColumns.at(f).columnType == "ROWID"))
                    value = "'"+childQuery.value(childTableIdentityColumns.indexOf(fieldName)).toString().replace("'","''")+"'";
                else if (childTableColumns.at(f).columnType == "DATE")
                    value = "TO_DATE('"+childQuery.value(childTableIdentityColumns.indexOf(fieldName)).toDateTime().toString("yyyy-MM-dd hh:mm:ss")+"','YYYY-MM-DD HH24:MI:SS')";
                else if ((childTableColumns.at(f).columnType == "NUMBER") ||
                         (childTableColumns.at(f).columnType == "INTEGER")
                         )
                    value = childQuery.value(childTableIdentityColumns.indexOf(fieldName)).toString();

                if (whereClause.isEmpty()) {
                    whereClause = fieldName + " = " + value;
                    whereClauseFormated = "B."+fieldName + " = " + value;
                }
                else {
                    whereClause = whereClause + " AND " + fieldName + " = " + value;
                    whereClauseFormated = whereClauseFormated + " AND B." + fieldName + " = " + value;
                }
            }
        }

        recordId.recordSchema = schemaClause;
        recordId.recordTable = table;
        recordId.recordKeyClause = whereClause;

        recordIdFormated.recordSchema = schemaClause;
        recordIdFormated.recordTable = table;
        recordIdFormated.recordKeyClause = whereClauseFormated;

        if (! mapRecordIds->contains(recordId.recordSchema+"."+recordId.recordTable+"."+recordId.recordKeyClause)) {
            newRecords << recordId;
            newRecordsFormated << recordIdFormated;
            mapRecordIds->insert(recordId.recordSchema+"."+recordId.recordTable+"."+recordId.recordKeyClause, recordId);
        }
    }

    //    for(int r=0; r<newRecords.count(); r++)
    //        qDebug() << newRecords.at(r).recordSchema + "." + newRecords.at(r).recordTable + "." + newRecords.at(r).recordKeyClause;

    // Join each dependent table
    for(int d=0; d<dependencies.count(); d++) {
        KvTableDependency dependency = dependencies.at(d);

        QList<KvTableColumn> parentTableColumns;
        if (mapTablesIdColumns->contains(dependency.parentSchema+"."+dependency.parentTable))
            parentTableColumns = mapTablesIdColumns->value(dependency.parentSchema+"."+dependency.parentTable);
        else {
            parentTableColumns = getTableIdentityColumns(dependency.parentSchema, dependency.parentTable);
            mapTablesIdColumns->insert(dependency.parentSchema+"."+dependency.parentTable, parentTableColumns);
        }
        QStringList parentColumns = QStringList();
        for(int cc=0; cc<parentTableColumns.count(); cc++)
            parentColumns << parentTableColumns.at(cc).columnName;

        // qDebug() << parentColumns;

        QStringList parentKeyColumns = parentColumns;
        for(int c=0; c<parentColumns.count(); c++)
            parentColumns.replace(c, QString("A.")+parentColumns.at(c));

        QString joinClause = QString();
        for(int jc=0; jc<dependency.columnsPair.count(); jc++) {
            if (joinClause.isEmpty())
                joinClause = "A."+dependency.columnsPair.at(jc).first+" = B."+dependency.columnsPair.at(jc).second;
            else
                joinClause = joinClause + " AND A."+dependency.columnsPair.at(jc).first+" = B."+dependency.columnsPair.at(jc).second;
        }

        QString joinStatement = QString("SELECT ")+
                parentColumns.join(",")+" FROM "+
                dependency.parentSchema+"."+dependency.parentTable+" A, "+
                dependency.childSchema+"."+dependency.childTable+" B WHERE "+joinClause+" AND ";

        for(int i=0; i<newRecords.count(); i++) {
            QString childKeysClause = newRecordsFormated.at(i).recordKeyClause;

            QSqlQuery joinQuery(joinStatement+childKeysClause, sessionDatabase);
            qDebug() << joinStatement+childKeysClause;
            while (joinQuery.next()) {
                QString parentKeyClause = QString();
                for(int k = 0; k<parentKeyColumns.count(); k++) {
                    QString value;

                    if (joinQuery.value(k).toString().isEmpty()) {
                        // Only Valid to Unique Key Column Null Values
                        value = "NULL";

                        if (parentKeyClause.isEmpty())
                            parentKeyClause = parentKeyColumns.at(k) + " IS NULL";
                        else
                            parentKeyClause = parentKeyClause + " AND " + parentKeyColumns.at(k) + " IS NULL";
                    }
                    else {
                        if ((parentTableColumns.at(k).columnType == "CHAR") ||
                                (parentTableColumns.at(k).columnType == "VARCHAR2") ||
                                (parentTableColumns.at(k).columnType == "NVARCHAR2") ||
                                (parentTableColumns.at(k).columnType == "ROWID"))
                            value = "'"+joinQuery.value(k).toString().replace("'","''")+"'";
                        else if (parentTableColumns.at(k).columnType == "DATE")
                            value = "TO_DATE('"+joinQuery.value(k).toDateTime().toString("yyyy-MM-dd hh:mm:ss")+"','YYYY-MM-DD HH24:MI:SS')";
                        else if ((parentTableColumns.at(k).columnType == "NUMBER") ||
                                 (parentTableColumns.at(k).columnType == "INTEGER")
                                 )
                            value = joinQuery.value(k).toString();

                        if (parentKeyClause.isEmpty())
                            parentKeyClause = parentKeyColumns.at(k) + " = " + value;
                        else
                            parentKeyClause = parentKeyClause + " AND " + parentKeyColumns.at(k) + " = " + value;
                    }
                }

                getParentRecords(dependency.parentSchema, dependency.parentTable, parentKeyClause, mapRecordIds, mapTablesIdColumns, mapTablesDependencies);
            }
        }
    }
}


QList<KvTableDependency> KvSqlSessionOracle::getTableChildRelationships(QString schema, QString table)
{
    QList<KvTableDependency> result = QList<KvTableDependency>();

    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QString constraintStatement = QString("SELECT ")+
            "C1.OWNER PARENT_SCHEMA, C1.TABLE_NAME PARENT_TABLE, C1.CONSTRAINT_NAME PARENT_CONSTRAINT, "+
            "C2.OWNER CHILD_SCHEMA, C2.TABLE_NAME CHILD_TABLE, C2.CONSTRAINT_NAME CHILD_CONSTRAINT "+
            "FROM "+adminViewPrefix+"_CONSTRAINTS C1, "+adminViewPrefix+"_CONSTRAINTS C2 "+
            "WHERE C1.OWNER = C2.R_OWNER AND C1.CONSTRAINT_NAME = C2.R_CONSTRAINT_NAME AND C1.CONSTRAINT_TYPE = 'P' AND "+
            "C1.OWNER = '"+schema+"' AND C1.TABLE_NAME = '"+table+"' "+
            "ORDER BY C2.OWNER, C2.TABLE_NAME, C2.CONSTRAINT_NAME";

    QSqlQuery consQuery(constraintStatement, sessionDatabase);

    while (consQuery.next()) {

        KvTableDependency tabDep;

        tabDep.parentSchema = consQuery.value(0).toString();
        tabDep.parentTable = consQuery.value(1).toString();
        tabDep.childSchema = consQuery.value(3).toString();
        tabDep.childTable = consQuery.value(4).toString();
        tabDep.constraintName = consQuery.value(5).toString();

        //        qDebug() << tabDep.constraintName;

        QString dependencyStatement = QString("SELECT ")+
                "CC1.COLUMN_NAME PARENT_COLUMN, "+
                "CC2.COLUMN_NAME CHILD_COLUMN, TC2.NULLABLE "+
                "FROM "+adminViewPrefix+"_CONS_COLUMNS CC1, "+adminViewPrefix+"_CONS_COLUMNS CC2, "+adminViewPrefix+"_TAB_COLUMNS TC2 "+
                "WHERE "+
                "CC1.OWNER = '"+consQuery.value(0).toString()+"' AND CC1.TABLE_NAME = '"+consQuery.value(1).toString()+"' AND "+
                "CC1.CONSTRAINT_NAME = '"+consQuery.value(2).toString()+"' AND "+
                "CC2.OWNER = '"+consQuery.value(3).toString()+"' AND CC2.TABLE_NAME = '"+consQuery.value(4).toString()+"' AND "+
                "CC2.CONSTRAINT_NAME = '"+consQuery.value(5).toString()+"' AND "+
                "CC1.POSITION = CC2.POSITION AND "+
                "CC2.OWNER = TC2.OWNER AND CC2.TABLE_NAME = TC2.TABLE_NAME AND CC2.COLUMN_NAME = TC2.COLUMN_NAME "+
                "ORDER BY CC2.OWNER, CC2.TABLE_NAME, CC2.CONSTRAINT_NAME, CC2.POSITION";

        QSqlQuery depQuery(dependencyStatement, sessionDatabase);
        while (depQuery.next()) {
            QPair<QString, QString> columnPair = QPair<QString, QString>();
            columnPair.first = depQuery.value(0).toString();
            columnPair.second = depQuery.value(1).toString();
            tabDep.columnsPair << columnPair;

            if (depQuery.value(2).toString().at(0) == 'Y')
                tabDep.optional = true;
            else
                tabDep.optional = false;
        }
        result << tabDep;
    }

    return result;
}

QList<KvTableDependency> KvSqlSessionOracle::getTableParentRelationships(QString schema, QString table)
{
    QList<KvTableDependency> result = QList<KvTableDependency>();

    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QString constraintStatement = QString("SELECT ")+
            "C1.OWNER PARENT_SCHEMA, C1.TABLE_NAME PARENT_TABLE, C1.CONSTRAINT_NAME PARENT_CONSTRAINT, "+
            "C2.OWNER CHILD_SCHEMA, C2.TABLE_NAME CHILD_TABLE, C2.CONSTRAINT_NAME CHILD_CONSTRAINT "+
            "FROM "+adminViewPrefix+"_CONSTRAINTS C1, "+adminViewPrefix+"_CONSTRAINTS C2 "+
            "WHERE C1.OWNER = C2.R_OWNER AND C1.CONSTRAINT_NAME = C2.R_CONSTRAINT_NAME AND C1.CONSTRAINT_TYPE = 'P' AND "+
            "C2.OWNER = '"+schema+"' AND C2.TABLE_NAME = '"+table+"' "+
            "ORDER BY C2.OWNER, C2.TABLE_NAME, C2.CONSTRAINT_NAME";

    QSqlQuery consQuery(constraintStatement, sessionDatabase);

    while (consQuery.next()) {

        KvTableDependency tabDep;

        tabDep.parentSchema = consQuery.value(0).toString();
        tabDep.parentTable = consQuery.value(1).toString();
        tabDep.childSchema = consQuery.value(3).toString();
        tabDep.childTable = consQuery.value(4).toString();
        tabDep.constraintName = consQuery.value(5).toString();

        //        qDebug() << tabDep.parentSchema;
        //        qDebug() << tabDep.parentTable;
        //        qDebug() << tabDep.childSchema;
        //        qDebug() << tabDep.childTable;
        //        qDebug() << tabDep.constraintName;

        QString dependencyStatement = QString("SELECT ")+
                "CC1.COLUMN_NAME PARENT_COLUMN, "+
                "CC2.COLUMN_NAME CHILD_COLUMN, TC2.NULLABLE "+
                "FROM "+adminViewPrefix+"_CONS_COLUMNS CC1, "+adminViewPrefix+"_CONS_COLUMNS CC2, "+adminViewPrefix+"_TAB_COLUMNS TC2 "+
                "WHERE "+
                "CC1.OWNER = '"+consQuery.value(0).toString()+"' AND CC1.TABLE_NAME = '"+consQuery.value(1).toString()+"' AND "+
                "CC1.CONSTRAINT_NAME = '"+consQuery.value(2).toString()+"' AND "+
                "CC2.OWNER = '"+consQuery.value(3).toString()+"' AND CC2.TABLE_NAME = '"+consQuery.value(4).toString()+"' AND "+
                "CC2.CONSTRAINT_NAME = '"+consQuery.value(5).toString()+"' AND "+
                "CC1.POSITION = CC2.POSITION AND "+
                "CC2.OWNER = TC2.OWNER AND CC2.TABLE_NAME = TC2.TABLE_NAME AND CC2.COLUMN_NAME = TC2.COLUMN_NAME "+
                "ORDER BY CC2.OWNER, CC2.TABLE_NAME, CC2.CONSTRAINT_NAME, CC2.POSITION";

        QSqlQuery depQuery(dependencyStatement, sessionDatabase);
        while (depQuery.next()) {
            QPair<QString, QString> columnPair = QPair<QString, QString>();
            columnPair.first = depQuery.value(0).toString();
            columnPair.second = depQuery.value(1).toString();
            tabDep.columnsPair << columnPair;

            if (depQuery.value(2).toString().at(0) == 'Y')
                tabDep.optional = true;
            else
                tabDep.optional = false;
            //            qDebug() << columnPair.first << columnPair.second;
        }
        result << tabDep;
    }

    return result;
}

QList< QPair<QString, QMap<QString,QString> > > KvSqlSessionOracle::getExecPlan(QString sqlStatement, QString StatementId)
{
    QList< QPair<QString, QMap<QString,QString> > > result;
    QString sqlStatementExplain = "DELETE FROM PLAN_TABLE";
    QSqlQuery queryExec(sqlStatementExplain, sessionDatabase);
    queryExec.exec();
    sqlStatementExplain = "EXPLAIN PLAN FOR "+sqlStatement.remove(";");
    queryExec.exec(sqlStatementExplain);

    QString sqlStatementPlan = "SELECT * FROM PLAN_TABLE ORDER BY NVL(PARENT_ID,-1)";
    QSqlQuery query(sqlStatementPlan, sessionDatabase);
    while (query.next()) {
        // Each plan line has a map of column names and their values
        QMap<QString,QString> pMap;
        QPair<QString, QMap<QString,QString> > pair;
        for(int i=0; i<query.record().count(); i++)
            pMap.insert(query.record().fieldName(i), query.value(i).toString());
        pair.first = query.value(15).toString();
        pair.second = pMap;
        result << pair;
    }
    return result;
}

QString KvSqlSessionOracle::findObjectStatement(QString fullObjectName, QString typeName)
{
    QString sqlStatement = QString();
    QString schema = QString();
    QString objectName = QString();

    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    if (fullObjectName.indexOf(".") > 0) {
        QStringList fullObjectNameParts = fullObjectName.split(".");
        schema = fullObjectNameParts.at(0);
        objectName = fullObjectNameParts.at(1);
    }
    else {
        objectName = fullObjectName;
    }
    schema = schema.replace("*","%");
    objectName = objectName.replace("*","%");

    if (schema.isEmpty()) {
        if (typeName.isEmpty()) {
            sqlStatement = "SELECT OWNER, OBJECT_NAME, OBJECT_TYPE FROM "+adminViewPrefix+"_OBJECTS WHERE "+
                    "OBJECT_NAME LIKE '"+objectName+"' OR OBJECT_NAME LIKE UPPER('"+objectName+"') "+
                    "ORDER BY OWNER, OBJECT_TYPE, OBJECT_NAME";
        }
        else {
            sqlStatement = "SELECT OWNER, OBJECT_NAME, OBJECT_TYPE FROM "+adminViewPrefix+"_OBJECTS WHERE "+
                    "(OBJECT_NAME LIKE '"+objectName+"' OR OBJECT_NAME LIKE UPPER('"+objectName+"')) AND "+
                    "OBJECT_TYPE = '"+typeName+"' "+
                    "ORDER BY OWNER, OBJECT_TYPE, OBJECT_NAME";
        }
    }
    else {
        if (typeName.isEmpty()) {
            sqlStatement = "SELECT OWNER, OBJECT_NAME, OBJECT_TYPE FROM "+adminViewPrefix+"_OBJECTS WHERE "+
                    "(OWNER LIKE '"+schema+"' AND OBJECT_NAME LIKE '"+objectName+"') OR "+
                    "(OWNER LIKE UPPER('"+schema+"') AND OBJECT_NAME LIKE UPPER('"+objectName+"')) "+
                    "ORDER BY OWNER, OBJECT_TYPE, OBJECT_NAME";
        }
        else {
            sqlStatement = "SELECT OWNER, OBJECT_NAME, OBJECT_TYPE FROM "+adminViewPrefix+"_OBJECTS WHERE "+
                    "((OWNER LIKE '"+schema+"' AND OBJECT_NAME LIKE '"+objectName+"') OR "+
                    "(OWNER LIKE UPPER('"+schema+"') AND OBJECT_NAME LIKE UPPER('"+objectName+"'))) AND "+
                    "OBJECT_TYPE = '"+typeName+"' "+
                    "ORDER BY OWNER, OBJECT_TYPE, OBJECT_NAME";
        }
    }
    return sqlStatement;
}

// Object List: each object named like "Schema"+ "." + "Object Name" + "." + "Object Type"
QMap<QString, QList< QPair<QString, QString> > > KvSqlSessionOracle::getObjectParents(const QStringList objectList)
{
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QMap<QString, QList< QPair<QString, QString> > > result = QMap<QString, QList< QPair<QString, QString> > >();
    foreach(QString obj, objectList) {
        QStringList objParts = obj.split(".");
        QString objSchema = objParts.at(0);
        QString objName = objParts.at(1);
        QString objType = objParts.at(2);

        if (objType == "TABLE") {
            QList< QPair<QString, QString> > objParents = QList< QPair<QString, QString> >();
            QSqlQuery query("SELECT C2.OWNER, C2.TABLE_NAME, 'TABLE', C2.CONSTRAINT_NAME FROM "+
                            adminViewPrefix+"_CONSTRAINTS C2, "+adminViewPrefix+"_CONSTRAINTS C1 "+
                            "WHERE C1.CONSTRAINT_TYPE IN ('P','U') AND C2.CONSTRAINT_TYPE = 'R' AND "+
                            "C2.R_OWNER = C1.OWNER AND C2.R_CONSTRAINT_NAME = C1.CONSTRAINT_NAME AND "+
                            "C1.OWNER = '"+objSchema+"' AND C1.TABLE_NAME = '"+objName+"' "
                            "ORDER BY C2.OWNER, C2.TABLE_NAME", sessionDatabase);
            while (query.next()) {
                QPair<QString, QString> pair = QPair<QString, QString>();
                pair.first = "";
                //result << query.value(0).toString();
            }
        }
        else {


        }

    }
    return result;
}

QStringList KvSqlSessionOracle::getSchemas(bool refreshSchemaList)
{
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    if ((schemas.size() > 0) && (! refreshSchemaList))
        return schemas;
    else {
        QStringList result;
        QSqlQuery query("SELECT USERNAME FROM "+adminViewPrefix+"_USERS ORDER BY USERNAME", sessionDatabase);
        //QSqlQuery query("SELECT DISTINCT OWNER FROM "+adminViewPrefix+"_OBJECTS ORDER BY OWNER", sessionDatabase);
        while (query.next()) {
            result << query.value(0).toString();
        }
        schemas.clear();
        schemas.append(result);
        return result;
    }
}

QStringList KvSqlSessionOracle::getSchemasWithTables()
{
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QStringList result;
    QSqlQuery query("SELECT DISTINCT OWNER FROM "+adminViewPrefix+"_TABLES ORDER BY OWNER", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionOracle::getSchemasWithViews()
{
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QStringList result;
    QSqlQuery query("SELECT DISTINCT OWNER FROM "+adminViewPrefix+"_VIEWS ORDER BY OWNER", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionOracle::getSchemasWithPrograms()
{
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QStringList result;
    QSqlQuery query("SELECT DISTINCT OWNER FROM "+adminViewPrefix+"_OBJECTS WHERE OBJECT_TYPE IN ('PROCEDURE','FUNCTION','TRIGGER','PACKAGE','PACKAGE BODY','TYPE','TYPE BODY') ORDER BY OWNER", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionOracle::getSchemasWithEtc()
{
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QStringList result;
    QSqlQuery query(QString("SELECT DISTINCT OWNER FROM (")+
                    "SELECT OWNER FROM "+adminViewPrefix+"_OBJECTS WHERE OBJECT_TYPE NOT IN ('TABLE','VIEW','PROCEDURE','FUNCTION','TRIGGER','PACKAGE','PACKAGE BODY','TYPE','TYPE BODY') UNION "+
                    "SELECT OWNER FROM "+adminViewPrefix+"_RECYCLEBIN )"+
                    "ORDER BY OWNER", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionOracle::getProgramsTypes()
{
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QStringList result;
    result << "FUNCTION" << "JAVA CLASS" << "JAVA DATA" << "JAVA RESOURCE" << "JAVA SOURCE";
    result << "PACKAGE" << "PACKAGE BODY" << "PROCEDURE" << "PROGRAM" << "TRIGGER" << "TYPE" << "TYPE BODY";
    return result;
}

QStringList KvSqlSessionOracle::getEtcTypes()
{
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QStringList result;
    result << "CLUSTER" << "CONSUMER GROUP" << "CONTEXT" << "DATABASE LINK" << "DIRECTORY" << "EVALUATION CONTEXT";
    result << "INDEX" << "INDEX PARTITION" << "INDEXTYPE";
    result << "JOB" << "JOB CLASS" << "LIBRARY" << "LOB" << "LOB PARTITION" << "MATERIALIZED VIEW" << "OPERATOR";
    result << "QUEUE" << "PUBLIC SYNONYM" << "RECYCLE BIN" << "RESOURCE PLAN" << "ROLE" << "RULE" << "RULE SET" << "SCHEDULE" << "SEQUENCE" << "SYNONYM";
    result << "TABLE PARTITION" << "TABLESPACE" << "UNDEFINED" << "WINDOW" << "WINDOW GROUP" << "XML SCHEMA";

    //result << "CONTEXT" << "DATABASE LINK" << "DIRECTORY" << "INDEX" << "JOB" << "LIBRARY" << "PUBLIC SYNONYM" << "ROLE" << "SEQUENCE" << "SYNONYM";
    return result;
}


QList< QPair< QPair<QString, QString>, QPair<QString, QString> > > KvSqlSessionOracle::getRelationsWithTables(const QList< QPair<QString, QString> > &tables)
{
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QList< QPair< QPair<QString, QString>, QPair<QString, QString> > > result;
    QString querySql =	"SELECT DISTINCT C2.OWNER, C2.TABLE_NAME, C1.OWNER, C1.TABLE_NAME FROM "+adminViewPrefix+"_CONSTRAINTS C1, "+adminViewPrefix+"_CONSTRAINTS C2 WHERE C1.R_CONSTRAINT_NAME = C2.CONSTRAINT_NAME AND C1.R_OWNER = C2.OWNER AND ";
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

QList< QPair<QString, QString> > KvSqlSessionOracle::getParentTables(const QString &schema, const QString &table)
{
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QList< QPair<QString, QString> > result;
    QSqlQuery query("SELECT DISTINCT C2.OWNER, C2.TABLE_NAME FROM "+adminViewPrefix+"_CONSTRAINTS C1, "+adminViewPrefix+"_CONSTRAINTS C2 WHERE C1.OWNER = '"+schema+"' AND C1.TABLE_NAME = '"+table+"' AND "+
                    "C1.R_CONSTRAINT_NAME = C2.CONSTRAINT_NAME AND C1.R_OWNER = C2.OWNER ORDER BY C2.OWNER, C2.TABLE_NAME", sessionDatabase);
    while (query.next()) {
        QPair<QString, QString> parentTable;
        parentTable.first	= query.value(0).toString();
        parentTable.second	= query.value(1).toString();
        result << parentTable;
    }
    return result;
}

QList< QPair<QString, QString> > KvSqlSessionOracle::getChildTables(const QString &schema, const QString &table) {
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QList< QPair<QString, QString> > result;
    QSqlQuery query("SELECT DISTINCT C1.OWNER, C1.TABLE_NAME FROM "+adminViewPrefix+"_CONSTRAINTS C1, "+adminViewPrefix+"_CONSTRAINTS C2 WHERE C2.OWNER = '"+schema+"' AND C2.TABLE_NAME = '"+table+"' AND "+
                    "C1.R_CONSTRAINT_NAME = C2.CONSTRAINT_NAME AND C1.R_OWNER = C2.OWNER ORDER BY C1.OWNER, C1.TABLE_NAME", sessionDatabase);
    while (query.next()) {
        QPair<QString, QString> childTable;
        childTable.first	= query.value(0).toString();
        childTable.second	= query.value(1).toString();
        result << childTable;
    }
    return result;
}

int KvSqlSessionOracle::getColumns(QTableWidget *tableWidget, QString schemaName, QString tableName) {
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QSqlError err;
    QString sqlStatement;

    tableWidget->setRowCount(0);

    sqlStatement = "SELECT COLUMN_NAME, DATA_TYPE, DATA_LENGTH, DATA_PRECISION, DATA_SCALE, NULLABLE, DATA_DEFAULT FROM "+adminViewPrefix+"_TAB_COLUMNS WHERE OWNER = '"+
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

QList<KvColumnInfo> KvSqlSessionOracle::getColumns(QString schemaName, QString tableName)
{
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QList<KvColumnInfo> result = QList<KvColumnInfo>();
    QSqlError err;
    QString sqlStatement;

    sqlStatement = "SELECT TC.COLUMN_NAME, TC.DATA_TYPE, TC.DATA_LENGTH, TC.DATA_PRECISION, TC.DATA_SCALE, TC.NULLABLE, TC.DATA_DEFAULT, CC.COMMENTS FROM "+adminViewPrefix+"_TAB_COLUMNS TC, "+adminViewPrefix+"_COL_COMMENTS CC WHERE TC.OWNER = '"+
            schemaName+"' AND TC.TABLE_NAME = '"+tableName+"' AND TC.OWNER = CC.OWNER AND TC.TABLE_NAME = CC.TABLE_NAME AND TC.COLUMN_NAME = CC.COLUMN_NAME ORDER BY TC.COLUMN_ID";

    QSqlQuery query(sqlStatement, sessionDatabase);
    while (query.next()) {
        KvColumnInfo columnInfo;
        columnInfo.columnName = query.value(0).toString();
        columnInfo.columnType = query.value(1).toString();
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
        if (dataDigits.size() > 0)
            columnInfo.columnSize = "("+dataLength+","+dataDigits+")";
        else
            columnInfo.columnSize = "("+dataLength+")";

        if (query.value(5).toString() == "Y") {
            columnInfo.columnNullable = true;
        }
        else {
            columnInfo.columnNullable = false;
        }

        columnInfo.columnDefault = query.value(6).toString();
        columnInfo.columnComments = query.value(7).toString();
        result << columnInfo;
    }

    return result;
}

QList<KvTableColumn> KvSqlSessionOracle::getTableIdentityColumns(QString schemaName, QString tableName)
{
    QList<KvTableColumn> result = QList<KvTableColumn>();
    QSqlError err;
    QString sqlStatement;
    bool useRowId = false;

    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    sqlStatement = "SELECT CC.COLUMN_NAME, TC.DATA_TYPE FROM "+adminViewPrefix+"_CONSTRAINTS C, "+adminViewPrefix+"_CONS_COLUMNS CC, "+adminViewPrefix+"_TAB_COLUMNS TC WHERE C.OWNER = '"+
            schemaName+"' AND C.TABLE_NAME = '"+tableName+"' AND C.OWNER = CC.OWNER AND C.TABLE_NAME = CC.TABLE_NAME AND C.CONSTRAINT_NAME = CC.CONSTRAINT_NAME AND C.CONSTRAINT_TYPE = 'P' AND "+
            "TC.OWNER = C.OWNER AND TC.TABLE_NAME = CC.TABLE_NAME AND TC.COLUMN_NAME = CC.COLUMN_NAME ORDER BY CC.POSITION";

    QSqlQuery query(sqlStatement, sessionDatabase);
    while (query.next()) {
        KvTableColumn tableColumn;
        tableColumn.columnSchema = schemaName;
        tableColumn.columnTable  = tableName;
        tableColumn.columnName   = query.value(0).toString();
        tableColumn.columnType   = query.value(1).toString();

        if ( (tableColumn.columnType != "CHAR") &&
             (tableColumn.columnType != "VARCHAR2") &&
             (tableColumn.columnType != "NVARCHAR2") &&
             (tableColumn.columnType != "NUMBER") &&
             (tableColumn.columnType != "INTEGER") &&
             (tableColumn.columnType != "DATE")
             )
            useRowId = true;

        result << tableColumn;
    }

    if (result.isEmpty()) {
        sqlStatement = "SELECT CC.COLUMN_NAME, TC.DATA_TYPE FROM "+adminViewPrefix+"_CONSTRAINTS C, "+adminViewPrefix+"_CONS_COLUMNS CC, "+adminViewPrefix+"_TAB_COLUMNS TC WHERE C.OWNER = '"+
                schemaName+"' AND C.TABLE_NAME = '"+tableName+"' AND C.OWNER = CC.OWNER AND C.TABLE_NAME = CC.TABLE_NAME AND C.CONSTRAINT_NAME = CC.CONSTRAINT_NAME AND C.CONSTRAINT_TYPE = 'U' AND "+
                "TC.OWNER = C.OWNER AND TC.TABLE_NAME = CC.TABLE_NAME AND TC.COLUMN_NAME = CC.COLUMN_NAME ORDER BY CC.POSITION";

        QSqlQuery query(sqlStatement, sessionDatabase);
        while (query.next()) {
            KvTableColumn tableColumn;
            tableColumn.columnSchema = schemaName;
            tableColumn.columnTable  = tableName;
            tableColumn.columnName   = query.value(0).toString();
            tableColumn.columnType   = query.value(1).toString();

            if ( (tableColumn.columnType != "CHAR") &&
                 (tableColumn.columnType != "VARCHAR2") &&
                 (tableColumn.columnType != "NVARCHAR2") &&
                 (tableColumn.columnType != "NUMBER") &&
                 (tableColumn.columnType != "INTEGER") &&
                 (tableColumn.columnType != "DATE")
                 )
                useRowId = true;

            result << tableColumn;
        }
    }

    if (result.isEmpty() || useRowId) {
        result.clear();
        KvTableColumn tableColumn;
        tableColumn.columnSchema = schemaName;
        tableColumn.columnTable  = tableName;
        tableColumn.columnName   = "ROWID";
        tableColumn.columnType   = "ROWID";
        result << tableColumn;
    }

    return result;
}

QStringList KvSqlSessionOracle::getTableComments(QString schemaName, QString tableName)
{
    QStringList result;
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    // Table Comments
    QString sqlTableComments = "SELECT COMMENTS FROM "+adminViewPrefix+"_TAB_COMMENTS WHERE OWNER = :C_OWNER AND TABLE_NAME = :C_TABLE";
    QSqlQuery queryComments(sqlTableComments, sessionDatabase);
    queryComments.bindValue(":C_OWNER", schemaName);
    queryComments.bindValue(":C_TABLE", tableName);
    queryComments.exec();
    while (queryComments.next()) {
        if ((! queryComments.value(0).isNull()) && (! queryComments.value(0).toString().trimmed().isEmpty()))
            result << "COMMENT ON TABLE "+schemaName+"."+tableName+" IS '"+queryComments.value(0).toString().replace("'","''")+"';";
    }

    // Columns Comments
    QString sqlColComments = QString("SELECT CM.COLUMN_NAME, CM.COMMENTS ")+
            "FROM "+adminViewPrefix+"_COL_COMMENTS CM, "+adminViewPrefix+"_TAB_COLUMNS C WHERE "
            "CM.COMMENTS IS NOT NULL AND "
            "CM.OWNER = :C_OWNER AND CM.TABLE_NAME = :C_TABLE AND "
            "CM.OWNER = C.OWNER AND CM.TABLE_NAME = C.TABLE_NAME AND "
            "CM.COLUMN_NAME = C.COLUMN_NAME "
            "ORDER BY C.COLUMN_ID";
    QSqlQuery queryColComments(sqlColComments, sessionDatabase);
    queryColComments.bindValue(":C_OWNER", schemaName);
    queryColComments.bindValue(":C_TABLE", tableName);
    queryColComments.exec();
    while (queryColComments.next()) {
        if ((! queryColComments.value(1).isNull()) && (! queryColComments.value(1).toString().trimmed().isEmpty()))
            result << "COMMENT ON COLUMN "+schemaName+"."+tableName+"."+queryColComments.value(0).toString()+
                      " IS '"+queryColComments.value(1).toString().replace("'","''")+"';";
    }
    if (result.count() > 0)
        result.insert(0, "-- "+tr("COMMENT(S)"));
    return result;
}

QString KvSqlSessionOracle::getOnlyTableComments(QString schemaName, QString tableName)
{
    QString result = QString();
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    // Table Comments
    QString sqlTableComments = "SELECT COMMENTS FROM "+adminViewPrefix+"_TAB_COMMENTS WHERE OWNER = :C_OWNER AND TABLE_NAME = :C_TABLE";
    QSqlQuery queryComments(sqlTableComments, sessionDatabase);
    queryComments.bindValue(":C_OWNER", schemaName);
    queryComments.bindValue(":C_TABLE", tableName);
    queryComments.exec();
    while (queryComments.next()) {
        if ((! queryComments.value(0).isNull()) && (! queryComments.value(0).toString().trimmed().isEmpty()))
            result = queryComments.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionOracle::getPrivileges(QString schemaName, QString objectName, QString objectType)
{
    QStringList result;
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QString sqlStatement = "SELECT GRANTEE, PRIVILEGE, GRANTABLE FROM "+adminViewPrefix+"_TAB_PRIVS WHERE GRANTOR = '"+
            schemaName+"' AND TABLE_NAME = '"+objectName+"' ORDER BY GRANTEE, PRIVILEGE";
    QSqlQuery query(sqlStatement, sessionDatabase);
    while (query.next()) {
        // Grantable (Grant Option)
        if (query.value(2).toString().contains("Y")) {
            result << "GRANT "+query.value(1).toString()+" ON "+schemaName+"."+objectName+" TO "+query.value(0).toString()+" WITH GRANT OPTION;";
        }
        else {
            result << "GRANT "+query.value(1).toString()+" ON "+schemaName+"."+objectName+" TO "+query.value(0).toString()+";";
        }
    }
    if (result.count() > 0)
        result.insert(0, "-- "+tr("GRANTED PRIVILEGE(S)"));
    else
        result.insert(0, "-- "+tr("NO PRIVILEGES GRANTED"));
    return result;
}

int KvSqlSessionOracle::getPrivileges(QTableWidget *tableWidget, QString schemaName, QString tableName, bool dbaRoleEnabled)
{
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QSqlError err;
    QString sqlStatement;

    tableWidget->setRowCount(0);

    sqlStatement = "SELECT GRANTEE, PRIVILEGE, GRANTABLE FROM "+adminViewPrefix+"_TAB_PRIVS WHERE GRANTOR = '"+
            schemaName+"' AND TABLE_NAME = '"+tableName+"' ORDER BY GRANTEE, PRIVILEGE";

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

bool KvSqlSessionOracle::isDbaRoleEnabled() {
    bool result = false;
    QSqlQuery queryDBATables("SELECT 1 FROM DBA_TABLES WHERE ROWNUM<=1", sessionDatabase);
    if (queryDBATables.lastError().text().trimmed().isEmpty()) {
        result = true;
    }
    if (result)
        adminViewPrefix = "DBA";
    else
        adminViewPrefix = "ALL";
    return result;
}

QStringList KvSqlSessionOracle::getConstraints(QString schemaName, QString tableName, KvSqlSession::ConstraintsTypes constraintsTypes)
{
    QStringList result;
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QString sqlStatement = QString("SELECT C.CONSTRAINT_NAME, C.CONSTRAINT_TYPE, C.SEARCH_CONDITION, C.R_OWNER, C.R_CONSTRAINT_NAME, C.DELETE_RULE, C.STATUS, C.GENERATED ")+
            "FROM "+adminViewPrefix+"_CONSTRAINTS C WHERE C.OWNER = :C_OWNER AND C.TABLE_NAME = :C_TABLE "+
            "ORDER BY DECODE(C.CONSTRAINT_TYPE, 'P', 1, 'U', 2, 'R', 3, 'C', 4, 5), DECODE(C.GENERATED, 'GENERATED NAME', 1, 'USER NAME', 2, 3), C.R_CONSTRAINT_NAME";
    QSqlQuery query(sqlStatement, sessionDatabase);
    query.bindValue(":C_OWNER", schemaName);
    query.bindValue(":C_TABLE", tableName);
    query.exec();
    while (query.next()) {

        // PRIMARY AND UNIQUE KEY CONSTRAINTS
        if (query.value(1).toString().contains("P") || query.value(1).toString().contains("U")) {
            if ((constraintsTypes == KvSqlSession::AllConstraints) || (constraintsTypes == KvSqlSession::PrimaryUniqueConstraints)) {
                if (query.value(1).toString().contains("P")) {
                    result << "-- "+tr("PRIMARY KEY");
                    result << "ALTER TABLE "+schemaName+"."+tableName+" ADD CONSTRAINT "+query.value(0).toString()+" PRIMARY KEY (";
                }
                else {
                    if (!result.contains("-- "+tr("UNIQUE KEY(S)")))
                        result << "-- "+tr("UNIQUE KEY(S)");
                    result << "ALTER TABLE "+schemaName+"."+tableName+" ADD CONSTRAINT "+query.value(0).toString()+" UNIQUE (";
                }


                QString sqlStatementForColumns = QString("SELECT COLUMN_NAME FROM "+adminViewPrefix+"_CONS_COLUMNS ")+
                        "WHERE OWNER = :C_OWNER AND TABLE_NAME = :C_TABLE AND CONSTRAINT_NAME = :C_CONS_NAME "+
                        "ORDER BY POSITION";
                QSqlQuery queryCols(sqlStatementForColumns, sessionDatabase);
                queryCols.bindValue(":C_OWNER", schemaName);
                queryCols.bindValue(":C_TABLE", tableName);
                queryCols.bindValue(":C_CONS_NAME", query.value(0).toString());
                queryCols.exec();
                while (queryCols.next()) {
                    result << "  "+queryCols.value(0).toString()+",";
                }
                QString lastColumn = result.last();
                result.removeLast();
                result << lastColumn.remove(',');
                result << ");";
                result << "";
            }
        }
        // FOREIGN KEY CONSTRAINTS
        else if (query.value(1).toString().contains("R")) {
            if ((constraintsTypes == KvSqlSession::AllConstraints) || (constraintsTypes == KvSqlSession::ReferentialConstraints)) {
                if (!result.contains("-- "+tr("FOREIGN KEY(S)")))
                    result << "-- "+tr("FOREIGN KEY(S)");

                QStringList pkColumns, fkColumns;
                result << "ALTER TABLE "+schemaName+"."+tableName+" ADD CONSTRAINT "+query.value(0).toString()+" FOREIGN KEY (";
                QString sqlStatementForColumns = QString("SELECT C1.COLUMN_NAME, C2.COLUMN_NAME, C2.OWNER, C2.TABLE_NAME FROM "+adminViewPrefix+"_CONS_COLUMNS C1, "+adminViewPrefix+"_CONS_COLUMNS C2 ")+
                        "WHERE C1.OWNER = :C_OWNER1 AND C1.CONSTRAINT_NAME = :C_CONSTRAINT1 AND C2.OWNER = :C_OWNER2 AND C2.CONSTRAINT_NAME = :C_CONSTRAINT2 AND "+
                        "C1.POSITION = C2.POSITION "
                        "ORDER BY C1.POSITION";
                QSqlQuery queryCols(sqlStatementForColumns, sessionDatabase);
                queryCols.bindValue(":C_OWNER1", schemaName);
                queryCols.bindValue(":C_CONSTRAINT1", query.value(0).toString());
                queryCols.bindValue(":C_OWNER2", query.value(3).toString());
                queryCols.bindValue(":C_CONSTRAINT2", query.value(4).toString());
                queryCols.exec();
                QString fkSchemaName, fkTableName;
                while (queryCols.next()) {
                    fkColumns << queryCols.value(0).toString();
                    pkColumns << queryCols.value(1).toString();
                    fkSchemaName = queryCols.value(2).toString();
                    fkTableName = queryCols.value(3).toString();
                }
                // Show each foreign key column component
                if (fkColumns.count() > 1)
                    for(int i=0; i<fkColumns.count()-1; i++)
                        result << "  "+fkColumns.at(i)+",";
                result << "  "+fkColumns.last()+")";
                result << "REFERENCES "+fkSchemaName+"."+fkTableName+" (";
                // Show each primary key column component referenced
                if (pkColumns.count() > 1)
                    for(int i=0; i<pkColumns.count()-1; i++)
                        result << "  "+pkColumns.at(i)+",";
                result << "  "+pkColumns.last()+");";
                result << "";
            }
        }
        // CHECK CONSTRAINTS
        else if (query.value(1).toString().contains("C")) {
            if ((constraintsTypes == KvSqlSession::AllConstraints) || (constraintsTypes == KvSqlSession::CheckConstraints)) {
                if (( query.value(7).toString().contains("GENERATED NAME")) &&
                        ( query.value(2).toString().contains("IS NOT NULL", Qt::CaseInsensitive)) &&
                        (!query.value(2).toString().contains(" AND ", Qt::CaseInsensitive)) &&
                        (!query.value(2).toString().contains(" OR ", Qt::CaseInsensitive))) {

                    // This check constraint is a generated NOT NULL constraint. This constraint is already defined on CREATE TABLE.
                }
                else {
                    if (!result.contains("-- "+tr("CHECK(S)")))
                        result << "-- "+tr("CHECK(S)");

                    result << "ALTER TABLE "+schemaName+"."+tableName+" ADD CONSTRAINT "+query.value(0).toString()+" CHECK ( ";
                    foreach(QString line, query.value(2).toString().split('\n', QString::SkipEmptyParts))
                        if (!line.trimmed().isEmpty())
                            result << line;
                    result << " );";
                    result << "";
                }
            }
        }
    }
    return result;
}

QList< KvTableConstraintInfo > KvSqlSessionOracle::getUniqueConstraints(QString schemaName, QString tableName) {
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QSqlError err;
    QString sqlStatementForTable;
    QString sqlStatementForColumns;
    QList< KvTableConstraintInfo > result;


    sqlStatementForTable = QString("SELECT C.OWNER, C.CONSTRAINT_NAME, C.TABLE_NAME, C.CONSTRAINT_TYPE, C.STATUS FROM "+adminViewPrefix+"_CONSTRAINTS C WHERE ")+
            "C.OWNER = '"+schemaName+"' AND C.TABLE_NAME = '"+tableName+"' AND "+
            "C.CONSTRAINT_TYPE IN ('P','U') ORDER BY C.CONSTRAINT_TYPE, C.CONSTRAINT_NAME";


    QSqlQuery queryForTable(sqlStatementForTable, sessionDatabase);
    while (queryForTable.next()) {
        KvTableConstraintInfo constraint;
        constraint.constraintSchema	= queryForTable.value(0).toString();
        constraint.constraintName	= queryForTable.value(1).toString();
        constraint.constraintTable	= queryForTable.value(2).toString();
        constraint.constraintType	= queryForTable.value(3).toString();
        constraint.constraintStatus	= queryForTable.value(4).toString();
        constraint.constraintOptional   = false;

        sqlStatementForColumns = QString("SELECT CC.COLUMN_NAME FROM "+adminViewPrefix+"_CONS_COLUMNS CC WHERE ")+
                "CC.OWNER = '"+constraint.constraintSchema+"' AND CC.CONSTRAINT_NAME = '"+constraint.constraintName+"' AND "+
                "CC.TABLE_NAME = '"+constraint.constraintTable+"' "+
                "ORDER BY CC.POSITION";

        QSqlQuery queryForColumns(sqlStatementForColumns, sessionDatabase);

        while (queryForColumns.next()) {
            constraint.constraintColumns.append(queryForColumns.value(0).toString());
        }
        result.append(constraint);
    }

    return result;
}


QList< KvTableConstraintInfo > KvSqlSessionOracle::getRelationshipConstraints(QString schemaName, QString tableName) {
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QSqlError err;
    QString sqlStatementForTable;
    QString sqlStatementForColumns;
    QList< KvTableConstraintInfo > result;


    sqlStatementForTable = QString("SELECT C1.OWNER, C1.CONSTRAINT_NAME, C1.TABLE_NAME, C1.CONSTRAINT_TYPE, C1.STATUS, C2.OWNER, C2.CONSTRAINT_NAME, C2.TABLE_NAME ")+
            "FROM "+adminViewPrefix+"_CONSTRAINTS C1, "+adminViewPrefix+"_CONSTRAINTS C2 "+
            "WHERE "+
            "C1.OWNER = '"+schemaName+"' AND C1.TABLE_NAME = '"+tableName+"' AND "+
            "C1.CONSTRAINT_TYPE = 'R' AND C1.R_OWNER = C2.OWNER AND C1.R_CONSTRAINT_NAME = C2.CONSTRAINT_NAME "+
            "ORDER BY C1.CONSTRAINT_TYPE, C2.TABLE_NAME, C1.CONSTRAINT_NAME";


    QSqlQuery queryForTable(sqlStatementForTable, sessionDatabase);
    while (queryForTable.next()) {
        KvTableConstraintInfo constraint;
        constraint.constraintSchema	= queryForTable.value(0).toString();
        constraint.constraintName	= queryForTable.value(1).toString();
        constraint.constraintTable	= queryForTable.value(2).toString();
        constraint.constraintType	= queryForTable.value(3).toString();
        constraint.constraintStatus	= queryForTable.value(4).toString();
        constraint.constraintRefOwner   = queryForTable.value(5).toString();
        constraint.constraintRefTable   = queryForTable.value(7).toString();
        constraint.constraintOptional   = false;

        sqlStatementForColumns = QString("SELECT CC1.COLUMN_NAME, CC2.COLUMN_NAME, TC1.NULLABLE FROM ")+
                adminViewPrefix+"_CONS_COLUMNS CC1,"+adminViewPrefix+"_CONS_COLUMNS CC2, "+adminViewPrefix+"_TAB_COLUMNS TC1 "
                "WHERE "+
                "CC1.OWNER = '"+constraint.constraintSchema+"' AND CC1.CONSTRAINT_NAME = '"+constraint.constraintName+"' AND CC1.TABLE_NAME = '"+constraint.constraintTable+"' AND "+
                "CC2.OWNER = '"+constraint.constraintRefOwner+"' AND CC2.CONSTRAINT_NAME = '"+queryForTable.value(6).toString()+"' AND CC2.TABLE_NAME = '"+constraint.constraintRefTable+"' AND "+
                "TC1.OWNER = CC1.OWNER AND TC1.TABLE_NAME = CC1.TABLE_NAME AND TC1.COLUMN_NAME = CC1.COLUMN_NAME AND CC1.POSITION = CC2.POSITION "+
                "ORDER BY CC1.POSITION";

        QSqlQuery queryForColumns(sqlStatementForColumns, sessionDatabase);
        while (queryForColumns.next()) {
            constraint.constraintColumns.append(queryForColumns.value(0).toString());
            constraint.constraintRefColumns.append(queryForColumns.value(1).toString());
            if (queryForColumns.value(1).toString().at(0)=='Y')
                constraint.constraintOptional   = true;
        }
        result.append(constraint);
    }

    return result;
}


QStringList KvSqlSessionOracle::describe(const QString &schema, const QString &table) {
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QStringList result;
    QString maxSizeStatement;
    QString describeStatement;
    int maxColumnSize = 0;

    QString admViewName  = adminViewPrefix+"_TAB_COLUMNS";
    QString schemaClause = "";

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

void KvSqlSessionOracle::getTablesOfSchema(QTreeWidgetItem *item, const QString &connectionName, const QString &schema)
{
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QStringList tables = getTables(schema);
    emit sendTablesOfSchema(item, schema, tables);
}

// This method is used to identify Oracle sessions (this information will be presented by querying v$session)
void KvSqlSessionOracle::setModuleInfoForSession(QString moduleInfo, QString actionInfo)
{
    // DBMS_APPLICATION_INFO.SET_MODULE ( module_name IN VARCHAR2, action_name IN VARCHAR2);
    QString statement = "begin DBMS_APPLICATION_INFO.SET_MODULE('"+moduleInfo+"', '"+actionInfo+"'); end;";
    QSqlQuery queryModule(statement, sessionDatabase);
    queryModule.exec();
}

QStringList KvSqlSessionOracle::getIndex(QString schema, QString indexName, bool showSchema)
{
    if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();

    QStringList result;
    QString sqlStatement = "SELECT I.OWNER, I.INDEX_NAME, I.INDEX_TYPE, I.TABLE_OWNER, I.TABLE_NAME, I.TABLE_TYPE, I.UNIQUENESS, I.GENERATED FROM "+
            adminViewPrefix+"_INDEXES I WHERE I.OWNER = :C_OWNER AND I.INDEX_NAME = :C_INDEX AND "+
            "NOT EXISTS (SELECT 1 FROM "+adminViewPrefix+"_SEGMENTS S "+
            "            WHERE I.INDEX_NAME = S.SEGMENT_NAME AND "+
            "              S.SEGMENT_TYPE = 'LOBINDEX' AND "+
            "              S.OWNER = I.OWNER)";
    QSqlQuery query(sqlStatement, sessionDatabase);
    query.bindValue(":C_OWNER", schema);
    query.bindValue(":C_INDEX", indexName);
    query.exec();
    while (query.next()) {
        result << "-- "+tr("CREATE INDEX");
        QString uniqueString = "";
        if (query.value(6).toString().trimmed().compare("UNIQUE", Qt::CaseInsensitive) == 0)
            uniqueString = "UNIQUE ";
        if (showSchema)
            result << "CREATE "+uniqueString+"INDEX "+query.value(0).toString()+"."+query.value(1).toString()+" ON "+query.value(3).toString()+"."+query.value(4).toString()+" (";
        else
            result << "CREATE "+uniqueString+"INDEX "+query.value(1).toString()+" ON "+query.value(4).toString()+" (";

        QString sqlIndexColumns = "SELECT COLUMN_NAME, COLUMN_POSITION FROM "+adminViewPrefix+"_IND_COLUMNS WHERE INDEX_OWNER = :C_OWNER AND INDEX_NAME = :C_INDEX "+
                "ORDER BY COLUMN_POSITION";
        QSqlQuery queryIndexColumns(sqlIndexColumns, sessionDatabase);
        queryIndexColumns.bindValue(":C_OWNER", schema);
        queryIndexColumns.bindValue(":C_INDEX", indexName);
        queryIndexColumns.exec();
        while (queryIndexColumns.next()) {
            result << "  "+queryIndexColumns.value(0).toString().trimmed()+",";
        }
        QString lastColumn = result.last();
        result.removeLast();
        result << lastColumn.remove(",");
        result << ");";
    }
    return result;
}

QMap<QString,QString> KvSqlSessionOracle::getSessionInfo()
{
    QMap<QString,QString> result;
    QString sqlStatement = QString("SELECT 'CURRENT_SCHEMA', sys_context('USERENV', 'CURRENT_SCHEMA') FROM dual union all ")+
            "SELECT 'CURRENT_SCHEMAID', sys_context('USERENV', 'CURRENT_SCHEMAID') FROM dual union all "+
            "SELECT 'DB_DOMAIN', sys_context('USERENV', 'DB_DOMAIN') FROM dual union all "+
            "SELECT 'DB_NAME', sys_context('USERENV', 'DB_NAME') FROM dual union all "+
            "SELECT 'DB_UNIQUE_NAME', sys_context('USERENV', 'DB_UNIQUE_NAME') FROM dual union all "+
            "SELECT 'GLOBAL_CONTEXT_MEMORY', sys_context('USERENV', 'GLOBAL_CONTEXT_MEMORY') FROM dual union all "+
            "SELECT 'HOST', sys_context('USERENV', 'HOST') FROM dual union all "+
            "SELECT 'IDENTIFICATION_TYPE', sys_context('USERENV', 'IDENTIFICATION_TYPE') FROM dual union all "+
            "SELECT 'INSTANCE', sys_context('USERENV', 'INSTANCE') FROM dual union all "+
            "SELECT 'INSTANCE_NAME', sys_context('USERENV', 'INSTANCE_NAME') FROM dual union all "+
            "SELECT 'ISDBA', sys_context('USERENV', 'ISDBA') FROM dual union all "+
            "SELECT 'LANG', sys_context('USERENV', 'LANG') FROM dual union all "+
            "SELECT 'LANGUAGE', sys_context('USERENV', 'LANGUAGE') FROM dual union all "+
            "SELECT 'MODULE', sys_context('USERENV', 'MODULE') FROM dual union all "+
            "SELECT 'NLS_CALENDAR', sys_context('USERENV', 'NLS_CALENDAR') FROM dual union all "+
            "SELECT 'NLS_CURRENCY', sys_context('USERENV', 'NLS_CURRENCY') FROM dual union all "+
            "SELECT 'NLS_DATE_FORMAT', sys_context('USERENV', 'NLS_DATE_FORMAT') FROM dual union all "+
            "SELECT 'NLS_DATE_LANGUAGE', sys_context('USERENV', 'NLS_DATE_LANGUAGE') FROM dual union all "+
            "SELECT 'NLS_SORT', sys_context('USERENV', 'NLS_SORT') FROM dual union all "+
            "SELECT 'NLS_TERRITORY', sys_context('USERENV', 'NLS_TERRITORY') FROM dual union all "+
            "SELECT 'NLS_TERRITORY', sys_context('USERENV', 'NLS_TERRITORY') FROM dual union all "+
            "SELECT 'OS_USER', sys_context('USERENV', 'OS_USER') FROM dual union all "+
            "SELECT 'SERVER_HOST', sys_context('USERENV', 'SERVER_HOST') FROM dual union all "+
            "SELECT 'SERVICE_NAME', sys_context('USERENV', 'SERVICE_NAME') FROM dual union all "+
            "SELECT 'SESSION_USER', sys_context('USERENV', 'SESSION_USER') FROM dual union all "+
            "SELECT 'SESSION_USERID', sys_context('USERENV', 'SESSION_USERID') FROM dual union all "+
            "SELECT 'SESSIONID', sys_context('USERENV', 'SESSIONID') FROM dual union all "+
            "SELECT 'SID', sys_context('USERENV', 'SID') FROM dual union all "+
            "SELECT 'STATEMENTID', sys_context('USERENV', 'STATEMENTID') FROM dual union all "+
            "SELECT 'TERMINAL', sys_context('USERENV', 'TERMINAL') FROM dual";
    QSqlQuery query(sqlStatement, sessionDatabase);
    query.exec();
    while (query.next()) {
        result.insert(query.value(0).toString(), query.value(1).toString());
    }

    // Identifying Serial#, if select on v$session granted...
    sqlStatement = QString("SELECT 'SERIAL#', serial# FROM v$session where audsid = SYS_CONTEXT('USERENV','SESSIONID')");
    QSqlQuery query2(sqlStatement, sessionDatabase);
    query2.exec();
    while (query2.next()) {
        result.insert(query2.value(0).toString(), query2.value(1).toString());
    }

    return result;
}

void KvSqlSessionOracle::setObjectTypeNames()
{
    databaseObjectTypeNames << "TABLE" << "VIEW";
    databaseObjectTypeNames << getProgramsTypes();
    databaseObjectTypeNames << getEtcTypes();
    databaseObjectTypeNames.removeAll("RECYCLE BIN");
    databaseObjectTypeNames.sort();
}

void KvSqlSessionOracle::setObjectTypeOrder()
{
    QStringList programTypes = getProgramsTypes();
    programTypes.removeAll("TYPE");
    programTypes.removeAll("TYPE BODY");
    programTypes.removeAll("FUNCTION");
    programTypes.removeAll("PROCEDURE");
    programTypes.removeAll("PACKAGE");
    programTypes.removeAll("PACKAGE BODY");
    programTypes.removeAll("TRIGGER");

    QStringList etcTypes = getEtcTypes();
    databaseObjectTypeOrder << "TABLE" << "VIEW";
    databaseObjectTypeOrder << etcTypes;
    databaseObjectTypeOrder << "TYPE" << "TYPE BODY" << "FUNCTION" << "PROCEDURE" << "PACKAGE" << "PACKAGE BODY" << "TRIGGER";
    databaseObjectTypeOrder << programTypes;
}
