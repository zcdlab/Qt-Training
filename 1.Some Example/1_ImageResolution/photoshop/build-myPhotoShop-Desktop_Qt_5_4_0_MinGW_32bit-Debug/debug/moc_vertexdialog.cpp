/****************************************************************************
** Meta object code from reading C++ file 'vertexdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myPhotoShop/vertexdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vertexdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_vertexDialog_t {
    QByteArrayData data[12];
    char stringdata[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vertexDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vertexDialog_t qt_meta_stringdata_vertexDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "vertexDialog"
QT_MOC_LITERAL(1, 13, 13), // "vertexConfirm"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 2), // "x1"
QT_MOC_LITERAL(4, 31, 2), // "x2"
QT_MOC_LITERAL(5, 34, 2), // "y1"
QT_MOC_LITERAL(6, 37, 2), // "y2"
QT_MOC_LITERAL(7, 40, 1), // "r"
QT_MOC_LITERAL(8, 42, 1), // "g"
QT_MOC_LITERAL(9, 44, 1), // "b"
QT_MOC_LITERAL(10, 46, 19), // "on_okButton_clicked"
QT_MOC_LITERAL(11, 66, 23) // "on_cancelButton_clicked"

    },
    "vertexDialog\0vertexConfirm\0\0x1\0x2\0y1\0"
    "y2\0r\0g\0b\0on_okButton_clicked\0"
    "on_cancelButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vertexDialog[] = {

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
       1,    7,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   44,    2, 0x08 /* Private */,
      11,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,    7,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void vertexDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vertexDialog *_t = static_cast<vertexDialog *>(_o);
        switch (_id) {
        case 0: _t->vertexConfirm((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 1: _t->on_okButton_clicked(); break;
        case 2: _t->on_cancelButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (vertexDialog::*_t)(int , int , int , int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&vertexDialog::vertexConfirm)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject vertexDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vertexDialog.data,
      qt_meta_data_vertexDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *vertexDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vertexDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_vertexDialog.stringdata))
        return static_cast<void*>(const_cast< vertexDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int vertexDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void vertexDialog::vertexConfirm(int _t1, int _t2, int _t3, int _t4, int _t5, int _t6, int _t7)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
