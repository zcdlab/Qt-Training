/****************************************************************************
** Meta object code from reading C++ file 'matrixdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myPhotoShop/matrixdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'matrixdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_matrixDialog_t {
    QByteArrayData data[14];
    char stringdata[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_matrixDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_matrixDialog_t qt_meta_stringdata_matrixDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "matrixDialog"
QT_MOC_LITERAL(1, 13, 13), // "matrixConfirm"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 2), // "a1"
QT_MOC_LITERAL(4, 31, 2), // "a2"
QT_MOC_LITERAL(5, 34, 2), // "a3"
QT_MOC_LITERAL(6, 37, 2), // "b1"
QT_MOC_LITERAL(7, 40, 2), // "b2"
QT_MOC_LITERAL(8, 43, 2), // "b3"
QT_MOC_LITERAL(9, 46, 2), // "c1"
QT_MOC_LITERAL(10, 49, 2), // "c2"
QT_MOC_LITERAL(11, 52, 2), // "c3"
QT_MOC_LITERAL(12, 55, 19), // "on_okButton_clicked"
QT_MOC_LITERAL(13, 75, 23) // "on_cancelButton_clicked"

    },
    "matrixDialog\0matrixConfirm\0\0a1\0a2\0a3\0"
    "b1\0b2\0b3\0c1\0c2\0c3\0on_okButton_clicked\0"
    "on_cancelButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_matrixDialog[] = {

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
       1,    9,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   48,    2, 0x08 /* Private */,
      13,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    3,    4,    5,    6,    7,    8,    9,   10,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void matrixDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        matrixDialog *_t = static_cast<matrixDialog *>(_o);
        switch (_id) {
        case 0: _t->matrixConfirm((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8])),(*reinterpret_cast< double(*)>(_a[9]))); break;
        case 1: _t->on_okButton_clicked(); break;
        case 2: _t->on_cancelButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (matrixDialog::*_t)(double , double , double , double , double , double , double , double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&matrixDialog::matrixConfirm)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject matrixDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_matrixDialog.data,
      qt_meta_data_matrixDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *matrixDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *matrixDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_matrixDialog.stringdata))
        return static_cast<void*>(const_cast< matrixDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int matrixDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void matrixDialog::matrixConfirm(double _t1, double _t2, double _t3, double _t4, double _t5, double _t6, double _t7, double _t8, double _t9)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
