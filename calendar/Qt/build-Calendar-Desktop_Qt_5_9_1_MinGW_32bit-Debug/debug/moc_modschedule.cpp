/****************************************************************************
** Meta object code from reading C++ file 'modschedule.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Calendar/modschedule.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modschedule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_modSchedule_t {
    QByteArrayData data[7];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_modSchedule_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_modSchedule_t qt_meta_stringdata_modSchedule = {
    {
QT_MOC_LITERAL(0, 0, 11), // "modSchedule"
QT_MOC_LITERAL(1, 12, 12), // "finishEditId"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "sendClickMod"
QT_MOC_LITERAL(4, 39, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(5, 63, 24), // "on_le_id_editingFinished"
QT_MOC_LITERAL(6, 88, 23) // "on_btn_checkMod_clicked"

    },
    "modSchedule\0finishEditId\0\0sendClickMod\0"
    "on_pushButton_2_clicked\0"
    "on_le_id_editingFinished\0"
    "on_btn_checkMod_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_modSchedule[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void modSchedule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        modSchedule *_t = static_cast<modSchedule *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finishEditId(); break;
        case 1: _t->sendClickMod(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_le_id_editingFinished(); break;
        case 4: _t->on_btn_checkMod_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (modSchedule::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&modSchedule::finishEditId)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (modSchedule::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&modSchedule::sendClickMod)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject modSchedule::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_modSchedule.data,
      qt_meta_data_modSchedule,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *modSchedule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *modSchedule::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_modSchedule.stringdata0))
        return static_cast<void*>(const_cast< modSchedule*>(this));
    return QWidget::qt_metacast(_clname);
}

int modSchedule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void modSchedule::finishEditId()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void modSchedule::sendClickMod()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
