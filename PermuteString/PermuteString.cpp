/*
 * PermuteString.cpp
 *
 *  Created on: May 21, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

vector<string> permute(char *a, int l, int r, vector<string> arr);
//void permute2(char *a, int l, int r);
void swap(char *x, char *y);
int main(){
	//char str[] = "cab";
	//int n = strlen(str);
	//permute(str, 0, n-1);
	string str = "cab";
	int n = str.length();
	char * cstr = new char [n+1];
	strcpy (cstr, str.c_str());
	vector<string> arr;
	arr = permute(cstr, 0, n-1, arr);
	for(vector<string>::iterator it = arr.begin(); it != arr.end(); it++){
		cout<< *it << endl;
	}
	return 0;
}

/*void permute2(char *a, int l, int r){
	int i;
	if(l == r){
		cout<<a<< endl;
	} else{
		for(i=l; i<=r; i++){
			swap();
		}
	}
}*/

vector<string> permute(char *a, int l, int r, vector<string> arr){
	int i;
	if(l==r){
		//cout<<a<<endl;
		arr.push_back(a);
	}else{
		for(i=l; i<=r; i++){
			swap(a+l, a+i);
			arr = permute(a, l+1, r, arr);
			swap(a+l, a+i);
		}
	}
	return arr;
}

void swap(char *a, char *b){
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


