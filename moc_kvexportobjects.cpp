/****************************************************************************
** Meta object code from reading C++ file 'kvexportobjects.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "kvexportobjects.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kvexportobjects.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KvExportObjects_t {
    QByteArrayData data[71];
    char stringdata0[1397];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KvExportObjects_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KvExportObjects_t qt_meta_stringdata_KvExportObjects = {
    {
QT_MOC_LITERAL(0, 0, 15), // "KvExportObjects"
QT_MOC_LITERAL(1, 16, 26), // "gotDatabaseObjectTypesSlot"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 12), // "objTypeNames"
QT_MOC_LITERAL(4, 57, 12), // "objTypeOrder"
QT_MOC_LITERAL(5, 70, 26), // "gotTableAndColumnsInfoSlot"
QT_MOC_LITERAL(6, 97, 9), // "objSchema"
QT_MOC_LITERAL(7, 107, 8), // "objTable"
QT_MOC_LITERAL(8, 116, 11), // "KvTableInfo"
QT_MOC_LITERAL(9, 128, 9), // "tableInfo"
QT_MOC_LITERAL(10, 138, 19), // "QList<KvColumnInfo>"
QT_MOC_LITERAL(11, 158, 7), // "columns"
QT_MOC_LITERAL(12, 166, 28), // "QList<KvTableConstraintInfo>"
QT_MOC_LITERAL(13, 195, 11), // "constraints"
QT_MOC_LITERAL(14, 207, 20), // "gotDdlFromObjectSlot"
QT_MOC_LITERAL(15, 228, 11), // "sessionName"
QT_MOC_LITERAL(16, 240, 6), // "schema"
QT_MOC_LITERAL(17, 247, 10), // "objectName"
QT_MOC_LITERAL(18, 258, 10), // "objectType"
QT_MOC_LITERAL(19, 269, 10), // "showSchema"
QT_MOC_LITERAL(20, 280, 6), // "result"
QT_MOC_LITERAL(21, 287, 22), // "KvSqlSession::DdlTypes"
QT_MOC_LITERAL(22, 310, 7), // "ddlType"
QT_MOC_LITERAL(23, 318, 11), // "saveObjects"
QT_MOC_LITERAL(24, 330, 13), // "exportObjects"
QT_MOC_LITERAL(25, 344, 19), // "enableSearchWidgets"
QT_MOC_LITERAL(26, 364, 5), // "value"
QT_MOC_LITERAL(27, 370, 43), // "on_comboBoxOutputChoice_curre..."
QT_MOC_LITERAL(28, 414, 5), // "index"
QT_MOC_LITERAL(29, 420, 46), // "on_actionAdd_All_Objects_to_S..."
QT_MOC_LITERAL(30, 467, 39), // "on_actionSet_Default_Only_One..."
QT_MOC_LITERAL(31, 507, 33), // "on_actionExport_Objects_trigg..."
QT_MOC_LITERAL(32, 541, 27), // "on_pushButtonCancel_clicked"
QT_MOC_LITERAL(33, 569, 28), // "copySelectedToExportedWidget"
QT_MOC_LITERAL(34, 598, 40), // "on_stackedWidgetExportObj_cur..."
QT_MOC_LITERAL(35, 639, 33), // "on_actionClear_Selected_trigg..."
QT_MOC_LITERAL(36, 673, 39), // "on_actionRemove_from_Selected..."
QT_MOC_LITERAL(37, 713, 42), // "on_actionAdd_Objects_to_Selec..."
QT_MOC_LITERAL(38, 756, 35), // "on_toolButtonCancelFetchAll_c..."
QT_MOC_LITERAL(39, 792, 31), // "on_toolButtonAllRecords_clicked"
QT_MOC_LITERAL(40, 824, 32), // "on_toolButtonNextRecords_clicked"
QT_MOC_LITERAL(41, 857, 31), // "on_actionFind_Objects_triggered"
QT_MOC_LITERAL(42, 889, 35), // "on_currentSessionComboBox_act..."
QT_MOC_LITERAL(43, 925, 4), // "text"
QT_MOC_LITERAL(44, 930, 25), // "on_pushButtonBack_clicked"
QT_MOC_LITERAL(45, 956, 31), // "on_pushButtonNextFinish_clicked"
QT_MOC_LITERAL(46, 988, 16), // "addActiveSession"
QT_MOC_LITERAL(47, 1005, 7), // "session"
QT_MOC_LITERAL(48, 1013, 19), // "removeActiveSession"
QT_MOC_LITERAL(49, 1033, 25), // "updateActiveSessionsCombo"
QT_MOC_LITERAL(50, 1059, 19), // "setComboSessionName"
QT_MOC_LITERAL(51, 1079, 26), // "gotFindObjectStatementSlot"
QT_MOC_LITERAL(52, 1106, 14), // "fullObjectName"
QT_MOC_LITERAL(53, 1121, 9), // "statement"
QT_MOC_LITERAL(54, 1131, 17), // "executedQuerySlot"
QT_MOC_LITERAL(55, 1149, 12), // "sqlStatement"
QT_MOC_LITERAL(56, 1162, 17), // "QList<QSqlRecord>"
QT_MOC_LITERAL(57, 1180, 7), // "records"
QT_MOC_LITERAL(58, 1188, 11), // "recordCount"
QT_MOC_LITERAL(59, 1200, 9), // "QSqlError"
QT_MOC_LITERAL(60, 1210, 5), // "error"
QT_MOC_LITERAL(61, 1216, 14), // "sqlStatementId"
QT_MOC_LITERAL(62, 1231, 18), // "gotNextRecordsSlot"
QT_MOC_LITERAL(63, 1250, 10), // "allRecords"
QT_MOC_LITERAL(64, 1261, 17), // "updateRecordCount"
QT_MOC_LITERAL(65, 1279, 10), // "partNumber"
QT_MOC_LITERAL(66, 1290, 11), // "totalNumber"
QT_MOC_LITERAL(67, 1302, 19), // "updateSelectedCount"
QT_MOC_LITERAL(68, 1322, 23), // "generateOutputFileNames"
QT_MOC_LITERAL(69, 1346, 16), // "setOutputOptions"
QT_MOC_LITERAL(70, 1363, 33) // "on_comboBoxOutputFormat_activ..."

    },
    "KvExportObjects\0gotDatabaseObjectTypesSlot\0"
    "\0objTypeNames\0objTypeOrder\0"
    "gotTableAndColumnsInfoSlot\0objSchema\0"
    "objTable\0KvTableInfo\0tableInfo\0"
    "QList<KvColumnInfo>\0columns\0"
    "QList<KvTableConstraintInfo>\0constraints\0"
    "gotDdlFromObjectSlot\0sessionName\0"
    "schema\0objectName\0objectType\0showSchema\0"
    "result\0KvSqlSession::DdlTypes\0ddlType\0"
    "saveObjects\0exportObjects\0enableSearchWidgets\0"
    "value\0on_comboBoxOutputChoice_currentIndexChanged\0"
    "index\0on_actionAdd_All_Objects_to_Selected_triggered\0"
    "on_actionSet_Default_Only_One_triggered\0"
    "on_actionExport_Objects_triggered\0"
    "on_pushButtonCancel_clicked\0"
    "copySelectedToExportedWidget\0"
    "on_stackedWidgetExportObj_currentChanged\0"
    "on_actionClear_Selected_triggered\0"
    "on_actionRemove_from_Selected_triggered\0"
    "on_actionAdd_Objects_to_Selected_triggered\0"
    "on_toolButtonCancelFetchAll_clicked\0"
    "on_toolButtonAllRecords_clicked\0"
    "on_toolButtonNextRecords_clicked\0"
    "on_actionFind_Objects_triggered\0"
    "on_currentSessionComboBox_activated\0"
    "text\0on_pushButtonBack_clicked\0"
    "on_pushButtonNextFinish_clicked\0"
    "addActiveSession\0session\0removeActiveSession\0"
    "updateActiveSessionsCombo\0setComboSessionName\0"
    "gotFindObjectStatementSlot\0fullObjectName\0"
    "statement\0executedQuerySlot\0sqlStatement\0"
    "QList<QSqlRecord>\0records\0recordCount\0"
    "QSqlError\0error\0sqlStatementId\0"
    "gotNextRecordsSlot\0allRecords\0"
    "updateRecordCount\0partNumber\0totalNumber\0"
    "updateSelectedCount\0generateOutputFileNames\0"
    "setOutputOptions\0on_comboBoxOutputFormat_activated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KvExportObjects[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      38,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,  204,    2, 0x0a /* Public */,
       5,    5,  209,    2, 0x0a /* Public */,
      14,    7,  220,    2, 0x08 /* Private */,
      23,    0,  235,    2, 0x08 /* Private */,
      24,    0,  236,    2, 0x08 /* Private */,
      25,    1,  237,    2, 0x08 /* Private */,
      27,    1,  240,    2, 0x08 /* Private */,
      29,    0,  243,    2, 0x08 /* Private */,
      30,    0,  244,    2, 0x08 /* Private */,
      31,    0,  245,    2, 0x08 /* Private */,
      32,    0,  246,    2, 0x08 /* Private */,
      33,    0,  247,    2, 0x08 /* Private */,
      34,    1,  248,    2, 0x08 /* Private */,
      35,    0,  251,    2, 0x08 /* Private */,
      36,    0,  252,    2, 0x08 /* Private */,
      37,    0,  253,    2, 0x08 /* Private */,
      38,    0,  254,    2, 0x08 /* Private */,
      39,    0,  255,    2, 0x08 /* Private */,
      40,    0,  256,    2, 0x08 /* Private */,
      41,    0,  257,    2, 0x08 /* Private */,
      42,    1,  258,    2, 0x08 /* Private */,
      44,    0,  261,    2, 0x08 /* Private */,
      45,    0,  262,    2, 0x08 /* Private */,
      46,    1,  263,    2, 0x08 /* Private */,
      48,    1,  266,    2, 0x08 /* Private */,
      49,    0,  269,    2, 0x08 /* Private */,
      50,    1,  270,    2, 0x08 /* Private */,
      51,    2,  273,    2, 0x08 /* Private */,
      54,    5,  278,    2, 0x08 /* Private */,
      54,    4,  289,    2, 0x28 /* Private | MethodCloned */,
      62,    6,  298,    2, 0x08 /* Private */,
      62,    5,  311,    2, 0x28 /* Private | MethodCloned */,
      62,    4,  322,    2, 0x28 /* Private | MethodCloned */,
      64,    2,  331,    2, 0x08 /* Private */,
      67,    0,  336,    2, 0x08 /* Private */,
      68,    1,  337,    2, 0x08 /* Private */,
      69,    0,  340,    2, 0x08 /* Private */,
      70,    1,  341,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 8, 0x80000000 | 10, 0x80000000 | 12,    6,    7,    9,   11,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QStringList, 0x80000000 | 21,   15,   16,   17,   18,   19,   20,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   43,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   47,
    QMetaType::Void, QMetaType::QString,   47,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   52,   53,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 56, QMetaType::Int, 0x80000000 | 59, QMetaType::QString,   55,   57,   58,   60,   61,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 56, QMetaType::Int, 0x80000000 | 59,   55,   57,   58,   60,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 56, QMetaType::Int, 0x80000000 | 59, QMetaType::Bool, QMetaType::QString,   55,   57,   58,   60,   63,   61,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 56, QMetaType::Int, 0x80000000 | 59, QMetaType::Bool,   55,   57,   58,   60,   63,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 56, QMetaType::Int, 0x80000000 | 59,   55,   57,   58,   60,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   65,   66,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   28,

       0        // eod
};

void KvExportObjects::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KvExportObjects *_t = static_cast<KvExportObjects *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gotDatabaseObjectTypesSlot((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 1: _t->gotTableAndColumnsInfoSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< KvTableInfo(*)>(_a[3])),(*reinterpret_cast< QList<KvColumnInfo>(*)>(_a[4])),(*reinterpret_cast< QList<KvTableConstraintInfo>(*)>(_a[5]))); break;
        case 2: _t->gotDdlFromObjectSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< QStringList(*)>(_a[6])),(*reinterpret_cast< KvSqlSession::DdlTypes(*)>(_a[7]))); break;
        case 3: _t->saveObjects(); break;
        case 4: _t->exportObjects(); break;
        case 5: _t->enableSearchWidgets((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_comboBoxOutputChoice_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_actionAdd_All_Objects_to_Selected_triggered(); break;
        case 8: _t->on_actionSet_Default_Only_One_triggered(); break;
        case 9: _t->on_actionExport_Objects_triggered(); break;
        case 10: _t->on_pushButtonCancel_clicked(); break;
        case 11: _t->copySelectedToExportedWidget(); break;
        case 12: _t->on_stackedWidgetExportObj_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_actionClear_Selected_triggered(); break;
        case 14: _t->on_actionRemove_from_Selected_triggered(); break;
        case 15: _t->on_actionAdd_Objects_to_Selected_triggered(); break;
        case 16: _t->on_toolButtonCancelFetchAll_clicked(); break;
        case 17: _t->on_toolButtonAllRecords_clicked(); break;
        case 18: _t->on_toolButtonNextRecords_clicked(); break;
        case 19: _t->on_actionFind_Objects_triggered(); break;
        case 20: _t->on_currentSessionComboBox_activated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->on_pushButtonBack_clicked(); break;
        case 22: _t->on_pushButtonNextFinish_clicked(); break;
        case 23: _t->addActiveSession((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: _t->removeActiveSession((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: _t->updateActiveSessionsCombo(); break;
        case 26: _t->setComboSessionName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: _t->gotFindObjectStatementSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 28: _t->executedQuerySlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 29: _t->executedQuerySlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4]))); break;
        case 30: _t->gotNextRecordsSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 31: _t->gotNextRecordsSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 32: _t->gotNextRecordsSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QSqlRecord>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QSqlError(*)>(_a[4]))); break;
        case 33: _t->updateRecordCount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 34: _t->updateSelectedCount(); break;
        case 35: _t->generateOutputFileNames((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->setOutputOptions(); break;
        case 37: _t->on_comboBoxOutputFormat_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject KvExportObjects::staticMetaObject = {
    { &KvSqlDialog::staticMetaObject, qt_meta_stringdata_KvExportObjects.data,
      qt_meta_data_KvExportObjects,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KvExportObjects::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KvExportObjects::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KvExportObjects.stringdata0))
        return static_cast<void*>(const_cast< KvExportObjects*>(this));
    return KvSqlDialog::qt_metacast(_clname);
}

int KvExportObjects::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = KvSqlDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 38)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 38;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
