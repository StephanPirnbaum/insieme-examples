//A simple parallel program with set thread number
#include <omp.h>
#include <stdio.h>
int main() {
	#pragma omp parallel num_threads(4)
	{
		printf("Thread: #(%d)", omp_get_thread_num());
	}
	return 0;
}

