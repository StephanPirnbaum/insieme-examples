//A simple OpenMP program which makes use of synchronization (Mutual Exclusion)
#include <omp.h>
#include <stdio.h>
void printCritical(int id) {
	printf("Thread: #(%d)", id);
} 

int main() {
	#pragma omp parallel 
	{
		printf("Concurrent Printing Thread: #(%d)", omp_get_thread_num());
		#pragma omp critical
		printCritical(omp_get_thread_num());
	}
	return 0;
}
