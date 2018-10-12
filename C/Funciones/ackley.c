#include "ackley.h"
#include <math.h>

double evaluar_ackley(double* valores, int dimension) {
	
	if(dimension <= 1) {
		return 0;
	}
	
	double evaluacion = 0;
	
	double sum_x = 0;
	double sum_cos = 0;
	
	int i = 0;
	
	for(i = 0; i < dimension; i++) {
		sum_x = sum_x + pow(valores[i], 2);
		sum_cos = sum_cos + cos(2*M_PI*valores[i]);
	}
	
	evaluacion = -20*exp(-0.2*sqrt(sum_x / dimension)) - exp(sum_cos / dimension) + 20 + exp(1);
		
	return evaluacion;
}