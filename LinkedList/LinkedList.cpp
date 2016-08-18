/*
 * LinkedList.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: Sindhu
 */
#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

node *head = NULL;

void add(int n){
	node *newNode = new node;
	newNode->data = n;
	newNode->next = NULL;
	if(head == NULL){
		head = newNode;
	}
	else{
		node *temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void print(){
	if(head != NULL){
		cout<< "Printing.." << endl;
		node *temp = head;
		while(temp->next != NULL){
			cout << temp->data <<endl;
			temp = temp->next;
		}
		cout << temp->data <<endl;
	} else{
		cout << "List empty"<<endl;
	}
}

void update(int v1, int v2){
	if(head != NULL){
		node *temp = head;
		while(temp->next != NULL){
			if(temp->data == v1){
				temp->data = v2;
			} else{
				temp = temp->next;
			}
		}
		if(temp->data == v1){
			temp->data = v2;
		}
	} else{
		cout << "List empty"<<endl;
	}
}

void deleteN(int val){
	bool isFound = false;
	if(head != NULL){
		node *temp = head;
		node *prev = head;
		if(temp->data == val){
			head = temp->next;
			isFound = true;
		} else{
			while(temp->next != NULL){
				prev = temp;
				temp = temp->next;
				if(temp->data == val){
					prev->next = temp->next;
					//temp = prev;
					isFound = true;
				}
			}
		}
		if(!isFound){
			cout << "Value not found" << endl;
		} else{
			cout << "Value deleted" << endl;
		}
	} else{
		cout << "List empty" << endl;
	}
}

void reverse(){
	node *prev = NULL;
	node *cur = head;
	node *next;
	while(cur != NULL){
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	head = prev;
}

int main(){
	int n;
	cout<<"Enter the operation(1.add, 2.update, 3.delete, 4.print 5.reverse or 0.exit):";
	while(cin){
		cin>>n;
		switch(n){
			case 0:
				return 0;
			case 1:
				cout<<"Enter the value to add: "<<endl;
				int a;
				cin>>a;
				add(a);
				break;
			case 2:
				int oldVal, newVal;
				cout<<"Enter the old value: "<<endl;
				cin>>oldVal;
				cout<<"Enter the new value: "<<endl;
				cin>>newVal;
				update(oldVal, newVal);
				break;
			case 3:
				cout<<"Enter the value to delete: "<<endl;
				int d;
				cin>>d;
				deleteN(d);
				break;
			case 4:
				print();
				break;
			case 5:
				reverse();
				break;
			default:
				break;
		}
	}
	return 0;
}



