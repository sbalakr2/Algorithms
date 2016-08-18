/*
 * swapBits.cpp
 *  Cracking the coding interview - 5.7
 *	Swap the bits in odd and even positions
 *  Created on: May 28, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <bitset>
using namespace std;

int swapOddEven(int n);
int main(){
	int n;
	cout<< "Enter the integer: " << endl;
	cin>>n;
	int res = swapOddEven(n);
	cout<< "Swapped result: " << res << endl;
}

int swapOddEven(int n){
	int res = 0;
	bitset<8> bin(n);
	bitset<8> maskOdd(0xAA);
	cout << "binnn " << bin << endl;
	cout << "maskk " << maskOdd << endl;
	bitset<8> oddRes = bin & maskOdd;
	cout << "oddrs " << oddRes << endl;
	cout << "oddrs " << (oddRes >> 1) << endl;
	oddRes >>= 1;

	bitset<8> maskEven(0x55);
	cout << "maskk " << maskEven << endl;
	bitset<8> evenRes = bin & maskEven;
	cout << "evenr " << evenRes << endl;
	cout << "evenr " << (evenRes << 1) << endl;
	evenRes <<= 1;
	res = (oddRes | evenRes).to_ulong();
	return res;
}


