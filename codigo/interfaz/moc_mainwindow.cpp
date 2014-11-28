/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   12,   11,   11, 0x05,
      52,   12,   11,   11, 0x05,
      90,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     128,   11,   11,   11, 0x09,
     144,   11,   11,   11, 0x09,
     160,   11,   11,   11, 0x09,
     177,   11,   11,   11, 0x09,
     194,   11,   11,   11, 0x09,
     215,   11,   11,   11, 0x09,
     230,   11,   11,   11, 0x09,
     245,   11,   11,   11, 0x09,
     267,   11,   11,   11, 0x09,
     280,   12,   11,   11, 0x09,
     311,   11,   11,   11, 0x09,
     340,  335,   11,   11, 0x09,
     393,   11,   11,   11, 0x09,
     418,   11,   11,   11, 0x09,
     443,   12,   11,   11, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0,,\0InformacionConcepto(QString,int,int)\0"
    "InformacionConcepto1(QString,int,int)\0"
    "InformacionConcepto2(QString,int,int)\0"
    "nuevoConcepto()\0unirConceptos()\0"
    "editarConcepto()\0guardarArchivo()\0"
    "guardarComoArchivo()\0abrirArchivo()\0"
    "nuevoArchivo()\0iniciarPresentacion()\0"
    "actualizar()\0nuevoConcepto(QString,int,int)\0"
    "idConceptoCambiado(int)\0,,,,\0"
    "ConceptoCambiado(int,QString,int,int,cambioConcepto)\0"
    "idConceptoCambiado1(int)\0"
    "idConceptoCambiado2(int)\0"
    "editarUnion(int,int,cambioUnion)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->InformacionConcepto((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->InformacionConcepto1((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->InformacionConcepto2((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->nuevoConcepto(); break;
        case 4: _t->unirConceptos(); break;
        case 5: _t->editarConcepto(); break;
        case 6: _t->guardarArchivo(); break;
        case 7: _t->guardarComoArchivo(); break;
        case 8: _t->abrirArchivo(); break;
        case 9: _t->nuevoArchivo(); break;
        case 10: _t->iniciarPresentacion(); break;
        case 11: _t->actualizar(); break;
        case 12: _t->nuevoConcepto((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 13: _t->idConceptoCambiado((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->ConceptoCambiado((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< cambioConcepto(*)>(_a[5]))); break;
        case 15: _t->idConceptoCambiado1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->idConceptoCambiado2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->editarUnion((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< cambioUnion(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::InformacionConcepto(QString _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::InformacionConcepto1(QString _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::InformacionConcepto2(QString _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
