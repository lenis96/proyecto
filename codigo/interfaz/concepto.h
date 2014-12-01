#ifndef CONCEPTO_H
#define CONCEPTO_H

# include <iostream>
//# include <QString>
# include <list>
# include <string>
#include <QList>
#include <elementopresentacion.h>

class concepto{
    friend class mapa;
    //static int numConceptos;
	int numConcepto;
	std::string textConcepto;
	int posX;
	int posY;
    QList <elementoPresentacion> elementos;
    int numElemtos;
    private:
        concepto(std::string ,int,int,int);
        void setNumConcepto(int);
	public:
		concepto(std::string ,int,int);
        concepto();
			//11std::cout <<"se creo el nuevo concepto"<<numConcepto<<numConceptos<<std::endl;
		~concepto();
		void setTexto(std::string );
        std::string getTexto() const;
        void setPosX(int);
        int getPosX() const;
		void setPosY(int);
        int getPosY()const;
        int getNumConcepto() const;
        //int getNumConceptos();
        bool esConceptoNulo() const;
        void crearElementoTexto(QString,int,int);
        void crearElementoImagen(QString,int,int);
        elementoPresentacion getElemNum(int);
        elementoPresentacion* getPtrElem(int);
        int getNumElementos()const;
        bool existeElemento(int);
        void eliminarElemento(int);

};
void imprimirConcepto(concepto);
//concepto::numConceptos=0;
#endif
