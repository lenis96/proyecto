#include "concepto.h"

concepto::concepto(std::string cadena="",int nuevaPosX=0,int nuevaPosY=0){
	numConceptos++;
	numConcepto=numConceptos;
	posX=nuevaPosX;
	posY=nuevaPosY;
	textConcepto=cadena;
	//11std::cout <<"se creo el nuevo concepto"<<numConcepto<<numConceptos<<std::endl;
}
concepto::~concepto(){
}
void concepto::setTexto(std::string nuevoTexto){textConcepto=nuevoTexto;}
std::string concepto::getTexto(){return textConcepto;}
void concepto::setPosX(int nuevaPos){posX=nuevaPos;}
int concepto::getPosX(){return posX;}
void concepto::setPosY(int nuevaPos){posY=nuevaPos;}
int concepto::getPosY(){return posY;}
int concepto::getNumConceptos(){return numConceptos;}
void imprimirConcepto(concepto conc){std::cout<<conc.getTexto()<<"\t"<<conc.getPosX()<<"\t"<<conc.getPosY()<<"\t"<<conc.getNumConceptos()<<"\n";}
int concepto::numConceptos=0;

