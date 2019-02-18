/****************************************************************************
** Meta object code from reading C++ file 'kvsqldialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../kvsqldialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kvsqldialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KvSqlDialog_t {
    QByteArrayData data[99];
    char stringdata0[1602];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KvSqlDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KvSqlDialog_t qt_meta_stringdata_KvSqlDialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "KvSqlDialog"
QT_MOC_LITERAL(1, 12, 18), // "cloneSessionSignal"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 3), // "WId"
QT_MOC_LITERAL(4, 36, 22), // "openDbConnectionSignal"
QT_MOC_LITERAL(5, 59, 23), // "closeDbConnectionSignal"
QT_MOC_LITERAL(6, 83, 20), // "getSessionInfoSignal"
QT_MOC_LITERAL(7, 104, 18), // "executeQuerySignal"
QT_MOC_LITERAL(8, 123, 14), // "sqlStatementId"
QT_MOC_LITERAL(9, 138, 18), // "getSqlBlocksSignal"
QT_MOC_LITERAL(10, 157, 12), // "fromPosition"
QT_MOC_LITERAL(11, 170, 10), // "toPosition"
QT_MOC_LITERAL(12, 181, 28), // "getFindObjectStatementSignal"
QT_MOC_LITERAL(13, 210, 20), // "getNextRecordsSignal"
QT_MOC_LITERAL(14, 231, 10), // "allRecords"
QT_MOC_LITERAL(15, 242, 23), // "commitTransactionSignal"
QT_MOC_LITERAL(16, 266, 25), // "rollbackTransactionSignal"
QT_MOC_LITERAL(17, 292, 22), // "getDdlFromObjectSignal"
QT_MOC_LITERAL(18, 315, 22), // "KvSqlSession::DdlTypes"
QT_MOC_LITERAL(19, 338, 21), // "getDependentSqlSignal"
QT_MOC_LITERAL(20, 360, 33), // "getExtractConsistentDataSqlSi..."
QT_MOC_LITERAL(21, 394, 13), // "getPlanSignal"
QT_MOC_LITERAL(22, 408, 21), // "getExportedDataSignal"
QT_MOC_LITERAL(23, 430, 28), // "getDatabaseObjectTypesSignal"
QT_MOC_LITERAL(24, 459, 28), // "getTableAndColumnsInfoSignal"
QT_MOC_LITERAL(25, 488, 10), // "schemaName"
QT_MOC_LITERAL(26, 499, 9), // "tableName"
QT_MOC_LITERAL(27, 509, 20), // "deleteTempThreadSlot"
QT_MOC_LITERAL(28, 530, 17), // "setActiveSessions"
QT_MOC_LITERAL(29, 548, 12), // "sessionNames"
QT_MOC_LITERAL(30, 561, 17), // "setCurrentSession"
QT_MOC_LITERAL(31, 579, 11), // "sessionName"
QT_MOC_LITERAL(32, 591, 16), // "addActiveSession"
QT_MOC_LITERAL(33, 608, 19), // "removeActiveSession"
QT_MOC_LITERAL(34, 628, 17), // "clonedSessionSlot"
QT_MOC_LITERAL(35, 646, 8), // "windowId"
QT_MOC_LITERAL(36, 655, 6), // "driver"
QT_MOC_LITERAL(37, 662, 8), // "hostName"
QT_MOC_LITERAL(38, 671, 4), // "port"
QT_MOC_LITERAL(39, 676, 12), // "databaseName"
QT_MOC_LITERAL(40, 689, 8), // "userName"
QT_MOC_LITERAL(41, 698, 8), // "password"
QT_MOC_LITERAL(42, 707, 22), // "openedDbConnectionSlot"
QT_MOC_LITERAL(43, 730, 8), // "connUser"
QT_MOC_LITERAL(44, 739, 6), // "connDb"
QT_MOC_LITERAL(45, 746, 9), // "QSqlError"
QT_MOC_LITERAL(46, 756, 5), // "error"
QT_MOC_LITERAL(47, 762, 22), // "closedDbConnectionSlot"
QT_MOC_LITERAL(48, 785, 18), // "gotSessionInfoSlot"
QT_MOC_LITERAL(49, 804, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(50, 826, 4), // "info"
QT_MOC_LITERAL(51, 831, 17), // "executedQuerySlot"
QT_MOC_LITERAL(52, 849, 12), // "sqlStatement"
QT_MOC_LITERAL(53, 862, 17), // "QList<QSqlRecord>"
QT_MOC_LITERAL(54, 880, 7), // "records"
QT_MOC_LITERAL(55, 888, 11), // "recordCount"
QT_MOC_LITERAL(56, 900, 16), // "gotSqlBlocksSlot"
QT_MOC_LITERAL(57, 917, 9), // "sqlBlocks"
QT_MOC_LITERAL(58, 927, 26), // "gotFindObjectStatementSlot"
QT_MOC_LITERAL(59, 954, 14), // "fullObjectName"
QT_MOC_LITERAL(60, 969, 9), // "statement"
QT_MOC_LITERAL(61, 979, 18), // "gotNextRecordsSlot"
QT_MOC_LITERAL(62, 998, 20), // "getDdlFromObjectSlot"
QT_MOC_LITERAL(63, 1019, 6), // "schema"
QT_MOC_LITERAL(64, 1026, 10), // "objectName"
QT_MOC_LITERAL(65, 1037, 10), // "objectType"
QT_MOC_LITERAL(66, 1048, 10), // "showSchema"
QT_MOC_LITERAL(67, 1059, 7), // "ddlType"
QT_MOC_LITERAL(68, 1067, 20), // "gotDdlFromObjectSlot"
QT_MOC_LITERAL(69, 1088, 6), // "result"
QT_MOC_LITERAL(70, 1095, 19), // "getDependentSqlSlot"
QT_MOC_LITERAL(71, 1115, 19), // "gotDependentSqlSlot"
QT_MOC_LITERAL(72, 1135, 22), // "dependentSqlStatements"
QT_MOC_LITERAL(73, 1158, 31), // "gotExtractConsistentDataSqlSlot"
QT_MOC_LITERAL(74, 1190, 23), // "consistentSqlStatements"
QT_MOC_LITERAL(75, 1214, 11), // "getPlanSlot"
QT_MOC_LITERAL(76, 1226, 11), // "gotPlanSlot"
QT_MOC_LITERAL(77, 1238, 45), // "QList<QPair<QString,QMap<QStr..."
QT_MOC_LITERAL(78, 1284, 19), // "getExportedDataSlot"
QT_MOC_LITERAL(79, 1304, 19), // "gotExportedDataSlot"
QT_MOC_LITERAL(80, 1324, 10), // "resultLine"
QT_MOC_LITERAL(81, 1335, 8), // "isTheEnd"
QT_MOC_LITERAL(82, 1344, 26), // "gotDatabaseObjectTypesSlot"
QT_MOC_LITERAL(83, 1371, 12), // "objTypeNames"
QT_MOC_LITERAL(84, 1384, 12), // "objTypeOrder"
QT_MOC_LITERAL(85, 1397, 26), // "gotTableAndColumnsInfoSlot"
QT_MOC_LITERAL(86, 1424, 9), // "objSchema"
QT_MOC_LITERAL(87, 1434, 8), // "objTable"
QT_MOC_LITERAL(88, 1443, 11), // "KvTableInfo"
QT_MOC_LITERAL(89, 1455, 9), // "tableInfo"
QT_MOC_LITERAL(90, 1465, 19), // "QList<KvColumnInfo>"
QT_MOC_LITERAL(91, 1485, 7), // "columns"
QT_MOC_LITERAL(92, 1493, 28), // "QList<KvTableConstraintInfo>"
QT_MOC_LITERAL(93, 1522, 11), // "constraints"
QT_MOC_LITERAL(94, 1534, 11), // "getFileName"
QT_MOC_LITERAL(95, 1546, 11), // "setFileName"
QT_MOC_LITERAL(96, 1558, 8), // "fullName"
QT_MOC_LITERAL(97, 1567, 17), // "startedThreadSlot"
QT_MOC_LITERAL(98, 1585, 16) // "deleteThreadSlot"

    },
    "KvSqlDialog\0cloneSessionSignal\0\0WId\0"
    "openDbConnectionSignal\0closeDbConnectionSignal\0"
    "getSessionInfoSignal\0executeQuerySignal\0"
    "sqlStatementId\0getSqlBlocksSignal\0"
    "fromPosition\0toPosition\0"
    "getFindObjectStatementSignal\0"
    "getNextRecordsSignal\0allRecords\0"
    "commitTransactionSignal\0"
    "rollbackTransactionSignal\0"
    "getDdlFromObjectSignal\0KvSqlSession::DdlTypes\0"
    "getDependentSqlSignal\0"
    "getExtractConsistentDataSqlSignal\0"
    "getPlanSignal\0getExportedDataSignal\0"
    "getDatabaseObjectTypesSignal\0"
    "getTableAndColumnsInfoSignal\0schemaName\0"
    "tableName\0deleteTempThreadSlot\0"
    "setActiveSessions\0sessionNames\0"
    "setCurrentSession\0sessionName\0"
    "addActiveSession\0removeActiveSession\0"
    "clonedSessionSlot\0windowId\0driver\0"
    "hostName\0port\0databaseName\0userName\0"
    "password\0openedDbConnectionSlot\0"
    "connUser\0connDb\0QSqlError\0error\0"
    "closedDbConnectionSlot\0gotSessionInfoSlot\0"
    "QMap<QString,QString>\0info\0executedQuerySlot\0"
    "sqlStatement\0QList<QSqlRecord>\0records\0"
    "recordCount\0gotSqlBlocksSlot\0sqlBlocks\0"
    "gotFindObjectStatementSlot\0fullObjectName\0"
    "statement\0gotNextRecordsSlot\0"
    "getDdlFromObjectSlot\0schema\0objectName\0"
    "objectType\0showSchema\0ddlType\0"
    "gotDdlFromObjectSlot\0result\0"
    "getDependentSqlSlot\0gotDependentSqlSlot\0"
    "dependentSqlStatements\0"
    "gotExtractConsistentDataSqlSlot\0"
    "consistentSqlStatements\0getPlanSlot\0"
    "gotPlanSlot\0QList<QPair<QString,QMap<QString,QString> > >\0"
    "getExportedDataSlot\0gotExportedDataSlot\0"
    "resultLine\0isTheEnd\0gotDatabaseObjectTypesSlot\0"
    "objTypeNames\0objTypeOrder\0"
    "gotTableAndColumnsInfoSlot\0objSchema\0"
    "objTable\0KvTableInfo\0tableInfo\0"
    "QList<KvColumnInfo>\0columns\0"
    "QList<KvTableConstraintInfo>\0constraints\0"
    "getFileName\0setFileName\0fullName\0"
    "startedThreadSlot\0deleteThreadSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KvSqlDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      54,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      23,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  284,    2, 0x06 /* Public */,
       4,    8,  289,    2, 0x06 /* Public */,
       5,    1,  306,    2, 0x06 /* Public */,
       6,    1,  309,    2, 0x06 /* Public */,
       7,    2,  312,    2, 0x06 /* Public */,
       7,    1,  317,    2, 0x26 /* Public | MethodCloned */,
       9,    3,  320,    2, 0x06 /* Public */,
       9,    2,  327,    2, 0x26 /* Public | MethodCloned */,
       9,    1,  332,    2, 0x26 /* Public | MethodCloned */,
      12,    2,  335,    2, 0x06 /* Public */,
      12,    1,  340,    2, 0x26 /* Public | MethodCloned */,
      13,    4,  343,    2, 0x06 /* Public */,
      13,    3,  352,    2, 0x26 /* Public | MethodCloned */,
      13,    2,  359,    2, 0x26 /* Public | MethodCloned */,
      15,    0,  364,    2, 0x06 /* Public */,
      16,    0,  365,    2, 0x06 /* Public */,
      17,    5,  366,    2, 0x06 /* Public */,
      19,    1,  377,    2, 0x06 /* Public */,
      20,    1,  380,    2, 0x06 /* Public */,
      21,    2,  383,    2, 0x06 /* Public */,
      22,    4,  388,    2, 0x06 /* Public */,
      23,    0,  397,    2, 0x06 /* Public */,
      24,    2,  398,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      27,    0,  403,    2, 0x0a /* Public */,
      28,    1,  404,    2, 0x0a /* Public */,
      30,    1,  407,    2, 0x0a /* Public */,
      32,    1,  410,    2, 0x0a /* Public */,
      33,    1,  413,    2, 0x0a /* Public */,
      34,    8,  416,    2, 0x0a /* Public */,
      42,    4,  433,    2, 0x0a /* Public */,
      47,    1,  442,    2, 0x0a /* Public */,
      48,    2,  445,    2, 0x0a /* Public */,
      51,    4,  450,    2, 0x0a /* Public */,
      56,    3,  459,    2, 0x0a /* Public */,
      58,    2,  466,    2, 0x0a /* Public */,
      61,    5,  471,    2, 0x0a /* Public */,
      61,    4,  482,    2, 0x2a /* Public | MethodCloned */,
      62,    5,  491,    2, 0x0a /* Public */,
      62,    4,  502,    2, 0x2a /* Public | MethodCloned */,
      62,    3,  511,    2, 0x2a /* Public | MethodCloned */,
      68,    7,  518,    2, 0x0a /* Public */,
      70,    1,  533,    2, 0x0a /* Public */,
      71,    2,  536,    2, 0x0a /* Public */,
      73,    2,  541,    2, 0x0a /* Public */,
      75,    2,  546,    2, 0x0a /* Public */,
      76,    3,  551,    2, 0x0a /* Public */,
      78,    4,  558,    2, 0x0a /* Public */,
      79,    7,  567,    2, 0x0a /* Public */,
      82,    2,  582,    2, 0x0a /* Public */,
      85,    5,  587,    2, 0x0a /* Public */,
      94,    0,  598,    2, 0x0a /* Public */,
      95,    1,  599,    2, 0x0a /* Public */,
      97,    1,  602,    2, 0x08 /* Private */,
      98,    0,  605,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    8,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int, QMetaType::Int,    2,   10,   11,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int,    2,   10,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Bool, QMetaType::QString,    2,    2,   14,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Bool,    2,    2,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, 0x80000000 | 18,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   25,   26,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,   29,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   35,   31,   36,   37,   38,   39,   40,   41,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 45,   31,   43,   44,   46,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 49,   31,   50,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 53, QMetaType::Int, 0x80000000 | 45,   52,   54,   55,   46,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int, QMetaType::Int,   57,   10,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   59,   60,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 53, QMetaType::Int, 0x80000000 | 45, QMetaType::Bool,   52,   54,   55,   46,   14,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 53, QMetaType::Int, 0x80000000 | 45,   52,   54,   55,   46,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, 0x80000000 | 18,   63,   64,   65,   66,   67,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   63,   64,   65,   66,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   63,   64,   65,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QStringList, 0x80000000 | 18,   31,   63,   64,   65,   66,   69,    2,
    QMetaType::Void, QMetaType::QString,   52,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,   52,   72,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,   52,   74,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   52,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 77,   52,    8,   69,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString,   63,   26,   66,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QString,   31,   63,   26,   66,   80,   81,    8,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,   83,   84,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 88, 0x80000000 | 90, 0x80000000 | 92,   86,   87,   89,   91,   93,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   96,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void,

       0        // eod
};

void KvSqlDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KvSqlDialog *_t = static_cast<KvSqlDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cloneSessionSignal((*reinterpret_cast< WId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->openDbConnectionSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 2: _t->closeDbConnectionSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->getSessionInfoSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->executeQuerySignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->executeQuerySignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->getSqlBlocksSignal((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->getSqlBlocksSignal((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->getSqlBlocksSignal((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 9: _t->getFindObjectStatementSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->getFindObjectStatementSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->getNextRecordsSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 12: _t->getNextRecordsSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 13: _t->getNextRecordsSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->commitTransactionSignal(); break;
        case 15: _t->rollbackTransactionSignal(); break;
        case 16: _t->getDdlFromObjectSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< KvSqlSession::DdlTypes(*)>(_a[5]))); break;
        case 17: _t->getDependentSqlSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->getExtractConsistentDataSqlSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->getPlanSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 20: _t->getExportedDataSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 21: _t->getDatabaseObjectTypesSignal(); break;
        case 22: _t->getTableAndColumnsInfoSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 23: _t->deleteTempThreadSlot(); break;
        case 24: _t->setActiveSessions((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 25: _t->setCurrentSession((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: _t->addActiveSession((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: _t->removeActiveSession((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: _t->clonedSessionSlot((*reinterpret_cast< WId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8]))); break;
        case 29: _t->openedDbConnectionSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4]))); break;
        case 30: _t->closedDbConnectionSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 31: _t->gotSessionInfoSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QMap<QString,QString>(*)>(_a[2]))); break;
        case 32: _t->executedQuerySlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4]))); break;
        case 33: _t->gotSqlBlocksSlot((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 34: _t->gotFindObjectStatementSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 35: _t->gotNextRecordsSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 36: _t->gotNextRecordsSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4]))); break;
        case 37: _t->getDdlFromObjectSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< KvSqlSession::DdlTypes(*)>(_a[5]))); break;
        case 38: _t->getDdlFromObjectSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 39: _t->getDdlFromObjectSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 40: _t->gotDdlFromObjectSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< QStringList(*)>(_a[6])),(*reinterpret_cast< KvSqlSession::DdlTypes(*)>(_a[7]))); break;
        case 41: _t->getDependentSqlSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 42: _t->gotDependentSqlSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 43: _t->gotExtractConsistentDataSqlSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 44: _t->getPlanSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 45: _t->gotPlanSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QList<QPair<QString,QMap<QString,QString> > >(*)>(_a[3]))); break;
        case 46: _t->getExportedDataSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 47: _t->gotExportedDataSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7]))); break;
        case 48: _t->gotDatabaseObjectTypesSlot((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 49: _t->gotTableAndColumnsInfoSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< KvTableInfo(*)>(_a[3])),(*reinterpret_cast< QList<KvColumnInfo>(*)>(_a[4])),(*reinterpret_cast< QList<KvTableConstraintInfo>(*)>(_a[5]))); break;
        case 50: { QString _r = _t->getFileName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 51: _t->setFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 52: _t->startedThreadSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 53: _t->deleteThreadSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KvSqlDialog::*)(WId , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlDialog::cloneSessionSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (KvSqlDialog::*)(QString , QString , QString , QString , QString , QString , QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlDialog::openDbConnectionSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (KvSqlDialog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlDialog::closeDbConnectionSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (KvSqlDialog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlDialog::getSessionInfoSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (KvSqlDialog::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlDialog::executeQuerySignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (KvSqlDialog::*)(QStringList , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlDialog::getSqlBlocksSignal)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (KvSqlDialog::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlDialog::getFindObjectStatementSignal)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (KvSqlDialog::*)(QString , int , bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlDialog::getNextRecordsSignal)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (KvSqlDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlDialog::commitTransactionSignal)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (KvSqlDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlDialog::rollbackTransactionSignal)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (KvSqlDialog::*)(QString , QString , QString , bool , KvSqlSession::DdlTypes );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlDialog::getDdlFromObjectSignal)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (KvSqlDialog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlDialog::getDependentSqlSignal)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (KvSqlDialog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlDialog::getExtractConsistentDataSqlSignal)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (KvSqlDialog::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlDialog::getPlanSignal)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (KvSqlDialog::*)(QString , QString , bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlDialog::getExportedDataSignal)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (KvSqlDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlDialog::getDatabaseObjectTypesSignal)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (KvSqlDialog::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlDialog::getTableAndColumnsInfoSignal)) {
                *result = 22;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KvSqlDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_KvSqlDialog.data,
    qt_meta_data_KvSqlDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KvSqlDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KvSqlDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KvSqlDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int KvSqlDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 54)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 54;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 54)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 54;
    }
    return _id;
}

// SIGNAL 0
void KvSqlDialog::cloneSessionSignal(WId _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KvSqlDialog::openDbConnectionSignal(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5, QString _t6, QString _t7, int _t8)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KvSqlDialog::closeDbConnectionSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void KvSqlDialog::getSessionInfoSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void KvSqlDialog::executeQuerySignal(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 6
void KvSqlDialog::getSqlBlocksSignal(QStringList _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 9
void KvSqlDialog::getFindObjectStatementSignal(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 11
void KvSqlDialog::getNextRecordsSignal(QString _t1, int _t2, bool _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 14
void KvSqlDialog::commitTransactionSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void KvSqlDialog::rollbackTransactionSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void KvSqlDialog::getDdlFromObjectSignal(QString _t1, QString _t2, QString _t3, bool _t4, KvSqlSession::DdlTypes _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void KvSqlDialog::getDependentSqlSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void KvSqlDialog::getExtractConsistentDataSqlSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void KvSqlDialog::getPlanSignal(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void KvSqlDialog::getExportedDataSignal(QString _t1, QString _t2, bool _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void KvSqlDialog::getDatabaseObjectTypesSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void KvSqlDialog::getTableAndColumnsInfoSignal(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
