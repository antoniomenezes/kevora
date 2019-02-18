/****************************************************************************
** Meta object code from reading C++ file 'kvsettingsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../kvsettingsdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kvsettingsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KvSettingsDialog_t {
    QByteArrayData data[60];
    char stringdata0[1531];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KvSettingsDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KvSettingsDialog_t qt_meta_stringdata_KvSettingsDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "KvSettingsDialog"
QT_MOC_LITERAL(1, 17, 19), // "needsToSaveSettings"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 25), // "changedConnectionsFileDir"
QT_MOC_LITERAL(4, 64, 19), // "saveConnectionsFile"
QT_MOC_LITERAL(5, 84, 31), // "on_lineEditWorkPath_textChanged"
QT_MOC_LITERAL(6, 116, 42), // "on_lineEditConnectionsFilePat..."
QT_MOC_LITERAL(7, 159, 21), // "on_buttonBox_rejected"
QT_MOC_LITERAL(8, 181, 39), // "on_comboBoxGuiStyle_currentIn..."
QT_MOC_LITERAL(9, 221, 11), // "currentText"
QT_MOC_LITERAL(10, 233, 24), // "on_workDirButton_clicked"
QT_MOC_LITERAL(11, 258, 24), // "on_connDirButton_clicked"
QT_MOC_LITERAL(12, 283, 31), // "on_lineEditLangPath_textChanged"
QT_MOC_LITERAL(13, 315, 4), // "text"
QT_MOC_LITERAL(14, 320, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(15, 342, 25), // "on_langComboBox_activated"
QT_MOC_LITERAL(16, 368, 24), // "on_langDirButton_clicked"
QT_MOC_LITERAL(17, 393, 30), // "on_sqliteDrvInfoButton_clicked"
QT_MOC_LITERAL(18, 424, 34), // "on_postgresqlDrvInfoButton_cl..."
QT_MOC_LITERAL(19, 459, 30), // "on_oracleDrvInfoButton_clicked"
QT_MOC_LITERAL(20, 490, 28), // "on_odbcDrvInfoButton_clicked"
QT_MOC_LITERAL(21, 519, 29), // "on_mysqlDrvInfoButton_clicked"
QT_MOC_LITERAL(22, 549, 32), // "on_firebirdDrvInfoButton_clicked"
QT_MOC_LITERAL(23, 582, 44), // "on_prefDrvSqliteComboBox_curr..."
QT_MOC_LITERAL(24, 627, 5), // "index"
QT_MOC_LITERAL(25, 633, 48), // "on_prefDrvPostgreSqlComboBox_..."
QT_MOC_LITERAL(26, 682, 44), // "on_prefDrvOracleComboBox_curr..."
QT_MOC_LITERAL(27, 727, 42), // "on_prefDrvODBCComboBox_curren..."
QT_MOC_LITERAL(28, 770, 43), // "on_prefDrvMySqlComboBox_curre..."
QT_MOC_LITERAL(29, 814, 46), // "on_prefDrvFirebirdComboBox_cu..."
QT_MOC_LITERAL(30, 861, 11), // "setLanguage"
QT_MOC_LITERAL(31, 873, 8), // "langCode"
QT_MOC_LITERAL(32, 882, 21), // "setNeedToSaveSettings"
QT_MOC_LITERAL(33, 904, 26), // "on_tableWidget_7_activated"
QT_MOC_LITERAL(34, 931, 11), // "QModelIndex"
QT_MOC_LITERAL(35, 943, 39), // "on_tableWidgetColorScheme_cel..."
QT_MOC_LITERAL(36, 983, 3), // "row"
QT_MOC_LITERAL(37, 987, 6), // "column"
QT_MOC_LITERAL(38, 994, 44), // "on_tableWidgetColorScheme_cur..."
QT_MOC_LITERAL(39, 1039, 10), // "currentRow"
QT_MOC_LITERAL(40, 1050, 13), // "currentColumn"
QT_MOC_LITERAL(41, 1064, 11), // "previousRow"
QT_MOC_LITERAL(42, 1076, 14), // "previousColumn"
QT_MOC_LITERAL(43, 1091, 28), // "on_toolButtonClearFg_clicked"
QT_MOC_LITERAL(44, 1120, 28), // "on_toolButtonClearBg_clicked"
QT_MOC_LITERAL(45, 1149, 23), // "on_checkBoxBold_toggled"
QT_MOC_LITERAL(46, 1173, 7), // "checked"
QT_MOC_LITERAL(47, 1181, 25), // "on_checkBoxItalic_toggled"
QT_MOC_LITERAL(48, 1207, 31), // "on_pushButtonCopyScheme_clicked"
QT_MOC_LITERAL(49, 1239, 42), // "on_comboBoxColorScheme_curren..."
QT_MOC_LITERAL(50, 1282, 4), // "arg1"
QT_MOC_LITERAL(51, 1287, 22), // "updateColorSchemeTable"
QT_MOC_LITERAL(52, 1310, 15), // "colorSchemeName"
QT_MOC_LITERAL(53, 1326, 28), // "on_toolButtonFgColor_clicked"
QT_MOC_LITERAL(54, 1355, 28), // "on_toolButtonBgColor_clicked"
QT_MOC_LITERAL(55, 1384, 33), // "on_pushButtonDeleteScheme_cli..."
QT_MOC_LITERAL(56, 1418, 44), // "on_prefDrvCubridComboBox_curr..."
QT_MOC_LITERAL(57, 1463, 30), // "on_cubridDrvInfoButton_clicked"
QT_MOC_LITERAL(58, 1494, 29), // "enableConnectionsFileDirAlert"
QT_MOC_LITERAL(59, 1524, 6) // "enable"

    },
    "KvSettingsDialog\0needsToSaveSettings\0"
    "\0changedConnectionsFileDir\0"
    "saveConnectionsFile\0on_lineEditWorkPath_textChanged\0"
    "on_lineEditConnectionsFilePath_textChanged\0"
    "on_buttonBox_rejected\0"
    "on_comboBoxGuiStyle_currentIndexChanged\0"
    "currentText\0on_workDirButton_clicked\0"
    "on_connDirButton_clicked\0"
    "on_lineEditLangPath_textChanged\0text\0"
    "on_buttonBox_accepted\0on_langComboBox_activated\0"
    "on_langDirButton_clicked\0"
    "on_sqliteDrvInfoButton_clicked\0"
    "on_postgresqlDrvInfoButton_clicked\0"
    "on_oracleDrvInfoButton_clicked\0"
    "on_odbcDrvInfoButton_clicked\0"
    "on_mysqlDrvInfoButton_clicked\0"
    "on_firebirdDrvInfoButton_clicked\0"
    "on_prefDrvSqliteComboBox_currentIndexChanged\0"
    "index\0on_prefDrvPostgreSqlComboBox_currentIndexChanged\0"
    "on_prefDrvOracleComboBox_currentIndexChanged\0"
    "on_prefDrvODBCComboBox_currentIndexChanged\0"
    "on_prefDrvMySqlComboBox_currentIndexChanged\0"
    "on_prefDrvFirebirdComboBox_currentIndexChanged\0"
    "setLanguage\0langCode\0setNeedToSaveSettings\0"
    "on_tableWidget_7_activated\0QModelIndex\0"
    "on_tableWidgetColorScheme_cellActivated\0"
    "row\0column\0on_tableWidgetColorScheme_currentCellChanged\0"
    "currentRow\0currentColumn\0previousRow\0"
    "previousColumn\0on_toolButtonClearFg_clicked\0"
    "on_toolButtonClearBg_clicked\0"
    "on_checkBoxBold_toggled\0checked\0"
    "on_checkBoxItalic_toggled\0"
    "on_pushButtonCopyScheme_clicked\0"
    "on_comboBoxColorScheme_currentIndexChanged\0"
    "arg1\0updateColorSchemeTable\0colorSchemeName\0"
    "on_toolButtonFgColor_clicked\0"
    "on_toolButtonBgColor_clicked\0"
    "on_pushButtonDeleteScheme_clicked\0"
    "on_prefDrvCubridComboBox_currentIndexChanged\0"
    "on_cubridDrvInfoButton_clicked\0"
    "enableConnectionsFileDirAlert\0enable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KvSettingsDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      44,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  234,    2, 0x06 /* Public */,
       3,    0,  235,    2, 0x06 /* Public */,
       4,    0,  236,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,  237,    2, 0x08 /* Private */,
       6,    1,  240,    2, 0x08 /* Private */,
       7,    0,  243,    2, 0x08 /* Private */,
       8,    1,  244,    2, 0x08 /* Private */,
      10,    0,  247,    2, 0x08 /* Private */,
      11,    0,  248,    2, 0x08 /* Private */,
      12,    1,  249,    2, 0x08 /* Private */,
      14,    0,  252,    2, 0x08 /* Private */,
      15,    1,  253,    2, 0x08 /* Private */,
      16,    0,  256,    2, 0x08 /* Private */,
      17,    0,  257,    2, 0x08 /* Private */,
      18,    0,  258,    2, 0x08 /* Private */,
      19,    0,  259,    2, 0x08 /* Private */,
      20,    0,  260,    2, 0x08 /* Private */,
      21,    0,  261,    2, 0x08 /* Private */,
      22,    0,  262,    2, 0x08 /* Private */,
      23,    1,  263,    2, 0x08 /* Private */,
      25,    1,  266,    2, 0x08 /* Private */,
      26,    1,  269,    2, 0x08 /* Private */,
      27,    1,  272,    2, 0x08 /* Private */,
      28,    1,  275,    2, 0x08 /* Private */,
      29,    1,  278,    2, 0x08 /* Private */,
      30,    1,  281,    2, 0x08 /* Private */,
      32,    0,  284,    2, 0x08 /* Private */,
      33,    1,  285,    2, 0x08 /* Private */,
      35,    2,  288,    2, 0x08 /* Private */,
      38,    4,  293,    2, 0x08 /* Private */,
      43,    0,  302,    2, 0x08 /* Private */,
      44,    0,  303,    2, 0x08 /* Private */,
      45,    1,  304,    2, 0x08 /* Private */,
      47,    1,  307,    2, 0x08 /* Private */,
      48,    0,  310,    2, 0x08 /* Private */,
      49,    1,  311,    2, 0x08 /* Private */,
      51,    1,  314,    2, 0x08 /* Private */,
      53,    0,  317,    2, 0x08 /* Private */,
      54,    0,  318,    2, 0x08 /* Private */,
      55,    0,  319,    2, 0x08 /* Private */,
      56,    1,  320,    2, 0x08 /* Private */,
      57,    0,  323,    2, 0x08 /* Private */,
      58,    1,  324,    2, 0x0a /* Public */,
      58,    0,  327,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 34,   24,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   36,   37,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   39,   40,   41,   42,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   46,
    QMetaType::Void, QMetaType::Bool,   46,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void, QMetaType::QString,   52,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   59,
    QMetaType::Void,

       0        // eod
};

void KvSettingsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KvSettingsDialog *_t = static_cast<KvSettingsDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->needsToSaveSettings(); break;
        case 1: _t->changedConnectionsFileDir(); break;
        case 2: _t->saveConnectionsFile(); break;
        case 3: _t->on_lineEditWorkPath_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_lineEditConnectionsFilePath_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_buttonBox_rejected(); break;
        case 6: _t->on_comboBoxGuiStyle_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->on_workDirButton_clicked(); break;
        case 8: _t->on_connDirButton_clicked(); break;
        case 9: _t->on_lineEditLangPath_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->on_buttonBox_accepted(); break;
        case 11: _t->on_langComboBox_activated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->on_langDirButton_clicked(); break;
        case 13: _t->on_sqliteDrvInfoButton_clicked(); break;
        case 14: _t->on_postgresqlDrvInfoButton_clicked(); break;
        case 15: _t->on_oracleDrvInfoButton_clicked(); break;
        case 16: _t->on_odbcDrvInfoButton_clicked(); break;
        case 17: _t->on_mysqlDrvInfoButton_clicked(); break;
        case 18: _t->on_firebirdDrvInfoButton_clicked(); break;
        case 19: _t->on_prefDrvSqliteComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->on_prefDrvPostgreSqlComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->on_prefDrvOracleComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_prefDrvODBCComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_prefDrvMySqlComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_prefDrvFirebirdComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->setLanguage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: _t->setNeedToSaveSettings(); break;
        case 27: _t->on_tableWidget_7_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 28: _t->on_tableWidgetColorScheme_cellActivated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 29: _t->on_tableWidgetColorScheme_currentCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 30: _t->on_toolButtonClearFg_clicked(); break;
        case 31: _t->on_toolButtonClearBg_clicked(); break;
        case 32: _t->on_checkBoxBold_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->on_checkBoxItalic_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->on_pushButtonCopyScheme_clicked(); break;
        case 35: _t->on_comboBoxColorScheme_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 36: _t->updateColorSchemeTable((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 37: _t->on_toolButtonFgColor_clicked(); break;
        case 38: _t->on_toolButtonBgColor_clicked(); break;
        case 39: _t->on_pushButtonDeleteScheme_clicked(); break;
        case 40: _t->on_prefDrvCubridComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->on_cubridDrvInfoButton_clicked(); break;
        case 42: _t->enableConnectionsFileDirAlert((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: _t->enableConnectionsFileDirAlert(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KvSettingsDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSettingsDialog::needsToSaveSettings)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (KvSettingsDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSettingsDialog::changedConnectionsFileDir)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (KvSettingsDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSettingsDialog::saveConnectionsFile)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KvSettingsDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_KvSettingsDialog.data,
    qt_meta_data_KvSettingsDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KvSettingsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KvSettingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KvSettingsDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int KvSettingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 44)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 44;
    }
    return _id;
}

// SIGNAL 0
void KvSettingsDialog::needsToSaveSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void KvSettingsDialog::changedConnectionsFileDir()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void KvSettingsDialog::saveConnectionsFile()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
