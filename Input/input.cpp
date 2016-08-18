/*
 * input.cpp
 *
 *  Created on: Mar 23, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	//int a,b,c;
	//cin>>a; cin>>b; cin>>c;
	//cout << "a: " << a << "--b: " << b << "--c: " <<c;
	int arr[] = {1,2,3};
	cout<<sizeof(arr)<<endl;

	int n = 37;
	cout <<"sqrt: "<<sqrt(n)<<endl;
	cout <<"sqrt: "<<floor(sqrt(n))<<endl;

	string s;
	getline(cin,s);
	cout<<s[1]<<endl;
	return 0;
}

