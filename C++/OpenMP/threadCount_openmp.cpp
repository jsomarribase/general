#include<iostream>
#include<omp.h>
#include<unistd.h>

#define THREAD_NUM 14

using namespace std;

int main(){
    omp_set_num_threads(THREAD_NUM); 

    #pragma omp parallel
    {
        usleep(1000000 * omp_get_thread_num()); //Avoid race conditions
        cout<<"Number of available threads: "<<omp_get_num_threads()<<endl;
        cout<<"Current thread number: "<<omp_get_thread_num()<<endl;
        cout<<"Hello world"<<endl;
    }
    return 0;
}