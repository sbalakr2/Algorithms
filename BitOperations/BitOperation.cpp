/*
 * BitOperation.cpp
 *
 *  Created on: May 26, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <bitset>
using namespace std;
void all_functions();
void insertMintoN(bitset<32> M, bitset<32> N, int i, int j);
int main(){
	//all_functions();
	bitset<32> M,N;
	int i,j;
	cin>>M>>N;
	cin>>i>>j;
	insertMintoN(M,N,i,j);
	return 0;
}

void insertMintoN(bitset<32> M, bitset<32> N, int i, int j){
	M <<=i;
	cout<<"N: " << N <<endl;
	// set all the bits in the position i through j to 0
	/*for(int k=i; k<=j; k++){
		N.reset(k);
	}*/
	// without loop - create a mask with i through j 0 and AND with N to clear the bits i through j in N to 0
	bitset<32> left = ~0;
	bitset<32> right = ((1 << i) - 1);
	left <<= (j+1);
	//cout << "left: " << left << endl;
	//cout << "right: " << right << endl;
	bitset<32> mask = left | right;
	//cout << "mask: " << mask << endl;

	N &= mask;

	// space vs time




	cout<<"N: "<<N <<endl;
	N |= M;
	cout << "N: " << N << endl;
}

void all_functions(){
	unsigned int x = 4;
		unsigned int y = 4;
		x = x << 1;
		cout<<x<<endl;
		y = ~y;
		cout<<y<<endl;
		bitset<16> z = 4;
		cout<<z<<endl;
		cout <<"Size.. " << z.size() << endl;
		cout<< "Are all the bits set to 1.." << z.all()<<endl;
		cout<<"Is there any 1.." << z.any()<<endl;
		cout<< "Is there no ones.. " << z.none()<<endl;
		cout<<"Number of ones.. " << z.count()<<endl;
		cout<<"Flipping all bits.. " << z.flip()<<endl;
		cout<<"Flipping bit at position 3 (from right).." << z.flip(3)<<endl;
		cout<<"Bit at position 3.. " << z[2] << endl;							// does not check if index exists
		cout << "Reset bit at position 4.. " << z.reset(4) << endl;
		cout << "Set bit at position 2.. " << z.set(2) << endl;
		cout << "Test of the bit at position is set.. "<< z.test(2) << endl;	// checks if index exists
}


