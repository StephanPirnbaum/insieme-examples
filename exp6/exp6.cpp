// A simple OpenMP program with loop carried dependence
#include <omp.h>
int main() {
	int dep  = 4;
	#pragma omp parallel for 
	for (int i = 0; i < 100; i++) {
		dep += i;
	}
	return 0;
}
