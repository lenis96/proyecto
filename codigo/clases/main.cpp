#include "concepto.h"
#include  "pareja.h"
int main(){
	concepto a("nose",1,1);
	std::list<concepto> listaConceptos;
	listaConceptos.push_back(concepto("arbol",4,5));
	listaConceptos.push_back(concepto("flor",3,5));
	listaConceptos.push_back(concepto("rama",4,5));
	listaConceptos.push_back(concepto("palma",7,5));
	listaConceptos.push_back(concepto("pino",6,8));
	std::list<concepto>::iterator i =listaConceptos.begin();
	while(i!=listaConceptos.end()){
		imprimirConcepto(*i);
		i++;
	}
	listaConceptos.clear();
	std::cout<<"\n\n\n";
	imprimirConcepto(a);
	
	//std::cout <<"se creo el nuevo concepto"<<std::endl;
	return 0;
}