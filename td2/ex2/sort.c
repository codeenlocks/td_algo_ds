#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n)
{
    // selection sort iterative
    for(int i=0; i<n; i++){
        int min=i ;
        for(int j=i+1; j<n-1; j++){
            if(arr[j]<arr[min]){
                min=j ;
            }
        }
        swap_int(&arr[i], &arr[min]) ;
    }
}

void insertion_sort(int *arr, int n)
{
    // insertion sort iterative
    for(int i=1; i<n; i++){
        int key = arr[i] ;
        int j = i-1 ;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j] ;
            j-- ;
        }
    }
}

void bubble_sort(int *arr, int n)
{
    // bubble sort iterative
    for(int i=0; i<n; i++){
        for(int j=0; j<i-1; j++){
            if(arr[j]>arr[j+1]) swap_int(&arr[j], &arr[j+1]) ;
        }
    }
}

void merge(int *arr, int *tmp, int l, int m, int r){
    // merge function
    int i = l, j=m+1 ;
    while(i<=m && j<=r){
        if(arr[i]<=arr[j]){
            tmp[i+j-(m+1)] = arr[i] ;
            i++ ;
        }
        else{
            tmp[i+j-(m+1)] = arr[j] ;
            j++ ;
        }
    }
    while(i<=m){
        tmp[i+j-(m+1)] = arr[i] ;
        i++ ;
    }
    while(j<=r){
        tmp[i+j-(m+1)] = arr[j] ;
        j++ ;
    }
    
}

void mergesort_rec(int *arr, int *tmp, int l, int r)
{
    // recursive steps of merge sort
    if(l<r){
        int m = l + (r-l)/2 ;
        mergesort_rec(arr, tmp, l, m) ;
        mergesort_rec(arr, tmp, m+1, r) ;
        merge(arr, tmp, l, m, r) ;
        for(int k=l; k<=r; k++){
            arr[k] = tmp[k] ;
        }
    }
    
}

void merge_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    int *tmp = (int *)malloc((size_t)n * sizeof(int));
    if (!tmp)
        return;
    mergesort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}

int partition(int *arr, int l, int r)
{
    // partition function
    int pivot = arr[r] ;
    int i = l-1 ;
    for(int j=l; j<r; j++){
        if(arr[j]<=pivot){
            i++ ;
            swap_int(&arr[i], &arr[j]) ;
        }
    }
}

void quick_sort_rec(int *arr, int l, int r)
{
    // recursive steps of quick sort
    if(l<r){
        int pi = partition(arr, l, r) ;
        quick_sort_rec(arr, l, pi-1) ;
        quick_sort_rec(arr, pi+1, r) ;
    }
}

void quick_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    quick_sort_rec(arr, 0, n - 1);
}