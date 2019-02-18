/****************************************************************************
** Meta object code from reading C++ file 'kvsqlsessionsqlite.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "kvsqlsessionsqlite.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kvsqlsessionsqlite.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KvSqlSessionSqlite_t {
    QByteArrayData data[9];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KvSqlSessionSqlite_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KvSqlSessionSqlite_t qt_meta_stringdata_KvSqlSessionSqlite = {
    {
QT_MOC_LITERAL(0, 0, 18), // "KvSqlSessionSqlite"
QT_MOC_LITERAL(1, 19, 18), // "sendTablesOfSchema"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 56, 4), // "item"
QT_MOC_LITERAL(5, 61, 6), // "schema"
QT_MOC_LITERAL(6, 68, 6), // "tables"
QT_MOC_LITERAL(7, 75, 17), // "getTablesOfSchema"
QT_MOC_LITERAL(8, 93, 14) // "connectionName"

    },
    "KvSqlSessionSqlite\0sendTablesOfSchema\0"
    "\0QTreeWidgetItem*\0item\0schema\0tables\0"
    "getTablesOfSchema\0connectionName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KvSqlSessionSqlite[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    3,   31,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QStringList,    4,    5,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString,    4,    8,    5,

       0        // eod
};

void KvSqlSessionSqlite::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KvSqlSessionSqlite *_t = static_cast<KvSqlSessionSqlite *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendTablesOfSchema((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 1: _t->getTablesOfSchema((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KvSqlSessionSqlite::*)(QTreeWidgetItem * , const QString & , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSqlSessionSqlite::sendTablesOfSchema)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KvSqlSessionSqlite::staticMetaObject = { {
    &KvSqlSession::staticMetaObject,
    qt_meta_stringdata_KvSqlSessionSqlite.data,
    qt_meta_data_KvSqlSessionSqlite,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KvSqlSessionSqlite::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KvSqlSessionSqlite::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KvSqlSessionSqlite.stringdata0))
        return static_cast<void*>(this);
    return KvSqlSession::qt_metacast(_clname);
}

int KvSqlSessionSqlite::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = KvSqlSession::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void KvSqlSessionSqlite::sendTablesOfSchema(QTreeWidgetItem * _t1, const QString & _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
