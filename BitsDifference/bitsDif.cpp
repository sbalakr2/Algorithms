/*
 * bitsDif.cpp
 *	Cracking the Coding Interview - 5.6
 *	Write a function to determine the number of bits that you would need
 *	to flip to convert integer A to integer B
 *  Created on: May 28, 2016
 *      Author: Sindhu
 */


#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

int getNumberOfBits(int a, int b);
int getNumberOfBitsV2(int a, int b);
int main(){
	int a,b;
	cin>>a>>b;
	// cout << bitset<32> (a) << "~" << bitset(32) (b) << endl;
	//int num = getNumberOfBits(a, b);
	int num = getNumberOfBitsV2(a, b);
	cout << "Number of bits needed to flip: " << num << endl;
	return 0;
}

int getNumberOfBits(int a, int b){
	bitset<32> c = a^b;
	int num = 0;
	cout << (c) << endl;
	while(c != 0){
		if(c.test(0))
			num++;
		c >>= 1;
		cout << (c) << endl;
	}
	return num;
}

int getNumberOfBitsV2(int a, int b){
	int num = 0;
	bitset<32> c = a^b;
	cout << bitset<32> (a) << "~" << bitset<32> (b) << endl;
	cout << c << endl;
	while(c != 0){
		num++;
		bitset<32> d(1);
		cout << "c_to_ulong: " << c.to_ulong() << endl;
		unsigned long diff = c.to_ulong() - d.to_ulong(); //not sure
		cout << "diff: " << diff << endl;
		bitset<32> res(diff);
		cout << "res: " << res << endl;
		c = c & res;
		cout << "c: " << c << endl;
	}
	return num;
}

