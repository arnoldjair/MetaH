#include <math.h>

#include "schwefel.h"

double evaluar_schwefel(double* valores, int dimension) {
	
	if(dimension <= 1) {
		return 0;
	}
	
	double evaluacion = 0;
	double sumatoria;
	
	int i = 0;
	
	for(i = 0; i < dimension; i++) {
		sumatoria = sumatoria + valores[i] * sin(sqrt(fabs(valores[i])));
	}
	 
	evaluacion = 418.9829 * dimension - sumatoria;
	
	return evaluacion;
}