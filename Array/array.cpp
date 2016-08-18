/*
 * array.cpp
 *
 *  Created on: Aug 9, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void maxSubarraySum();
void selectionSort();
void doInsertionSort();
void insertionSort(int arr[], int n);
void bubbleSort();
void mergeSort();
void heapSort();
void recursiveMergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int mid, int r);
int findMaxSubarraySum(int arr[], int n);
void printArray(int arr[], int n);
void doHeapSort(int arr[], int lp, int rp);
void heapify(int arr[], int lp, int rp);
void rotateAnArray();
void reverseArray(int arr[], int lp, int rp);
void fibonacciNumber();
int fibonacci(int n);
void twoSum();

int main(){
	//maxSubarraySum();
	//selectionSort();
	//insertionSort();
	//bubbleSort();
	//mergeSort();
	//heapSort();
	//rotateAnArray();
	//fibonacciNumber();
	twoSum();
}

void twoSum(){
	int arr[] = {2, -9, 5, 1, -4, 6, 0, -7, 9};
	int n = sizeof(arr) / sizeof(int);
	int target = 0;
	// sort array and find the indexes
	/*insertionSort(arr, n);
	printArray(arr, n);
	int lp = 0, rp = n-1;
	while(lp < rp){
		int sum = arr[lp] + arr[rp];
		if(sum == target){
			cout << "Indexes: " << lp << " " << rp;
			break;
		}
		else{
			if(sum < target)
				lp++;
			else
				rp--;
		}
	}*/
	// using unordered map
	unordered_map<int,int> hashMap;
	unordered_map<int,int>::iterator it;
	for(int i=0; i<n; i++){
		it = hashMap.find(arr[i]);
		if(it != hashMap.end()){
			int index = it->second;
			cout<< "Indexes: " << index << " " << i << endl;
			break;
		} else{
			hashMap.insert(target - arr[i], i);
		}
	}
}

void fibonacciNumber(){
	int n = 5;
	int fib = fibonacci(n);
	cout<< "Fibonacci: "<<fib << endl;
}

int fibonacci(int n){
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	return fibonacci(n-1) + fibonacci(n-2);
}

void rotateAnArray(){
	int arr[] = {2, -9, 5, 1, -4, 6, 0, -7, 9};
	int n = sizeof(arr) / sizeof(int);
	int k = 4;
	/*Efficient Solution: Using Array Reversal
	1. Reverse the array elements from 0 to k-1.
	2. Reverse the array elements from k to array.length-1.
	3. Reverse the whole array.*/
	reverseArray(arr, 0, k-1);
	reverseArray(arr, k, n-1);
	reverseArray(arr, 0, n-1);
	printArray(arr, n);
}

void reverseArray(int arr[], int lp, int rp){
	while(lp < rp){
		int temp = arr[lp];
		arr[lp] = arr[rp];
		arr[rp] = temp;
		lp++;
		rp--;
	}
}

void heapSort(){
	int arr[] = {2, -9, 5, 1, -4, 6, 0, -7, 9};
	int n = sizeof(arr) / sizeof(int);
	doHeapSort(arr, 0, n-1);
	printArray(arr, n);
}

void doHeapSort(int arr[], int lp, int rp){
	while(lp < rp){
		heapify(arr, lp, rp);
		int temp = arr[lp];
		arr[lp] = arr[rp];
		arr[rp] = temp;
		rp--;
	}
}

void heapify(int arr[], int lp, int rp){
	int n = rp - lp + 1;
	int temp;
	for(int i= ((n/2)-1); i>=0; i--){
		int j = 2*i+1;
		int k = j+1;
		int lg = j;
		if(k < n && arr[k] >= arr[j])
			lg = k;
		if(arr[i] < arr[lg]){
			temp = arr[i];
			arr[i] = arr[lg];
			arr[lg] = temp;
		}
	}
}

void mergeSort(){
	int arr[] = {2, -9, 5, 1, -4, 6, 0, -7, 9};
	int n = sizeof(arr) / sizeof(int);
	recursiveMergeSort(arr, 0, n-1);
	printArray(arr, n);
}

void recursiveMergeSort(int arr[], int l, int r){
	if(l == r)
		return;
	int mid = (r+l)/2;
	recursiveMergeSort(arr, l, mid);
	recursiveMergeSort(arr, mid+1, r);
	merge(arr, l, mid, r);
}

void merge(int arr[], int l, int mid, int r){
	int n = r-l+1;
	int *temp = new int[n];
	int lp = l, rp = mid+1;
	int i=0;
	while(lp <= mid && rp <= r){
		if(arr[lp] <= arr[rp]){
			temp[i] = arr[lp];
			lp++;
		} else{
			temp[i] = arr[rp];
			rp++;
		}
		i++;
	}
	while(lp <= mid){
		temp[i] = arr[lp];
		lp++;
		i++;
	}
	while(rp <= r){
		temp[i] = arr[rp];
		rp++;
		i++;
	}
	// copy from temp back to original array
	for(int k=l; k<=r; k++){
		arr[k] = temp[k-l];
	}
	delete[] temp;
}

void bubbleSort(){
	int arr[] = {2, -9, 5, 1, -4, 6, 0, -7};
	int n = sizeof(arr) / sizeof(int);
	bool swapped;
	do{
		swapped = false;
		for(int i=1; i<n; i++){
			if(arr[i-1] > arr[i]){
				int temp = arr[i-1];
				arr[i-1] = arr[i];
				arr[i] = temp;
				swapped = true;
			}
		}
		printArray(arr, n);
	} while(swapped);
}

void doInsertionSort(){
	int arr[] = {2, -9, 5, 1, -4, 6, 0, -7};
	int n = sizeof(arr) / sizeof(int);
	insertionSort(arr, n);
	printArray(arr, n);
}
void insertionSort(int arr[], int n){
	int j;
	for(int i=1; i<n; i++){
		int key = arr[i];
		for(j=(i-1); j>=0; j--){
			if(key < arr[j])
				arr[j+1] = arr[j];
			else break;
		}
		arr[j+1] = key;
		//printArray(arr, n); //steps
	}
}

void selectionSort(){
	int arr[] = {2, -9, 5, 1, -4, 6, 0, -7};
	int n = sizeof(arr) / sizeof(int);
	int curMin = 0;
	int k;				// index at which we find the curMin
	for(int i=0; i<n; i++){
		curMin = arr[i];
		k=i;
		for(int j=i+1; j<n; j++){
			if(arr[j] < curMin){
				curMin = arr[j];
				k=j;
			}
		}
		int temp = arr[i];
		arr[i] = curMin;
		arr[k] = temp;
	}
	printArray(arr, n);
}

void maxSubarraySum(){
	int arr[] = {2, -9, 5, 1, -4, 6, 0, -7};
	//int arr[] = {-2, -9, -5, -1, -4, -6, -10, -7, -8};
	int n = sizeof(arr) / sizeof(int);
	int sum = findMaxSubarraySum(arr, n);
	cout<< "Max Sub-array Sum: " <<sum << endl;
}

int findMaxSubarraySum(int arr[], int n){
	/*int curSum = 0;
	int maxSum = 0;
	for(int i=0; i<n; i++){
		curSum += arr[i];
		if(curSum < 0)
			curSum = 0;
		else{
		if(maxSum < curSum)
			maxSum = curSum;
		}
	}
	return maxSum;*/
	int curSum = arr[0];
	int maxSum = arr[0];
	for(int i=1; i<n; i++){
		curSum = max(arr[i], curSum+arr[i]);
		maxSum = max(maxSum, curSum);
	}
	return maxSum;
}

void printArray(int arr[], int n){
	for(int a=0; a<n; a++){
		cout << arr[a] << " ";
	}
	cout<<endl;
}

