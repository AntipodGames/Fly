/****************************************************************************
** Meta object code from reading C++ file 'ingame.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ingame.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ingame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_InGame[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      21,    7,    7,    7, 0x0a,
      42,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_InGame[] = {
    "InGame\0\0pausePopUp()\0endLvlPopUp(QString)\0"
    "changeMusic(QString)\0"
};

void InGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        InGame *_t = static_cast<InGame *>(_o);
        switch (_id) {
        case 0: _t->pausePopUp(); break;
        case 1: _t->endLvlPopUp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->changeMusic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData InGame::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject InGame::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_InGame,
      qt_meta_data_InGame, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &InGame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *InGame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *InGame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InGame))
        return static_cast<void*>(const_cast< InGame*>(this));
    return QWidget::qt_metacast(_clname);
}

int InGame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
