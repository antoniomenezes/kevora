/****************************************************************************
** Meta object code from reading C++ file 'kvtreewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "kvtreewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kvtreewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KvTreeWidget_t {
    QByteArrayData data[25];
    char stringdata0[416];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KvTreeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KvTreeWidget_t qt_meta_stringdata_KvTreeWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "KvTreeWidget"
QT_MOC_LITERAL(1, 13, 25), // "databaseTreeConnectionOff"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 14), // "connectionName"
QT_MOC_LITERAL(4, 55, 8), // "userName"
QT_MOC_LITERAL(5, 64, 23), // "objectTreeConnectionOff"
QT_MOC_LITERAL(6, 88, 24), // "getObjectsOfSchemaSignal"
QT_MOC_LITERAL(7, 113, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(8, 130, 4), // "item"
QT_MOC_LITERAL(9, 135, 6), // "schema"
QT_MOC_LITERAL(10, 142, 23), // "getGroupsOfSchemaSignal"
QT_MOC_LITERAL(11, 166, 30), // "getGroupElementsOfSchemaSignal"
QT_MOC_LITERAL(12, 197, 4), // "type"
QT_MOC_LITERAL(13, 202, 26), // "currentDatabaseItemChanged"
QT_MOC_LITERAL(14, 229, 7), // "current"
QT_MOC_LITERAL(15, 237, 8), // "previous"
QT_MOC_LITERAL(16, 246, 14), // "onItemExpanded"
QT_MOC_LITERAL(17, 261, 16), // "itemErrorClicked"
QT_MOC_LITERAL(18, 278, 6), // "column"
QT_MOC_LITERAL(19, 285, 17), // "turnConnectionOff"
QT_MOC_LITERAL(20, 303, 22), // "gotObjectsOfSchemaSlot"
QT_MOC_LITERAL(21, 326, 7), // "objects"
QT_MOC_LITERAL(22, 334, 21), // "gotGroupsOfSchemaSlot"
QT_MOC_LITERAL(23, 356, 28), // "gotGroupElementsOfSchemaSlot"
QT_MOC_LITERAL(24, 385, 30) // "QList<QPair<QString,QString> >"

    },
    "KvTreeWidget\0databaseTreeConnectionOff\0"
    "\0connectionName\0userName\0"
    "objectTreeConnectionOff\0"
    "getObjectsOfSchemaSignal\0QTreeWidgetItem*\0"
    "item\0schema\0getGroupsOfSchemaSignal\0"
    "getGroupElementsOfSchemaSignal\0type\0"
    "currentDatabaseItemChanged\0current\0"
    "previous\0onItemExpanded\0itemErrorClicked\0"
    "column\0turnConnectionOff\0"
    "gotObjectsOfSchemaSlot\0objects\0"
    "gotGroupsOfSchemaSlot\0"
    "gotGroupElementsOfSchemaSlot\0"
    "QList<QPair<QString,QString> >"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KvTreeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       5,    2,   79,    2, 0x06 /* Public */,
       6,    3,   84,    2, 0x06 /* Public */,
      10,    3,   91,    2, 0x06 /* Public */,
      11,    4,   98,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    2,  107,    2, 0x0a /* Public */,
      16,    1,  112,    2, 0x0a /* Public */,
      17,    2,  115,    2, 0x0a /* Public */,
      19,    2,  120,    2, 0x0a /* Public */,
      20,    3,  125,    2, 0x0a /* Public */,
      22,    3,  132,    2, 0x0a /* Public */,
      23,    4,  139,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QString, QMetaType::QString,    8,    3,    9,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QString, QMetaType::QString,    8,    3,    9,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    3,    9,   12,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,   14,   15,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,   18,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QString, QMetaType::QStringList,    8,    9,   21,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QString, QMetaType::QStringList,    8,    9,   21,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QString, QMetaType::QString, 0x80000000 | 24,    8,    9,   12,   21,

       0        // eod
};

void KvTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KvTreeWidget *_t = static_cast<KvTreeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->databaseTreeConnectionOff((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->objectTreeConnectionOff((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->getObjectsOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 3: _t->getGroupsOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 4: _t->getGroupElementsOfSchemaSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 5: _t->currentDatabaseItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        case 6: _t->onItemExpanded((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 7: _t->itemErrorClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->turnConnectionOff((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->gotObjectsOfSchemaSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 10: _t->gotGroupsOfSchemaSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 11: _t->gotGroupElementsOfSchemaSlot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< QList<QPair<QString,QString> >(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (KvTreeWidget::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KvTreeWidget::databaseTreeConnectionOff)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (KvTreeWidget::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KvTreeWidget::objectTreeConnectionOff)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (KvTreeWidget::*_t)(QTreeWidgetItem * , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KvTreeWidget::getObjectsOfSchemaSignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (KvTreeWidget::*_t)(QTreeWidgetItem * , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KvTreeWidget::getGroupsOfSchemaSignal)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (KvTreeWidget::*_t)(QTreeWidgetItem * , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KvTreeWidget::getGroupElementsOfSchemaSignal)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject KvTreeWidget::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_KvTreeWidget.data,
      qt_meta_data_KvTreeWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KvTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KvTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KvTreeWidget.stringdata0))
        return static_cast<void*>(const_cast< KvTreeWidget*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int KvTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void KvTreeWidget::databaseTreeConnectionOff(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KvTreeWidget::objectTreeConnectionOff(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KvTreeWidget::getObjectsOfSchemaSignal(QTreeWidgetItem * _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void KvTreeWidget::getGroupsOfSchemaSignal(QTreeWidgetItem * _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void KvTreeWidget::getGroupElementsOfSchemaSignal(QTreeWidgetItem * _t1, const QString & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
