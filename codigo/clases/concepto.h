#ifndef CONCEPTO_H
#define CONCEPTO_H

# include <iostream>
//# include <QString>
# include <list>
# include <string>

class concepto{
	
	static int numConceptos;
	int numConcepto;
	std::string textConcepto;
	int posX;
	int posY;
	
	public:
		concepto(std::string ,int,int);
			//11std::cout <<"se creo el nuevo concepto"<<numConcepto<<numConceptos<<std::endl;
		~concepto();
		void setTexto(std::string );
		std::string getTexto();
		void setPosX(int);
		int getPosX();
		void setPosY(int);
		int getPosY();
		int getNumConceptos();

};
void imprimirConcepto(concepto);
//concepto::numConceptos=0;
#endif