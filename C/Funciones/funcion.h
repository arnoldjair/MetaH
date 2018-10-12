#ifndef FUNCION_H
#define FUNCION_H

typedef double (*funcion_p)(double* valores, int dimension);

struct s_funcion {
	funcion_p f;
	char* nombre;
};

typedef struct s_funcion m_funcion;

#endif