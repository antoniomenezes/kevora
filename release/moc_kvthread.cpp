/****************************************************************************
** Meta object code from reading C++ file 'kvthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../kvthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kvthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KvThread_t {
    QByteArrayData data[100];
    char stringdata0[2048];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KvThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KvThread_t qt_meta_stringdata_KvThread = {
    {
QT_MOC_LITERAL(0, 0, 8), // "KvThread"
QT_MOC_LITERAL(1, 9, 19), // "startedThreadSignal"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 22), // "openDbConnectionSignal"
QT_MOC_LITERAL(4, 53, 24), // "openedDbConnectionSignal"
QT_MOC_LITERAL(5, 78, 9), // "QSqlError"
QT_MOC_LITERAL(6, 88, 20), // "getSessionInfoSignal"
QT_MOC_LITERAL(7, 109, 20), // "gotSessionInfoSignal"
QT_MOC_LITERAL(8, 130, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(9, 152, 18), // "cloneSessionSignal"
QT_MOC_LITERAL(10, 171, 3), // "WId"
QT_MOC_LITERAL(11, 175, 19), // "clonedSessionSignal"
QT_MOC_LITERAL(12, 195, 26), // "getSchemasWithTablesSignal"
QT_MOC_LITERAL(13, 222, 26), // "gotSchemasWithTablesSignal"
QT_MOC_LITERAL(14, 249, 25), // "getSchemasWithViewsSignal"
QT_MOC_LITERAL(15, 275, 25), // "gotSchemasWithViewsSignal"
QT_MOC_LITERAL(16, 301, 28), // "getSchemasWithProgramsSignal"
QT_MOC_LITERAL(17, 330, 28), // "gotSchemasWithProgramsSignal"
QT_MOC_LITERAL(18, 359, 23), // "getSchemasWithEtcSignal"
QT_MOC_LITERAL(19, 383, 23), // "gotSchemasWithEtcSignal"
QT_MOC_LITERAL(20, 407, 23), // "getTablesOfSchemaSignal"
QT_MOC_LITERAL(21, 431, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(22, 448, 23), // "gotTablesOfSchemaSignal"
QT_MOC_LITERAL(23, 472, 22), // "getViewsOfSchemaSignal"
QT_MOC_LITERAL(24, 495, 22), // "gotViewsOfSchemaSignal"
QT_MOC_LITERAL(25, 518, 29), // "getProgramTypesOfSchemaSignal"
QT_MOC_LITERAL(26, 548, 29), // "gotProgramTypesOfSchemaSignal"
QT_MOC_LITERAL(27, 578, 25), // "getProgramsOfSchemaSignal"
QT_MOC_LITERAL(28, 604, 25), // "gotProgramsOfSchemaSignal"
QT_MOC_LITERAL(29, 630, 30), // "QList<QPair<QString,QString> >"
QT_MOC_LITERAL(30, 661, 25), // "getEtcTypesOfSchemaSignal"
QT_MOC_LITERAL(31, 687, 25), // "gotEtcTypesOfSchemaSignal"
QT_MOC_LITERAL(32, 713, 20), // "getEtcOfSchemaSignal"
QT_MOC_LITERAL(33, 734, 20), // "gotEtcOfSchemaSignal"
QT_MOC_LITERAL(34, 755, 23), // "closeDbConnectionSignal"
QT_MOC_LITERAL(35, 779, 24), // "closedDbConnectionSignal"
QT_MOC_LITERAL(36, 804, 18), // "executeQuerySignal"
QT_MOC_LITERAL(37, 823, 14), // "sqlStatementId"
QT_MOC_LITERAL(38, 838, 18), // "getSqlBlocksSignal"
QT_MOC_LITERAL(39, 857, 20), // "getNextRecordsSignal"
QT_MOC_LITERAL(40, 878, 10), // "allRecords"
QT_MOC_LITERAL(41, 889, 19), // "executedQuerySignal"
QT_MOC_LITERAL(42, 909, 17), // "QList<QSqlRecord>"
QT_MOC_LITERAL(43, 927, 18), // "gotSqlBlocksSignal"
QT_MOC_LITERAL(44, 946, 28), // "getFindObjectStatementSignal"
QT_MOC_LITERAL(45, 975, 28), // "gotFindObjectStatementSignal"
QT_MOC_LITERAL(46, 1004, 20), // "gotNextRecordsSignal"
QT_MOC_LITERAL(47, 1025, 23), // "commitTransactionSignal"
QT_MOC_LITERAL(48, 1049, 25), // "rollbackTransactionSignal"
QT_MOC_LITERAL(49, 1075, 22), // "getDdlFromObjectSignal"
QT_MOC_LITERAL(50, 1098, 22), // "KvSqlSession::DdlTypes"
QT_MOC_LITERAL(51, 1121, 22), // "gotDdlFromObjectSignal"
QT_MOC_LITERAL(52, 1144, 21), // "getDependentSqlSignal"
QT_MOC_LITERAL(53, 1166, 21), // "gotDependentSqlSignal"
QT_MOC_LITERAL(54, 1188, 33), // "getExtractConsistentDataSqlSi..."
QT_MOC_LITERAL(55, 1222, 33), // "gotExtractConsistentDataSqlSi..."
QT_MOC_LITERAL(56, 1256, 13), // "getPlanSignal"
QT_MOC_LITERAL(57, 1270, 13), // "gotPlanSignal"
QT_MOC_LITERAL(58, 1284, 45), // "QList<QPair<QString,QMap<QStr..."
QT_MOC_LITERAL(59, 1330, 21), // "getExportedDataSignal"
QT_MOC_LITERAL(60, 1352, 21), // "gotExportedDataSignal"
QT_MOC_LITERAL(61, 1374, 28), // "getDatabaseObjectTypesSignal"
QT_MOC_LITERAL(62, 1403, 28), // "gotDatabaseObjectTypesSignal"
QT_MOC_LITERAL(63, 1432, 28), // "getTableAndColumnsInfoSignal"
QT_MOC_LITERAL(64, 1461, 10), // "schemaName"
QT_MOC_LITERAL(65, 1472, 9), // "tableName"
QT_MOC_LITERAL(66, 1482, 28), // "gotTableAndColumnsInfoSignal"
QT_MOC_LITERAL(67, 1511, 11), // "KvTableInfo"
QT_MOC_LITERAL(68, 1523, 19), // "QList<KvColumnInfo>"
QT_MOC_LITERAL(69, 1543, 28), // "QList<KvTableConstraintInfo>"
QT_MOC_LITERAL(70, 1572, 20), // "openDbConnectionSlot"
QT_MOC_LITERAL(71, 1593, 11), // "sessionName"
QT_MOC_LITERAL(72, 1605, 5), // "alias"
QT_MOC_LITERAL(73, 1611, 10), // "connDriver"
QT_MOC_LITERAL(74, 1622, 6), // "connDb"
QT_MOC_LITERAL(75, 1629, 13), // "connDbMachine"
QT_MOC_LITERAL(76, 1643, 8), // "connUser"
QT_MOC_LITERAL(77, 1652, 8), // "connPass"
QT_MOC_LITERAL(78, 1661, 10), // "connDbPort"
QT_MOC_LITERAL(79, 1672, 22), // "openedDbConnectionSlot"
QT_MOC_LITERAL(80, 1695, 5), // "error"
QT_MOC_LITERAL(81, 1701, 16), // "cloneSessionSlot"
QT_MOC_LITERAL(82, 1718, 8), // "windowId"
QT_MOC_LITERAL(83, 1727, 24), // "getSchemasWithTablesSlot"
QT_MOC_LITERAL(84, 1752, 23), // "getSchemasWithViewsSlot"
QT_MOC_LITERAL(85, 1776, 26), // "getSchemasWithProgramsSlot"
QT_MOC_LITERAL(86, 1803, 21), // "getSchemasWithEtcSlot"
QT_MOC_LITERAL(87, 1825, 21), // "getTablesOfSchemaSlot"
QT_MOC_LITERAL(88, 1847, 4), // "item"
QT_MOC_LITERAL(89, 1852, 6), // "schema"
QT_MOC_LITERAL(90, 1859, 20), // "getViewsOfSchemaSlot"
QT_MOC_LITERAL(91, 1880, 27), // "getProgramTypesOfSchemaSlot"
QT_MOC_LITERAL(92, 1908, 23), // "getProgramsOfSchemaSlot"
QT_MOC_LITERAL(93, 1932, 4), // "type"
QT_MOC_LITERAL(94, 1937, 23), // "getEtcTypesOfSchemaSlot"
QT_MOC_LITERAL(95, 1961, 18), // "getEtcOfSchemaSlot"
QT_MOC_LITERAL(96, 1980, 21), // "closeDbConnectionSlot"
QT_MOC_LITERAL(97, 2002, 22), // "closedDbConnectionSlot"
QT_MOC_LITERAL(98, 2025, 17), // "startedThreadSlot"
QT_MOC_LITERAL(99, 2043, 4) // "stop"

    },
    "KvThread\0startedThreadSignal\0\0"
    "openDbConnectionSignal\0openedDbConnectionSignal\0"
    "QSqlError\0getSessionInfoSignal\0"
    "gotSessionInfoSignal\0QMap<QString,QString>\0"
    "cloneSessionSignal\0WId\0clonedSessionSignal\0"
    "getSchemasWithTablesSignal\0"
    "gotSchemasWithTablesSignal\0"
    "getSchemasWithViewsSignal\0"
    "gotSchemasWithViewsSignal\0"
    "getSchemasWithProgramsSignal\0"
    "gotSchemasWithProgramsSignal\0"
    "getSchemasWithEtcSignal\0gotSchemasWithEtcSignal\0"
    "getTablesOfSchemaSignal\0QTreeWidgetItem*\0"
    "gotTablesOfSchemaSignal\0getViewsOfSchemaSignal\0"
    "gotViewsOfSchemaSignal\0"
    "getProgramTypesOfSchemaSignal\0"
    "gotProgramTypesOfSchemaSignal\0"
    "getProgramsOfSchemaSignal\0"
    "gotProgramsOfSchemaSignal\0"
    "QList<QPair<QString,QString> >\0"
    "getEtcTypesOfSchemaSignal\0"
    "gotEtcTypesOfSchemaSignal\0"
    "getEtcOfSchemaSignal\0gotEtcOfSchemaSignal\0"
    "closeDbConnectionSignal\0"
    "closedDbConnectionSignal\0executeQuerySignal\0"
    "sqlStatementId\0getSqlBlocksSignal\0"
    "getNextRecordsSignal\0allRecords\0"
    "executedQuerySignal\0QList<QSqlRecord>\0"
    "gotSqlBlocksSignal\0getFindObjectStatementSignal\0"
    "gotFindObjectStatementSignal\0"
    "gotNextRecordsSignal\0commitTransactionSignal\0"
    "rollbackTransactionSignal\0"
    "getDdlFromObjectSignal\0KvSqlSession::DdlTypes\0"
    "gotDdlFromObjectSignal\0getDependentSqlSignal\0"
    "gotDependentSqlSignal\0"
    "getExtractConsistentDataSqlSignal\0"
    "gotExtractConsistentDataSqlSignal\0"
    "getPlanSignal\0gotPlanSignal\0"
    "QList<QPair<QString,QMap<QString,QString> > >\0"
    "getExportedDataSignal\0gotExportedDataSignal\0"
    "getDatabaseObjectTypesSignal\0"
    "gotDatabaseObjectTypesSignal\0"
    "getTableAndColumnsInfoSignal\0schemaName\0"
    "tableName\0gotTableAndColumnsInfoSignal\0"
    "KvTableInfo\0QList<KvColumnInfo>\0"
    "QList<KvTableConstraintInfo>\0"
    "openDbConnectionSlot\0sessionName\0alias\0"
    "connDriver\0connDb\0connDbMachine\0"
    "connUser\0connPass\0connDbPort\0"
    "openedDbConnectionSlot\0error\0"
    "cloneSessionSlot\0windowId\0"
    "getSchemasWithTablesSlot\0"
    "getSchemasWithViewsSlot\0"
    "getSchemasWithProgramsSlot\0"
    "getSchemasWithEtcSlot\0getTablesOfSchemaSlot\0"
    "item\0schema\0getViewsOfSchemaSlot\0"
    "getProgramTypesOfSchemaSlot\0"
    "getProgramsOfSchemaSlot\0type\0"
    "getEtcTypesOfSchemaSlot\0getEtcOfSchemaSlot\0"
    "closeDbConnectionSlot\0closedDbConnectionSlot\0"
    "startedThreadSlot\0stop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KvThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      77,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      60,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  399,    2, 0x06 /* Public */,
       3,    7,  402,    2, 0x06 /* Public */,
       4,    4,  417,    2, 0x06 /* Public */,
       6,    1,  426,    2, 0x06 /* Public */,
       7,    2,  429,    2, 0x06 /* Public */,
       9,    2,  434,    2, 0x06 /* Public */,
      11,    8,  439,    2, 0x06 /* Public */,
      12,    1,  456,    2, 0x06 /* Public */,
      13,    3,  459,    2, 0x06 /* Public */,
      14,    1,  466,    2, 0x06 /* Public */,
      15,    3,  469,    2, 0x06 /* Public */,
      16,    1,  476,    2, 0x06 /* Public */,
      17,    3,  479,    2, 0x06 /* Public */,
      18,    1,  486,    2, 0x06 /* Public */,
      19,    3,  489,    2, 0x06 /* Public */,
      20,    3,  496,    2, 0x06 /* Public */,
      22,    3,  503,    2, 0x06 /* Public */,
      23,    3,  510,    2, 0x06 /* Public */,
      24,    3,  517,    2, 0x06 /* Public */,
      25,    3,  524,    2, 0x06 /* Public */,
      26,    3,  531,    2, 0x06 /* Public */,
      27,    4,  538,    2, 0x06 /* Public */,
      28,    4,  547,    2, 0x06 /* Public */,
      30,    3,  556,    2, 0x06 /* Public */,
      31,    3,  563,    2, 0x06 /* Public */,
      32,    4,  570,    2, 0x06 /* Public */,
      33,    4,  579,    2, 0x06 /* Public */,
      34,    1,  588,    2, 0x06 /* Public */,
      35,    1,  591,    2, 0x06 /* Public */,
      36,    2,  594,    2, 0x06 /* Public */,
      36,    1,  599,    2, 0x26 /* Public | MethodCloned */,
      38,    3,  602,    2, 0x06 /* Public */,
      39,    4,  609,    2, 0x06 /* Public */,
      39,    3,  618,    2, 0x26 /* Public | MethodCloned */,
      39,    2,  625,    2, 0x26 /* Public | MethodCloned */,
      41,    5,  630,    2, 0x06 /* Public */,
      41,    4,  641,    2, 0x26 /* Public | MethodCloned */,
      43,    3,  650,    2, 0x06 /* Public */,
      44,    2,  657,    2, 0x06 /* Public */,
      44,    1,  662,    2, 0x26 /* Public | MethodCloned */,
      45,    2,  665,    2, 0x06 /* Public */,
      46,    6,  670,    2, 0x06 /* Public */,
      46,    5,  683,    2, 0x26 /* Public | MethodCloned */,
      46,    4,  694,    2, 0x26 /* Public | MethodCloned */,
      47,    0,  703,    2, 0x06 /* Public */,
      48,    0,  704,    2, 0x06 /* Public */,
      49,    5,  705,    2, 0x06 /* Public */,
      51,    7,  716,    2, 0x06 /* Public */,
      52,    1,  731,    2, 0x06 /* Public */,
      53,    2,  734,    2, 0x06 /* Public */,
      54,    1,  739,    2, 0x06 /* Public */,
      55,    2,  742,    2, 0x06 /* Public */,
      56,    2,  747,    2, 0x06 /* Public */,
      57,    3,  752,    2, 0x06 /* Public */,
      59,    4,  759,    2, 0x06 /* Public */,
      60,    7,  768,    2, 0x06 /* Public */,
      61,    0,  783,    2, 0x06 /* Public */,
      62,    2,  784,    2, 0x06 /* Public */,
      63,    2,  789,    2, 0x06 /* Public */,
      66,    5,  794,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      70,    8,  805,    2, 0x0a /* Public */,
      79,    4,  822,    2, 0x0a /* Public */,
      81,    2,  831,    2, 0x0a /* Public */,
      83,    1,  836,    2, 0x0a /* Public */,
      84,    1,  839,    2, 0x0a /* Public */,
      85,    1,  842,    2, 0x0a /* Public */,
      86,    1,  845,    2, 0x0a /* Public */,
      87,    3,  848,    2, 0x0a /* Public */,
      90,    3,  855,    2, 0x0a /* Public */,
      91,    3,  862,    2, 0x0a /* Public */,
      92,    4,  869,    2, 0x0a /* Public */,
      94,    3,  878,    2, 0x0a /* Public */,
      95,    4,  885,    2, 0x0a /* Public */,
      96,    1,  894,    2, 0x0a /* Public */,
      97,    1,  897,    2, 0x0a /* Public */,
      98,    0,  900,    2, 0x0a /* Public */,
      99,    0,  901,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 5,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8,    2,    2,
    QMetaType::Void, 0x80000000 | 10, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 10, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QString, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QString, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QString, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QString, QMetaType::QString, 0x80000000 | 29,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QString, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QString, QMetaType::QString, 0x80000000 | 29,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,   37,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Bool, QMetaType::QString,    2,    2,   40,   37,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Bool,    2,    2,   40,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 42, QMetaType::Int, 0x80000000 | 5, QMetaType::QString,    2,    2,    2,    2,   37,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 42, QMetaType::Int, 0x80000000 | 5,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 42, QMetaType::Int, 0x80000000 | 5, QMetaType::Bool, QMetaType::QString,    2,    2,    2,    2,   40,   37,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 42, QMetaType::Int, 0x80000000 | 5, QMetaType::Bool,    2,    2,    2,    2,   40,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 42, QMetaType::Int, 0x80000000 | 5,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, 0x80000000 | 50,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QStringList, 0x80000000 | 50,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 58,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   64,   65,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 67, 0x80000000 | 68, 0x80000000 | 69,    2,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,   71,   72,   73,   74,   75,   76,   77,   78,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 5,   71,   76,   74,   80,
    QMetaType::Void, 0x80000000 | 10, QMetaType::QString,   82,   71,
    QMetaType::Void, QMetaType::QString,   71,
    QMetaType::Void, QMetaType::QString,   71,
    QMetaType::Void, QMetaType::QString,   71,
    QMetaType::Void, QMetaType::QString,   71,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QString, QMetaType::QString,   88,   71,   89,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QString, QMetaType::QString,   88,   71,   89,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QString, QMetaType::QString,   88,   71,   89,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QString, QMetaType::QString, QMetaType::QString,   88,   71,   89,   93,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QString, QMetaType::QString,   88,   71,   89,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QString, QMetaType::QString, QMetaType::QString,   88,   71,   89,   93,
    QMetaType::Void, QMetaType::QString,   71,
    QMetaType::Void, QMetaType::QString,   71,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void KvThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KvThread *_t = static_cast<KvThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startedThreadSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->openDbConnectionSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 2: _t->openedDbConnectionSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4]))); break;
        case 3: _t->getSessionInfoSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->gotSessionInfoSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[2]))); break;
        case 5: _t->cloneSessionSignal((*reinterpret_cast< WId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->clonedSessionSignal((*reinterpret_cast< WId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8]))); break;
        case 7: _t->getSchemasWithTablesSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->gotSchemasWithTablesSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 9: _t->getSchemasWithViewsSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->gotSchemasWithViewsSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 11: _t->getSchemasWithProgramsSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->gotSchemasWithProgramsSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 13: _t->getSchemasWithEtcSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->gotSchemasWithEtcSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 15: _t->getTablesOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 16: _t->gotTablesOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 17: _t->getViewsOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 18: _t->gotViewsOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 19: _t->getProgramTypesOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 20: _t->gotProgramTypesOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 21: _t->getProgramsOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 22: _t->gotProgramsOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QList<QPair<QString,QString> >(*)>(_a[4]))); break;
        case 23: _t->getEtcTypesOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 24: _t->gotEtcTypesOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 25: _t->getEtcOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 26: _t->gotEtcOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QList<QPair<QString,QString> >(*)>(_a[4]))); break;
        case 27: _t->closeDbConnectionSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: _t->closedDbConnectionSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: _t->executeQuerySignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 30: _t->executeQuerySignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 31: _t->getSqlBlocksSignal((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 32: _t->getNextRecordsSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 33: _t->getNextRecordsSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 34: _t->getNextRecordsSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 35: _t->executedQuerySignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 36: _t->executedQuerySignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4]))); break;
        case 37: _t->gotSqlBlocksSignal((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 38: _t->getFindObjectStatementSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 39: _t->getFindObjectStatementSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 40: _t->gotFindObjectStatementSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 41: _t->gotNextRecordsSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 42: _t->gotNextRecordsSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 43: _t->gotNextRecordsSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4]))); break;
        case 44: _t->commitTransactionSignal(); break;
        case 45: _t->rollbackTransactionSignal(); break;
        case 46: _t->getDdlFromObjectSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< KvSqlSession::DdlTypes(*)>(_a[5]))); break;
        case 47: _t->gotDdlFromObjectSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< QStringList(*)>(_a[6])),(*reinterpret_cast< KvSqlSession::DdlTypes(*)>(_a[7]))); break;
        case 48: _t->getDependentSqlSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 49: _t->gotDependentSqlSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 50: _t->getExtractConsistentDataSqlSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 51: _t->gotExtractConsistentDataSqlSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 52: _t->getPlanSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 53: _t->gotPlanSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QList<QPair<QString,QMap<QString,QString> > >(*)>(_a[3]))); break;
        case 54: _t->getExportedDataSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 55: _t->gotExportedDataSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7]))); break;
        case 56: _t->getDatabaseObjectTypesSignal(); break;
        case 57: _t->gotDatabaseObjectTypesSignal((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 58: _t->getTableAndColumnsInfoSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 59: _t->gotTableAndColumnsInfoSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< KvTableInfo(*)>(_a[3])),(*reinterpret_cast< QList<KvColumnInfo>(*)>(_a[4])),(*reinterpret_cast< QList<KvTableConstraintInfo>(*)>(_a[5]))); break;
        case 60: _t->openDbConnectionSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 61: _t->openedDbConnectionSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4]))); break;
        case 62: _t->cloneSessionSlot((*reinterpret_cast< WId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 63: _t->getSchemasWithTablesSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 64: _t->getSchemasWithViewsSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 65: _t->getSchemasWithProgramsSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 66: _t->getSchemasWithEtcSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 67: _t->getTablesOfSchemaSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 68: _t->getViewsOfSchemaSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 69: _t->getProgramTypesOfSchemaSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 70: _t->getProgramsOfSchemaSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 71: _t->getEtcTypesOfSchemaSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 72: _t->getEtcOfSchemaSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 73: _t->closeDbConnectionSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 74: _t->closedDbConnectionSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 75: _t->startedThreadSlot(); break;
        case 76: _t->stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KvThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::startedThreadSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QString , QString , QString , QString , QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::openDbConnectionSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QString , QString , QSqlError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::openedDbConnectionSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getSessionInfoSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QMap<QString,QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotSessionInfoSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(WId , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::cloneSessionSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(WId , QString , QString , QString , int , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::clonedSessionSignal)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getSchemasWithTablesSignal)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotSchemasWithTablesSignal)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getSchemasWithViewsSignal)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotSchemasWithViewsSignal)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getSchemasWithProgramsSignal)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotSchemasWithProgramsSignal)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getSchemasWithEtcSignal)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotSchemasWithEtcSignal)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QTreeWidgetItem * , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getTablesOfSchemaSignal)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QTreeWidgetItem * , QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotTablesOfSchemaSignal)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QTreeWidgetItem * , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getViewsOfSchemaSignal)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QTreeWidgetItem * , QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotViewsOfSchemaSignal)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QTreeWidgetItem * , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getProgramTypesOfSchemaSignal)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QTreeWidgetItem * , QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotProgramTypesOfSchemaSignal)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QTreeWidgetItem * , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getProgramsOfSchemaSignal)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QTreeWidgetItem * , QString , QString , QList<QPair<QString,QString> > );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotProgramsOfSchemaSignal)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QTreeWidgetItem * , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getEtcTypesOfSchemaSignal)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QTreeWidgetItem * , QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotEtcTypesOfSchemaSignal)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QTreeWidgetItem * , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getEtcOfSchemaSignal)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QTreeWidgetItem * , QString , QString , QList<QPair<QString,QString> > );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotEtcOfSchemaSignal)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::closeDbConnectionSignal)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::closedDbConnectionSignal)) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::executeQuerySignal)) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QStringList , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getSqlBlocksSignal)) {
                *result = 31;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , int , bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getNextRecordsSignal)) {
                *result = 32;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QList<QSqlRecord> , int , QSqlError , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::executedQuerySignal)) {
                *result = 35;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QStringList , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotSqlBlocksSignal)) {
                *result = 37;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getFindObjectStatementSignal)) {
                *result = 38;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotFindObjectStatementSignal)) {
                *result = 40;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QList<QSqlRecord> , int , QSqlError , bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotNextRecordsSignal)) {
                *result = 41;
                return;
            }
        }
        {
            using _t = void (KvThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::commitTransactionSignal)) {
                *result = 44;
                return;
            }
        }
        {
            using _t = void (KvThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::rollbackTransactionSignal)) {
                *result = 45;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QString , QString , bool , KvSqlSession::DdlTypes );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getDdlFromObjectSignal)) {
                *result = 46;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QString , QString , QString , bool , QStringList , KvSqlSession::DdlTypes );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotDdlFromObjectSignal)) {
                *result = 47;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getDependentSqlSignal)) {
                *result = 48;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotDependentSqlSignal)) {
                *result = 49;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getExtractConsistentDataSqlSignal)) {
                *result = 50;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotExtractConsistentDataSqlSignal)) {
                *result = 51;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getPlanSignal)) {
                *result = 52;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QString , QList<QPair<QString,QMap<QString,QString> > > );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotPlanSignal)) {
                *result = 53;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QString , bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getExportedDataSignal)) {
                *result = 54;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QString , QString , bool , QString , bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotExportedDataSignal)) {
                *result = 55;
                return;
            }
        }
        {
            using _t = void (KvThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getDatabaseObjectTypesSignal)) {
                *result = 56;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QStringList , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotDatabaseObjectTypesSignal)) {
                *result = 57;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::getTableAndColumnsInfoSignal)) {
                *result = 58;
                return;
            }
        }
        {
            using _t = void (KvThread::*)(QString , QString , KvTableInfo , QList<KvColumnInfo> , QList<KvTableConstraintInfo> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThread::gotTableAndColumnsInfoSignal)) {
                *result = 59;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KvThread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_KvThread.data,
    qt_meta_data_KvThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KvThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KvThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KvThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int KvThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 77)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 77;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 77)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 77;
    }
    return _id;
}

// SIGNAL 0
void KvThread::startedThreadSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KvThread::openDbConnectionSignal(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5, QString _t6, int _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KvThread::openedDbConnectionSignal(QString _t1, QString _t2, QString _t3, QSqlError _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void KvThread::getSessionInfoSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void KvThread::gotSessionInfoSignal(QString _t1, QMap<QString,QString> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void KvThread::cloneSessionSignal(WId _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void KvThread::clonedSessionSignal(WId _t1, QString _t2, QString _t3, QString _t4, int _t5, QString _t6, QString _t7, QString _t8)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void KvThread::getSchemasWithTablesSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void KvThread::gotSchemasWithTablesSignal(QString _t1, QString _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void KvThread::getSchemasWithViewsSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void KvThread::gotSchemasWithViewsSignal(QString _t1, QString _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void KvThread::getSchemasWithProgramsSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void KvThread::gotSchemasWithProgramsSignal(QString _t1, QString _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void KvThread::getSchemasWithEtcSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void KvThread::gotSchemasWithEtcSignal(QString _t1, QString _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void KvThread::getTablesOfSchemaSignal(QTreeWidgetItem * _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void KvThread::gotTablesOfSchemaSignal(QTreeWidgetItem * _t1, QString _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void KvThread::getViewsOfSchemaSignal(QTreeWidgetItem * _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void KvThread::gotViewsOfSchemaSignal(QTreeWidgetItem * _t1, QString _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void KvThread::getProgramTypesOfSchemaSignal(QTreeWidgetItem * _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void KvThread::gotProgramTypesOfSchemaSignal(QTreeWidgetItem * _t1, QString _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void KvThread::getProgramsOfSchemaSignal(QTreeWidgetItem * _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void KvThread::gotProgramsOfSchemaSignal(QTreeWidgetItem * _t1, QString _t2, QString _t3, QList<QPair<QString,QString> > _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void KvThread::getEtcTypesOfSchemaSignal(QTreeWidgetItem * _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void KvThread::gotEtcTypesOfSchemaSignal(QTreeWidgetItem * _t1, QString _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void KvThread::getEtcOfSchemaSignal(QTreeWidgetItem * _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void KvThread::gotEtcOfSchemaSignal(QTreeWidgetItem * _t1, QString _t2, QString _t3, QList<QPair<QString,QString> > _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void KvThread::closeDbConnectionSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void KvThread::closedDbConnectionSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void KvThread::executeQuerySignal(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 31
void KvThread::getSqlBlocksSignal(QStringList _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void KvThread::getNextRecordsSignal(QString _t1, int _t2, bool _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 35
void KvThread::executedQuerySignal(QString _t1, QList<QSqlRecord> _t2, int _t3, QSqlError _t4, QString _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 35, _a);
}

// SIGNAL 37
void KvThread::gotSqlBlocksSignal(QStringList _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 37, _a);
}

// SIGNAL 38
void KvThread::getFindObjectStatementSignal(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 38, _a);
}

// SIGNAL 40
void KvThread::gotFindObjectStatementSignal(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 40, _a);
}

// SIGNAL 41
void KvThread::gotNextRecordsSignal(QString _t1, QList<QSqlRecord> _t2, int _t3, QSqlError _t4, bool _t5, QString _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 41, _a);
}

// SIGNAL 44
void KvThread::commitTransactionSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 44, nullptr);
}

// SIGNAL 45
void KvThread::rollbackTransactionSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 45, nullptr);
}

// SIGNAL 46
void KvThread::getDdlFromObjectSignal(QString _t1, QString _t2, QString _t3, bool _t4, KvSqlSession::DdlTypes _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 46, _a);
}

// SIGNAL 47
void KvThread::gotDdlFromObjectSignal(QString _t1, QString _t2, QString _t3, QString _t4, bool _t5, QStringList _t6, KvSqlSession::DdlTypes _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 47, _a);
}

// SIGNAL 48
void KvThread::getDependentSqlSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 48, _a);
}

// SIGNAL 49
void KvThread::gotDependentSqlSignal(QString _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 49, _a);
}

// SIGNAL 50
void KvThread::getExtractConsistentDataSqlSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 50, _a);
}

// SIGNAL 51
void KvThread::gotExtractConsistentDataSqlSignal(QString _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 51, _a);
}

// SIGNAL 52
void KvThread::getPlanSignal(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 52, _a);
}

// SIGNAL 53
void KvThread::gotPlanSignal(QString _t1, QString _t2, QList<QPair<QString,QMap<QString,QString> > > _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 53, _a);
}

// SIGNAL 54
void KvThread::getExportedDataSignal(QString _t1, QString _t2, bool _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 54, _a);
}

// SIGNAL 55
void KvThread::gotExportedDataSignal(QString _t1, QString _t2, QString _t3, bool _t4, QString _t5, bool _t6, QString _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 55, _a);
}

// SIGNAL 56
void KvThread::getDatabaseObjectTypesSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 56, nullptr);
}

// SIGNAL 57
void KvThread::gotDatabaseObjectTypesSignal(QStringList _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 57, _a);
}

// SIGNAL 58
void KvThread::getTableAndColumnsInfoSignal(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 58, _a);
}

// SIGNAL 59
void KvThread::gotTableAndColumnsInfoSignal(QString _t1, QString _t2, KvTableInfo _t3, QList<KvColumnInfo> _t4, QList<KvTableConstraintInfo> _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 59, _a);
}
struct qt_meta_stringdata_KvThreadWorker_t {
    QByteArrayData data[91];
    char stringdata0[1731];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KvThreadWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KvThreadWorker_t qt_meta_stringdata_KvThreadWorker = {
    {
QT_MOC_LITERAL(0, 0, 14), // "KvThreadWorker"
QT_MOC_LITERAL(1, 15, 24), // "openedDbConnectionSignal"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 9), // "QSqlError"
QT_MOC_LITERAL(4, 51, 19), // "clonedSessionSignal"
QT_MOC_LITERAL(5, 71, 3), // "WId"
QT_MOC_LITERAL(6, 75, 20), // "gotSessionInfoSignal"
QT_MOC_LITERAL(7, 96, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(8, 118, 26), // "gotSchemasWithTablesSignal"
QT_MOC_LITERAL(9, 145, 25), // "gotSchemasWithViewsSignal"
QT_MOC_LITERAL(10, 171, 28), // "gotSchemasWithProgramsSignal"
QT_MOC_LITERAL(11, 200, 23), // "gotSchemasWithEtcSignal"
QT_MOC_LITERAL(12, 224, 23), // "gotTablesOfSchemaSignal"
QT_MOC_LITERAL(13, 248, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(14, 265, 22), // "gotViewsOfSchemaSignal"
QT_MOC_LITERAL(15, 288, 29), // "gotProgramTypesOfSchemaSignal"
QT_MOC_LITERAL(16, 318, 25), // "gotProgramsOfSchemaSignal"
QT_MOC_LITERAL(17, 344, 30), // "QList<QPair<QString,QString> >"
QT_MOC_LITERAL(18, 375, 25), // "gotEtcTypesOfSchemaSignal"
QT_MOC_LITERAL(19, 401, 20), // "gotEtcOfSchemaSignal"
QT_MOC_LITERAL(20, 422, 24), // "closedDbConnectionSignal"
QT_MOC_LITERAL(21, 447, 19), // "executedQuerySignal"
QT_MOC_LITERAL(22, 467, 17), // "QList<QSqlRecord>"
QT_MOC_LITERAL(23, 485, 14), // "sqlStatementId"
QT_MOC_LITERAL(24, 500, 18), // "gotSqlBlocksSignal"
QT_MOC_LITERAL(25, 519, 28), // "gotFindObjectStatementSignal"
QT_MOC_LITERAL(26, 548, 20), // "gotNextRecordsSignal"
QT_MOC_LITERAL(27, 569, 10), // "allRecords"
QT_MOC_LITERAL(28, 580, 22), // "gotDdlFromObjectSignal"
QT_MOC_LITERAL(29, 603, 22), // "KvSqlSession::DdlTypes"
QT_MOC_LITERAL(30, 626, 33), // "gotExtractConsistentDataSqlSi..."
QT_MOC_LITERAL(31, 660, 21), // "gotDependentSqlSignal"
QT_MOC_LITERAL(32, 682, 13), // "gotPlanSignal"
QT_MOC_LITERAL(33, 696, 45), // "QList<QPair<QString,QMap<QStr..."
QT_MOC_LITERAL(34, 742, 21), // "gotExportedDataSignal"
QT_MOC_LITERAL(35, 764, 28), // "gotDatabaseObjectTypesSignal"
QT_MOC_LITERAL(36, 793, 28), // "gotTableAndColumnsInfoSignal"
QT_MOC_LITERAL(37, 822, 11), // "KvTableInfo"
QT_MOC_LITERAL(38, 834, 19), // "QList<KvColumnInfo>"
QT_MOC_LITERAL(39, 854, 28), // "QList<KvTableConstraintInfo>"
QT_MOC_LITERAL(40, 883, 20), // "openDbConnectionSlot"
QT_MOC_LITERAL(41, 904, 7), // "session"
QT_MOC_LITERAL(42, 912, 10), // "connDriver"
QT_MOC_LITERAL(43, 923, 6), // "connDb"
QT_MOC_LITERAL(44, 930, 13), // "connDbMachine"
QT_MOC_LITERAL(45, 944, 8), // "connUser"
QT_MOC_LITERAL(46, 953, 8), // "connPass"
QT_MOC_LITERAL(47, 962, 10), // "connDbPort"
QT_MOC_LITERAL(48, 973, 16), // "cloneSessionSlot"
QT_MOC_LITERAL(49, 990, 8), // "windowId"
QT_MOC_LITERAL(50, 999, 11), // "sessionName"
QT_MOC_LITERAL(51, 1011, 18), // "getSessionInfoSlot"
QT_MOC_LITERAL(52, 1030, 24), // "getSchemasWithTablesSlot"
QT_MOC_LITERAL(53, 1055, 23), // "getSchemasWithViewsSlot"
QT_MOC_LITERAL(54, 1079, 26), // "getSchemasWithProgramsSlot"
QT_MOC_LITERAL(55, 1106, 21), // "getSchemasWithEtcSlot"
QT_MOC_LITERAL(56, 1128, 21), // "getTablesOfSchemaSlot"
QT_MOC_LITERAL(57, 1150, 4), // "item"
QT_MOC_LITERAL(58, 1155, 6), // "schema"
QT_MOC_LITERAL(59, 1162, 20), // "getViewsOfSchemaSlot"
QT_MOC_LITERAL(60, 1183, 27), // "getProgramTypesOfSchemaSlot"
QT_MOC_LITERAL(61, 1211, 23), // "getProgramsOfSchemaSlot"
QT_MOC_LITERAL(62, 1235, 4), // "type"
QT_MOC_LITERAL(63, 1240, 23), // "getEtcTypesOfSchemaSlot"
QT_MOC_LITERAL(64, 1264, 18), // "getEtcOfSchemaSlot"
QT_MOC_LITERAL(65, 1283, 21), // "closeDbConnectionSlot"
QT_MOC_LITERAL(66, 1305, 16), // "executeQuerySlot"
QT_MOC_LITERAL(67, 1322, 12), // "sqlStatement"
QT_MOC_LITERAL(68, 1335, 16), // "getSqlBlocksSlot"
QT_MOC_LITERAL(69, 1352, 8), // "sqlLines"
QT_MOC_LITERAL(70, 1361, 12), // "fromPosition"
QT_MOC_LITERAL(71, 1374, 10), // "toPosition"
QT_MOC_LITERAL(72, 1385, 26), // "getFindObjectStatementSlot"
QT_MOC_LITERAL(73, 1412, 14), // "fullObjectName"
QT_MOC_LITERAL(74, 1427, 8), // "typeName"
QT_MOC_LITERAL(75, 1436, 18), // "getNextRecordsSlot"
QT_MOC_LITERAL(76, 1455, 16), // "fromRecordNumber"
QT_MOC_LITERAL(77, 1472, 21), // "commitTransactionSlot"
QT_MOC_LITERAL(78, 1494, 23), // "rollbackTransactionSlot"
QT_MOC_LITERAL(79, 1518, 20), // "getDdlFromObjectSlot"
QT_MOC_LITERAL(80, 1539, 10), // "objectName"
QT_MOC_LITERAL(81, 1550, 10), // "objectType"
QT_MOC_LITERAL(82, 1561, 10), // "showSchema"
QT_MOC_LITERAL(83, 1572, 19), // "getDependentSqlSlot"
QT_MOC_LITERAL(84, 1592, 31), // "getExtractConsistentDataSqlSlot"
QT_MOC_LITERAL(85, 1624, 11), // "getPlanSlot"
QT_MOC_LITERAL(86, 1636, 19), // "getExportedDataSlot"
QT_MOC_LITERAL(87, 1656, 9), // "tableName"
QT_MOC_LITERAL(88, 1666, 26), // "getDatabaseObjectTypesSlot"
QT_MOC_LITERAL(89, 1693, 26), // "getTableAndColumnsInfoSlot"
QT_MOC_LITERAL(90, 1720, 10) // "schemaName"

    },
    "KvThreadWorker\0openedDbConnectionSignal\0"
    "\0QSqlError\0clonedSessionSignal\0WId\0"
    "gotSessionInfoSignal\0QMap<QString,QString>\0"
    "gotSchemasWithTablesSignal\0"
    "gotSchemasWithViewsSignal\0"
    "gotSchemasWithProgramsSignal\0"
    "gotSchemasWithEtcSignal\0gotTablesOfSchemaSignal\0"
    "QTreeWidgetItem*\0gotViewsOfSchemaSignal\0"
    "gotProgramTypesOfSchemaSignal\0"
    "gotProgramsOfSchemaSignal\0"
    "QList<QPair<QString,QString> >\0"
    "gotEtcTypesOfSchemaSignal\0"
    "gotEtcOfSchemaSignal\0closedDbConnectionSignal\0"
    "executedQuerySignal\0QList<QSqlRecord>\0"
    "sqlStatementId\0gotSqlBlocksSignal\0"
    "gotFindObjectStatementSignal\0"
    "gotNextRecordsSignal\0allRecords\0"
    "gotDdlFromObjectSignal\0KvSqlSession::DdlTypes\0"
    "gotExtractConsistentDataSqlSignal\0"
    "gotDependentSqlSignal\0gotPlanSignal\0"
    "QList<QPair<QString,QMap<QString,QString> > >\0"
    "gotExportedDataSignal\0"
    "gotDatabaseObjectTypesSignal\0"
    "gotTableAndColumnsInfoSignal\0KvTableInfo\0"
    "QList<KvColumnInfo>\0QList<KvTableConstraintInfo>\0"
    "openDbConnectionSlot\0session\0connDriver\0"
    "connDb\0connDbMachine\0connUser\0connPass\0"
    "connDbPort\0cloneSessionSlot\0windowId\0"
    "sessionName\0getSessionInfoSlot\0"
    "getSchemasWithTablesSlot\0"
    "getSchemasWithViewsSlot\0"
    "getSchemasWithProgramsSlot\0"
    "getSchemasWithEtcSlot\0getTablesOfSchemaSlot\0"
    "item\0schema\0getViewsOfSchemaSlot\0"
    "getProgramTypesOfSchemaSlot\0"
    "getProgramsOfSchemaSlot\0type\0"
    "getEtcTypesOfSchemaSlot\0getEtcOfSchemaSlot\0"
    "closeDbConnectionSlot\0executeQuerySlot\0"
    "sqlStatement\0getSqlBlocksSlot\0sqlLines\0"
    "fromPosition\0toPosition\0"
    "getFindObjectStatementSlot\0fullObjectName\0"
    "typeName\0getNextRecordsSlot\0"
    "fromRecordNumber\0commitTransactionSlot\0"
    "rollbackTransactionSlot\0getDdlFromObjectSlot\0"
    "objectName\0objectType\0showSchema\0"
    "getDependentSqlSlot\0getExtractConsistentDataSqlSlot\0"
    "getPlanSlot\0getExportedDataSlot\0"
    "tableName\0getDatabaseObjectTypesSlot\0"
    "getTableAndColumnsInfoSlot\0schemaName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KvThreadWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      64,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      28,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,  334,    2, 0x06 /* Public */,
       4,    8,  343,    2, 0x06 /* Public */,
       6,    2,  360,    2, 0x06 /* Public */,
       8,    3,  365,    2, 0x06 /* Public */,
       9,    3,  372,    2, 0x06 /* Public */,
      10,    3,  379,    2, 0x06 /* Public */,
      11,    3,  386,    2, 0x06 /* Public */,
      12,    3,  393,    2, 0x06 /* Public */,
      14,    3,  400,    2, 0x06 /* Public */,
      15,    3,  407,    2, 0x06 /* Public */,
      16,    4,  414,    2, 0x06 /* Public */,
      18,    3,  423,    2, 0x06 /* Public */,
      19,    4,  430,    2, 0x06 /* Public */,
      20,    1,  439,    2, 0x06 /* Public */,
      21,    5,  442,    2, 0x06 /* Public */,
      21,    4,  453,    2, 0x26 /* Public | MethodCloned */,
      24,    3,  462,    2, 0x06 /* Public */,
      25,    2,  469,    2, 0x06 /* Public */,
      26,    6,  474,    2, 0x06 /* Public */,
      26,    5,  487,    2, 0x26 /* Public | MethodCloned */,
      26,    4,  498,    2, 0x26 /* Public | MethodCloned */,
      28,    7,  507,    2, 0x06 /* Public */,
      30,    2,  522,    2, 0x06 /* Public */,
      31,    2,  527,    2, 0x06 /* Public */,
      32,    3,  532,    2, 0x06 /* Public */,
      34,    7,  539,    2, 0x06 /* Public */,
      35,    2,  554,    2, 0x06 /* Public */,
      36,    5,  559,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      40,    7,  570,    2, 0x0a /* Public */,
      48,    2,  585,    2, 0x0a /* Public */,
      51,    1,  590,    2, 0x0a /* Public */,
      52,    1,  593,    2, 0x0a /* Public */,
      53,    1,  596,    2, 0x0a /* Public */,
      54,    1,  599,    2, 0x0a /* Public */,
      55,    1,  602,    2, 0x0a /* Public */,
      56,    3,  605,    2, 0x0a /* Public */,
      59,    3,  612,    2, 0x0a /* Public */,
      60,    3,  619,    2, 0x0a /* Public */,
      61,    4,  626,    2, 0x0a /* Public */,
      63,    3,  635,    2, 0x0a /* Public */,
      64,    4,  642,    2, 0x0a /* Public */,
      65,    1,  651,    2, 0x0a /* Public */,
      66,    2,  654,    2, 0x0a /* Public */,
      66,    1,  659,    2, 0x2a /* Public | MethodCloned */,
      68,    3,  662,    2, 0x0a /* Public */,
      68,    2,  669,    2, 0x2a /* Public | MethodCloned */,
      68,    1,  674,    2, 0x2a /* Public | MethodCloned */,
      72,    2,  677,    2, 0x0a /* Public */,
      72,    1,  682,    2, 0x2a /* Public | MethodCloned */,
      75,    4,  685,    2, 0x0a /* Public */,
      75,    3,  694,    2, 0x2a /* Public | MethodCloned */,
      75,    2,  701,    2, 0x2a /* Public | MethodCloned */,
      77,    0,  706,    2, 0x0a /* Public */,
      78,    0,  707,    2, 0x0a /* Public */,
      79,    5,  708,    2, 0x0a /* Public */,
      79,    4,  719,    2, 0x2a /* Public | MethodCloned */,
      79,    3,  728,    2, 0x2a /* Public | MethodCloned */,
      83,    1,  735,    2, 0x0a /* Public */,
      84,    1,  738,    2, 0x0a /* Public */,
      85,    2,  741,    2, 0x0a /* Public */,
      85,    1,  746,    2, 0x2a /* Public | MethodCloned */,
      86,    4,  749,    2, 0x0a /* Public */,
      88,    0,  758,    2, 0x0a /* Public */,
      89,    2,  759,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 3,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString, QMetaType::QString, 0x80000000 | 17,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString, QMetaType::QString, 0x80000000 | 17,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 22, QMetaType::Int, 0x80000000 | 3, QMetaType::QString,    2,    2,    2,    2,   23,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 22, QMetaType::Int, 0x80000000 | 3,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 22, QMetaType::Int, 0x80000000 | 3, QMetaType::Bool, QMetaType::QString,    2,    2,    2,    2,   27,   23,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 22, QMetaType::Int, 0x80000000 | 3, QMetaType::Bool,    2,    2,    2,    2,   27,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 22, QMetaType::Int, 0x80000000 | 3,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QStringList, 0x80000000 | 29,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 33,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 37, 0x80000000 | 38, 0x80000000 | 39,    2,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,   41,   42,   43,   44,   45,   46,   47,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString,   49,   50,
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString, QMetaType::QString,   57,   41,   58,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString, QMetaType::QString,   57,   41,   58,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString, QMetaType::QString,   57,   41,   58,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString, QMetaType::QString, QMetaType::QString,   57,   41,   58,   62,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString, QMetaType::QString,   57,   41,   58,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString, QMetaType::QString, QMetaType::QString,   57,   41,   58,   62,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   67,   23,
    QMetaType::Void, QMetaType::QString,   67,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int, QMetaType::Int,   69,   70,   71,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int,   69,   70,
    QMetaType::Void, QMetaType::QStringList,   69,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   73,   74,
    QMetaType::Void, QMetaType::QString,   73,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Bool, QMetaType::QString,   67,   76,   27,   23,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Bool,   67,   76,   27,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   67,   76,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, 0x80000000 | 29,   58,   80,   81,   82,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   58,   80,   81,   82,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   58,   80,   81,
    QMetaType::Void, QMetaType::QString,   67,
    QMetaType::Void, QMetaType::QString,   67,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   67,   23,
    QMetaType::Void, QMetaType::QString,   67,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString,   58,   87,   82,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   90,   87,

       0        // eod
};

void KvThreadWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KvThreadWorker *_t = static_cast<KvThreadWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openedDbConnectionSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4]))); break;
        case 1: _t->clonedSessionSignal((*reinterpret_cast< WId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8]))); break;
        case 2: _t->gotSessionInfoSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[2]))); break;
        case 3: _t->gotSchemasWithTablesSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 4: _t->gotSchemasWithViewsSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 5: _t->gotSchemasWithProgramsSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 6: _t->gotSchemasWithEtcSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 7: _t->gotTablesOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 8: _t->gotViewsOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 9: _t->gotProgramTypesOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 10: _t->gotProgramsOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QList<QPair<QString,QString> >(*)>(_a[4]))); break;
        case 11: _t->gotEtcTypesOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 12: _t->gotEtcOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QList<QPair<QString,QString> >(*)>(_a[4]))); break;
        case 13: _t->closedDbConnectionSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->executedQuerySignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 15: _t->executedQuerySignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4]))); break;
        case 16: _t->gotSqlBlocksSignal((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 17: _t->gotFindObjectStatementSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 18: _t->gotNextRecordsSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 19: _t->gotNextRecordsSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 20: _t->gotNextRecordsSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4]))); break;
        case 21: _t->gotDdlFromObjectSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< QStringList(*)>(_a[6])),(*reinterpret_cast< KvSqlSession::DdlTypes(*)>(_a[7]))); break;
        case 22: _t->gotExtractConsistentDataSqlSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 23: _t->gotDependentSqlSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 24: _t->gotPlanSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QList<QPair<QString,QMap<QString,QString> > >(*)>(_a[3]))); break;
        case 25: _t->gotExportedDataSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7]))); break;
        case 26: _t->gotDatabaseObjectTypesSignal((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 27: _t->gotTableAndColumnsInfoSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< KvTableInfo(*)>(_a[3])),(*reinterpret_cast< QList<KvColumnInfo>(*)>(_a[4])),(*reinterpret_cast< QList<KvTableConstraintInfo>(*)>(_a[5]))); break;
        case 28: _t->openDbConnectionSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 29: _t->cloneSessionSlot((*reinterpret_cast< WId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 30: _t->getSessionInfoSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 31: _t->getSchemasWithTablesSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 32: _t->getSchemasWithViewsSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 33: _t->getSchemasWithProgramsSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 34: _t->getSchemasWithEtcSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 35: _t->getTablesOfSchemaSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 36: _t->getViewsOfSchemaSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 37: _t->getProgramTypesOfSchemaSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 38: _t->getProgramsOfSchemaSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 39: _t->getEtcTypesOfSchemaSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 40: _t->getEtcOfSchemaSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 41: _t->closeDbConnectionSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 42: _t->executeQuerySlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 43: _t->executeQuerySlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 44: _t->getSqlBlocksSlot((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 45: _t->getSqlBlocksSlot((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 46: _t->getSqlBlocksSlot((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 47: _t->getFindObjectStatementSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 48: _t->getFindObjectStatementSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 49: _t->getNextRecordsSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 50: _t->getNextRecordsSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 51: _t->getNextRecordsSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 52: _t->commitTransactionSlot(); break;
        case 53: _t->rollbackTransactionSlot(); break;
        case 54: _t->getDdlFromObjectSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< KvSqlSession::DdlTypes(*)>(_a[5]))); break;
        case 55: _t->getDdlFromObjectSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 56: _t->getDdlFromObjectSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 57: _t->getDependentSqlSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 58: _t->getExtractConsistentDataSqlSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 59: _t->getPlanSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 60: _t->getPlanSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 61: _t->getExportedDataSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 62: _t->getDatabaseObjectTypesSlot(); break;
        case 63: _t->getTableAndColumnsInfoSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KvThreadWorker::*)(QString , QString , QString , QSqlError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::openedDbConnectionSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(WId , QString , QString , QString , int , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::clonedSessionSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QString , QMap<QString,QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotSessionInfoSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QString , QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotSchemasWithTablesSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QString , QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotSchemasWithViewsSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QString , QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotSchemasWithProgramsSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QString , QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotSchemasWithEtcSignal)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QTreeWidgetItem * , QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotTablesOfSchemaSignal)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QTreeWidgetItem * , QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotViewsOfSchemaSignal)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QTreeWidgetItem * , QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotProgramTypesOfSchemaSignal)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QTreeWidgetItem * , QString , QString , QList<QPair<QString,QString> > );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotProgramsOfSchemaSignal)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QTreeWidgetItem * , QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotEtcTypesOfSchemaSignal)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QTreeWidgetItem * , QString , QString , QList<QPair<QString,QString> > );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotEtcOfSchemaSignal)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::closedDbConnectionSignal)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QString , QList<QSqlRecord> , int , QSqlError , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::executedQuerySignal)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QStringList , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotSqlBlocksSignal)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotFindObjectStatementSignal)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QString , QList<QSqlRecord> , int , QSqlError , bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotNextRecordsSignal)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QString , QString , QString , QString , bool , QStringList , KvSqlSession::DdlTypes );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotDdlFromObjectSignal)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotExtractConsistentDataSqlSignal)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotDependentSqlSignal)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QString , QString , QList<QPair<QString,QMap<QString,QString> > > );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotPlanSignal)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QString , QString , QString , bool , QString , bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotExportedDataSignal)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QStringList , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotDatabaseObjectTypesSignal)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (KvThreadWorker::*)(QString , QString , KvTableInfo , QList<KvColumnInfo> , QList<KvTableConstraintInfo> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvThreadWorker::gotTableAndColumnsInfoSignal)) {
                *result = 27;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KvThreadWorker::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_KvThreadWorker.data,
    qt_meta_data_KvThreadWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KvThreadWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KvThreadWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KvThreadWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int KvThreadWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 64)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 64;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 64)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 64;
    }
    return _id;
}

// SIGNAL 0
void KvThreadWorker::openedDbConnectionSignal(QString _t1, QString _t2, QString _t3, QSqlError _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KvThreadWorker::clonedSessionSignal(WId _t1, QString _t2, QString _t3, QString _t4, int _t5, QString _t6, QString _t7, QString _t8)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KvThreadWorker::gotSessionInfoSignal(QString _t1, QMap<QString,QString> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void KvThreadWorker::gotSchemasWithTablesSignal(QString _t1, QString _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void KvThreadWorker::gotSchemasWithViewsSignal(QString _t1, QString _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void KvThreadWorker::gotSchemasWithProgramsSignal(QString _t1, QString _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void KvThreadWorker::gotSchemasWithEtcSignal(QString _t1, QString _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void KvThreadWorker::gotTablesOfSchemaSignal(QTreeWidgetItem * _t1, QString _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void KvThreadWorker::gotViewsOfSchemaSignal(QTreeWidgetItem * _t1, QString _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void KvThreadWorker::gotProgramTypesOfSchemaSignal(QTreeWidgetItem * _t1, QString _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void KvThreadWorker::gotProgramsOfSchemaSignal(QTreeWidgetItem * _t1, QString _t2, QString _t3, QList<QPair<QString,QString> > _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void KvThreadWorker::gotEtcTypesOfSchemaSignal(QTreeWidgetItem * _t1, QString _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void KvThreadWorker::gotEtcOfSchemaSignal(QTreeWidgetItem * _t1, QString _t2, QString _t3, QList<QPair<QString,QString> > _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void KvThreadWorker::closedDbConnectionSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void KvThreadWorker::executedQuerySignal(QString _t1, QList<QSqlRecord> _t2, int _t3, QSqlError _t4, QString _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 16
void KvThreadWorker::gotSqlBlocksSignal(QStringList _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void KvThreadWorker::gotFindObjectStatementSignal(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void KvThreadWorker::gotNextRecordsSignal(QString _t1, QList<QSqlRecord> _t2, int _t3, QSqlError _t4, bool _t5, QString _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 21
void KvThreadWorker::gotDdlFromObjectSignal(QString _t1, QString _t2, QString _t3, QString _t4, bool _t5, QStringList _t6, KvSqlSession::DdlTypes _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void KvThreadWorker::gotExtractConsistentDataSqlSignal(QString _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void KvThreadWorker::gotDependentSqlSignal(QString _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void KvThreadWorker::gotPlanSignal(QString _t1, QString _t2, QList<QPair<QString,QMap<QString,QString> > > _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void KvThreadWorker::gotExportedDataSignal(QString _t1, QString _t2, QString _t3, bool _t4, QString _t5, bool _t6, QString _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void KvThreadWorker::gotDatabaseObjectTypesSignal(QStringList _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void KvThreadWorker::gotTableAndColumnsInfoSignal(QString _t1, QString _t2, KvTableInfo _t3, QList<KvColumnInfo> _t4, QList<KvTableConstraintInfo> _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
