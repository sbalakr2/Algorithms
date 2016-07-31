/*
 * tree.cpp
 *
 *  Created on: Jul 16, 2016
 *      Author: Sindhu
 */
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct tree_node{
	int key;
	tree_node *left;
	tree_node *right;
};

void getUserCommand();
void addBFS(int k);
void deleteN(int k);
void update(int v1, int v2);
void printBFS();
void printDFS();
void printPreOrder(tree_node *root);
void printDFSRecursive(tree_node *root);
tree_node* createNewNode(int k);

tree_node *root = NULL;
queue<tree_node*> bfsAddQueue;

int main(){
	root = createNewNode(17);
	root->left = createNewNode(14);
	root->right = createNewNode(12);
	root->left->left = createNewNode(6);
	root->left->right = createNewNode(7);
	root->right->left = createNewNode(9);
	root->right->right = createNewNode(34);
	//printPreOrder(root);
	//getUserCommand();
	printDFSRecursive(root);
	return 0;
}

tree_node* createNewNode(int k){
	tree_node *newNode = new tree_node;
	newNode->key = k;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void getUserCommand(){
	int n;
	cout<<"Enter the operation(1.addBFS, 2.update, 3.delete, 4.printPreOrder, 5.printBFS, 6.printDFS or 0.exit):";
	while(cin){
		cin>>n;
		switch(n){
			case 0:
				break;
			case 1:
				int k;
				cout<<"Enter the key: "<<endl;
				cin>>k;
				addBFS(k);
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
				printPreOrder(root);
				break;
			case 5:
				printBFS();
				break;
			case 6:
				printDFS();
				break;
			default:
				break;
		}
	}
}

void addBFS(int k){
	//bfsAddQueue
	tree_node *newNode = createNewNode(k);
	bfsAddQueue.push(newNode);
	if(root == NULL)
		root = newNode;
	else{
		tree_node *freeNode = bfsAddQueue.front();
		if(freeNode->left == NULL)
			freeNode->left = newNode;
		else{
			freeNode->right = newNode;
			bfsAddQueue.pop();
		}
	}
}
/*tree_node * getNextLeaf(tree_node *root);
void add(int k){
	tree_node *newNode = new tree_node;
	newNode->key = k;
	newNode->left = NULL;
	newNode->right = NULL;
	if(root == NULL){
		 root = newNode;
	}else{
		// find the next available null pointer to insert the new node
		tree_node *cur = getNextLeaf(root);
		(cur->left == NULL)? (cur->left = newNode) : (cur->right = newNode);
	}
}

// wrong
tree_node * getNextLeaf(tree_node *root){
	if(root->left == NULL || root->right == NULL)
		return root;
	return getNextLeaf(root->left);
	return getNextLeaf(root->right);
}*/

void deleteN(int k){

}

void update(int oldV, int newV){

}

void printPreOrder(tree_node *node){ // recursive preorder
	if(node == NULL)
		return;
	else{
		cout << node->key << endl;
		printPreOrder(node->left);
		printPreOrder(node->right);
	}
}

void printBFS(){ // iterative
	if(root == NULL)
		return;
	else{
		queue<tree_node*> bfsque;
		bfsque.push(root);

		// printing
		while(!bfsque.empty()){
			tree_node *cur = bfsque.front();
			cout<< cur->key <<endl;
			if(cur->left != NULL)
				bfsque.push(cur->left);
			if(cur->right != NULL)
				bfsque.push(cur->right);
			bfsque.pop();
		}
	}
}

void printDFS(){ // iterative
	if(root == NULL)
		return;
	else{
		stack<tree_node*> bfstack;
		bfstack.push(root);

		// printing
		while(!bfstack.empty()){
			tree_node *cur = bfstack.top();
			cout<< cur->key <<endl;
			bfstack.pop();
			if(cur->right != NULL)
				bfstack.push(cur->right);
			if(cur->left != NULL)
				bfstack.push(cur->left);
		}
	}
}

void printDFSRecursive(tree_node* root){
	if(root){
		cout<<root->key<<" ";
		printDFSRecursive(root->left);
		printDFSRecursive(root->right);
	}
}


