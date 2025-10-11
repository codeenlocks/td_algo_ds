#include <stdio.h>
#include <time.h>
#include "prime.h"

void main(){
    long long n = 109;
    clock_t start, end ;
    double cpu_time_used ;
    start = clock() ;
    printf("Those are %llu primes numbers (naive) under %llu\n", prime_count_naive(n), n) ;
    end = clock() ;
    cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC ;
    printf("Time taken (naive) : %f seconds\n", cpu_time_used) ;

    start = clock() ;
    printf("Those are %llu primes numbers (efficient) under %llu\n", prime_count_efficient(n), n) ;
    end = clock() ;
    cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC ;
    printf("Time taken (efficient) : %f seconds\n", cpu_time_used) ;
}