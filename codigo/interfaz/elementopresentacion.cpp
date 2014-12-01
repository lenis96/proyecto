#include "elementopresentacion.h"

elementoPresentacion::elementoPresentacion(tipoElemento tipo,QString informacion,int x,int y,int id)
{

    if(tipo==texto){
        this->id=id;
        tipoElem=texto;
        //QGraphicsTextItem* text=new QGraphicsTextItem(informacion);
        elemento=new QGraphicsTextItem(informacion);
        elemento->setX(x);
        elemento->setY(y);
        cadena=informacion;
    }
    else if(tipo==imagen){
        this->id=id;
        tipoElem=imagen;
        QPixmap img(informacion);
        elemento=new QGraphicsPixmapItem(img);
        elemento->setX(x);
        elemento->setY(y);
        cadena=informacion;
    }
    else {
        tipoElem=nulo;
        this->id=0;

    }
}
QGraphicsItem* elementoPresentacion::getElem()const{
    return elemento;
}
int elementoPresentacion::getId()const{return id;}
tipoElemento elementoPresentacion::getTipo()const{return tipoElem;}
QString elementoPresentacion::getCadena()const{return cadena;}
int elementoPresentacion::getX()const{
    return elemento->x();
}
int elementoPresentacion::getY()const{
    return elemento->y();
}
void elementoPresentacion::setInformacion(QString cadena, int x, int y){
    this->cadena=cadena;
    if(tipoElem==texto){
        delete elemento;
        elemento=new QGraphicsTextItem(cadena);
        elemento->setX(x);
        elemento->setY(y);
    }
    else if(tipoElem==imagen){
        delete elemento;
        QPixmap img(cadena);
        elemento=new QGraphicsPixmapItem(img);
        elemento->setX(x);
        elemento->setY(y);
    }
}
