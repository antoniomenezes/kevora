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

#include "kvsqlsessionpostgresql.h"

KvSqlSessionPostgreSql::KvSqlSessionPostgreSql(QObject * parent): KvSqlSession(parent)
{
}

QString KvSqlSessionPostgreSql::databaseForDriver(const QString &driver) {
    if ((driver.contains("QPSQL")) || (driver.contains("QPSQL7")))
        return "PostgreSql";
    else
        return "";
}

QString KvSqlSessionPostgreSql::nameForDriver(const QString &driver)
{
    if (driver == "QPSQL")
        return "PostgreSql";
    else if (driver == "QPSQL7")
        return "PostgreSql";
    else
        return "";
}

QString KvSqlSessionPostgreSql::getDriverComments(const QString &driver) {
    if (driver == "QPSQL")
        return "QPSQL: "+tr("This plugin supports version 7.3 and higher of the PostgreSQL server.");
    else if (driver == "QPSQL7")
        return "QPSQL7: "+tr("This plugin supports both version 6 and 7 of PostgreSQL.");
    else
        return "";
}

QString KvSqlSessionPostgreSql::getDbmsTypeName() {
    return "PostgreSql";
}

QStringList KvSqlSessionPostgreSql::getTables(const QString &schema)
{
    QStringList result;

    QSqlQuery query("SELECT TABLE_NAME FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_SCHEMA = '"+schema+"' AND TABLE_TYPE = 'BASE TABLE' ORDER BY TABLE_NAME", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionPostgreSql::getViews(const QString &schema)
{
    QStringList result;
    QSqlQuery query("SELECT TABLE_NAME FROM INFORMATION_SCHEMA.VIEWS WHERE TABLE_SCHEMA = '"+schema+"' ORDER BY TABLE_NAME", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionPostgreSql::getPrograms(const QString &schema, const QString &type)
{
    QStringList result;
    /*if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();*/

    QSqlQuery query(sessionDatabase);
    if (type.compare("FUNCTION", Qt::CaseInsensitive) == 0)
        query.exec();
    else if (type.compare("TRIGGER", Qt::CaseInsensitive) == 0)
        query.exec();
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionPostgreSql::getEtc(const QString &schema, const QString &type)
{
    QStringList result;
    /*if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();*/

    /*QSqlQuery query("SELECT OBJECT_NAME FROM DBA_OBJECTS WHERE OWNER = '"+schema+"' AND OBJECT_TYPE = '"+type+"' ORDER BY OBJECT_NAME", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }*/
    return result;
}

QList< QPair<QString, QString> > KvSqlSessionPostgreSql::getProgramsWithStatus(const QString &schema, const QString &type)
{
    /*if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();*/

    QList< QPair<QString, QString> > result;
    QSqlQuery query(sessionDatabase);

    if (type.compare("TRIGGER", Qt::CaseInsensitive) == 0) {
        query.exec(QString("SELECT DISTINCT trigger_name, 'Y' ")+
                   "FROM information_schema.triggers "+
                   "WHERE trigger_schema = '"+schema+"'");
    }
    else if (type.compare("FUNCTION", Qt::CaseInsensitive) == 0) {
        query.exec(QString("SELECT routine_name, 'Y' ")+
                   "FROM information_schema.routines "+
                   "WHERE specific_schema = '"+schema+"' "+
                   "AND type_udt_name != 'trigger'");
    }
    while (query.next()) {
        QPair<QString, QString> pair;
        pair.first = query.value(0).toString();
        pair.second = query.value(1).toString();
        result << pair;
    }
    return result;
}

QList< QPair<QString, QString> > KvSqlSessionPostgreSql::getEtcWithStatus(const QString &schema, const QString &type)
{
    QString queryEtc;
    QList< QPair<QString, QString> > result;

    /*

    if (type.compare("DOMAIN", Qt::CaseInsensitive) == 0) {
        queryEtc = "SELECT DOMAIN_NAME, 'Y' FROM INFORMATION_SCHEMA.DOMAINS WHERE DOMAIN_SCHEMA = '"+schema+"' ORDER BY DOMAIN_NAME";
    }
    else if (type.compare("RULE", Qt::CaseInsensitive) == 0) {
        queryEtc = "SELECT rulename, 'Y' FROM pg_catalog.pg_rules WHERE schemaname = '"+schema+"'  ORDER BY rulename";
    }
    else if (type.compare("SYNONYM", Qt::CaseInsensitive) == 0) {
        if (schema.compare("PUBLIC", Qt::CaseInsensitive) == 0) {
            return result;
        }
        else {
            queryEtc = "SELECT OBJECT_NAME, DECODE(STATUS,'VALID','Y','INVALID','N') FROM DBA_OBJECTS WHERE OWNER = '"+schema+"' AND OBJECT_TYPE = '"+type+"' ORDER BY OBJECT_NAME";
        }
    }
    else if (type.compare("RECYCLE BIN", Qt::CaseInsensitive) == 0) {
        queryEtc = "SELECT ORIGINAL_NAME, 'Y' FROM DBA_RECYCLEBIN WHERE OWNER = '"+schema+"' ORDER BY ORIGINAL_NAME";
    }
    else if (type.compare("TABLESPACE", Qt::CaseInsensitive) == 0) {
        queryEtc = QString("SELECT DISTINCT t.TABLESPACE_NAME, 'Y' FROM DBA_TABLESPACES t, DBA_SEGMENTS s ")+
                "WHERE s.TABLESPACE_NAME = t.TABLESPACE_NAME AND s.OWNER = '"+schema+"' UNION "+
                "SELECT DEFAULT_TABLESPACE, 'Y' FROM DBA_USERS WHERE USERNAME = '"+schema+"' UNION "+
                "SELECT TEMPORARY_TABLESPACE, 'Y' FROM DBA_USERS WHERE USERNAME = '"+schema+"'";
    }
    else {
        queryEtc = "SELECT OBJECT_NAME, DECODE(STATUS,'VALID','Y','INVALID','N') FROM DBA_OBJECTS WHERE OWNER = '"+schema+"' AND OBJECT_TYPE = '"+type+"' ORDER BY OBJECT_NAME";
    }

    QSqlQuery query(queryEtc, sessionDatabase);
    while (query.next()) {
        QPair<QString, QString> pair;
        pair.first = query.value(0).toString();
        pair.second = query.value(1).toString();
        result << pair;
    }

    */

    return result;
}

QStringList KvSqlSessionPostgreSql::getSqlBlocks(QStringList sqlLines, int fromPosition, int toPosition)
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

QStringList KvSqlSessionPostgreSql::getDdlFromObject(QString schema, QString objectName, QString objectType, bool showSchema, KvSqlSession::DdlTypes ddlType)
{
    bool hasShownSchema = false;
    QStringList result;

    if ( (objectType.compare("FUNCTION", Qt::CaseInsensitive) == 0) ||
         (objectType.compare("PROCEDURE", Qt::CaseInsensitive) == 0) ||
         (objectType.compare("TRIGGER", Qt::CaseInsensitive) == 0) )
    {
        QString sqlStatement = QString("SELECT routine_definition, external_language, data_type ")+
                "FROM information_schema.routines WHERE routine_schema = '"+schema+"' AND "+
                "routine_name = '"+objectName+"' AND "+
                "routine_type = '"+objectType+"'";

        QSqlQuery query(sqlStatement, sessionDatabase);
        while (query.next()) {
            QString lineString = query.value(0).toString();
            lineString = "CREATE OR REPLACE "+objectType+" "+schema+"."+objectName+"()"+'\n'+"  RETURNS "+
                    query.value(2).toString()+" AS"+'\n'+"$BODY$"+'\n'+lineString+'\n'+"$BODY$"+'\n'+
                    "LANGUAGE '"+query.value(1).toString().toLower()+"';"; // VOLATILE COST 100;

            QStringList lines = lineString.split('\n', QString::SkipEmptyParts);

            if (query.value(1).toInt() == 1) {
                lineString = "CREATE OR REPLACE "+lineString;
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
            foreach(QString line, lines) {
                result << line;
            }
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



            describeStatement = "SELECT column_name, is_nullable, data_type, character_maximum_length, numeric_precision, numeric_scale, column_default FROM information_schema.columns WHERE table_schema = '"+schema+"' AND table_name = '"+objectName+"' ORDER BY ordinal_position";
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
                if (query.value(1).toString() == "YES")
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
            QString sqlIndexStatement = QString("SELECT OWNER, INDEX_NAME FROM _INDEXES WHERE TABLE_OWNER = :C_OWNER AND TABLE_NAME = :C_TABLE AND ")+
                    "INDEX_NAME NOT IN ( SELECT CONSTRAINT_NAME FROM _CONSTRAINTS WHERE OWNER = :C_OWNER AND TABLE_NAME = :C_TABLE AND CONSTRAINT_TYPE IN ('U','P')) "
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
        viewTextStatement = "SELECT view_definition FROM information_schema.views WHERE table_schema = '"+schema+"' AND table_name = '"+objectName+"'";
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
        //QString lastResultLine = result.last();
        //result.removeLast();
        //result << lastResultLine + ";";
    }
    else if (objectType.compare("INDEX", Qt::CaseInsensitive) == 0) {
        result.append( getIndex(schema, objectName, showSchema) );
    }
    else if (objectType.compare("SEQUENCE", Qt::CaseInsensitive) == 0) {
        QString sqlStatement = QString("SELECT SEQUENCE_OWNER, SEQUENCE_NAME, MIN_VALUE, MAX_VALUE, INCREMENT_BY, CYCLE_FLAG, ORDER_FLAG, ")+
                "CACHE_SIZE, LAST_NUMBER+1 "+
                "FROM "+"_SEQUENCES WHERE SEQUENCE_OWNER = :C_OWNER AND SEQUENCE_NAME = :C_SEQUENCE ";
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
    if ((ddlType == KvSqlSession::CompleteDdl) && (objectType.contains("TABLE") || objectType.contains("VIEW") ||
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

QStringList KvSqlSessionPostgreSql::getDependentSql(QString sqlStatement)
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
    fullTableName = sqlStatement.mid(fromIndex+4, whereIndex-(fromIndex+4)).trimmed();
    if (fullTableName.contains(".")) {
        schemaName = fullTableName.split(".").at(0);
        tableName = fullTableName.split(".").at(1);
    }
    else {
        schemaName = QString();
        tableName = fullTableName;
    }

    QString operation = statementsByFrom.split(" ").at(0);

    qDebug() << "fullTableName" << fullTableName;
    qDebug() << "schemaName" << schemaName;
    qDebug() << "tableName" << tableName;
    qDebug() << "statementsByWhere" << statementsByWhere;
    qDebug() << "operation" << operation;

    if (operation.toUpper().compare("DELETE") == 0) {

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

void KvSqlSessionPostgreSql::getChildRecords(QString schema, QString table, QString recordClause,
                                             QMap<QString, KvRecordIdentifier> *mapRecordIds,
                                             QMap<QString, QList<KvTableColumn> > *mapTablesIdColumns,
                                             QMap<QString, QList<KvTableDependency> > *mapTablesDependencies)
{
    QList<KvRecordIdentifier> newRecords = QList<KvRecordIdentifier>();
    QList<KvRecordIdentifier> newRecordsFormated = QList<KvRecordIdentifier>();

    QString schemaClause = QString();

    if (schema.isEmpty()) {
        QString sqlSchemaStatement;

        sqlSchemaStatement = QString("SELECT table_schema FROM information_schema.tables where table_type = 'BASE TABLE' and table_schema = 'public'");
        QSqlQuery schemaQuery(sqlSchemaStatement, sessionDatabase);
        while (schemaQuery.next()) {
            schemaClause = schemaQuery.value(0).toString();
        }
    }
    else
        schemaClause = schema;

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

    qDebug() << parentSqlStatement;
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

                if ((parentTableColumns.at(f).columnType == "character") ||
                        (parentTableColumns.at(f).columnType == "character varying") ||
                        (parentTableColumns.at(f).columnType == "text") ||
                        (parentTableColumns.at(f).columnType == "ctid"))
                    value = "'"+parentQuery.value(parentTableIdentityColumns.indexOf(fieldName)).toString().replace("'","''")+"'";
                else if (parentTableColumns.at(f).columnType == "date")
                    value = "TO_DATE('"+parentQuery.value(parentTableIdentityColumns.indexOf(fieldName)).toDateTime().toString("yyyy-MM-dd hh:mm:ss")+"','YYYY-MM-DD HH24:MI:SS')";
                else if ((parentTableColumns.at(f).columnType == "integer") ||
                         (parentTableColumns.at(f).columnType == "timestamp without time zone")
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

    for(int r=0; r<newRecords.count(); r++)
        qDebug() << newRecords.at(r).recordSchema + "." + newRecords.at(r).recordTable + "." + newRecords.at(r).recordKeyClause;

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
            qDebug() << joinStatement+parentKeysClause;
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

                        if ((childTableColumns.at(k).columnType == "character") ||
                                (childTableColumns.at(k).columnType == "character varying") ||
                                (childTableColumns.at(k).columnType == "text") ||
                                (childTableColumns.at(k).columnType == "ctid"))
                            value = "'"+joinQuery.value(k).toString().replace("'","''")+"'";
                        else if (childTableColumns.at(k).columnType == "date")
                            value = "TO_DATE('"+joinQuery.value(k).toDateTime().toString("yyyy-MM-dd hh:mm:ss")+"','YYYY-MM-DD HH24:MI:SS')";
                        else if ((childTableColumns.at(k).columnType == "integer") ||
                                 (childTableColumns.at(k).columnType == "timestamp without time zone")
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


QList<KvTableDependency> KvSqlSessionPostgreSql::getTableChildRelationships(QString schema, QString table)
{
    QList<KvTableDependency> result = QList<KvTableDependency>();

    QString constraintStatement = QString("SELECT ")+
            "rc.unique_constraint_schema, "+
            "tcp.table_name, "+
            "rc.unique_constraint_name, "+
            "rc.constraint_schema, "+
            "tcf.table_name, "+
            "rc.constraint_name "+
            "FROM information_schema.referential_constraints rc, information_schema.table_constraints tcp, information_schema.table_constraints tcf "+
            "where tcp.constraint_schema = rc.unique_constraint_schema and tcp.constraint_name = rc.unique_constraint_name and "+
            "tcf.constraint_schema = rc.constraint_schema and tcf.constraint_name = rc.constraint_name and "+
            "tcp.constraint_schema = '"+schema+"' and tcp.table_name = '"+table+"' "+
            "order by rc.constraint_schema, tcf.table_name, rc.constraint_name";

    qDebug() << constraintStatement;

    QSqlQuery consQuery(constraintStatement, sessionDatabase);

    while (consQuery.next()) {

        KvTableDependency tabDep;

        tabDep.parentSchema = consQuery.value(0).toString();
        tabDep.parentTable = consQuery.value(1).toString();
        tabDep.childSchema = consQuery.value(3).toString();
        tabDep.childTable = consQuery.value(4).toString();
        tabDep.constraintName = consQuery.value(5).toString();

        qDebug() << tabDep.constraintName;

        QString dependencyStatement = QString("SELECT ")+
                "kp.column_name, kf.column_name, substr(cf.is_nullable,1,1) "+
                "FROM "+
                "information_schema.columns cf, "+
                "information_schema.key_column_usage kp, "+
                "information_schema.key_column_usage kf "+
                "where "+
                "kf.table_schema = cf.table_schema and "+
                "kf.table_name = cf.table_name and "+
                "kf.column_name = cf.column_name and "+
                "kp.ordinal_position = kf.ordinal_position and "+
                "kp.constraint_schema = '"+consQuery.value(0).toString()+"' and "+
                "kp.constraint_name = '"+consQuery.value(2).toString()+"' and "+
                "kp.table_name = '"+consQuery.value(1).toString()+"' and "+
                "kf.constraint_schema = '"+consQuery.value(3).toString()+"' and "+
                "kf.constraint_name = '"+consQuery.value(5).toString()+"' and "+
                "kf.table_name = '"+consQuery.value(4).toString()+"' "+
                "order by kf.table_schema, kf.table_name, kf.constraint_name, kf.ordinal_position";

        qDebug() << dependencyStatement;

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

QList<KvTableDependency> KvSqlSessionPostgreSql::getTableParentRelationships(QString schema, QString table)
{
    QList<KvTableDependency> result = QList<KvTableDependency>();

    QString constraintStatement = QString("SELECT ")+
            "rc.unique_constraint_schema, "+
            "tcp.table_name, "+
            "rc.unique_constraint_name, "+
            "rc.constraint_schema, "+
            "tcf.table_name, "+
            "rc.constraint_name "+
            "FROM information_schema.referential_constraints rc, information_schema.table_constraints tcp, information_schema.table_constraints tcf "+
            "where tcp.constraint_schema = rc.unique_constraint_schema and tcp.constraint_name = rc.unique_constraint_name and "+
            "tcf.constraint_schema = rc.constraint_schema and tcf.constraint_name = rc.constraint_name and "+
            "tcf.constraint_schema = '"+schema+"' and tcf.table_name = '"+table+"' "+
            "order by rc.constraint_schema, tcf.table_name, rc.constraint_name";

    qDebug() << constraintStatement;

    QSqlQuery consQuery(constraintStatement, sessionDatabase);

    while (consQuery.next()) {

        KvTableDependency tabDep;

        tabDep.parentSchema = consQuery.value(0).toString();
        tabDep.parentTable = consQuery.value(1).toString();
        tabDep.childSchema = consQuery.value(3).toString();
        tabDep.childTable = consQuery.value(4).toString();
        tabDep.constraintName = consQuery.value(5).toString();

        qDebug() << tabDep.constraintName;

        QString dependencyStatement = QString("SELECT ")+
                "kp.column_name, kf.column_name, substr(cf.is_nullable,1,1) "+
                "FROM "+
                "information_schema.columns cf, "+
                "information_schema.key_column_usage kp, "+
                "information_schema.key_column_usage kf "+
                "where "+
                "kf.table_schema = cf.table_schema and "+
                "kf.table_name = cf.table_name and "+
                "kf.column_name = cf.column_name and "+
                "kp.ordinal_position = kf.ordinal_position and "+
                "kp.constraint_schema = '"+consQuery.value(0).toString()+"' and "+
                "kp.constraint_name = '"+consQuery.value(2).toString()+"' and "+
                "kp.table_name = '"+consQuery.value(1).toString()+"' and "+
                "kf.constraint_schema = '"+consQuery.value(3).toString()+"' and "+
                "kf.constraint_name = '"+consQuery.value(5).toString()+"' and "+
                "kf.table_name = '"+consQuery.value(4).toString()+"' "+
                "order by kf.table_schema, kf.table_name, kf.constraint_name, kf.ordinal_position";

        qDebug() << dependencyStatement;

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

QString KvSqlSessionPostgreSql::findObjectStatement(QString fullObjectName, QString typeName)
{
  return QString();
}

QStringList KvSqlSessionPostgreSql::getSchemas()
{
    QStringList result;
    QSqlQuery query("SELECT SCHEMA_NAME FROM INFORMATION_SCHEMA.SCHEMATA ORDER BY SCHEMA_NAME", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionPostgreSql::getSchemasWithTables()
{
    QStringList result;
    QSqlQuery query("SELECT DISTINCT TABLE_SCHEMA FROM INFORMATION_SCHEMA.TABLES ORDER BY TABLE_SCHEMA", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionPostgreSql::getSchemasWithViews()
{
    QStringList result;
    QSqlQuery query("SELECT DISTINCT TABLE_SCHEMA FROM INFORMATION_SCHEMA.VIEWS ORDER BY TABLE_SCHEMA", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionPostgreSql::getSchemasWithPrograms()
{
    /*if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();*/

    QStringList result;
    QSqlQuery query("SELECT DISTINCT TABLE_SCHEMA FROM INFORMATION_SCHEMA.VIEWS ORDER BY TABLE_SCHEMA", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionPostgreSql::getSchemasWithEtc()
{
    /*if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();*/

    QStringList result;
    QSqlQuery query("SELECT DISTINCT TABLE_SCHEMA FROM INFORMATION_SCHEMA.VIEWS ORDER BY TABLE_SCHEMA", sessionDatabase);
    while (query.next()) {
        result << query.value(0).toString();
    }
    return result;
}

QStringList KvSqlSessionPostgreSql::getProgramsTypes()
{
    /*if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();*/

    QStringList result;
    result << "FUNCTION";
    result << "TRIGGER";
    return result;
}

QStringList KvSqlSessionPostgreSql::getEtcTypes()
{
    /*if (adminViewPrefix.isEmpty())
        isDbaRoleEnabled();*/

    QStringList result;
    result << "AGGREGATE" << "CAST" << "CONVERSION" << "DOMAIN" << "GROUP" << "INDEX" << "LANGUAGE";
    result << "OPERATOR" << "OPERATOR CLASS" << "OPERATOR FAMILY";
    result << "ROLE" << "RULE" << "SEQUENCE";
    result << "TABLESPACE";
    result << "TEXT SEARCH CONFIGURATION" << "TEXT SEARCH DICTIONARY";
    result << "TEXT SEARCH PARSER" << "TEXT SEARCH TEMPLATE" << "TYPE";

    return result;
}

QList< QPair< QPair<QString, QString>, QPair<QString, QString> > > KvSqlSessionPostgreSql::getRelationsWithTables(const QList< QPair<QString, QString> > &tables)
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

QList< QPair<QString, QString> > KvSqlSessionPostgreSql::getParentTables(const QString &schema, const QString &table)
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

QList< QPair<QString, QString> > KvSqlSessionPostgreSql::getChildTables(const QString &schema, const QString &table) {
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

int KvSqlSessionPostgreSql::getColumns(QTableWidget *tableWidget, QString schemaName, QString tableName) {
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

QList<KvColumnInfo> KvSqlSessionPostgreSql::getColumns(QString schemaName, QString tableName)
{
    QList<KvColumnInfo> result = QList<KvColumnInfo>();
    return result;
}

QList<KvTableColumn> KvSqlSessionPostgreSql::getTableIdentityColumns(QString schemaName, QString tableName)
{
    QList<KvTableColumn> result = QList<KvTableColumn>();
    QSqlError err;
    QString sqlStatement;
    bool useCTId = false;

    sqlStatement = QString("SELECT cc.column_name, tc.data_type ")+
            "FROM information_schema.table_constraints c, information_schema.constraint_column_usage cc, information_schema.columns tc "+
            "where c.constraint_type = 'PRIMARY KEY' and c.table_schema = cc.table_schema and c.table_name = cc.table_name and "
            "c.constraint_name = cc.constraint_name and tc.table_schema = cc.table_schema and tc.table_name = cc.table_name and "+
            "tc.column_name = cc.column_name and c.table_schema = '"+schemaName+"' and c.table_name = '"+tableName+"' "+
            "order by c.table_schema, c.table_name, tc.ordinal_position";

    QSqlQuery query(sqlStatement, sessionDatabase);
    while (query.next()) {
        KvTableColumn tableColumn;
        tableColumn.columnSchema = schemaName;
        tableColumn.columnTable  = tableName;
        tableColumn.columnName   = query.value(0).toString();
        tableColumn.columnType   = query.value(1).toString();

        if ( (tableColumn.columnType != "character") &&
             (tableColumn.columnType != "character varying") &&
             (tableColumn.columnType != "date") &&
             (tableColumn.columnType != "integer") &&
             (tableColumn.columnType != "text") &&
             (tableColumn.columnType != "timestamp without time zone")
             )
            useCTId = true;

        result << tableColumn;
    }

    if (result.isEmpty()) {
        sqlStatement = QString("SELECT cc.column_name, tc.data_type ")+
                "FROM information_schema.table_constraints c, information_schema.constraint_column_usage cc, information_schema.columns tc "+
                "where c.constraint_type = 'UNIQUE' and c.table_schema = cc.table_schema and c.table_name = cc.table_name and "
                "c.constraint_name = cc.constraint_name and tc.table_schema = cc.table_schema and tc.table_name = cc.table_name and "+
                "tc.column_name = cc.column_name and c.table_schema = '"+schemaName+"' and c.table_name = '"+tableName+"' "+
                "order by c.table_schema, c.table_name, tc.ordinal_position";

        QSqlQuery query(sqlStatement, sessionDatabase);
        while (query.next()) {
            KvTableColumn tableColumn;
            tableColumn.columnSchema = schemaName;
            tableColumn.columnTable  = tableName;
            tableColumn.columnName   = query.value(0).toString();
            tableColumn.columnType   = query.value(1).toString();

            if ( (tableColumn.columnType != "character") &&
                 (tableColumn.columnType != "character varying") &&
                 (tableColumn.columnType != "date") &&
                 (tableColumn.columnType != "integer") &&
                 (tableColumn.columnType != "text") &&
                 (tableColumn.columnType != "timestamp without time zone")
                 )
                useCTId = true;

            result << tableColumn;
        }
    }

    if (result.isEmpty() || useCTId) {
        result.clear();
        KvTableColumn tableColumn;
        tableColumn.columnSchema = schemaName;
        tableColumn.columnTable  = tableName;
        tableColumn.columnName   = "ctid";
        tableColumn.columnType   = "ctid";
        result << tableColumn;
    }

    return result;
}

QStringList KvSqlSessionPostgreSql::getTableComments(QString schemaName, QString tableName)
{
    return QStringList();
}

QString KvSqlSessionPostgreSql::getOnlyTableComments(QString schemaName, QString tableName)
{
    return QString();
}

QStringList KvSqlSessionPostgreSql::getPrivileges(QString schemaName, QString objectName, QString objectType)
{
    QStringList result;

    if (objectType.compare("VIEW", Qt::CaseInsensitive) == 0) {
        QString sqlStatement = "SELECT grantee, privilege_type, substr(is_grantable,1,1) FROM information_schema.role_table_grants WHERE table_schema = '"+
                schemaName+"' AND table_name = '"+objectName+"' ORDER BY grantee, privilege_type";
        QSqlQuery query(sqlStatement, sessionDatabase);
        while (query.next()) {
            // Grantable (Admin Option)
            if (query.value(2).toString().contains("Y")) {
                result << "GRANT "+query.value(1).toString()+" ON "+schemaName+"."+objectName+" TO "+query.value(0).toString()+" WITH ADMIN OPTION;";
            }
            else {
                result << "GRANT "+query.value(1).toString()+" ON "+schemaName+"."+objectName+" TO "+query.value(0).toString()+";";
            }
        }
    }
    if (result.count() > 0)
        result.insert(0, "-- "+tr("GRANTED PRIVILEGE(S)"));
    else
        result.insert(0, "-- "+tr("NO PRIVILEGES GRANTED"));
    return result;
}


int KvSqlSessionPostgreSql::getPrivileges(QTableWidget *tableWidget, QString schemaName, QString tableName, bool dbaRoleEnabled)
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

bool KvSqlSessionPostgreSql::isDbaRoleEnabled() {
    bool result = true;
    /*QSqlQuery queryDBATables("SELECT 1 FROM DBA_TABLES WHERE ROWNUM<=1", sessionDatabase);
    if (queryDBATables.lastError().text().trimmed().isEmpty()) {
        result = true;
    }*/
    return result;
}

QStringList KvSqlSessionPostgreSql::getConstraints(QString schemaName, QString tableName, KvSqlSession::ConstraintsTypes constraintsTypes)
{
    return QStringList();
}

QList< KvTableConstraintInfo > KvSqlSessionPostgreSql::getUniqueConstraints(QString schemaName, QString tableName) {
    QSqlError err;
    QString sqlStatementForTable;
    QString sqlStatementForColumns;
    QList< KvTableConstraintInfo > result;

    sqlStatementForTable = QString("SELECT C.constraint_schema, C.constraint_name, C.table_name, C.constraint_type FROM information_schema.table_constraints C WHERE ")+
            "C.table_schema = '"+schemaName+"' AND C.table_name = '"+tableName+"' AND "+
            "C.constraint_type IN ('PRIMARY KEY','UNIQUE') ORDER BY C.constraint_type, C.constraint_name";

    sqlStatementForColumns = QString("SELECT CC.column_name FROM information_schema.key_column_usage CC WHERE ")+
            "CC.constraint_schema = ':C_OWNER' AND CC.constraint_name = ':C_CONSTRAINT_NAME' "+
            "ORDER BY CC.position_in_unique_constraint";
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

QList<KvTableConstraintInfo> KvSqlSessionPostgreSql::getRelationshipConstraints(QString schemaName, QString tableName)
{
    QList<KvTableConstraintInfo> result = QList<KvTableConstraintInfo>();
    return result;
}

QStringList KvSqlSessionPostgreSql::describe(const QString &schema, const QString &table) {
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

QStringList KvSqlSessionPostgreSql::getIndex(QString schema, QString indexName, bool showSchema)
{
    return QStringList();
}

void KvSqlSessionPostgreSql::getTablesOfSchema(QTreeWidgetItem *item, const QString &connectionName, const QString &schema)
{
    QStringList tables = getTables(schema);
    emit sendTablesOfSchema(item, schema, tables);
}

QMap<QString,QString> KvSqlSessionPostgreSql::getSessionInfo()
{
    return QMap<QString,QString>();
}

void KvSqlSessionPostgreSql::setObjectTypeNames()
{
    databaseObjectTypeNames << "TABLE" << "VIEW";
    databaseObjectTypeNames << getProgramsTypes();
    databaseObjectTypeNames << getEtcTypes();
    databaseObjectTypeNames.sort();
}

void KvSqlSessionPostgreSql::setObjectTypeOrder()
{
    databaseObjectTypeOrder << "TABLE" << "VIEW";
    databaseObjectTypeOrder << getProgramsTypes();
    databaseObjectTypeOrder << getEtcTypes();
}
