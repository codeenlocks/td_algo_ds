#include "utils.h"

bool is_sorted_nondecreasing(int *arr, int n){
    int tmp = arr[0] ;
    for(int i=1; i<n; i++){
        if(arr[i]<tmp){
            return false ;
        }
        tmp = arr[i] ;
    }
    return true ;
}

int min_int(int a, int b){
    return (a<b)? a : b ;
}