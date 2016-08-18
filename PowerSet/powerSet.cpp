/*
 * powerSet.cpp
 *	Program to print all the possible subsets of the given set
 *  Created on: May 29, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;

int main(){
	int n;
	vector<int> arr;
	cout << "Enter the elements of the set:" << endl;
	while(cin >> n){
		arr.push_back(n);
	}
	int len = arr.size();
	int num = pow(2, len);
	for(int i=0; i<num; i++){
		for(int j=0; j < len; j++){
			if(i & (1 << j))
				cout << arr.at(j);
		}
		cout<<endl;
	}
	//cout<< num;
	/*for(vector<int>::iterator it = arr.begin(); it != arr.end(); it++){
		cout << *it << endl;
	}*/
	return 0;
}


