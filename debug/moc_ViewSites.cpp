/****************************************************************************
** Meta object code from reading C++ file 'ViewSites.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../view/ViewSites.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ViewSites.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ViewSites_t {
    QByteArrayData data[13];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ViewSites_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ViewSites_t qt_meta_stringdata_ViewSites = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ViewSites"
QT_MOC_LITERAL(1, 10, 20), // "signalChangeEditMode"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 11), // "dataChanged"
QT_MOC_LITERAL(4, 44, 7), // "slotAdd"
QT_MOC_LITERAL(5, 52, 10), // "slotDelete"
QT_MOC_LITERAL(6, 63, 8), // "slotEdit"
QT_MOC_LITERAL(7, 72, 8), // "slotSave"
QT_MOC_LITERAL(8, 81, 10), // "slotCancel"
QT_MOC_LITERAL(9, 92, 11), // "slotRefresh"
QT_MOC_LITERAL(10, 104, 17), // "slotEnableButtons"
QT_MOC_LITERAL(11, 122, 14), // "QItemSelection"
QT_MOC_LITERAL(12, 137, 11) // "slotOpenUrl"

    },
    "ViewSites\0signalChangeEditMode\0\0"
    "dataChanged\0slotAdd\0slotDelete\0slotEdit\0"
    "slotSave\0slotCancel\0slotRefresh\0"
    "slotEnableButtons\0QItemSelection\0"
    "slotOpenUrl"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewSites[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    2,   77,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      12,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 11,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ViewSites::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ViewSites *_t = static_cast<ViewSites *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalChangeEditMode(); break;
        case 1: _t->dataChanged(); break;
        case 2: _t->slotAdd(); break;
        case 3: _t->slotDelete(); break;
        case 4: _t->slotEdit(); break;
        case 5: _t->slotSave(); break;
        case 6: _t->slotCancel(); break;
        case 7: _t->slotRefresh(); break;
        case 8: _t->slotEnableButtons((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 9: _t->slotEnableButtons(); break;
        case 10: _t->slotOpenUrl(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ViewSites::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ViewSites::signalChangeEditMode)) {
                *result = 0;
            }
        }
        {
            typedef void (ViewSites::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ViewSites::dataChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ViewSites::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ViewSites.data,
      qt_meta_data_ViewSites,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ViewSites::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewSites::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ViewSites.stringdata0))
        return static_cast<void*>(const_cast< ViewSites*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ViewSites::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void ViewSites::signalChangeEditMode()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ViewSites::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
