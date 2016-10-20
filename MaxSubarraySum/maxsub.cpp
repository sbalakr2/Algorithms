/*
 * find the sum of contiguous sub-array within a one-dimensional array
 * of numbers which has the largest sum.
 */
#include <iostream>
using namespace std;
int getMaxSubarraySum(int a[], int n);

int main(){
	int arr[] = {-2, -3, 7, -1, -2, -1, 5, 3};
	int n = sizeof(arr)/sizeof(int);
	cout << "Max sub-array sum: " << getMaxSubarraySum(arr, n);
	return 0;
}

// handles negative numbers also
int getMaxSubarraySum(int a[], int n){
	int maxSum = a[0];
	int curSum = a[0];
	for(int i=1; i<n; i++){
		curSum = max(a[i], curSum + a[i]);
		maxSum = max(maxSum, curSum);
	}
	return maxSum;
}
