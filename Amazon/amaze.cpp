/*
 * code.cpp
 *
 *  Created on: Sep 29, 2016
 *      Author: Sindhu
 */
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <tr1/unordered_map>
#include <queue>
using namespace std;

struct tree_node{
	int val;
	tree_node* left;
	tree_node* right;
};
tree_node* createNode(int v){
	tree_node* node = new tree_node();
	node->val = v;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void getNodes(tree_node* root, size_t i, vector< vector<int> >& vec){
	if(root == NULL) return;
	vector<int> temp;
	if(i == vec.size()){
		temp.push_back(root->val);
		vec.push_back(temp);
	} else{
		temp = vec.at(i);
		temp.push_back(root->val);
		vec.at(i) = temp;
		//vec.erase(vec.begin()+i);
		//vec.emplace(vec.begin()+i, temp);
	}
	getNodes(root->left, i+1, vec);
	getNodes(root->right, i+1, vec);
}
void printVec(vector< vector<int> > &v){
	vector< vector<int> >::iterator it;
	for(it = v.begin(); it != v.end(); ++it){
		vector<int>::iterator it2;
		for(it2 = (*it).begin(); it2 != (*it).end(); ++it2){
			cout << *it2 << " ";
		}
		cout << endl;
	}
}
void delimiterMatching();
void delimiterMatching2();
void movingInMaze();
void priorityqueue();
void matrixMaze();
int main(){
	tree_node* root = createNode(3);
	root->left = createNode(9);
	root->right = createNode(20);
	root->right->left = createNode(15);
	root->right->right = createNode(7);
	vector< vector<int> > vec;
	getNodes(root, 0, vec);
	printVec(vec);
	//delimiterMatching();
	//delimiterMatching2();
	//movingInMaze();
	//priorityqueue();
	//matrixMaze();
	return 0;
}

void priorityqueue(){
	priority_queue<int, vector<int>, greater<int> > pq;
	pq.push(30);
	pq.push(20);
	pq.push(40);
	cout << pq.top();
}

bool findPathInMaze(int maze[4][4], int n, int a, int b, vector< vector<int> > &res);

void movingInMaze(){
	int maze[4][4] = {{1, 0, 0, 0},
					{1, 1, 0, 1},
					{0, 1, 0, 0},
					{1, 1, 1, 1}};
	// all 0 is blocked
    // start is (0,0) and destination is (3,3)
	vector< vector<int> > res;
	if(findPathInMaze(maze, 4, 0, 0, res)){
		cout << "Path exists:" <<endl;
		//print path
		vector< vector<int> >::iterator it;
		for(it = res.begin(); it != res.end(); ++it){
			vector<int> temp = *it;
			cout << temp.at(0) << ", " <<temp.at(1) << endl;
 		}
	} else{
		cout << "No path exists!";
	}
}

bool isSafe(int n, int a, int b){
	if(a < 0 || a >= n || b < 0 || b >= n){
		return false;
	}
	return true;
}

bool findPathInMaze(int maze[4][4], int n, int a, int b, vector< vector<int> > &res){
	if(isSafe(n,a,b) && (maze[a][b] == 1)){
		vector<int> temp(2,0);
		temp.at(0) = a; temp.at(1) = b;
		res.push_back(temp);

		if(a == n-1 && b == n-1){
			return true;
		}
		if(findPathInMaze(maze, n, a+1, b, res) || findPathInMaze(maze, n, a, b+1, res))
			return true;
		// backtrack
		res.pop_back();
		return false;
	}
	return false;
}

//print the result matrix
bool mazePathExists(int maze[4][4], int n, int a, int b, int sol[4][4]){
	if(isSafe(n,a,b) && (maze[a][b] == 1)){
		sol[a][b] = 1;

		if(a == n-1 && b == n-1){
			return true;
		}
		if(mazePathExists(maze, n, a+1, b, sol) || mazePathExists(maze, n, a, b+1, sol))
			return true;
		// backtrack
		sol[a][b] = 0;
		return false;
	}
	return false;
}
void matrixMaze(){
	int maze[4][4] = {{1, 0, 0, 0},
					{1, 1, 0, 1},
					{0, 1, 0, 0},
					{1, 1, 1, 1}};
	int sol[4][4] = {{0, 0, 0, 0},
					{0, 0, 0, 0},
					{0, 0, 0, 0},
					{0, 0, 0, 0}};

	if(mazePathExists(maze, 4, 0, 0, sol)){
		cout << "Path exists: "<<endl;
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
		//print sol matrix
	} else{
		cout << "No path found!" << endl;
	}

}

bool isDelimiter(int val){
	if(val == 123 || val == 125 || val == 40 || val == 41 || val == 91 || val == 93)
		return true;
	return false;
}
bool isPair(int open, int close){
	if(open > close) return false;
	if((open == 123 && close == 125) || (open == 40 && close == 41) || (open == 91 && close == 93))
		return true;
	return false;
}
// Using two stacks
void delimiterMatching(){
	string s("([)]");
	int n = s.length();
	stack<int> st1, st2;
	for(int i=0; i<n; i++){
		if(isDelimiter(s[i]))
			st1.push(s[i]);
	}
	while(!st1.empty()){
		int top = st1.top();
		st1.pop();
		if(!st2.empty() && isPair(top, st2.top())){
			st2.pop();
		}
		else if(!st1.empty() && isPair(st1.top(), top)){
			st1.pop();
		} else{
			st2.push(top);
		}
	}
	(st2.empty())? cout << "Match!" : cout << "Not matching!" ;
}

bool isClose(int val){
	if(val == 125 || val == 41 || val == 93)
		return true;
	return false;
}

bool isOpen(int val){
	if(val == 123 || val == 40 || val == 91)
		return true;
	return false;
}

bool isMatch(string s){
	int n = s.length();
	stack<int> st1;
	for(int i=0; i<n; i++){
		if(isDelimiter(s[i])){
			if(isOpen(s[i])){
				st1.push(s[i]);
			} else{
				// compare it to top
				if(isPair(st1.top(), s[i])){
					st1.pop();
				} else{
					return false;
				}
			}
		}
	}
	return true;
}
//Using one stack
void delimiterMatching2(){
	string s("{([()])}");
	isMatch(s) ? cout << "Match!" : cout <<"Not match!";

}



