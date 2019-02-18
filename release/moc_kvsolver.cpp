/****************************************************************************
** Meta object code from reading C++ file 'kvsolver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../kvsolver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kvsolver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KvSolver_t {
    QByteArrayData data[15];
    char stringdata0[274];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KvSolver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KvSolver_t qt_meta_stringdata_KvSolver = {
    {
QT_MOC_LITERAL(0, 0, 8), // "KvSolver"
QT_MOC_LITERAL(1, 9, 27), // "creationOrderOfObjectSignal"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 17), // "QList<KvDbObject>"
QT_MOC_LITERAL(4, 56, 10), // "objectList"
QT_MOC_LITERAL(5, 67, 10), // "KvDbObject"
QT_MOC_LITERAL(6, 78, 6), // "object"
QT_MOC_LITERAL(7, 85, 11), // "oldPosition"
QT_MOC_LITERAL(8, 97, 11), // "newPosition"
QT_MOC_LITERAL(9, 109, 16), // "completeCreation"
QT_MOC_LITERAL(10, 126, 22), // "creationOrderOfObjects"
QT_MOC_LITERAL(11, 149, 43), // "QPair<QList<KvDbObject>,QList..."
QT_MOC_LITERAL(12, 193, 54), // "QMap<KvDbObject,QList<QPair<K..."
QT_MOC_LITERAL(13, 248, 13), // "objectParents"
QT_MOC_LITERAL(14, 262, 11) // "emitSignals"

    },
    "KvSolver\0creationOrderOfObjectSignal\0"
    "\0QList<KvDbObject>\0objectList\0KvDbObject\0"
    "object\0oldPosition\0newPosition\0"
    "completeCreation\0creationOrderOfObjects\0"
    "QPair<QList<KvDbObject>,QList<KvDbObject> >\0"
    "QMap<KvDbObject,QList<QPair<KvDbObject,KvDbObject> > >\0"
    "objectParents\0emitSignals"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KvSolver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   34,    2, 0x06 /* Public */,
       1,    4,   45,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
      10,    3,   54,    2, 0x0a /* Public */,
      10,    2,   61,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    4,    6,    7,    8,    9,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::Int, QMetaType::Int,    4,    6,    7,    8,

 // slots: parameters
    0x80000000 | 11, 0x80000000 | 3, 0x80000000 | 12, QMetaType::Bool,    4,   13,   14,
    0x80000000 | 11, 0x80000000 | 3, 0x80000000 | 12,    4,   13,

       0        // eod
};

void KvSolver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KvSolver *_t = static_cast<KvSolver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->creationOrderOfObjectSignal((*reinterpret_cast< QList<KvDbObject>(*)>(_a[1])),(*reinterpret_cast< KvDbObject(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 1: _t->creationOrderOfObjectSignal((*reinterpret_cast< QList<KvDbObject>(*)>(_a[1])),(*reinterpret_cast< KvDbObject(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: { QPair<QList<KvDbObject>,QList<KvDbObject> > _r = _t->creationOrderOfObjects((*reinterpret_cast< const QList<KvDbObject>(*)>(_a[1])),(*reinterpret_cast< const QMap<KvDbObject,QList<QPair<KvDbObject,KvDbObject> > >(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QPair<QList<KvDbObject>,QList<KvDbObject> >*>(_a[0]) = std::move(_r); }  break;
        case 3: { QPair<QList<KvDbObject>,QList<KvDbObject> > _r = _t->creationOrderOfObjects((*reinterpret_cast< const QList<KvDbObject>(*)>(_a[1])),(*reinterpret_cast< const QMap<KvDbObject,QList<QPair<KvDbObject,KvDbObject> > >(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPair<QList<KvDbObject>,QList<KvDbObject> >*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KvSolver::*)(QList<KvDbObject> , KvDbObject , int , int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvSolver::creationOrderOfObjectSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KvSolver::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_KvSolver.data,
    qt_meta_data_KvSolver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KvSolver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KvSolver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KvSolver.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int KvSolver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void KvSolver::creationOrderOfObjectSignal(QList<KvDbObject> _t1, KvDbObject _t2, int _t3, int _t4, bool _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
