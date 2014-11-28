/****************************************************************************
** Meta object code from reading C++ file 'unirconceptosventana.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "unirconceptosventana.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'unirconceptosventana.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_unirConceptosVentana[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   22,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      64,   22,   21,   21, 0x09,
     105,   22,   21,   21, 0x09,
     146,   21,   21,   21, 0x09,
     166,   21,   21,   21, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_unirConceptosVentana[] = {
    "unirConceptosVentana\0\0,,\0"
    "emitirInformacion(int,int,cambioUnion)\0"
    "setInformacionConcepto1(QString,int,int)\0"
    "setInformacionConcepto2(QString,int,int)\0"
    "enviarInformacion()\0elimUnion()\0"
};

void unirConceptosVentana::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        unirConceptosVentana *_t = static_cast<unirConceptosVentana *>(_o);
        switch (_id) {
        case 0: _t->emitirInformacion((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< cambioUnion(*)>(_a[3]))); break;
        case 1: _t->setInformacionConcepto1((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->setInformacionConcepto2((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->enviarInformacion(); break;
        case 4: _t->elimUnion(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData unirConceptosVentana::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject unirConceptosVentana::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_unirConceptosVentana,
      qt_meta_data_unirConceptosVentana, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &unirConceptosVentana::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *unirConceptosVentana::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *unirConceptosVentana::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_unirConceptosVentana))
        return static_cast<void*>(const_cast< unirConceptosVentana*>(this));
    return QDialog::qt_metacast(_clname);
}

int unirConceptosVentana::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void unirConceptosVentana::emitirInformacion(int _t1, int _t2, cambioUnion _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
