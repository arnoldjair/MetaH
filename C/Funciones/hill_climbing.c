#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdint.h>

#include "hill_climbing.h"
#include "utils.h"
#include "r_restarts.h"



void tweak_1(double* S, double* R, int dimension, double radio) {

	int i = 0;

	for(i = 0; i < dimension; i++) {
		double ran = random;
		R[i] = S[i] + ((-1 * radio) + (2 * radio * ran));
	}

}

double hc(m_funcion* m_f, int n_ejecuciones, int n_iteraciones,\
          int dimension, double l_superior, double l_inferior, double radio) {

	mkdir("hc", S_IRWXU | S_IRWXG);
	char* n_algoritmo = malloc(sizeof(char)*30);
	sprintf(n_algoritmo, "hc/%s", m_f->nombre);
	mkdir(n_algoritmo, S_IRWXU | S_IRWXG);

	if(n_ejecuciones == 0) {
		n_ejecuciones = 30;
	}

	srand(time(NULL));

	int ejecucion_actual = 0;
	int i = 0;

	double resp = 0;

	double* S;

	char* o_file = malloc(sizeof(char)*(strlen(m_f->nombre) + 30));

	while(ejecucion_actual < n_ejecuciones) {

		sprintf(o_file, "hc/%s/%d.txt", m_f->nombre, ejecucion_actual);

		S = (double*)malloc(sizeof(double) * dimension);

		for(i = 0; i < dimension; i++) {
			double ran = random;
			S[i] = l_inferior + ran*(l_superior - l_inferior);
		}

		resp = hc_s(m_f, n_iteraciones, dimension, l_superior, l_inferior, radio, S, o_file);

		ejecucion_actual++;
		free(S);

	}

	resp = resp / n_ejecuciones;

	return resp;
}


double hc_s(m_funcion* m_f, int n_iteraciones, int dimension,\
            double l_superior, double l_inferior, double radio, double* S, char* o_file) {

	int i = 0;
	int j = 0;

	double Q_S = 0;
	double Q_R = 0;

	double* R;

	R = (double*)malloc(sizeof(double) * dimension);

	Q_S = m_f->f(S, dimension);


	FILE* archivo = fopen(o_file, "w+");

	if(archivo== 0) {
		return -1;
	}

	for(i = 0; i < n_iteraciones; i++) {
		fprintf(archivo, "%d;", i);

		//tweak
		tweak_1(S,R, dimension, radio);

		//Quality, resultado de la evaluación de la función en los puntos dados.
		Q_R = m_f->f(R, dimension);

		if(Q_R < Q_S) {
			for(j = 0; j < dimension; j++) {
				S[j] = R[j];
			}
			Q_S = Q_R;
		}

		fprintf(archivo, "%F\n", Q_S);

	}

	free(R);
	return Q_S;

}

double hc_r_r(m_funcion* m_f, int n_iteraciones,\
              int dimension, double l_superior, double l_inferior, double radio, int i_tiempo, int t_max, int t_min) {

	int* T = malloc(sizeof(int) * i_tiempo);

	if(t_min < 0) {
		return -1;
	}

	if(t_intervals(t_min, t_max, i_tiempo, T) != 0) {
		return -1;
	}

	mkdir("hc_random_restarts", S_IRWXU | S_IRWXG);
	char* n_algoritmo = malloc(sizeof(char)*40);
	sprintf(n_algoritmo, "hc_random_restarts/%s", m_f->nombre);
	mkdir(n_algoritmo, S_IRWXU | S_IRWXG);

	srand(time(NULL));

	int t_pos = 0;
	int i = 0;
	int j = 0;
	int it_actual = 0;

	double Q_S = 0;
	double Q_R = 0;
	double Q_B = 0;

	double* S;
	double* R;
	double* B;

	S = (double*)malloc(sizeof(double) * dimension);
	R = (double*)malloc(sizeof(double) * dimension);
	B = (double*)malloc(sizeof(double) * dimension);

	for(i = 0; i < dimension; i++) {
		double ran = random;
		S[i] = l_inferior + ran*(l_superior - l_inferior);
		B[i] = S[i];
	}

	Q_S = m_f->f(S, dimension);
	Q_B = Q_S;

	//Intervalos agotados.
	while(t_pos < i_tiempo) {
		char* o_file = malloc(sizeof(char)*(strlen(m_f->nombre) + 50));
		sprintf(o_file, "hc_random_restarts/%s/%d.txt", m_f->nombre, t_pos);
		FILE* archivo = fopen(o_file, "w");

		double ran = random;
		int pos = ran*i_tiempo;

		if(pos == i_tiempo || T[pos] == -1) {
			continue;
		}

		time_t curr;
		time_t next;

		time(&curr);
		next = curr + (time_t) T[pos];

		it_actual = 0;

		while(difftime(next, curr) != 0 && it_actual < n_iteraciones) {

			fprintf(archivo, "%d;", it_actual);

			tweak_1(S, R, dimension, radio);

			Q_R = m_f->f(R, dimension);

			if(Q_R < Q_S) {
				for(j = 0; j < dimension; j++) {
					S[j] = R[j];
				}
				Q_S = Q_R;
			}

			fprintf(archivo, "%F\n", Q_S);

			time(&curr);
			it_actual++;

		}

		if(Q_S < Q_B) {
			for(j = 0; j < dimension; j++) {
				B[j] = S[j];
			}
			Q_B = Q_S;
		}

		for(i = 0; i < dimension; i++) {
			double ran = random;
			S[i] = l_inferior + ran*(l_superior - l_inferior);
		}

		t_pos++;
		T[pos] = -1;
	}

	return Q_B;

}
