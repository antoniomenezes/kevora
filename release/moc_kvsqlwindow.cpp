/****************************************************************************
** Meta object code from reading C++ file 'kvsqlwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../kvsqlwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kvsqlwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KvSqlWindow_t {
    QByteArrayData data[119];
    char stringdata0[1983];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KvSqlWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KvSqlWindow_t qt_meta_stringdata_KvSqlWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "KvSqlWindow"
QT_MOC_LITERAL(1, 12, 14), // "openFileSignal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 17), // "setActiveSessions"
QT_MOC_LITERAL(4, 46, 8), // "sessions"
QT_MOC_LITERAL(5, 55, 16), // "addActiveSession"
QT_MOC_LITERAL(6, 72, 7), // "session"
QT_MOC_LITERAL(7, 80, 19), // "removeActiveSession"
QT_MOC_LITERAL(8, 100, 17), // "clonedSessionSlot"
QT_MOC_LITERAL(9, 118, 3), // "WId"
QT_MOC_LITERAL(10, 122, 8), // "windowId"
QT_MOC_LITERAL(11, 131, 11), // "sessionName"
QT_MOC_LITERAL(12, 143, 6), // "driver"
QT_MOC_LITERAL(13, 150, 8), // "hostName"
QT_MOC_LITERAL(14, 159, 4), // "port"
QT_MOC_LITERAL(15, 164, 12), // "databaseName"
QT_MOC_LITERAL(16, 177, 8), // "userName"
QT_MOC_LITERAL(17, 186, 8), // "password"
QT_MOC_LITERAL(18, 195, 22), // "openedDbConnectionSlot"
QT_MOC_LITERAL(19, 218, 14), // "connectionName"
QT_MOC_LITERAL(20, 233, 8), // "connUser"
QT_MOC_LITERAL(21, 242, 6), // "connDb"
QT_MOC_LITERAL(22, 249, 9), // "QSqlError"
QT_MOC_LITERAL(23, 259, 5), // "error"
QT_MOC_LITERAL(24, 265, 14), // "setHighLighter"
QT_MOC_LITERAL(25, 280, 28), // "KvDbUtil::DbmsHighlightTypes"
QT_MOC_LITERAL(26, 309, 1), // "h"
QT_MOC_LITERAL(27, 311, 17), // "executedQuerySlot"
QT_MOC_LITERAL(28, 329, 12), // "sqlStatement"
QT_MOC_LITERAL(29, 342, 17), // "QList<QSqlRecord>"
QT_MOC_LITERAL(30, 360, 7), // "records"
QT_MOC_LITERAL(31, 368, 11), // "recordCount"
QT_MOC_LITERAL(32, 380, 14), // "sqlStatementId"
QT_MOC_LITERAL(33, 395, 16), // "gotSqlBlocksSlot"
QT_MOC_LITERAL(34, 412, 9), // "sqlBlocks"
QT_MOC_LITERAL(35, 422, 12), // "fromPosition"
QT_MOC_LITERAL(36, 435, 10), // "toPosition"
QT_MOC_LITERAL(37, 446, 18), // "gotNextRecordsSlot"
QT_MOC_LITERAL(38, 465, 10), // "allRecords"
QT_MOC_LITERAL(39, 476, 17), // "updateRecordCount"
QT_MOC_LITERAL(40, 494, 10), // "partNumber"
QT_MOC_LITERAL(41, 505, 11), // "totalNumber"
QT_MOC_LITERAL(42, 517, 23), // "getPreparedSqlStatement"
QT_MOC_LITERAL(43, 541, 23), // "updateRecordViewHeaders"
QT_MOC_LITERAL(44, 565, 16), // "updateRecordView"
QT_MOC_LITERAL(45, 582, 19), // "setCancelAllRecords"
QT_MOC_LITERAL(46, 602, 5), // "sqlId"
QT_MOC_LITERAL(47, 608, 5), // "value"
QT_MOC_LITERAL(48, 614, 19), // "setComboSessionName"
QT_MOC_LITERAL(49, 634, 15), // "setSqlStatement"
QT_MOC_LITERAL(50, 650, 15), // "runSqlStatement"
QT_MOC_LITERAL(51, 666, 10), // "setDdlInfo"
QT_MOC_LITERAL(52, 677, 10), // "schemaName"
QT_MOC_LITERAL(53, 688, 10), // "objectName"
QT_MOC_LITERAL(54, 699, 10), // "objectType"
QT_MOC_LITERAL(55, 710, 10), // "showSchema"
QT_MOC_LITERAL(56, 721, 17), // "setExportDataInfo"
QT_MOC_LITERAL(57, 739, 9), // "tableName"
QT_MOC_LITERAL(58, 749, 20), // "getDdlFromObjectSlot"
QT_MOC_LITERAL(59, 770, 6), // "schema"
QT_MOC_LITERAL(60, 777, 22), // "KvSqlSession::DdlTypes"
QT_MOC_LITERAL(61, 800, 7), // "ddlType"
QT_MOC_LITERAL(62, 808, 20), // "gotDdlFromObjectSlot"
QT_MOC_LITERAL(63, 829, 6), // "result"
QT_MOC_LITERAL(64, 836, 19), // "gotDependentSqlSlot"
QT_MOC_LITERAL(65, 856, 22), // "dependentSqlStatements"
QT_MOC_LITERAL(66, 879, 31), // "gotExtractConsistentDataSqlSlot"
QT_MOC_LITERAL(67, 911, 23), // "consistentSqlStatements"
QT_MOC_LITERAL(68, 935, 11), // "getPlanSlot"
QT_MOC_LITERAL(69, 947, 11), // "gotPlanSlot"
QT_MOC_LITERAL(70, 959, 45), // "QList<QPair<QString,QMap<QStr..."
QT_MOC_LITERAL(71, 1005, 19), // "getExportedDataSlot"
QT_MOC_LITERAL(72, 1025, 19), // "gotExportedDataSlot"
QT_MOC_LITERAL(73, 1045, 10), // "resultLine"
QT_MOC_LITERAL(74, 1056, 8), // "isTheEnd"
QT_MOC_LITERAL(75, 1065, 8), // "openFile"
QT_MOC_LITERAL(76, 1074, 8), // "fileName"
QT_MOC_LITERAL(77, 1083, 8), // "saveFile"
QT_MOC_LITERAL(78, 1092, 28), // "on_actionTimed_Run_triggered"
QT_MOC_LITERAL(79, 1121, 29), // "on_actionExplainAll_triggered"
QT_MOC_LITERAL(80, 1151, 33), // "on_toolButtonCancelParams_cli..."
QT_MOC_LITERAL(81, 1185, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(82, 1213, 5), // "index"
QT_MOC_LITERAL(83, 1219, 31), // "on_tabWidgetData_currentChanged"
QT_MOC_LITERAL(84, 1251, 36), // "on_actionCopy_to_Clipboard_tr..."
QT_MOC_LITERAL(85, 1288, 26), // "on_actionRun_All_triggered"
QT_MOC_LITERAL(86, 1315, 26), // "on_actionRun_Sql_triggered"
QT_MOC_LITERAL(87, 1342, 28), // "on_toolButtonZoomOut_clicked"
QT_MOC_LITERAL(88, 1371, 27), // "on_toolButtonZoomIn_clicked"
QT_MOC_LITERAL(89, 1399, 29), // "on_toolButtonRollback_clicked"
QT_MOC_LITERAL(90, 1429, 27), // "on_toolButtonCommit_clicked"
QT_MOC_LITERAL(91, 1457, 32), // "on_toolButtonApplyParams_clicked"
QT_MOC_LITERAL(92, 1490, 36), // "on_plainTextEditSql_selection..."
QT_MOC_LITERAL(93, 1527, 33), // "on_plainTextEditSql_updateReq..."
QT_MOC_LITERAL(94, 1561, 4), // "rect"
QT_MOC_LITERAL(95, 1566, 2), // "dy"
QT_MOC_LITERAL(96, 1569, 35), // "on_currentSessionComboBox_act..."
QT_MOC_LITERAL(97, 1605, 4), // "text"
QT_MOC_LITERAL(98, 1610, 16), // "getSqlParameters"
QT_MOC_LITERAL(99, 1627, 7), // "sqlText"
QT_MOC_LITERAL(100, 1635, 25), // "updateActiveSessionsCombo"
QT_MOC_LITERAL(101, 1661, 13), // "exportResults"
QT_MOC_LITERAL(102, 1675, 9), // "separator"
QT_MOC_LITERAL(103, 1685, 12), // "exportHeader"
QT_MOC_LITERAL(104, 1698, 12), // "exportRecord"
QT_MOC_LITERAL(105, 1711, 6), // "runSql"
QT_MOC_LITERAL(106, 1718, 17), // "isSelectStatement"
QT_MOC_LITERAL(107, 1736, 10), // "newSqlData"
QT_MOC_LITERAL(108, 1747, 10), // "KvSqlData*"
QT_MOC_LITERAL(109, 1758, 8), // "newSqlId"
QT_MOC_LITERAL(110, 1767, 11), // "newSqlLabel"
QT_MOC_LITERAL(111, 1779, 10), // "newSqlText"
QT_MOC_LITERAL(112, 1790, 18), // "getNextRecordsSlot"
QT_MOC_LITERAL(113, 1809, 17), // "getAllRecordsSlot"
QT_MOC_LITERAL(114, 1827, 25), // "cancelAllRecordsFetchSlot"
QT_MOC_LITERAL(115, 1853, 24), // "currentRecordChangedSlot"
QT_MOC_LITERAL(116, 1878, 10), // "currentRow"
QT_MOC_LITERAL(117, 1889, 46), // "on_actionGenerate_Cascade_Ope..."
QT_MOC_LITERAL(118, 1936, 46) // "on_actionExtract_Consistent_S..."

    },
    "KvSqlWindow\0openFileSignal\0\0"
    "setActiveSessions\0sessions\0addActiveSession\0"
    "session\0removeActiveSession\0"
    "clonedSessionSlot\0WId\0windowId\0"
    "sessionName\0driver\0hostName\0port\0"
    "databaseName\0userName\0password\0"
    "openedDbConnectionSlot\0connectionName\0"
    "connUser\0connDb\0QSqlError\0error\0"
    "setHighLighter\0KvDbUtil::DbmsHighlightTypes\0"
    "h\0executedQuerySlot\0sqlStatement\0"
    "QList<QSqlRecord>\0records\0recordCount\0"
    "sqlStatementId\0gotSqlBlocksSlot\0"
    "sqlBlocks\0fromPosition\0toPosition\0"
    "gotNextRecordsSlot\0allRecords\0"
    "updateRecordCount\0partNumber\0totalNumber\0"
    "getPreparedSqlStatement\0updateRecordViewHeaders\0"
    "updateRecordView\0setCancelAllRecords\0"
    "sqlId\0value\0setComboSessionName\0"
    "setSqlStatement\0runSqlStatement\0"
    "setDdlInfo\0schemaName\0objectName\0"
    "objectType\0showSchema\0setExportDataInfo\0"
    "tableName\0getDdlFromObjectSlot\0schema\0"
    "KvSqlSession::DdlTypes\0ddlType\0"
    "gotDdlFromObjectSlot\0result\0"
    "gotDependentSqlSlot\0dependentSqlStatements\0"
    "gotExtractConsistentDataSqlSlot\0"
    "consistentSqlStatements\0getPlanSlot\0"
    "gotPlanSlot\0QList<QPair<QString,QMap<QString,QString> > >\0"
    "getExportedDataSlot\0gotExportedDataSlot\0"
    "resultLine\0isTheEnd\0openFile\0fileName\0"
    "saveFile\0on_actionTimed_Run_triggered\0"
    "on_actionExplainAll_triggered\0"
    "on_toolButtonCancelParams_clicked\0"
    "on_tabWidget_currentChanged\0index\0"
    "on_tabWidgetData_currentChanged\0"
    "on_actionCopy_to_Clipboard_triggered\0"
    "on_actionRun_All_triggered\0"
    "on_actionRun_Sql_triggered\0"
    "on_toolButtonZoomOut_clicked\0"
    "on_toolButtonZoomIn_clicked\0"
    "on_toolButtonRollback_clicked\0"
    "on_toolButtonCommit_clicked\0"
    "on_toolButtonApplyParams_clicked\0"
    "on_plainTextEditSql_selectionChanged\0"
    "on_plainTextEditSql_updateRequest\0"
    "rect\0dy\0on_currentSessionComboBox_activated\0"
    "text\0getSqlParameters\0sqlText\0"
    "updateActiveSessionsCombo\0exportResults\0"
    "separator\0exportHeader\0exportRecord\0"
    "runSql\0isSelectStatement\0newSqlData\0"
    "KvSqlData*\0newSqlId\0newSqlLabel\0"
    "newSqlText\0getNextRecordsSlot\0"
    "getAllRecordsSlot\0cancelAllRecordsFetchSlot\0"
    "currentRecordChangedSlot\0currentRow\0"
    "on_actionGenerate_Cascade_Operations_triggered\0"
    "on_actionExtract_Consistent_Sql_Data_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KvSqlWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      70,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  364,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,  367,    2, 0x0a /* Public */,
       5,    1,  370,    2, 0x0a /* Public */,
       7,    1,  373,    2, 0x0a /* Public */,
       8,    8,  376,    2, 0x0a /* Public */,
      18,    4,  393,    2, 0x0a /* Public */,
      24,    1,  402,    2, 0x0a /* Public */,
      27,    5,  405,    2, 0x0a /* Public */,
      27,    4,  416,    2, 0x2a /* Public | MethodCloned */,
      33,    3,  425,    2, 0x0a /* Public */,
      37,    6,  432,    2, 0x0a /* Public */,
      37,    5,  445,    2, 0x2a /* Public | MethodCloned */,
      37,    4,  456,    2, 0x2a /* Public | MethodCloned */,
      39,    2,  465,    2, 0x0a /* Public */,
      42,    0,  470,    2, 0x0a /* Public */,
      43,    0,  471,    2, 0x0a /* Public */,
      44,    0,  472,    2, 0x0a /* Public */,
      45,    2,  473,    2, 0x0a /* Public */,
      48,    1,  478,    2, 0x0a /* Public */,
      49,    1,  481,    2, 0x0a /* Public */,
      50,    1,  484,    2, 0x0a /* Public */,
      51,    4,  487,    2, 0x0a /* Public */,
      51,    3,  496,    2, 0x2a /* Public | MethodCloned */,
      56,    3,  503,    2, 0x0a /* Public */,
      56,    2,  510,    2, 0x2a /* Public | MethodCloned */,
      58,    5,  515,    2, 0x0a /* Public */,
      58,    4,  526,    2, 0x2a /* Public | MethodCloned */,
      58,    3,  535,    2, 0x2a /* Public | MethodCloned */,
      62,    7,  542,    2, 0x0a /* Public */,
      64,    2,  557,    2, 0x0a /* Public */,
      66,    2,  562,    2, 0x0a /* Public */,
      68,    2,  567,    2, 0x0a /* Public */,
      69,    3,  572,    2, 0x0a /* Public */,
      71,    4,  579,    2, 0x0a /* Public */,
      72,    7,  588,    2, 0x0a /* Public */,
      75,    1,  603,    2, 0x0a /* Public */,
      77,    0,  606,    2, 0x0a /* Public */,
      78,    0,  607,    2, 0x08 /* Private */,
      79,    0,  608,    2, 0x08 /* Private */,
      80,    0,  609,    2, 0x08 /* Private */,
      81,    1,  610,    2, 0x08 /* Private */,
      83,    1,  613,    2, 0x08 /* Private */,
      84,    0,  616,    2, 0x08 /* Private */,
      85,    0,  617,    2, 0x08 /* Private */,
      86,    0,  618,    2, 0x08 /* Private */,
      87,    0,  619,    2, 0x08 /* Private */,
      88,    0,  620,    2, 0x08 /* Private */,
      89,    0,  621,    2, 0x08 /* Private */,
      90,    0,  622,    2, 0x08 /* Private */,
      91,    0,  623,    2, 0x08 /* Private */,
      92,    0,  624,    2, 0x08 /* Private */,
      93,    2,  625,    2, 0x08 /* Private */,
      96,    1,  630,    2, 0x08 /* Private */,
      98,    1,  633,    2, 0x08 /* Private */,
     100,    0,  636,    2, 0x08 /* Private */,
     101,    2,  637,    2, 0x08 /* Private */,
     101,    1,  642,    2, 0x28 /* Private | MethodCloned */,
     104,    2,  645,    2, 0x08 /* Private */,
     104,    1,  650,    2, 0x28 /* Private | MethodCloned */,
     105,    2,  653,    2, 0x08 /* Private */,
     105,    1,  658,    2, 0x28 /* Private | MethodCloned */,
     105,    0,  661,    2, 0x28 /* Private | MethodCloned */,
     106,    1,  662,    2, 0x08 /* Private */,
     107,    3,  665,    2, 0x08 /* Private */,
     112,    1,  672,    2, 0x08 /* Private */,
     113,    1,  675,    2, 0x08 /* Private */,
     114,    1,  678,    2, 0x08 /* Private */,
     115,    2,  681,    2, 0x08 /* Private */,
     117,    0,  686,    2, 0x08 /* Private */,
     118,    0,  687,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   12,   13,   14,   15,   16,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 22,   19,   20,   21,   23,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 29, QMetaType::Int, 0x80000000 | 22, QMetaType::QString,   28,   30,   31,   23,   32,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 29, QMetaType::Int, 0x80000000 | 22,   28,   30,   31,   23,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int, QMetaType::Int,   34,   35,   36,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 29, QMetaType::Int, 0x80000000 | 22, QMetaType::Bool, QMetaType::QString,   28,   30,   31,   23,   38,   32,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 29, QMetaType::Int, 0x80000000 | 22, QMetaType::Bool,   28,   30,   31,   23,   38,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 29, QMetaType::Int, 0x80000000 | 22,   28,   30,   31,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   40,   41,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   46,   47,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   52,   53,   54,   55,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   52,   53,   54,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   52,   57,   55,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   52,   57,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, 0x80000000 | 60,   59,   53,   54,   55,   61,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   59,   53,   54,   55,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   59,   53,   54,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QStringList, 0x80000000 | 60,   11,   59,   53,   54,   55,   63,   61,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,   28,   65,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,   28,   67,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   28,   32,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 70,   28,   32,   63,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString,   59,   57,   55,   32,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QString,   11,   59,   57,   55,   73,   74,   32,
    QMetaType::Void, QMetaType::QString,   76,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   82,
    QMetaType::Void, QMetaType::Int,   82,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRect, QMetaType::Int,   94,   95,
    QMetaType::Void, QMetaType::QString,   97,
    QMetaType::QStringList, QMetaType::QString,   99,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString, QMetaType::Bool,  102,  103,
    QMetaType::QString, QMetaType::QString,  102,
    QMetaType::QString, QMetaType::QString, QMetaType::Bool,  102,  103,
    QMetaType::QString, QMetaType::QString,  102,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   35,   36,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   97,
    0x80000000 | 108, QMetaType::QString, QMetaType::QString, QMetaType::QString,  109,  110,  111,
    QMetaType::Void, QMetaType::QString,   46,
    QMetaType::Void, QMetaType::QString,   46,
    QMetaType::Void, QMetaType::QString,   46,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,  116,   46,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void KvSqlWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KvSqlWindow *_t = static_cast<KvSqlWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openFileSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setActiveSessions((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->addActiveSession((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->removeActiveSession((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->clonedSessionSlot((*reinterpret_cast< WId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8]))); break;
        case 5: _t->openedDbConnectionSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4]))); break;
        case 6: _t->setHighLighter((*reinterpret_cast< KvDbUtil::DbmsHighlightTypes(*)>(_a[1]))); break;
        case 7: _t->executedQuerySlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 8: _t->executedQuerySlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4]))); break;
        case 9: _t->gotSqlBlocksSlot((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 10: _t->gotNextRecordsSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 11: _t->gotNextRecordsSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 12: _t->gotNextRecordsSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4]))); break;
        case 13: _t->updateRecordCount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: { QString _r = _t->getPreparedSqlStatement();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->updateRecordViewHeaders(); break;
        case 16: _t->updateRecordView(); break;
        case 17: _t->setCancelAllRecords((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 18: _t->setComboSessionName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->setSqlStatement((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->runSqlStatement((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->setDdlInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 22: _t->setDdlInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 23: _t->setExportDataInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 24: _t->setExportDataInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 25: _t->getDdlFromObjectSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< KvSqlSession::DdlTypes(*)>(_a[5]))); break;
        case 26: _t->getDdlFromObjectSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 27: _t->getDdlFromObjectSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 28: _t->gotDdlFromObjectSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< QStringList(*)>(_a[6])),(*reinterpret_cast< KvSqlSession::DdlTypes(*)>(_a[7]))); break;
        case 29: _t->gotDependentSqlSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 30: _t->gotExtractConsistentDataSqlSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 31: _t->getPlanSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 32: _t->gotPlanSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QList<QPair<QString,QMap<QString,QString> > >(*)>(_a[3]))); break;
        case 33: _t->getExportedDataSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 34: _t->gotExportedDataSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7]))); break;
        case 35: _t->openFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 36: _t->saveFile(); break;
        case 37: _t->on_actionTimed_Run_triggered(); break;
        case 38: _t->on_actionExplainAll_triggered(); break;
        case 39: _t->on_toolButtonCancelParams_clicked(); break;
        case 40: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->on_tabWidgetData_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->on_actionCopy_to_Clipboard_triggered(); break;
        case 43: _t->on_actionRun_All_triggered(); break;
        case 44: _t->on_actionRun_Sql_triggered(); break;
        case 45: _t->on_toolButtonZoomOut_clicked(); break;
        case 46: _t->on_toolButtonZoomIn_clicked(); break;
        case 47: _t->on_toolButtonRollback_clicked(); break;
        case 48: _t->on_toolButtonCommit_clicked(); break;
        case 49: _t->on_toolButtonApplyParams_clicked(); break;
        case 50: _t->on_plainTextEditSql_selectionChanged(); break;
        case 51: _t->on_plainTextEditSql_updateRequest((*reinterpret_cast< QRect(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 52: _t->on_currentSessionComboBox_activated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 53: { QStringList _r = _t->getSqlParameters((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 54: _t->updateActiveSessionsCombo(); break;
        case 55: { QString _r = _t->exportResults((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 56: { QString _r = _t->exportResults((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 57: { QString _r = _t->exportRecord((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 58: { QString _r = _t->exportRecord((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 59: _t->runSql((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 60: _t->runSql((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 61: _t->runSql(); break;
        case 62: { bool _r = _t->isSelectStatement((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 63: { KvSqlData* _r = _t->newSqlData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< KvSqlData**>(_a[0]) = std::move(_r); }  break;
        case 64: _t->getNextRecordsSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 65: _t->getAllRecordsSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 66: _t->cancelAllRecordsFetchSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 67: _t->currentRecordChangedSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 68: _t->on_actionGenerate_Cascade_Operations_triggered(); break;
        case 69: _t->on_actionExtract_Consistent_Sql_Data_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KvSqlWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlWindow::openFileSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KvSqlWindow::staticMetaObject = { {
    &KvSqlDialog::staticMetaObject,
    qt_meta_stringdata_KvSqlWindow.data,
    qt_meta_data_KvSqlWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KvSqlWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KvSqlWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KvSqlWindow.stringdata0))
        return static_cast<void*>(this);
    return KvSqlDialog::qt_metacast(_clname);
}

int KvSqlWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = KvSqlDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 70)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 70;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 70)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 70;
    }
    return _id;
}

// SIGNAL 0
void KvSqlWindow::openFileSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
