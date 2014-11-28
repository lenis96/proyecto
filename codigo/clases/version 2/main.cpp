#include "concepto.h"
#include  <QPair>
#include "mapa.h"
#include <QDebug>
int main(){
	concepto a("nose",1,1);
    mapa mapaC("/home/lenis96/Escritorio/prueba.xml");
    qDebug()<<mapaC.getNumConceptos();
    mapaC.imprimirConceptos();
    mapaC.imprimirUniones();
    /*
    mapaC.agregarConcepto(concepto("arbol1",4,5));
    //std::list<concepto> listaConceptos;
    mapaC.agregarConcepto(concepto("arbol2",4,5));
    mapaC.agregarConcepto(concepto("flor3",3,5));
    mapaC.agregarConcepto(concepto("rama4",4,5));
    mapaC.agregarConcepto(concepto("palma5",7,5));
    mapaC.agregarConcepto(concepto("pino6",6,8));
    mapaC.imprimirConceptos();
    mapaC.agregarUnion(mapaC.conceptoPos(1),mapaC.conceptoPos(2));
    mapaC.agregarUnion(2,3);
    std::cout<<"\n";
    imprimirConcepto(mapaC.conceptoPos(6));
    //std::list<concepto>::iterator i =listaConceptos.begin();
    qDebug ()<<mapaC.existeUnion(mapaC.conceptoPos(2),mapaC.conceptoPos(3))<<endl;
    qDebug()<<mapaC.existeConcepto(6)<<mapaC.existeConcepto(7)<<mapaC.existeConcepto(0)<<endl;
    mapaC.eliminarConcepto(mapaC.conceptoPos(6));
    qDebug()<<mapaC.existeConcepto(6);
    //mapaC.guardar("/home/lenis96/Escritorio/prueba.xml");
    mapaC.~mapa();
    qDebug()<<mapaC.getNumConceptos()<<endl;
    qDebug()<<"si funciono";
    //listaConceptos.clear();
    //std::cout<<"\n\n\n";
    //imprimirConcepto(a);
    */
	//std::cout <<"se creo el nuevo concepto"<<std::endl;
	return 0;
}
