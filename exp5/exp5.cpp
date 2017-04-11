//A simple OpenMP program with worksharing and variable synchronization
#include <omp.h>
int main() {
	const int SIZE = 100;
	double a[SIZE]; 
	#pragma omp parallel for num_threads(4) shared(a)
	{
		for (int i=0; i < SIZE; i++) {
			a[i] = omp_get_thread_num();
		}
	} 
	int count0 = 0, count1 = 0, count2 = 0, count3 = 0;
	#pragma omp parallel for shared(a)
	{
		for (int i = 0; i < SIZE; i++) {
			if (a[i] == 0) {
				#pragma omp atomic 
				count0++;
			} else if (a[i] == 1) {
				#pragma omp atomic
				count1++;
			} else if (a[i] == 2) {
				#pragma omp atomic
				count2++;
			} else if (a[i] == 3) {
				#pragma omp atomic
				count3++;
			}

	 	}
	}
	return 0;
}
