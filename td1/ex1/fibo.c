#include <stdio.h>
#include "fibo.h"

//Question 1
long long fibo_naive(long long n){
    if(n <= 1){return n;}
    return fibo_naive(n-1) + fibo_naive(n-2) ;
}

//Question 2
long long fibo_dynamic(long long n, long long f[]){
    if (f[n] != -1){
        return f[n] ;
    }
    if (n <=1){
        f[n] = n ;
        return n ;
    }
    else{
        f[n] = fibo_dynamic(n-1,f) + fibo_dynamic(n-2,f) ;
        return f[n] ;
    }
}
