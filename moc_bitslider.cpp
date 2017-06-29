/****************************************************************************
** Meta object code from reading C++ file 'bitslider.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bitslider.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bitslider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BitSlider[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   11,   10,   10, 0x05,
      55,   53,   10,   10, 0x05,
      78,   53,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     108,  102,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BitSlider[] = {
    "BitSlider\0\0newValue\0"
    "memorySizeChangedString(QString)\0n\0"
    "memorySizeChanged(int)\0pointerSizeChanged(int)\0"
    "value\0setPointerSize(int)\0"
};

void BitSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BitSlider *_t = static_cast<BitSlider *>(_o);
        switch (_id) {
        case 0: _t->memorySizeChangedString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->memorySizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->pointerSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setPointerSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BitSlider::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BitSlider::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BitSlider,
      qt_meta_data_BitSlider, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BitSlider::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BitSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BitSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BitSlider))
        return static_cast<void*>(const_cast< BitSlider*>(this));
    return QWidget::qt_metacast(_clname);
}

int BitSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void BitSlider::memorySizeChangedString(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BitSlider::memorySizeChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BitSlider::pointerSizeChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
