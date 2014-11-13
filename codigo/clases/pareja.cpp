#include "pareja.h"
pareja::pareja(int num1=0,int num2=0){i1=num1;i2=num2;}
pareja::pareja(concepto c1, concepto c2){i1=c1.getNumConcepto();i2=c2.getNumConcepto();}
void pareja::setPareja1(int nuevoNum=0){i1=nuevoNum;}
void pareja::setPareja2(int nuevoNum=0){i2=nuevoNum;}
void pareja::setPareja(int nuevoNum1=0,int nuevoNum2=0){i1=nuevoNum1;i2=nuevoNum2;}
int pareja::getPareja1(){return i1;}
int pareja::getPareja2(){return i2;}
