#include <math.h>

#include "rastrigin.h"

double evaluar_rastrigin(double* valores, int dimension) {
	
	if(dimension <= 1) {
		return 0;
	}
	
	double evaluacion = 0;
	
	int i = 0;
	
	double sumatoria = 0;
	
	for(i = 0; i < dimension; i++) {
		sumatoria = sumatoria + pow(valores[i], 2) - 10 * cos(2* M_PI * valores[i]);
	}
	
	evaluacion = 10 * dimension + sumatoria;
	
	return evaluacion;
}