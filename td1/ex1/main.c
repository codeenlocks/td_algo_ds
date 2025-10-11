#include <stdio.h>
#include <time.h>
#include "fibo.h"

void main(){
    long long n = 45 ;
    long long f[n+1] ;
    for (int i=0 ; i<n+1 ; i++ ){
        f[i] = -1 ;
    }
    clock_t start, end ;
    double cpu_time_used ;
    start = clock() ;
    printf("The %lluth Fibonacci number (naive) is %llu\n", n, fibo_naive(n)) ;
    end = clock() ;
    cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC ;
    printf("Time taken (naive) : %f seconds\n", cpu_time_used) ;

    start = clock() ;
    printf("The %lluth Fibonacci number (dynamic) is %llu\n", n, fibo_dynamic(n,f)) ;
    end = clock() ;
    cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC ;
    printf("Time taken (dynamic) : %f seconds\n", cpu_time_used) ;
}