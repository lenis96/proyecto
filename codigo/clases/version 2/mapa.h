#ifndef MAPA_H
#define MAPA_H
#include <QPair>
#include <QList>
#include <QListIterator>
#include "concepto.h"
#include <list>

class mapa
{
    std::list<concepto> listaConceptos;
    QList<QPair<concepto,concepto> > listaParejas;
    std::list<concepto>::iterator iteradorConceptos;
    //QList<QPair>::iterator iteradorParejas;
    QListIterator <QPair<concepto,concepto> > iteradorParejas (listaParejas);
    int numConceptos;
public:
    mapa();
    ~mapa();
    concepto conceptoPos(int);
    void agregarConcepto(concepto);
    //void agregarUnion(int,int);
    void agregarUnion(concepto,concepto);
    void imprimirConceptos();
    bool existeConcepto(concepto);
    bool existeConcepto(int);
    bool existeUnion(concepto,concepto);
    //bool existeUnion(int,int);
};

#endif // MAPA_H
