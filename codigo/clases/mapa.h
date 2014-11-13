#ifndef MAPA_H
#define MAPA_H
#include "pareja.h"
#include "concepto.h"
#include <list>

class mapa
{
    std::list<concepto> listaConceptos;
    std::list<pareja> listaParejas;
    std::list<concepto>::iterator iteradorConceptos;
    std::list<pareja>::iterator iteradorParejas;
    int numConceptos;
public:
    mapa();
    ~mapa();
    concepto conceptoPos(int);
    void agregarConcepto(concepto);
    void agregarUnion(int,int);
    void agregarUnion(concepto,concepto);
    void imprimirConceptos();
    bool existeConcepto(concepto);
    bool existeConcepto(int);
    bool existeUnion(concepto,concepto);
    bool existeUnion(int,int);
};

#endif // MAPA_H
