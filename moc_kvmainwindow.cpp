/****************************************************************************
** Meta object code from reading C++ file 'kvmainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "kvmainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kvmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KvMainWindow_t {
    QByteArrayData data[105];
    char stringdata0[2257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KvMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KvMainWindow_t qt_meta_stringdata_KvMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "KvMainWindow"
QT_MOC_LITERAL(1, 13, 22), // "openDbConnectionSignal"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 24), // "openedDbConnectionSignal"
QT_MOC_LITERAL(4, 62, 14), // "connectionName"
QT_MOC_LITERAL(5, 77, 8), // "connUser"
QT_MOC_LITERAL(6, 86, 6), // "connDb"
QT_MOC_LITERAL(7, 93, 9), // "QSqlError"
QT_MOC_LITERAL(8, 103, 5), // "error"
QT_MOC_LITERAL(9, 109, 23), // "closeDbConnectionSignal"
QT_MOC_LITERAL(10, 133, 24), // "closedDbConnectionSignal"
QT_MOC_LITERAL(11, 158, 18), // "cloneSessionSignal"
QT_MOC_LITERAL(12, 177, 3), // "WId"
QT_MOC_LITERAL(13, 181, 19), // "clonedSessionSignal"
QT_MOC_LITERAL(14, 201, 26), // "getSchemasWithTablesSignal"
QT_MOC_LITERAL(15, 228, 25), // "getSchemasWithViewsSignal"
QT_MOC_LITERAL(16, 254, 28), // "getSchemasWithProgramsSignal"
QT_MOC_LITERAL(17, 283, 23), // "getSchemasWithEtcSignal"
QT_MOC_LITERAL(18, 307, 14), // "createDbThread"
QT_MOC_LITERAL(19, 322, 7), // "session"
QT_MOC_LITERAL(20, 330, 17), // "startedThreadSlot"
QT_MOC_LITERAL(21, 348, 22), // "openedDbConnectionSlot"
QT_MOC_LITERAL(22, 371, 22), // "closedDbConnectionSlot"
QT_MOC_LITERAL(23, 394, 24), // "gotSchemasWithTablesSlot"
QT_MOC_LITERAL(24, 419, 11), // "sessionName"
QT_MOC_LITERAL(25, 431, 8), // "userName"
QT_MOC_LITERAL(26, 440, 5), // "items"
QT_MOC_LITERAL(27, 446, 23), // "gotSchemasWithViewsSlot"
QT_MOC_LITERAL(28, 470, 26), // "gotSchemasWithProgramsSlot"
QT_MOC_LITERAL(29, 497, 21), // "gotSchemasWithEtcSlot"
QT_MOC_LITERAL(30, 519, 18), // "isActiveConnection"
QT_MOC_LITERAL(31, 538, 5), // "alias"
QT_MOC_LITERAL(32, 544, 13), // "execAutoLogon"
QT_MOC_LITERAL(33, 558, 16), // "updateWindowList"
QT_MOC_LITERAL(34, 575, 8), // "exitSlot"
QT_MOC_LITERAL(35, 584, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(36, 608, 34), // "on_actionRefresh_Schemas_trig..."
QT_MOC_LITERAL(37, 643, 42), // "on_actionExport_Database_Obje..."
QT_MOC_LITERAL(38, 686, 30), // "on_actionExport_Data_triggered"
QT_MOC_LITERAL(39, 717, 27), // "on_actionView_DDL_triggered"
QT_MOC_LITERAL(40, 745, 35), // "on_actionRefreshEtcSchema_tri..."
QT_MOC_LITERAL(41, 781, 39), // "on_actionRefreshProgramSchema..."
QT_MOC_LITERAL(42, 821, 36), // "on_actionRefreshViewSchema_tr..."
QT_MOC_LITERAL(43, 858, 37), // "on_actionRefreshTableSchema_t..."
QT_MOC_LITERAL(44, 896, 32), // "on_actionView_ViewData_triggered"
QT_MOC_LITERAL(45, 929, 33), // "on_actionView_TableData_trigg..."
QT_MOC_LITERAL(46, 963, 32), // "on_actionDisconnectAll_triggered"
QT_MOC_LITERAL(47, 996, 32), // "on_actionMain_Tool_Bar_triggered"
QT_MOC_LITERAL(48, 1029, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(49, 1054, 36), // "on_actionClose_All_Windows_tr..."
QT_MOC_LITERAL(50, 1091, 31), // "on_actionTile_Windows_triggered"
QT_MOC_LITERAL(51, 1123, 34), // "on_actionCascade_Windows_trig..."
QT_MOC_LITERAL(52, 1158, 41), // "on_listWidgetWindows_itemSele..."
QT_MOC_LITERAL(53, 1200, 26), // "on_actionNew_Sql_triggered"
QT_MOC_LITERAL(54, 1227, 29), // "on_mdiArea_subWindowActivated"
QT_MOC_LITERAL(55, 1257, 14), // "QMdiSubWindow*"
QT_MOC_LITERAL(56, 1272, 6), // "window"
QT_MOC_LITERAL(57, 1279, 28), // "on_actionWork_Path_triggered"
QT_MOC_LITERAL(58, 1308, 30), // "on_actionWindow_List_triggered"
QT_MOC_LITERAL(59, 1339, 26), // "on_actionObjects_triggered"
QT_MOC_LITERAL(60, 1366, 28), // "on_actionNavigator_triggered"
QT_MOC_LITERAL(61, 1395, 29), // "on_dbTreeWidget_doubleClicked"
QT_MOC_LITERAL(62, 1425, 5), // "index"
QT_MOC_LITERAL(63, 1431, 36), // "on_actionDelete_Connection_tr..."
QT_MOC_LITERAL(64, 1468, 33), // "on_actionAdd_Connection_trigg..."
QT_MOC_LITERAL(65, 1502, 34), // "on_actionDelete_Database_trig..."
QT_MOC_LITERAL(66, 1537, 23), // "on_actionEdit_triggered"
QT_MOC_LITERAL(67, 1561, 24), // "on_fileTreeView_expanded"
QT_MOC_LITERAL(68, 1586, 44), // "on_activeConnObjComboBox_curr..."
QT_MOC_LITERAL(69, 1631, 4), // "text"
QT_MOC_LITERAL(70, 1636, 30), // "on_actionPreferences_triggered"
QT_MOC_LITERAL(71, 1667, 29), // "on_actionDisconnect_triggered"
QT_MOC_LITERAL(72, 1697, 26), // "on_actionConnect_triggered"
QT_MOC_LITERAL(73, 1724, 31), // "on_actionAdd_Database_triggered"
QT_MOC_LITERAL(74, 1756, 27), // "on_actionAbout_Qt_triggered"
QT_MOC_LITERAL(75, 1784, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(76, 1808, 31), // "on_actionAbout_Kevora_triggered"
QT_MOC_LITERAL(77, 1840, 14), // "updateViewMenu"
QT_MOC_LITERAL(78, 1855, 8), // "closeTab"
QT_MOC_LITERAL(79, 1864, 1), // "i"
QT_MOC_LITERAL(80, 1866, 20), // "deleteTempThreadSlot"
QT_MOC_LITERAL(81, 1887, 8), // "openFile"
QT_MOC_LITERAL(82, 1896, 8), // "fileName"
QT_MOC_LITERAL(83, 1905, 8), // "saveFile"
QT_MOC_LITERAL(84, 1914, 12), // "KvSqlWindow*"
QT_MOC_LITERAL(85, 1927, 12), // "newSqlWindow"
QT_MOC_LITERAL(86, 1940, 12), // "sqlStatement"
QT_MOC_LITERAL(87, 1953, 12), // "toBeExecuted"
QT_MOC_LITERAL(88, 1966, 11), // "windowTitle"
QT_MOC_LITERAL(89, 1978, 12), // "newDdlWindow"
QT_MOC_LITERAL(90, 1991, 10), // "schemaName"
QT_MOC_LITERAL(91, 2002, 10), // "objectName"
QT_MOC_LITERAL(92, 2013, 10), // "objectType"
QT_MOC_LITERAL(93, 2024, 10), // "showSchema"
QT_MOC_LITERAL(94, 2035, 19), // "newExportDataWindow"
QT_MOC_LITERAL(95, 2055, 9), // "tableName"
QT_MOC_LITERAL(96, 2065, 22), // "newExportObjectsWindow"
QT_MOC_LITERAL(97, 2088, 7), // "loadXml"
QT_MOC_LITERAL(98, 2096, 7), // "saveXml"
QT_MOC_LITERAL(99, 2104, 7), // "copyXml"
QT_MOC_LITERAL(100, 2112, 15), // "runKevoraUpdate"
QT_MOC_LITERAL(101, 2128, 33), // "on_actionKevora_Updates_trigg..."
QT_MOC_LITERAL(102, 2162, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(103, 2186, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(104, 2213, 43) // "on_actionCompare_Database_obj..."

    },
    "KvMainWindow\0openDbConnectionSignal\0"
    "\0openedDbConnectionSignal\0connectionName\0"
    "connUser\0connDb\0QSqlError\0error\0"
    "closeDbConnectionSignal\0"
    "closedDbConnectionSignal\0cloneSessionSignal\0"
    "WId\0clonedSessionSignal\0"
    "getSchemasWithTablesSignal\0"
    "getSchemasWithViewsSignal\0"
    "getSchemasWithProgramsSignal\0"
    "getSchemasWithEtcSignal\0createDbThread\0"
    "session\0startedThreadSlot\0"
    "openedDbConnectionSlot\0closedDbConnectionSlot\0"
    "gotSchemasWithTablesSlot\0sessionName\0"
    "userName\0items\0gotSchemasWithViewsSlot\0"
    "gotSchemasWithProgramsSlot\0"
    "gotSchemasWithEtcSlot\0isActiveConnection\0"
    "alias\0execAutoLogon\0updateWindowList\0"
    "exitSlot\0on_actionOpen_triggered\0"
    "on_actionRefresh_Schemas_triggered\0"
    "on_actionExport_Database_Objects_triggered\0"
    "on_actionExport_Data_triggered\0"
    "on_actionView_DDL_triggered\0"
    "on_actionRefreshEtcSchema_triggered\0"
    "on_actionRefreshProgramSchema_triggered\0"
    "on_actionRefreshViewSchema_triggered\0"
    "on_actionRefreshTableSchema_triggered\0"
    "on_actionView_ViewData_triggered\0"
    "on_actionView_TableData_triggered\0"
    "on_actionDisconnectAll_triggered\0"
    "on_actionMain_Tool_Bar_triggered\0"
    "on_actionClose_triggered\0"
    "on_actionClose_All_Windows_triggered\0"
    "on_actionTile_Windows_triggered\0"
    "on_actionCascade_Windows_triggered\0"
    "on_listWidgetWindows_itemSelectionChanged\0"
    "on_actionNew_Sql_triggered\0"
    "on_mdiArea_subWindowActivated\0"
    "QMdiSubWindow*\0window\0"
    "on_actionWork_Path_triggered\0"
    "on_actionWindow_List_triggered\0"
    "on_actionObjects_triggered\0"
    "on_actionNavigator_triggered\0"
    "on_dbTreeWidget_doubleClicked\0index\0"
    "on_actionDelete_Connection_triggered\0"
    "on_actionAdd_Connection_triggered\0"
    "on_actionDelete_Database_triggered\0"
    "on_actionEdit_triggered\0"
    "on_fileTreeView_expanded\0"
    "on_activeConnObjComboBox_currentIndexChanged\0"
    "text\0on_actionPreferences_triggered\0"
    "on_actionDisconnect_triggered\0"
    "on_actionConnect_triggered\0"
    "on_actionAdd_Database_triggered\0"
    "on_actionAbout_Qt_triggered\0"
    "on_actionExit_triggered\0"
    "on_actionAbout_Kevora_triggered\0"
    "updateViewMenu\0closeTab\0i\0"
    "deleteTempThreadSlot\0openFile\0fileName\0"
    "saveFile\0KvSqlWindow*\0newSqlWindow\0"
    "sqlStatement\0toBeExecuted\0windowTitle\0"
    "newDdlWindow\0schemaName\0objectName\0"
    "objectType\0showSchema\0newExportDataWindow\0"
    "tableName\0newExportObjectsWindow\0"
    "loadXml\0saveXml\0copyXml\0runKevoraUpdate\0"
    "on_actionKevora_Updates_triggered\0"
    "on_actionSave_triggered\0"
    "on_actionSave_As_triggered\0"
    "on_actionCompare_Database_objects_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KvMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      84,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    8,  434,    2, 0x06 /* Public */,
       3,    4,  451,    2, 0x06 /* Public */,
       9,    1,  460,    2, 0x06 /* Public */,
      10,    1,  463,    2, 0x06 /* Public */,
      11,    2,  466,    2, 0x06 /* Public */,
      13,    8,  471,    2, 0x06 /* Public */,
      14,    1,  488,    2, 0x06 /* Public */,
      15,    1,  491,    2, 0x06 /* Public */,
      16,    1,  494,    2, 0x06 /* Public */,
      17,    1,  497,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    1,  500,    2, 0x0a /* Public */,
      20,    1,  503,    2, 0x0a /* Public */,
      21,    4,  506,    2, 0x0a /* Public */,
      22,    1,  515,    2, 0x0a /* Public */,
      23,    3,  518,    2, 0x0a /* Public */,
      27,    3,  525,    2, 0x0a /* Public */,
      28,    3,  532,    2, 0x0a /* Public */,
      29,    3,  539,    2, 0x0a /* Public */,
      30,    2,  546,    2, 0x0a /* Public */,
      30,    1,  551,    2, 0x2a /* Public | MethodCloned */,
      32,    0,  554,    2, 0x0a /* Public */,
      33,    0,  555,    2, 0x0a /* Public */,
      34,    0,  556,    2, 0x0a /* Public */,
      35,    0,  557,    2, 0x08 /* Private */,
      36,    0,  558,    2, 0x08 /* Private */,
      37,    0,  559,    2, 0x08 /* Private */,
      38,    0,  560,    2, 0x08 /* Private */,
      39,    0,  561,    2, 0x08 /* Private */,
      40,    0,  562,    2, 0x08 /* Private */,
      41,    0,  563,    2, 0x08 /* Private */,
      42,    0,  564,    2, 0x08 /* Private */,
      43,    0,  565,    2, 0x08 /* Private */,
      44,    0,  566,    2, 0x08 /* Private */,
      45,    0,  567,    2, 0x08 /* Private */,
      46,    0,  568,    2, 0x08 /* Private */,
      47,    0,  569,    2, 0x08 /* Private */,
      48,    0,  570,    2, 0x08 /* Private */,
      49,    0,  571,    2, 0x08 /* Private */,
      50,    0,  572,    2, 0x08 /* Private */,
      51,    0,  573,    2, 0x08 /* Private */,
      52,    0,  574,    2, 0x08 /* Private */,
      53,    0,  575,    2, 0x08 /* Private */,
      54,    1,  576,    2, 0x08 /* Private */,
      57,    0,  579,    2, 0x08 /* Private */,
      58,    0,  580,    2, 0x08 /* Private */,
      59,    0,  581,    2, 0x08 /* Private */,
      60,    0,  582,    2, 0x08 /* Private */,
      61,    1,  583,    2, 0x08 /* Private */,
      63,    0,  586,    2, 0x08 /* Private */,
      64,    0,  587,    2, 0x08 /* Private */,
      65,    0,  588,    2, 0x08 /* Private */,
      66,    0,  589,    2, 0x08 /* Private */,
      67,    1,  590,    2, 0x08 /* Private */,
      68,    1,  593,    2, 0x08 /* Private */,
      70,    0,  596,    2, 0x08 /* Private */,
      71,    0,  597,    2, 0x08 /* Private */,
      72,    0,  598,    2, 0x08 /* Private */,
      73,    0,  599,    2, 0x08 /* Private */,
      74,    0,  600,    2, 0x08 /* Private */,
      75,    0,  601,    2, 0x08 /* Private */,
      76,    0,  602,    2, 0x08 /* Private */,
      77,    0,  603,    2, 0x08 /* Private */,
      78,    1,  604,    2, 0x08 /* Private */,
      80,    0,  607,    2, 0x08 /* Private */,
      81,    1,  608,    2, 0x08 /* Private */,
      83,    2,  611,    2, 0x08 /* Private */,
      85,    4,  616,    2, 0x08 /* Private */,
      85,    3,  625,    2, 0x28 /* Private | MethodCloned */,
      85,    2,  632,    2, 0x28 /* Private | MethodCloned */,
      85,    1,  637,    2, 0x28 /* Private | MethodCloned */,
      85,    0,  640,    2, 0x28 /* Private | MethodCloned */,
      89,    5,  641,    2, 0x08 /* Private */,
      89,    4,  652,    2, 0x28 /* Private | MethodCloned */,
      94,    4,  661,    2, 0x08 /* Private */,
      94,    3,  670,    2, 0x28 /* Private | MethodCloned */,
      96,    0,  677,    2, 0x08 /* Private */,
      97,    0,  678,    2, 0x08 /* Private */,
      98,    0,  679,    2, 0x08 /* Private */,
      99,    0,  680,    2, 0x08 /* Private */,
     100,    0,  681,    2, 0x08 /* Private */,
     101,    0,  682,    2, 0x08 /* Private */,
     102,    0,  683,    2, 0x08 /* Private */,
     103,    0,  684,    2, 0x08 /* Private */,
     104,    0,  685,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 7,    4,    5,    6,    8,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 12, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 12, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 7,    4,    5,    6,    8,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QStringList,   24,   25,   26,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QStringList,   24,   25,   26,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QStringList,   24,   25,   26,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QStringList,   24,   25,   26,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,   31,   25,
    QMetaType::Bool, QMetaType::QString,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 55,   56,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   62,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   62,
    QMetaType::Void, QMetaType::QString,   69,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   79,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   82,
    QMetaType::Void, 0x80000000 | 84, QMetaType::QString,   56,   82,
    0x80000000 | 84, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString,   24,   86,   87,   88,
    0x80000000 | 84, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   24,   86,   87,
    0x80000000 | 84, QMetaType::QString, QMetaType::QString,   24,   86,
    0x80000000 | 84, QMetaType::QString,   24,
    0x80000000 | 84,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   24,   90,   91,   92,   93,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   24,   90,   91,   92,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   24,   90,   95,   93,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   24,   90,   95,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void KvMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KvMainWindow *_t = static_cast<KvMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openDbConnectionSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 1: _t->openedDbConnectionSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4]))); break;
        case 2: _t->closeDbConnectionSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->closedDbConnectionSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->cloneSessionSignal((*reinterpret_cast< WId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->clonedSessionSignal((*reinterpret_cast< WId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8]))); break;
        case 6: _t->getSchemasWithTablesSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->getSchemasWithViewsSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->getSchemasWithProgramsSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->getSchemasWithEtcSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: { bool _r = _t->createDbThread((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: _t->startedThreadSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->openedDbConnectionSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4]))); break;
        case 13: _t->closedDbConnectionSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->gotSchemasWithTablesSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 15: _t->gotSchemasWithViewsSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 16: _t->gotSchemasWithProgramsSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 17: _t->gotSchemasWithEtcSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 18: { bool _r = _t->isActiveConnection((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 19: { bool _r = _t->isActiveConnection((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 20: _t->execAutoLogon(); break;
        case 21: _t->updateWindowList(); break;
        case 22: _t->exitSlot(); break;
        case 23: _t->on_actionOpen_triggered(); break;
        case 24: _t->on_actionRefresh_Schemas_triggered(); break;
        case 25: _t->on_actionExport_Database_Objects_triggered(); break;
        case 26: _t->on_actionExport_Data_triggered(); break;
        case 27: _t->on_actionView_DDL_triggered(); break;
        case 28: _t->on_actionRefreshEtcSchema_triggered(); break;
        case 29: _t->on_actionRefreshProgramSchema_triggered(); break;
        case 30: _t->on_actionRefreshViewSchema_triggered(); break;
        case 31: _t->on_actionRefreshTableSchema_triggered(); break;
        case 32: _t->on_actionView_ViewData_triggered(); break;
        case 33: _t->on_actionView_TableData_triggered(); break;
        case 34: _t->on_actionDisconnectAll_triggered(); break;
        case 35: _t->on_actionMain_Tool_Bar_triggered(); break;
        case 36: _t->on_actionClose_triggered(); break;
        case 37: _t->on_actionClose_All_Windows_triggered(); break;
        case 38: _t->on_actionTile_Windows_triggered(); break;
        case 39: _t->on_actionCascade_Windows_triggered(); break;
        case 40: _t->on_listWidgetWindows_itemSelectionChanged(); break;
        case 41: _t->on_actionNew_Sql_triggered(); break;
        case 42: _t->on_mdiArea_subWindowActivated((*reinterpret_cast< QMdiSubWindow*(*)>(_a[1]))); break;
        case 43: _t->on_actionWork_Path_triggered(); break;
        case 44: _t->on_actionWindow_List_triggered(); break;
        case 45: _t->on_actionObjects_triggered(); break;
        case 46: _t->on_actionNavigator_triggered(); break;
        case 47: _t->on_dbTreeWidget_doubleClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 48: _t->on_actionDelete_Connection_triggered(); break;
        case 49: _t->on_actionAdd_Connection_triggered(); break;
        case 50: _t->on_actionDelete_Database_triggered(); break;
        case 51: _t->on_actionEdit_triggered(); break;
        case 52: _t->on_fileTreeView_expanded((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 53: _t->on_activeConnObjComboBox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 54: _t->on_actionPreferences_triggered(); break;
        case 55: _t->on_actionDisconnect_triggered(); break;
        case 56: _t->on_actionConnect_triggered(); break;
        case 57: _t->on_actionAdd_Database_triggered(); break;
        case 58: _t->on_actionAbout_Qt_triggered(); break;
        case 59: _t->on_actionExit_triggered(); break;
        case 60: _t->on_actionAbout_Kevora_triggered(); break;
        case 61: _t->updateViewMenu(); break;
        case 62: _t->closeTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 63: _t->deleteTempThreadSlot(); break;
        case 64: _t->openFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 65: _t->saveFile((*reinterpret_cast< KvSqlWindow*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 66: { KvSqlWindow* _r = _t->newSqlWindow((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< KvSqlWindow**>(_a[0]) = _r; }  break;
        case 67: { KvSqlWindow* _r = _t->newSqlWindow((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< KvSqlWindow**>(_a[0]) = _r; }  break;
        case 68: { KvSqlWindow* _r = _t->newSqlWindow((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< KvSqlWindow**>(_a[0]) = _r; }  break;
        case 69: { KvSqlWindow* _r = _t->newSqlWindow((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< KvSqlWindow**>(_a[0]) = _r; }  break;
        case 70: { KvSqlWindow* _r = _t->newSqlWindow();
            if (_a[0]) *reinterpret_cast< KvSqlWindow**>(_a[0]) = _r; }  break;
        case 71: _t->newDdlWindow((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 72: _t->newDdlWindow((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 73: _t->newExportDataWindow((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 74: _t->newExportDataWindow((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 75: _t->newExportObjectsWindow(); break;
        case 76: _t->loadXml(); break;
        case 77: _t->saveXml(); break;
        case 78: _t->copyXml(); break;
        case 79: { bool _r = _t->runKevoraUpdate();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 80: _t->on_actionKevora_Updates_triggered(); break;
        case 81: _t->on_actionSave_triggered(); break;
        case 82: _t->on_actionSave_As_triggered(); break;
        case 83: _t->on_actionCompare_Database_objects_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 42:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMdiSubWindow* >(); break;
            }
            break;
        case 65:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< KvSqlWindow* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (KvMainWindow::*_t)(QString , QString , QString , QString , QString , QString , QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KvMainWindow::openDbConnectionSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (KvMainWindow::*_t)(QString , QString , QString , QSqlError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KvMainWindow::openedDbConnectionSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (KvMainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KvMainWindow::closeDbConnectionSignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (KvMainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KvMainWindow::closedDbConnectionSignal)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (KvMainWindow::*_t)(WId , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KvMainWindow::cloneSessionSignal)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (KvMainWindow::*_t)(WId , QString , QString , QString , int , QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KvMainWindow::clonedSessionSignal)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (KvMainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KvMainWindow::getSchemasWithTablesSignal)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (KvMainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KvMainWindow::getSchemasWithViewsSignal)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (KvMainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KvMainWindow::getSchemasWithProgramsSignal)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (KvMainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KvMainWindow::getSchemasWithEtcSignal)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject KvMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_KvMainWindow.data,
      qt_meta_data_KvMainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KvMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KvMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KvMainWindow.stringdata0))
        return static_cast<void*>(const_cast< KvMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int KvMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 84)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 84;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 84)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 84;
    }
    return _id;
}

// SIGNAL 0
void KvMainWindow::openDbConnectionSignal(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5, QString _t6, QString _t7, int _t8)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KvMainWindow::openedDbConnectionSignal(QString _t1, QString _t2, QString _t3, QSqlError _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KvMainWindow::closeDbConnectionSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void KvMainWindow::closedDbConnectionSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void KvMainWindow::cloneSessionSignal(WId _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void KvMainWindow::clonedSessionSignal(WId _t1, QString _t2, QString _t3, QString _t4, int _t5, QString _t6, QString _t7, QString _t8)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void KvMainWindow::getSchemasWithTablesSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void KvMainWindow::getSchemasWithViewsSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void KvMainWindow::getSchemasWithProgramsSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void KvMainWindow::getSchemasWithEtcSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
