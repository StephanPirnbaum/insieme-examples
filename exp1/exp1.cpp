// A simple parallel program written with OpenMP
#include <omp.h>
#include <stdio.h>
int main() {
	#pragma omp parallel
	{
		printf("Thread: #(%d)", omp_get_thread_num());
	}
	return 0;
}

