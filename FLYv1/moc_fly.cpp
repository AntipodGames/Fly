/****************************************************************************
** Meta object code from reading C++ file 'fly.h'
**
** Created: Sat Jul 12 19:20:41 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "fly.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fly.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Fly[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x05,
      14,    4,    4,    4, 0x05,
      26,   24,    4,    4, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,    4,    4,    4, 0x0a,
      50,    4,    4,    4, 0x0a,
      58,    4,    4,    4, 0x0a,
      70,    4,    4,    4, 0x0a,
      82,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Fly[] = {
    "Fly\0\0noLeft()\0noRight()\0,\0sendPos(int,int)\0"
    "Left()\0Right()\0turn(float)\0Boost(bool)\0"
    "takeControl(bool)\0"
};

void Fly::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Fly *_t = static_cast<Fly *>(_o);
        switch (_id) {
        case 0: _t->noLeft(); break;
        case 1: _t->noRight(); break;
        case 2: _t->sendPos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->Left(); break;
        case 4: _t->Right(); break;
        case 5: _t->turn((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: _t->Boost((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->takeControl((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Fly::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Fly::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Fly,
      qt_meta_data_Fly, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Fly::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Fly::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Fly::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Fly))
        return static_cast<void*>(const_cast< Fly*>(this));
    if (!strcmp(_clname, "Entite"))
        return static_cast< Entite*>(const_cast< Fly*>(this));
    return QObject::qt_metacast(_clname);
}

int Fly::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Fly::noLeft()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Fly::noRight()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Fly::sendPos(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
