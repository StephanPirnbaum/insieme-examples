//A simple OpenMP program using barriers for synchronization
#include <omp.h>
#include <stdio.h>
int main() {
	#pragma omp parallel
	{
		printf("Thread: #(%d)", omp_get_thread_num());
		#pragma omp barrier
		#pragma omp for
		for (int i = 0; i < omp_get_thread_num(); i++) {
			printf("First Loop, Thread: #(%d), Iteration: #(%d)", omp_get_thread_num(), i);
		} //implicit barrier
		#pragma omp for nowait
		for (int i = 0; i < omp_get_thread_num(); i++) {
			printf("Second Loop, Thread: #(%d), Iteration: #(%d)", omp_get_thread_num(), i);
		} //no barrier
		printf("Done, Thread: #(%d)", omp_get_thread_num());
	}
	return 0;
}
