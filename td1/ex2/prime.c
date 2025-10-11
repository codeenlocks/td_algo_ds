#include "prime.h"

long long prime_count_naive( long long n){
    long long count = 2 ;
    if(n<2){
        return 0;}
    for (int i = 2; i<=n ; i++){
        for(int j = 2; j*j<=i ; j++){
            if (i%j==0) {
                count++ ;
                break ;
            }
        }
    }
    return n+1 - count ;
}

long long prime_count_efficient(long long n){
    if(n<2){
        return 0;}
    short prime[n+1] ;
    long long count = 0 ;
    for(int i = 0 ; i<n+1 ; i++){
        prime[i] = 1 ;
    }
    prime[0] = 0 ; prime[1] = 0 ;

    for(int i = 2; i<=n ; i++ ){
        if(prime[i]){
            count++ ;
            for(int j=i*i; j<=n ; j+=i){
                prime[j] = 0 ;
            }
        }
    }
    return count ;
}