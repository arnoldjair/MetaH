#ifndef HILL_CLIMBING_H
#define HILL_CLIMBING_H

#include "funcion.h"


void tweak_1(double* S, double* R, int dimension, double radio);


double hc(m_funcion* funcion, int n_ejecuciones, int n_iteraciones,\
          int dimension, double l_superior, double l_inferior, double radio);

double hc_s(m_funcion* funcion, int n_iteraciones, int dimension,\
            double l_superior, double l_inferior, double radio, double* S, char* o_file);


double hc_r_r(m_funcion* funcion, int n_iteraciones,\
              int dimension, double l_superior, double l_inferior, double radio, int i_tiempo, int t_min, int t_max);
#endif
