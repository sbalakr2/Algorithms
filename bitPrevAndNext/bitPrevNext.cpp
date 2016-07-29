/*
 * bitPrevNext.cpp
 *  Cracking the coding interview - 5.4
 *  Given a positive integer, print the next smallest and the
 *  next largest number that have the same number of 1 bits in
 *  their binary representation
 *  Created on: May 29, 2016
 *      Author: Sindhu
 */
#include <iostream>
#include <bitset>
#include <cmath>
#include <map>
using namespace std;

int getNext(int n);
int getPrev(int n);
//map<char, int> getOnesZerosCount(int n);
int main(){
	int n;
	cin>>n;
	int next = getNext(n);
	cout << "next: " << next << endl;
	int prev = getPrev(n);
	cout << "Next number: " << next << " & Previous number: " << prev << endl;
	return 0;
}

int getNext(int n){
	int c = n;
	int c0 = 0, c1 = 0;
	while(((c & 1) == 0) && (c != 0)){
		c0++;
		c >>= 1;
	}
	while((c & 1) == 1){
		c1++;
		c >>= 1;
	}
	int p = c0 + c1;
	if(p == 31 || p == 0)
		return -1;
	// actual logic
	n |= 1 << p;
	n &= ~((1 << p) - 1);
	//n |= pow(2, c1-1) - 1;
	n |= (1 << (c1 - 1)) - 1;
	return n;
}

int getPrev(int n){
	int c = n;
	int c0 = 0, c1 = 0;
	while((c & 1) == 1){
		c1++;
		c >>= 1;
	}
	if(c == 0) return -1;
	while(((c & 1) == 0) && (c != 0)){
		c0++;
		c >>= 1;
	}
	int p = c0 + c1;
	if(p == 31 || p == 0)
		return -1;

	//actual logic
	n &= (~0) << (p+1);
	n |= (1 << (c1 + 1) - 1) << (c0 - 1);
	return n;
}

/*map<char, int> getOnesZerosCount(int n){
	int c0 = 0, c1 = 0;
	while(((n & 1) == 0) && (n != 0)){
		c0++;
		n >>= 1;
	}
	while((n & 1) == 1){
		c1++;
		n >>= 1;
	}
	map<char, int> res;
	res['c0'] = c0;
	res['c1'] = c1;
	return res;
}*/



