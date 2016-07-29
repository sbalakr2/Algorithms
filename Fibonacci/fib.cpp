/*
 * fib.cpp
 *
 *  Created on: May 30, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <vector>
using namespace std;
int fibonacci(int n);
int memoizedFib(int n);
int topDownMemoizedFib(int i, vector<int> arr);
int main(){
	cout <<"Enter n: ";
	int n;
	cin>>n;
	//int res = fibonacci(n);
	//int res = memoizedFib(n);
	vector<int> arr(n+1,0);
	int res = topDownMemoizedFib(n, arr);
	cout<<res<<endl;
	return 0;
}

int fibonacci(int n){
	//cout<<"n: "<<n<<endl;
	if(n==0) return 0;
	if(n==1) return 1;
	return fibonacci(n-1)+fibonacci(n-2);
}

// Bottom-up dynamic programming
int memoizedFib(int n){
	int memo[n];
	memo[0] = 0;
	memo[1] = 1;
	for(int i=2; i< n; i++){
		memo[i] = memo[i-1] + memo[i-2];
	}
	return memo[n-1] + memo[n-2];
}

// Top-down memoization
int topDownMemoizedFib(int i, vector<int> memo){
	//for(vector<int>::iterator it= memo.begin(); it != memo.end(); it++)
		//cout << *it << endl;
	if(i==0 || i==1)
		return i;
	//cout<< memo.at(i)<<endl;
	if(memo.at(i) == 0)
		memo.at(i) = topDownMemoizedFib(i-1, memo) + topDownMemoizedFib(i-2, memo);
	return memo.at(i);
	return 0;
}

