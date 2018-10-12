#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "esfera.h"
#include "ackley.h"
#include "griewank.h"
#include "rastrigin.h"
#include "schwefel.h"
#include "hill_climbing.h"
#include "funcion.h"

int main(int argc, char **argv) {


	double valores[2];
	double evaluacion = 0;

	srand(time(0));

	int dimension = sizeof(valores) / sizeof(valores[0]);

	//funcion = evaluar_esfera;
	
	m_funcion* funcion = malloc(sizeof(m_funcion));
	
	funcion->f = evaluar_esfera;
	//TODO: Esto es c, no puede ser tan sencillo como hacer esto:
	funcion->nombre = "Esfera";

	evaluacion = hc(funcion, 30, 1000, dimension, 100, -100, 0.6);
	printf("Evaluacion hc esfera: %F\n", evaluacion);

	funcion->f = evaluar_ackley;
	funcion->nombre = "Ackley";
	
	evaluacion = hc(funcion, 30, 1000, dimension, 32, -32, 0.6);
	printf("Evaluacion hc ackley: %F\n", evaluacion);
	
	funcion->f = evaluar_griewank;
	funcion->nombre = "Griewank";
	
	evaluacion = hc(funcion, 30, 1000, dimension, 600, -600, 0.6);
	printf("Evaluacion hc griewank: %F\n", evaluacion);
	
	funcion->f = evaluar_rastrigin;
	funcion->nombre = "Rastrigin";
	
	evaluacion = hc(funcion, 30, 1000, dimension, 5.12, -5.12, 0.6);
	printf("Evaluacion hc rastrigin: %F\n", evaluacion);
	
	funcion->f = evaluar_schwefel;
	funcion->nombre = "Schwefel";
	
	evaluacion = hc(funcion, 30, 1000, dimension, 500, -500, 0.6);
	printf("Evaluacion hc schewel: %F\n", evaluacion);
	
	//Random Restarts
	
	funcion->f = evaluar_esfera;
	funcion->nombre = "Esfera";

	evaluacion = hc_r_r(funcion, 1000, dimension, 100, -100, 0.6, 10, 2, 1);
	printf("Evaluacion hc_r_r esfera: %F\n", evaluacion);
	
	funcion->f = evaluar_ackley;
	funcion->nombre = "Ackley";
	
	evaluacion = hc_r_r(funcion, 1000, dimension, 32, -32, 0.6, 10, 2, 1);
	printf("Evaluacion hc_r_r ackley: %F\n", evaluacion);
	
	funcion->f = evaluar_griewank;
	funcion->nombre = "Griewank";
	
	evaluacion = hc_r_r(funcion, 1000, dimension, 600, -600, 0.6, 10, 2, 1);
	printf("Evaluacion hc_r_r griewank: %F\n", evaluacion);
	
	funcion->f = evaluar_rastrigin;
	funcion->nombre = "Rastrigin";
	
	evaluacion = hc_r_r(funcion, 1000, dimension, 5.12, -5.12, 0.6, 10, 2, 1);
	printf("Evaluacion hc_r_r rastrigin: %F\n", evaluacion);
	
	funcion->f = evaluar_schwefel;
	funcion->nombre = "Schwefel";
	
	evaluacion = hc_r_r(funcion, 1000, dimension, 500, -500, 0.6, 10, 2, 1);
	printf("Evaluacion hc_r_r schewel: %F\n", evaluacion);
	
	return 0;
}
