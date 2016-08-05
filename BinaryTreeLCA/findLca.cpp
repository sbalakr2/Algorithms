/*
 * findLca.cpp
 * Program to find the LCA of two nodes
 *  Created on: Jul 14, 2016
 *      Author: Sindhu
 */

// A O(n) solution to find LCA of two given values n1 and n2
#include <iostream>
#include <vector>
using namespace std;

struct tree_node{
	int key;
	tree_node* left;
	tree_node* right;
};

tree_node* newTreeNode(int key){
	tree_node* newNode = new tree_node;
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

tree_node* createBTforLSA(){
	/*tree_node* root = newTreeNode(1);
	root->left = newTreeNode(2);
	root->right = newTreeNode(3);
	root->left->left = newTreeNode(4);
	root->left->right = newTreeNode(5);
	root->right->left = newTreeNode(6);
	root->right->right = newTreeNode(7);
	root->left->left->left = newTreeNode(8);
	root->left->left->right = newTreeNode(9);
	root->left->right->left = newTreeNode(10);*/

	tree_node* root = newTreeNode(20);
	root->left = newTreeNode(8);
	root->right = newTreeNode(22);
	root->left->left = newTreeNode(4);
	root->left->right = newTreeNode(12);
	root->left->right->left = newTreeNode(10);
	root->left->right->right = newTreeNode(14);
	return root;
}

void printVector(vector<int> v){
	vector<int>::iterator it;
	cout<< "Printing Vector: ";
	for(it = v.begin(); it != v.end(); it++)
		cout<< *it << " ";
	cout<<endl;
}

bool findPath(tree_node* root, vector<int> &path, int k){
	if(!root)
		return false;
	path.push_back(root->key);

	if(root->key == k)
		return true;

	if((root->left && findPath(root->left, path, k)) ||
	   (root->right && findPath(root->right, path, k)))
		return true;

	path.pop_back();
	return false;
}

int findLCAOfBT(tree_node* root, int n1, int n2){
	vector<int> path1, path2;
	if(! findPath(root, path1, n1) || !findPath(root, path2, n2))
		return -1;

	printVector(path1);
	printVector(path2);
	size_t i = 0;
	for(i=0; i< path1.size() && i < path2.size(); i++){
		if(path1[i] != path2[i])
			break;
	}
	return path1[i-1];
}

int findLCAOfBTRecursive(tree_node* root, int n1, int n2){
	if(!root)
		return -1;
	if(root->key == n1 || root->key == n2)
		return root->key;

	int left_lca = findLCAOfBTRecursive(root->left, n1, n2);
	int right_lca = findLCAOfBTRecursive(root->right, n1, n2);

	if((left_lca != -1)&& (right_lca != -1))
		return root->key;

	return (left_lca != -1) ? left_lca : right_lca;
}

void findLCAOfBinaryTree(tree_node* root){
	int n1,n2;
	cout <<"\n Enter the two nodes: " << endl;
	cin>>n1>>n2;
	//int lca = findLCAOfBT(root, n1, n2);
	int lca = findLCAOfBTRecursive(root, n1, n2);
	if(lca != -1)
		cout << "Lowest Common Ancestor: " << lca;
	else
		cout << "LCA not found!";
}

void printPreOrder(tree_node* root){
	if(root){
		cout << root->key << " ";
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

tree_node* findLCAOfBST(tree_node* root, int n1, int n2){// assumes that n1 and n2 are present in the BST
	if(!root || n1 == n2)
		return NULL;
	int low = (n1 < n2) ? n1 : n2;
	int high = (n1 < n2) ? n2 : n1;

	if(low < root->key && high < root->key)
		return findLCAOfBST(root->left, low, high);

	if(low > root->key && high > root->key)
		return findLCAOfBST(root->right, low, high);

	return root;
}

int main(){
	tree_node* root = createBTforLSA();
	printPreOrder(root);
	//findLCAOfBinaryTree(root);
	tree_node* lcaNode = findLCAOfBST(root, 14, 22);
	if(lcaNode)
		cout << "LCA: " << lcaNode->key;
	else
		cout<<"No LCA";
	return 0;
}
