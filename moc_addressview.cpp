/****************************************************************************
** Meta object code from reading C++ file 'addressview.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "addressview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addressview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddressView[] = {

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
      15,   13,   12,   12, 0x0a,
      31,   13,   12,   12, 0x0a,
      53,   13,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AddressView[] = {
    "AddressView\0\0n\0setNumBits(int)\0"
    "setNumOffsetBits(int)\0setNumSetBits(int)\0"
};

void AddressView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AddressView *_t = static_cast<AddressView *>(_o);
        switch (_id) {
        case 0: _t->setNumBits((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setNumOffsetBits((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setNumSetBits((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AddressView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AddressView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AddressView,
      qt_meta_data_AddressView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddressView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddressView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddressView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddressView))
        return static_cast<void*>(const_cast< AddressView*>(this));
    return QWidget::qt_metacast(_clname);
}

int AddressView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
