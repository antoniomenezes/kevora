/****************************************************************************
** Meta object code from reading C++ file 'kvcodeeditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "kvcodeeditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kvcodeeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KvCodeEditor_t {
    QByteArrayData data[6];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KvCodeEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KvCodeEditor_t qt_meta_stringdata_KvCodeEditor = {
    {
QT_MOC_LITERAL(0, 0, 12), // "KvCodeEditor"
QT_MOC_LITERAL(1, 13, 14), // "openFileSignal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 25), // "updateLineNumberAreaWidth"
QT_MOC_LITERAL(4, 55, 13), // "newBlockCount"
QT_MOC_LITERAL(5, 69, 20) // "updateLineNumberArea"

    },
    "KvCodeEditor\0openFileSignal\0\0"
    "updateLineNumberAreaWidth\0newBlockCount\0"
    "updateLineNumberArea"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KvCodeEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   32,    2, 0x08 /* Private */,
       5,    2,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::QRect, QMetaType::Int,    2,    2,

       0        // eod
};

void KvCodeEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KvCodeEditor *_t = static_cast<KvCodeEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openFileSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->updateLineNumberAreaWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->updateLineNumberArea((*reinterpret_cast< const QRect(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (KvCodeEditor::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KvCodeEditor::openFileSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject KvCodeEditor::staticMetaObject = {
    { &QPlainTextEdit::staticMetaObject, qt_meta_stringdata_KvCodeEditor.data,
      qt_meta_data_KvCodeEditor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KvCodeEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KvCodeEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KvCodeEditor.stringdata0))
        return static_cast<void*>(const_cast< KvCodeEditor*>(this));
    return QPlainTextEdit::qt_metacast(_clname);
}

int KvCodeEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void KvCodeEditor::openFileSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE