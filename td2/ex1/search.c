#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target){
    // linear search, return index of target
    // return -1 if not found
    for(int i=0; i<n; i++){
        if(arr[i]==target){
            return i ;
        }
    }
    

    return -1;
}

int jump_search(int *arr, int n, int target)
{
    // jump search on sorted array, return index
    // of target, return -1 if not found
    
    int step = sqrt(n) - 1 ;
    int add = sqrt(n) ;
    if(arr[step]==target){
        return step ;
    }
    while(step<n && arr[step]< target ){
        step+=add ;
    }
    
    for(int i=step-add+1; i<=min_int(step, n-1) ; i++){
        if(arr[i]==target) return i ;
    }
    
    
    return -1;
}

int binary_search(int *arr, int n, int target){
    // binary search on sorted array, return index
    // of target, return -1 if not found
    if(n<=0){
        return -1 ;
    }
    int mid = n/2 ;
    if(arr[mid]==target){
        return mid ;
    }
    else if(arr[mid]>target){
        return binary_search(arr, mid, target) ;
    }
    else{
        int res = binary_search(arr+mid+1, n-mid-1, target) ;
        return (res==-1)?res:res+mid+1 ;
    }
    
}