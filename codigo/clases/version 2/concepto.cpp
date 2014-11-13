#include "concepto.h"

concepto::concepto(std::string cadena="",int nuevaPosX=0,int nuevaPosY=0){
    if (cadena!="nulo"){
        numConcepto=0;
        posX=nuevaPosX;
        posY=nuevaPosY;
        textConcepto=cadena;
    }
    else{
        numConcepto=0;
        posX=0;
        posY=0;
        textConcepto=cadena;
    }
}
concepto::concepto(std::string cadena="",int nuevaPosX=0,int nuevaPosY=0,int num=0){
    if (cadena!="nulo"){
        numConcepto=num;
        posX=nuevaPosX;
        posY=nuevaPosY;
        textConcepto=cadena;
    }
    else{
        numConcepto=0;
        posX=0;
        posY=0;
        textConcepto=cadena;
    }
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
//int concepto::getNumConceptos(){return numConceptos;}
int concepto::getNumConcepto(){return numConcepto;}
void imprimirConcepto(concepto conc){std::cout<<conc.getTexto()<<"\t"<<conc.getPosX()<<"\t"<<conc.getPosY()<<"\t"<<conc.getNumConcepto()<<"\n";}
//int concepto::numConceptos=0;
bool concepto::esConceptoNulo(){
    if(textConcepto=="nulo"){
        return true;
    }
    else{
        return false;
    }
}


