#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void){
    // implement main here
    // create array example using malloc
    // use searching algorithms and compare runtime
    int taille = 100000 ;
    int* arr = malloc(taille*sizeof(int)) ;
    for(int i=0; i<taille; i++){
        arr[i] = i ;
    }
    int target1 = arr[taille-1] ;
    int target2 = arr[taille/2] ;
    int target3 = arr[0] ;
    int target0 = -taille ;
    if(!is_sorted_nondecreasing(arr, taille)) {
        printf("Array is not sorted\n") ;
        return -1 ;   
    }
    clock_t start, end ;
    double cpu_time_used ;
    int result ;
    int target = target0; // change target here to test different cases
    start = clock() ;
    result =  linear_search(arr, taille, target) ;
    end = clock() ;
    printf("The result of linear search is %i\n",result) ;
    cpu_time_used = ((double)(end - start)/CLOCKS_PER_SEC) ;
    printf("Time taken (linear search) : %f seconds\n", cpu_time_used) ;


    start = clock() ;
    result =  jump_search(arr, taille, target) ;
    end = clock() ;
    printf("The result of jump search is %i\n", result) ;
    cpu_time_used = ((double)(end - start)/CLOCKS_PER_SEC) ;
    printf("Time taken (jump search) : %f seconds\n", cpu_time_used) ;


    start = clock() ;
    result = binary_search(arr, taille, target) ;
    end = clock() ;
    printf("The result of binary search is %i\n", result) ;
    cpu_time_used = ((double)(end - start)/CLOCKS_PER_SEC) ;
    printf("Time taken (binary search) : %f seconds\n", cpu_time_used) ;
    free(arr) ;
    return 0;
}
