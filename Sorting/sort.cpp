/*
 * sort.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Sindhu
 */

#include <iostream>
using namespace std;
void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main(){
	int arr[] = {5,7,1,13,6,9,12,4,12,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	quicksort(arr, 0, n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}

void quicksort(int arr[], int low, int high){
	if(low < high){
		int p = partition(arr, low, high);
		quicksort(arr, low, p-1);
		quicksort(arr, p+1, high);
	}
}

void swap(int *x, int *y){
	int t = *y;
	*y = *x;
	*x = t;
}

int partition(int arr[], int low, int high){
	int i,j;
	i = low - 1;
	j = low;
	int pivot = arr[high]; // partition element
	while(j < high){
		if(arr[j] < pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i+1], &arr[high]);
	return i+1;
}
