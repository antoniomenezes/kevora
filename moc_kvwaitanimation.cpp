/****************************************************************************
** Meta object code from reading C++ file 'kvwaitanimation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "kvwaitanimation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kvwaitanimation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KvWaitAnimation_t {
    QByteArrayData data[10];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KvWaitAnimation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KvWaitAnimation_t qt_meta_stringdata_KvWaitAnimation = {
    {
QT_MOC_LITERAL(0, 0, 15), // "KvWaitAnimation"
QT_MOC_LITERAL(1, 16, 12), // "valueChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "value"
QT_MOC_LITERAL(4, 36, 8), // "setValue"
QT_MOC_LITERAL(5, 45, 11), // "setMaxValue"
QT_MOC_LITERAL(6, 57, 11), // "setMinValue"
QT_MOC_LITERAL(7, 69, 13), // "setFirstColor"
QT_MOC_LITERAL(8, 83, 14), // "setSecondColor"
QT_MOC_LITERAL(9, 98, 7) // "refresh"

    },
    "KvWaitAnimation\0valueChanged\0\0value\0"
    "setValue\0setMaxValue\0setMinValue\0"
    "setFirstColor\0setSecondColor\0refresh"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KvWaitAnimation[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   57,    2, 0x0a /* Public */,
       4,    1,   58,    2, 0x0a /* Public */,
       5,    1,   61,    2, 0x0a /* Public */,
       6,    1,   64,    2, 0x0a /* Public */,
       7,    1,   67,    2, 0x0a /* Public */,
       8,    1,   70,    2, 0x0a /* Public */,
       9,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    2,

 // slots: parameters
    QMetaType::Double,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void,

       0        // eod
};

void KvWaitAnimation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KvWaitAnimation *_t = static_cast<KvWaitAnimation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: { double _r = _t->value();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->setValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setMaxValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setMinValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setFirstColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 6: _t->setSecondColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 7: _t->refresh(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KvWaitAnimation::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KvWaitAnimation::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KvWaitAnimation::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_KvWaitAnimation.data,
    qt_meta_data_KvWaitAnimation,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KvWaitAnimation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KvWaitAnimation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KvWaitAnimation.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int KvWaitAnimation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void KvWaitAnimation::valueChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
