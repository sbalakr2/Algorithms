/*
 *  rotateFindMin.cpp
 *  Find minimum element in a sorted-then-rotated array in O(log n) time
 *  Using binary search
 *	http://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
 *  Created on: May 24, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> arr, int l, int r){
	if(l == r){
		return arr.at(l);
	} else{
		int mid = (l+r)/2;
		if(arr.at(mid) < arr.at(mid-1))
			return arr.at(mid);
		if(arr.at(mid) > arr.at(mid+1))
			return arr.at(mid+1);
		if(arr.at(mid) < arr.at(l))
			return findMin(arr, l, mid-1);
		else if(arr.at(mid) > arr.at(r))
			return findMin(arr, mid+1, r);
		else
			return arr.at(0);
	}
}

int main(){
	vector<int> arr;
	int n;
	int i = 0;
	while(cin>>arr[i]){
		arr.push_back(n);
	}
	int length = arr.size();
	int min = findMin(arr, 0, length-1);
	cout<<"The minimum element is " <<  min << endl;
	return 0;
}

/*int main(){
	vector<int> arr;
	int n;
	while(cin>>n){
		arr.push_back(n);
	}
	size_t j;
	bool found = false;
	for(j=1; j < arr.size(); j++){
		if(arr.at(j) < arr.at(j-1)){
			found = true;
			break;
		}
	}
	if(found)
		cout<<"The smallest element is: " << arr.at(j) << endl;
	else
		cout<<"The smallest element is: " << arr.at(0) << endl;

	return 0;
}*/

/*int main(){
	int *arr = new int[5];
	int i = 0;
	int min;
	while(cin>>arr[i]){
		cout <<"element " << arr[i] << "at index: " << i <<endl;
		if(arr[i] < min)min = arr[i];
		i++;
	}
	cout<<"The smallest element is: " << min << endl;

	return 0;
}*/






