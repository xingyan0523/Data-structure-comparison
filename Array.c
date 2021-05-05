#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structure.h"

struct Array;

void Array_insert(struct Array *arr, int key){
    arr->first[arr->rear++] = key;
}

bool Array_search(struct Array *arr, int key){
    for(int i = 0; i <= arr->rear; i++){
        if(arr->first[i] == key){
            return true;
        }
    }
    return false;
}

bool Array_Bsearch(int *arr, int left, int right, int key){
	if(left <= right){
		int mid = left + (right - left) / 2;
		if(arr[mid] == key)
			return true;
		
		if(arr[mid] > key)
			return Array_Bsearch(arr, left, mid - 1, key);

		return Array_Bsearch(arr, mid + 1, right, key);
	}
	return false;
}

void swap(int* a, int* b) { 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

int partition (int *arr, int low, int high) { 
	int pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high- 1; j++) { 
		if (arr[j] < pivot) { 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

void quickSort(int *arr, int low, int high) { 
	if (low < high) { 
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
}