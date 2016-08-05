/*
 * tree.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: Sindhu
 */
#include <iostream>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

node *root = NULL;

node *getChild(node *cur,int n){
	if(n > cur->data){
		if(cur->right != NULL){
			return getChild(cur->right,n);
		} else{
			return cur;
		}
	} else{
		if(cur->left != NULL){
			return getChild(cur->left,n);
		} else{
			return cur;
		}
	}
}
void insert(int n){
	node *temp = new node;
	temp->data = n;
	temp->left = NULL;
	temp->right = NULL;
	if(root == NULL){
		root = temp;
	} else{
		node *parent = getChild(root,n);
		if(n > parent->data){
			parent->right = temp;
		}
		else{
			parent->left = temp;
		}
	}
}
bool searchAndUpdate(node *cur, int v1, int v2){
	if(cur->data == v1){
		cur->data = v2;
		return true;
	} else{
		if(v1 < cur->data){
			if(cur->left != NULL)
				searchAndUpdate(cur->left,v1,v2);
		}
		else{
			if(cur->right != NULL)
				searchAndUpdate(cur->right,v1,v2);
		}
	}
	return false;
}
void update(int v1, int v2){
	bool isOk = searchAndUpdate(root,v1,v2);
	cout<<"is OK: "<<isOk<<endl;
	if(isOk)
		cout <<"Updated"<<endl;
	else
		cout<<"Data not found"<<endl;
}
void deleteN(int val){

}
void preorder(node *cur){
	cout<<cur->data<<" ";
	if(cur->left != NULL)
		preorder(cur->left);
	if(cur->right != NULL)
		preorder(cur->right);
}
int main(){
	int n;
		cout<<"Enter the operation(1.insert, 2.update, 3.delete, 4.preorder or 0.exit):";
		while(cin){
			cin>>n;
			switch(n){
				case 0:
					return 0;
				case 1:
					cout<<"Enter the value to insert: "<<endl;
					int a;
					cin>>a;
					insert(a);
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
					preorder(root);
					break;
				default:
					break;
			}
		}
		return 0;
}



