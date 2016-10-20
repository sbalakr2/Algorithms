/*
 * bit.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: Sindhu
 */

#include <string>
#include <iostream>
#include <bitset>
#include <climits>
using namespace std;

template<typename T>
void doCircularShift(T num, int n, string dir){
	static const size_t size = sizeof(T)*CHAR_BIT;
	bitset<size> b(num);
	bitset<size> mask;
	mask.set();
	cout << "num " << b << endl;
	if(dir.compare("right") == 0){
		mask = mask >> (size-n);
		mask = mask & b;
		mask = mask << (size-n);
		b = b >> n;
		b = b | mask;
		cout << "res " << b << endl;
	} else{
		mask = mask << (size-n);
		mask = mask & b;
		mask = mask >> (size-n);
		b = b << n;
		b = b | mask;
		cout << "res " << b << endl;
	}
}

int main(){
	int num = 23567445;
	int n = 4;
	string dir = "left";
	doCircularShift(num, n, dir);
	return 0;
}




