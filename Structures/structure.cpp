/*
 * structure.cpp
 *
 *  Created on: Jul 16, 2016
 *      Author: Sindhu
 */

#include <iostream>
using namespace std;
void createPointerNode();
void createNode();
struct node{
	int data;
	int key;
};
int main(){
	createNode();
	//createPointerNode();
	return 0;
}
void createNode(){
	node node01;
	node01.data = 10;
	node01.key = 20;
	cout << node01.data << endl;
	//cout << node01 << endl; - will throw error
}
void createPointerNode(){
	node *node01 = new node;
	(*node01).data = 2;
	node01->key = 1;
	cout<<node01->data << endl;
	cout<< "address: " << node01;
}


