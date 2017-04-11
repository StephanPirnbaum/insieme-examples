//A simple OpenMP program which makes use of synchronization (Mutual Exclusion for updating variables)
#include <omp.h>
int main() {
	int x = 0;
	#pragma omp parallel 
	{	
		#pragma omp atomic
		   	x++;
	}
	return 0;
}
