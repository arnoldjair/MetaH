#ifndef ESFERA_H
#define ESFERA_H

struct esfera{
	double limite_sup;
	double limite_inf;	
};

double evaluar_esfera(double* valores, int dimension);

#endif