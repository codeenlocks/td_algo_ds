#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

int main(void)
{
    // implement main here
    // create array example using malloc
    // use sorting algorithms and compare runtime
    int n = 1000 ;
    int *arr = (int *)malloc(n * sizeof(int)) ;
    int *arr_copy = (int *)malloc(n * sizeof(int)) ;
    if(!arr || !arr_copy){
        printf("Memory allocation failed\n") ;
        return 1 ;
    }
    // fill array with random numbers
    srand((unsigned int)time(NULL)) ;
    for(int i=0; i<n; i++){
        arr[i] = rand() % 10000 ;
    }
    // copy array
    for(int i=0; i<n; i++){
        arr_copy[i] = arr[i] ;
    }
    
    // measure time for selection sort
    clock_t start = clock() ;
    selection_sort(arr, n) ;
    clock_t end = clock() ;
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC ;
    printf("Selection sort time: %f seconds\n", time_spent) ;
    // copy array back
    for(int i=0; i<n; i++){
        arr[i] = arr_copy[i] ;
    }

    // measure time for insertion sort
    start = clock() ;
    insertion_sort(arr, n) ;
    end = clock() ;
    time_spent = (double)(end - start) / CLOCKS_PER_SEC ;
    printf("Insertion sort time: %f seconds\n", time_spent) ;
    // copy array back
    for(int i=0; i<n; i++){
        arr[i] = arr_copy[i] ;
    }

    // measure time for bubble sort
    start = clock() ;
    bubble_sort(arr, n) ;
    end = clock() ;
    time_spent = (double)(end - start) / CLOCKS_PER_SEC ;
    printf("Bubble sort time: %f seconds\n", time_spent) ;
    // copy array back
    for(int i=0; i<n; i++){
        arr[i] = arr_copy[i] ;
    }
    
    // measure time for merge sort
    start = clock() ;
    merge_sort(arr, n) ;
    end = clock() ;
    time_spent = (double)(end - start) / CLOCKS_PER_SEC ;
    printf("Merge sort time: %f seconds\n", time_spent) ;
    // copy array back
    for(int i=0; i<n; i++){
        arr[i] = arr_copy[i] ;
    }
    // measure time for quick sort
    start = clock() ;
    quick_sort(arr, n) ;
    end = clock() ;
    time_spent = (double)(end - start) / CLOCKS_PER_SEC ;
    printf("Quick sort time: %f seconds\n", time_spent) ;
    // free memory
    free(arr) ;
    free(arr_copy) ;
    return 0;
}
