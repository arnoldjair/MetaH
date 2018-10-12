#include <math.h>

#include "griewank.h"

double evaluar_griewank(double* valores, int dimension) {

  if (dimension <= 1) {
    return 0;
  }

  double evaluacion = 0;
  double sum_cuadrados = 0;
  double multiplicatoria = 0;

  int i = 0;

  for (i = 0; i < dimension; i++) {
    sum_cuadrados = sum_cuadrados + pow(valores[i], 2);
  }

  sum_cuadrados = sum_cuadrados / 4000;

  for (i = 0; i < dimension; i++) {
    multiplicatoria = multiplicatoria * cos(valores[i] / sqrt(i));
  }

  evaluacion = sum_cuadrados - multiplicatoria + 1;

  return evaluacion;
}
