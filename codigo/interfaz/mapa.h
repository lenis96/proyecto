#ifndef MAPA_H
#define MAPA_H
#include <QPair>
#include <QList>
#include <QListIterator>
#include "concepto.h"
#include <list>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QDebug>
#include <QMutableListIterator>
#include <QMessageBox>
#include <elementopresentacion.h>

class mapa
{
    QList<concepto> listaConceptos;
    QList<QPair<concepto*,concepto*> > listaParejas;
    //QListIterator<concepto> iteradorConceptos;
    //QList<QPair>::iterator iteradorParejas;
    //QListIterator <QPair<concepto,concepto> > iteradorParejas;
    int numConceptos;
    bool Error;
    void cargarConcepto(concepto);
public:
    mapa();
    mapa(QString);
    ~mapa();
    concepto getConceptoNum(int)const;
    concepto* getPtrNum(int);
    //concepto* getPointerConcepto(int)const;
    void setConcepto(int,concepto);
    void agregarConcepto(concepto);
    void eliminarConcepto(concepto);
    void eliminarConcepto(int);
    bool tieneError() const;
    //void agregarUnion(int,int);
    void agregarUnion(concepto,concepto);
    void agregarUnion(int,int);
    void eliminarUnion(concepto,concepto);
    void eliminarUnion(int,int);
    void imprimirConceptos()const;
    void imprimirUniones()const;
    bool existeConcepto(concepto) const;
    bool existeConcepto(int) const;
    bool existeUnion(concepto,concepto) const;
    bool existeUnion(int,int)const;
    void guardar(QString);
    void abrir(QString);
    int getNumConceptos() const;
    //bool existeUnion(int,int);

};

#endif // MAPA_H
