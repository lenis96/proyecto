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
    numElemtos=0;
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
    numElemtos=0;
//11std::cout <<"se creo el nuevo concepto"<<numConcepto<<numConceptos<<std::endl;
}
concepto::concepto(){
    numElemtos=0;
}

concepto::~concepto(){
}
void concepto::setTexto(std::string nuevoTexto){textConcepto=nuevoTexto;}
std::string concepto::getTexto() const{return textConcepto;}
void concepto::setPosX(int nuevaPos){posX=nuevaPos;}
int concepto::getPosX() const{return posX;}
void concepto::setPosY(int nuevaPos){posY=nuevaPos;}
int concepto::getPosY() const{return posY;}
//int concepto::getNumConceptos(){return numConceptos;}
int concepto::getNumConcepto() const{return numConcepto;}
void imprimirConcepto(concepto conc){std::cout<<conc.getTexto()<<"\t"<<conc.getPosX()<<"\t"<<conc.getPosY()<<"\t"<<conc.getNumConcepto()<<"\n";}
//int concepto::numConceptos=0;
bool concepto::esConceptoNulo() const{
    if(textConcepto=="nulo"){
        return true;
    }
    else{
        return false;
    }
}
void concepto::setNumConcepto(int num){
    numConcepto=num;
}
void concepto::crearElementoTexto(QString text,int x,int y){
    numElemtos++;
    elementos.append(elementoPresentacion(texto,text,x,y,numElemtos));
}
void concepto::crearElementoImagen(QString ubicacionImagen,int x,int y){
    numElemtos++;
    elementos.append(elementoPresentacion(imagen,ubicacionImagen,x,y,numElemtos));
}
elementoPresentacion concepto::getElemNum(int num){
    QListIterator <elementoPresentacion> i(elementos);
    i.toFront();
    while(i.hasNext()){
        if(i.peekNext().getId()==num){
            return i.peekNext();
        }
        i.next();
    }
    return elementoPresentacion(nulo,"",0,0,0);
}
elementoPresentacion* concepto::getPtrElem(int num){
    QMutableListIterator <elementoPresentacion> i(elementos);
    i.toFront();
    while(i.hasNext()){
        if(i.peekNext().getId()==num){
            return &i.peekNext();
        }
        i.next();
    }
    return NULL;
}

bool concepto::existeElemento(int num){
    QListIterator <elementoPresentacion> i (elementos);
    i.toFront();
    while(i.hasNext()){
        if(i.peekNext().getId()==num){
            return true;
        }
        i.next();
    }
    return false;
}
int concepto::getNumElementos()const{
    return numElemtos;
}
void concepto::eliminarElemento(int id){
    QMutableListIterator <elementoPresentacion> i(elementos);
    i.toFront();
    while(i.hasNext()){
        if(i.peekNext().getId()==id){
            i.next();
            i.remove();
            break;
        }
        i.next();
    }
}
