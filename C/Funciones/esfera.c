#include<stdio.h>
#include<math.h>


#include "esfera.h"

double evaluar_esfera(double* valores, int dimension) {
		
	if(dimension <= 1) {
		return 0;
	}
	
	double evaluacion = 0;
	
	int i = 0;
	
	for(i = 0; i < dimension; i++) {
		evaluacion = evaluacion +  pow(valores[i], 2);
	}
	return evaluacion;
}