/****************************************************************************
** Meta object code from reading C++ file 'editarconceptoventana.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "editarconceptoventana.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editarconceptoventana.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_editarConceptoVentana[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   23,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      93,   90,   22,   22, 0x09,
     133,   22,   22,   22, 0x09,
     153,   22,   22,   22, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_editarConceptoVentana[] = {
    "editarConceptoVentana\0\0,,,,\0"
    "emitirInformacionConcepto(int,QString,int,int,cambioConcepto)\0"
    ",,\0setInformacionConcepto(QString,int,int)\0"
    "enviarInformacion()\0elimComcepto()\0"
};

void editarConceptoVentana::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        editarConceptoVentana *_t = static_cast<editarConceptoVentana *>(_o);
        switch (_id) {
        case 0: _t->emitirInformacionConcepto((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< cambioConcepto(*)>(_a[5]))); break;
        case 1: _t->setInformacionConcepto((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->enviarInformacion(); break;
        case 3: _t->elimComcepto(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData editarConceptoVentana::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject editarConceptoVentana::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_editarConceptoVentana,
      qt_meta_data_editarConceptoVentana, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &editarConceptoVentana::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *editarConceptoVentana::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *editarConceptoVentana::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_editarConceptoVentana))
        return static_cast<void*>(const_cast< editarConceptoVentana*>(this));
    return QDialog::qt_metacast(_clname);
}

int editarConceptoVentana::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void editarConceptoVentana::emitirInformacionConcepto(int _t1, QString _t2, int _t3, int _t4, cambioConcepto _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
