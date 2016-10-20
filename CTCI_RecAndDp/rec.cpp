/*
 * rec.cpp
 *
 *  Created on: Sep 18, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <vector>
#include "maze.h"
#include <map>
using namespace std;

void stairsProblem();
int getWaysToJump(int n);
int getWaysToJumpMemo(int n);
int getWaysToJumpTopDown(int n, vector<int>& memo);
void mazeProblem();
bool getPath(int r, int c, int i, int j, vector<Point> &path, map<Point, bool> &cache);

int main(){
	//stairsProblem();
	mazeProblem();
	return 0;
}

void mazeProblem(){
	int row,col;
	cout << "Enter the number of rows and columns: ";
	cin>>row>>col;
	vector<Point> path;
	map<Point, bool> cache;
	if(getPath(row-1, col-1, row-1, col-1, path, cache)){
		cout << "Path exists";
	} else{
		cout << "No Path found!";
	}
}

bool getPath(int r, int c, int i, int j, vector<Point> &path, map<Point, bool> &cache){
	Point p(r, c);

	if((r<0) || (c<0) || (i>r) || (j>c)){
		return false;
	}

	//if(cache.find(p) != cache.end()){
		//return cache.find(p)->second;
	//}

	bool isOrigin = (i == 0) && (j == 0);
	bool success = false;

	if(isOrigin || getPath(r, c, i-1, j, path, cache) || getPath(r, c, i, j-1, path, cache)){
		path.push_back(p);
		success = true;
	}
	//cache.insert(pair<Point, bool>(p,success));
	return success;
}

void stairsProblem(){
	cout << "Enter the number of stairs: ";
	int n;
	cin>>n;
	//cout << "Possible ways: " << getWaysToJump(n);
	//cout << "Possible ways: " << getWaysToJumpMemo(n);
	vector<int> v(n+1,-1);
	cout << "Possible ways: " << getWaysToJumpTopDown(n, v);
}

int getWaysToJump(int n){
	if(n<0)
		return 0;
	if(n==0)
		return 1;
	return getWaysToJump(n-1) + getWaysToJump(n-2) + getWaysToJump(n-3);
}

// Memoized version
int getWaysToJumpMemo(int n){
	if(n<0)return 0;
	int memo[n+1];
	memo[0] = 1;
	memo[1] = 1;
	memo[2] = 2;
	for(int i=3; i<=n; i++){
		memo[i] = memo[i-1] + memo[i-2] + memo[i-3];
	}
	return memo[n];
}

int getWaysToJumpTopDown(int n, vector<int>& memo){
	if(n<0)
		return 0;
	if(n==0)
		return 1;
	if(memo.at(n) == -1){
		memo.at(n) = getWaysToJumpTopDown(n-1, memo) +
				getWaysToJumpTopDown(n-2, memo) + getWaysToJumpTopDown(n-3, memo);
	}
	return memo.at(n);
}
