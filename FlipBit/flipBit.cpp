/*
 * flipBit.cpp
 *	Cracking the Coding Interview 5.3
 *	You have an integer and can flip exactly one bit from 0 to 1
 *	Find the length of the longest sequence of 1s you could create
 *  Created on: May 27, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>
using namespace std;

int getMaxSequence(int seq[]);
void shift(int sq[]);
int findLongestSequence(int n, bitset<32> binNum);
int main(){
	cout << "Enter the integer: "<< endl;
	int n;
	cin>>n;
	bitset<32> ele(n);
	cout<< ele << endl;
	//cout<<bitset<4> (-1)<<endl;
	//cout<<bitset<4> (1)<<endl;
	//cout<< (n & 1) << endl;
	int len = findLongestSequence(n, ele);
	cout<<"Maximum Length: " << len << endl;
	return 0;
}

int findLongestSequence(int n, bitset<32> binNum){
	int maxLen = 1;
	int seq[] = {0, 0, 0};
	int loop = (log2(n)) + 1;
	int searchFor = 0;
	for(int i=0; i<= loop; i++){
		if(binNum.test(i) != searchFor){
			if(searchFor == 1){
				maxLen = max(maxLen, getMaxSequence(seq));
			}
			searchFor ^= 1; // flip
			//cout<<"search: " << searchFor << endl;
			shift(seq);
		}
		seq[0]++;
	}
	if(searchFor == 0)
		shift(seq);
	return maxLen;
}

int getMaxSequence(int seq[]){
	if(seq[1] == 1)
		return seq[0] + seq[2] + 1;
	else if(seq[1] == 0)	//series one side only
		return max(seq[0], seq[2]);
	else	// many zeros
		return max(seq[0], seq[2]) + 1;
}

void shift(int sq[]){
	sq[2] = sq[1];
	sq[1] = sq[0];
	sq[0] = 0;
}



