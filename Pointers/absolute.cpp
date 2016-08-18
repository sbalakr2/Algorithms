/*
 * absolute.cpp
 *
 *  Created on: Mar 23, 2016
 *      Author: Sindhu
 */
#include <iostream>
#include <cmath>
using namespace std;

void update(int *a, int *b){
	*a = *a + *b;
	*b = abs(*a - 2*(*b));
}

struct stu{
	int id;
	string name;
};

void testUpdate(){
	int a, b;
	int *pa = &a, *pb = &b;
	cin >>a; cin>>b;
	update(pa, pb);
	cout << a << endl << b<< endl;
}

void testStruct(){
	stu stu1;
	stu1.id = 1;
	stu1.name = "Gem";

	stu *stu2 = NULL;
	stu2->id = 2;
	stu2->name = "John";

	cout << stu1.id<<endl;
}

int main() {
   // testUpdate();
    testStruct();
    return 0;
}




