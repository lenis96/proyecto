#include "concepto.h"
#include  <QPair>
#include "mapa.h"
int main(){
	concepto a("nose",1,1);
    mapa mapaC;
    mapaC.agregarConcepto(concepto("arbol1",4,5));
    //std::list<concepto> listaConceptos;
    mapaC.agregarConcepto(concepto("arbol2",4,5));
    mapaC.agregarConcepto(concepto("flor3",3,5));
    mapaC.agregarConcepto(concepto("rama4",4,5));
    mapaC.agregarConcepto(concepto("palma5",7,5));
    mapaC.agregarConcepto(concepto("pino6",6,8));
    mapaC.imprimirConceptos();
    std::cout<<"\n";
    imprimirConcepto(mapaC.conceptoPos(6));
    //std::list<concepto>::iterator i =listaConceptos.begin();

    //listaConceptos.clear();
    //std::cout<<"\n\n\n";
    //imprimirConcepto(a);
	
	//std::cout <<"se creo el nuevo concepto"<<std::endl;
	return 0;
}
