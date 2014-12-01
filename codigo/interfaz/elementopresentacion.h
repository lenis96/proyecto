#ifndef ELEMENTOPRESENTACION_H
#define ELEMENTOPRESENTACION_H
#include <QtGui>
enum tipoElemento{texto,imagen,nulo};
class elementoPresentacion{
    tipoElemento tipoElem;
    QGraphicsItem* elemento;
    int id;
    QString cadena;
public:
    elementoPresentacion(tipoElemento,QString,int,int,int);
    QGraphicsItem* getElem()const;
    int getId()const;
    tipoElemento getTipo()const;
    QString getCadena()const;
    int getX()const;
    int getY()const;
    void setInformacion(QString,int,int);
};

#endif // ELEMENTOPRESENTACION_H
