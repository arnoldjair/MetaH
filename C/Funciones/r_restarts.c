#include "r_restarts.h"
#include "utils.h"

int t_intervals(int min, int max, int size, int* v) {

	if(v == 0) {
		return -1;
	}

	int i = 0;

	for(i = 0; i < size; i++) {
		double ran = random;
		v[i] = min + ran*(max - min);
	}

	return 0;
}
