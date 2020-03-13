#ifdef _OPENACC
#include <omp.h>
#else
#include <openacc.h>
#endif
#include <iostream>


void get_array(int* array, int n, int val) {
    for (int i=0; i<n; i++) {
        array[i] = i * val;
    }
}


int main() {
    int mean[10];
    get_array(mean, 10, 0);
    {
        #ifdef _OPENACC
        #pragma omp parallel for reduction(+:mean[:10])
        #else
        #pragma acc parallel loop reduction(+:mean[:10])
        #endif
        for (int i=0; i<10; i++) {
            int array[10];
            get_array(array, 10, i);
            for(int i2=0; i2<10; i2++) {
                mean[i2] += array[i2];
            }
        }
    }
    std::cout << "mean: " << std::endl;
    for (int i=0; i<10; i++) {
        std::cout << " " << mean[i];
    }
    std::cout << std::endl;


}