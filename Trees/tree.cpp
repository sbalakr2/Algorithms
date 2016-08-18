/*
 * tree.cpp
 *
 *  Created on: Jul 24, 2016
 *      Author: Sindhu
 */
/*
 * findLca.cpp
 * Program to find the LCA of two nodes
 *  Created on: Jul 14, 2016
 *      Author: Sindhu
 */

// A O(n) solution to find LCA of two given values n1 and n2
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

struct tree_node{
	int key;
	tree_node* left;
	tree_node* right;
};

struct node{
	int data;
	node* next;
};

node* newLinkedListNode(int data){
	node* newLNode = new node;
	newLNode->data = data;
	newLNode->next = NULL;
	return newLNode;
}

tree_node* newTreeNode(int key){
	tree_node* newNode = new tree_node;
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void printPreOrder(tree_node* root){
	if(root){
		cout << root->key << " ";
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

tree_node* createBSTFromArr(int arr[], float start, float end){
	if(end < start)
		return NULL;
	int mid = ceil((start + end) / 2);
	tree_node* root = newTreeNode(arr[mid]);
	root->left = createBSTFromArr(arr, start, mid-1);
	root->right = createBSTFromArr(arr, mid+1, end);
	return root;
}

void insertintoLL(node* head, int key){
	node* temp = head;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = newLinkedListNode(key);
}

void createLinkedListAtDepths(tree_node* root, vector<node*> &varr, size_t level){ // recursive
	cout<<"lvl: "<<level<<endl;
	if(!root)
		return;
	if(varr.size() == level){ // create a new linked list
		node* head = newLinkedListNode(root->key);
		varr.push_back(head);
	} else{
		node* head = varr.at(level);
		insertintoLL(head, root->key);
	}
	createLinkedListAtDepths(root->left, varr, level+1);
	createLinkedListAtDepths(root->right, varr, level+1);
}

//todo
void createLinkedListAtDepthBFS(tree_node* root, vector<node*> varr){
	/*if(!root)
		return;
	tree_node* temp = root;
	node* curlist = newLinkedListNode(temp->key);
	varr.push_back(curlist);

	while(curlist){
		tree_node* cur = temp;
		node
		if(cur->left)
	}*/
}

void printLinkedList(node* head){
	node* temp = head;
	while(temp){
		cout<< temp->data << " ";
		temp = temp->next;
	}
	cout<<endl;
}

void printAllLinkedLists(vector<node*> v){
	vector<node*>::iterator it;
	int i=0;
	for(it = v.begin(); it != v.end(); it++){
		cout<< "Printing list at level " <<i <<": ";
		printLinkedList(*it);
		i++;
	}
}

int checkHeight(tree_node* root){
	if(!root)
		return 0;
	int leftHt = checkHeight(root->left);
	if(leftHt == -1)
		return -1;
	int rightHt = checkHeight(root->right);
	if(rightHt == -1)
		return -1;
	int diff = abs(leftHt - rightHt);
	if(diff > 1)
		return -1;
	else
		return max(leftHt, rightHt) + 1;

}

void checkBalancedBT(tree_node* root){
	int ht = checkHeight(root);
	if(ht == -1)
		cout<<"Not balanced";
	else
		cout<<"Balanced and height is "<<ht;
}

int lastChecked = -1;
bool isBSTByInOrder(tree_node* root){
	if(!root)
		return true;
	if(!isBSTByInOrder(root->left))
		return false;
	if(lastChecked != -1 && root->key <= lastChecked)
		return false;
	lastChecked = root->key;
	if(!isBSTByInOrder(root->right))
		return false;
	return true;
}

void checkIfBTisBST(tree_node* root){
	// in-order traversal should yield sorted elements
	bool flag = isBSTByInOrder(root);
	(flag)? cout<<"BST" : cout<<"Not BST";
}

bool checkBSTree(tree_node* root, int min, int max){
	if(!root)
		return true;
	if((min != -1 && min > root->key)|| (max != -1 && max <= root->key))
		return false;
	if(!checkBSTree(root->left, min, root->key) || !checkBSTree(root->right, root->key, max))
		return false;
	return true;
}

void checkBST(tree_node* root){
	bool flag = checkBSTree(root, -1, -1);
	flag? cout<<"BST" : cout<< "Not BST";
}

int getMinVal(tree_node* n){
	tree_node* cur = n;
	while(cur->left)
		cur = cur->left;
	return cur->key;
}

void printInOrderSuccessor(tree_node* root, tree_node* n){
	if(n->right != NULL){
		cout << "InOrder Successor:" << getMinVal(n->right);
	} else{
		// start from the root
		tree_node* succ = NULL;
		tree_node* temp = root;
		while(temp){
			if(n->key < temp->key){
				succ = temp;
				temp = temp->left;
			} else if(n->key > temp->key){
				temp = temp->right;
			} else
				break;
		}
		succ? cout<< "InOrder Successor:" << succ->key : cout << "No Successor";
	}
}

tree_node* getPreOrderSuccessor(tree_node* root, tree_node* n){
	if(n->left)
		return n->left;
	if(n->right)
		return n->right;
	stack<tree_node*> parents;
	tree_node* temp = root;
	while(temp->key != n->key){
		parents.push(temp);
		if(n->key < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	while(!parents.empty()){
		if(parents.top()->right && (n->key != parents.top()->right->key)){
			return parents.top()->right;
		}
		n = parents.top();
		parents.pop();
	}
	return NULL;
}

void printPreOrderSuccessor(tree_node* root, tree_node* n){
	tree_node* succ = getPreOrderSuccessor(root, n);
	succ? cout << "PreOrder Successor: " << succ->key :
			cout<< "No PreOrder Successor";
}

tree_node* createTree(){
	tree_node *root = newTreeNode(20);
	root->left = newTreeNode(8);
	root->right = newTreeNode(22);
	root->left->left = newTreeNode(4);
	root->left->right = newTreeNode(12);
	root->left->right->left = newTreeNode(10);
	root->left->right->right = newTreeNode(14);
	return root;
}

int main(){
	/***** CTCI - 4.2 *****/
	//int arr[] = {1,2,3,4,5,6,7,8,9,10};
	//float len = sizeof(arr)/sizeof(int);
	//tree_node* root = createBSTFromArr(arr, 0, len-1);
	//printPreOrder(root);
	/***** CTCI - 4.3 *****/
	tree_node* root = createTree();
	//vector<node*> llArray;
	//createLinkedListAtDepths(root, llArray, 0);
	//createLinkedListAtDepthBFS(root, llArray);
	//printAllLinkedLists(llArray);
	/***** CTCI - 4.4 *****/
	//checkBalancedBT(root);

	//checkIfBTisBST(root);
	//checkBST(root);
	//printInOrderSuccessor(root, root->left->right);
	printPreOrderSuccessor(root, root->left->right->right);
	return 0;
}




