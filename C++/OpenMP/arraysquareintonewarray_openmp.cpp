#include<iostream>
#include <omp.h>
#include<algorithm>


#define ARRAY_SIZE 100000000
#define ARRAY_VALUE 1231
#define THREAD_NUM 14
using namespace std;

int main(){
    omp_set_num_threads(THREAD_NUM);

    int *arr = new int[ARRAY_SIZE];
    fill_n(arr, ARRAY_SIZE, ARRAY_VALUE);

    #pragma omp parallel for
    for(int i=0; i<ARRAY_SIZE;i++){
        arr[i]=arr[i]/arr[i]+arr[i]/5-14;
    }
    delete[] arr;
    return 0;
}

/*
single threaded
real    0m0.295s
user    0m0.000s
sys     0m0.000s

openmp
real    0m0.146s
user    0m0.015s
sys     0m0.000s
*/