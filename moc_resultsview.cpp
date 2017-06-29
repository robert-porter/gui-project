/****************************************************************************
** Meta object code from reading C++ file 'resultsview.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "resultsview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'resultsview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ResultsView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   13,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ResultsView[] = {
    "ResultsView\0\0results\0"
    "setResults(CacheSimulationResults)\0"
};

void ResultsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ResultsView *_t = static_cast<ResultsView *>(_o);
        switch (_id) {
        case 0: _t->setResults((*reinterpret_cast< CacheSimulationResults(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ResultsView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ResultsView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ResultsView,
      qt_meta_data_ResultsView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ResultsView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ResultsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ResultsView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ResultsView))
        return static_cast<void*>(const_cast< ResultsView*>(this));
    return QWidget::qt_metacast(_clname);
}

int ResultsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
