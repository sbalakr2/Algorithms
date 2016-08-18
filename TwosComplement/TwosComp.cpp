/*
 * TwosComp.cpp
 *
 *  Created on: May 22, 2016
 *      Author: Sindhu
 */
#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main(){
	cout<< "Enter the bits: ";
	string bits;
	cin>>bits;
	cout<< "Enter the operation: 1. One's Complement, 2. Two's complement";
	int n;
	cin>>n;
	bitset<16> bit (bits);
	if(n>0 && n<3){
		switch(n){
		case 1:{
			cout << "Result: " << bit.flip() << endl;
			break;
		}
		case 2:{
			cout << "Result: " << bit.flip()  << endl;
			break;
		}
		default:
			break;
		}
	} else{
		cout<<"Invalid option!"<<endl;
	}
	return 0;
}


