#ifndef PAREJA_H
#define PAREJA_H

#include <iostream>
#include <string>
#include "concepto.h"
class pareja{
	int i1,i2;
	public:
		pareja(int,int);
        pareja(concepto,concepto);
		void setPareja1(int);
		void setPareja2(int);
		void setPareja(int,int);
		int getPareja1();
		int getPareja2();
};
#endif 
