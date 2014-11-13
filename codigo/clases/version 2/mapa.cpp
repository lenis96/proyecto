#include "mapa.h"
mapa::mapa()
{
    numConceptos=0;
}
void mapa::agregarConcepto(concepto concep){
    numConceptos++;

    listaConceptos.push_back(concepto(concep.getTexto(),concep.getPosX(),concep.getPosY(),numConceptos));
}
void mapa::agregarUnion(concepto c1,concepto c2){
    if(!existeUnion(c1,c2)){
        QPair<concepto,concepto> a(c1,c2);
        listaParejas.append(a);
        //listaParejas.append(QPair(c1,c2));
    }
}
mapa::~mapa(){
    listaConceptos.clear();
    listaParejas.clear();
}
void mapa::imprimirConceptos(){
    iteradorConceptos =listaConceptos.begin();

    while(iteradorConceptos!=listaConceptos.end()){
        imprimirConcepto(*iteradorConceptos);
        iteradorConceptos++;
    }
}
/*
void mapa::agregarUnion(int num1,int num2){
    if(!existeUnion(num1,num2)){
        listaParejas.push_back(pareja(num1,num2));
    }
}*/

concepto mapa::conceptoPos(int num){
    iteradorConceptos=listaConceptos.begin();
    while(iteradorConceptos!=listaConceptos.end() && iteradorConceptos->getNumConcepto()!=num){
        iteradorConceptos++;
    }
    if(iteradorConceptos->getNumConcepto()==num){
        return *iteradorConceptos;
    }
    else{
        return concepto ("nulo",0,0);
    }
}
bool mapa::existeUnion(concepto c1,concepto c2){
    QPair <concepto,concepto> a(c1,c2);
    QPair <concepto,concepto> b(c2,c1);
    QPair <concepto,concepto> c(c1,c1);
    for (int i=0;i<listaParejas.size();i++){
        c=listaParejas.at(i);
        c.first;
        if((c.first).getNumConcepto()==(a.first).getNumConcepto()){
            return true;//teeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeerminar
        }

    }
    return false;
    //return listaParejas.contains(a)||listaParejas.contains(b);//existeUnion(c1.getNumConcepto(),c2.getNumConcepto());
}
/*
bool mapa::existeUnion(int num1,int num2){
    iteradorParejas=listaParejas.begin();
    while(iteradorParejas!=listaParejas.end()){
        if(((iteradorParejas->getPareja1()==num1 && iteradorParejas->getPareja2()==num2)||(iteradorParejas->getPareja1()==num2 && iteradorParejas->getPareja2()==num1))){
            return true;
        }
        iteradorParejas++;
    }
    return false;
}*/
bool mapa::existeConcepto(concepto co){//validate concepto nulo //imprimir Parejas
    return existeConcepto(co.getNumConcepto());
}
bool mapa::existeConcepto(int num){
    iteradorConceptos=listaConceptos.begin();
    while(iteradorConceptos!=listaConceptos.end()){
        if(iteradorConceptos->getNumConcepto()==num){
            return true;
        }

        iteradorConceptos++;

    }
    return false;
}
