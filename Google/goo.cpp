/*
 * goo.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: Sindhu
 */

#include<iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <stack>
using namespace std;
int getMin(int n);
string intToString(int n);
void printTransCnt();
void pathProblem();
void SplitString();

int main(){
	//int n = 23316;
	//cout << getMin(n);
	//printTransCnt();
	//pathProblem();
	SplitString();
	return 0;
}

void SplitString(){
	string s = "this \n  is \n   not";
	stringstream ss(s);
	string str;
	while(getline(ss, str)){
		cout << str << endl;
	}
}

void pathProblem(){
	cout << "Enter the path: ";
	stack<string> pathStack;
	string str;
	size_t i=0;
	int len = 0;
	int total_len = 0;
	bool isPrev = false; // is the previous one file
	while(getline(cin, str)){
		if(str.find_first_not_of("\t") == i){
			if((str.find(".jpeg") != string::npos) || (str.find(".gif") != string::npos)){
				isPrev = true;
				total_len += len;
			} else{
				isPrev = false;
				pathStack.push(str);
				len += (str.length() + 1 - i); cout << "len1: " << len << endl;
				i++;
			}
		} else{
			if((str.find(".jpeg") != string::npos) || (str.find(".gif") != string::npos)){
				if(!isPrev){
					len -= (pathStack.top().length() + 1 - pathStack.top().find_first_not_of("\t"));
					cout << "len: " << len << endl;
					total_len += len;
					cout << "total_len: " << total_len << endl;
					pathStack.pop();
				}
				isPrev = true;
			} else{
				isPrev = false;
				len += (str.length() - pathStack.top().length());
				pathStack.pop();
				pathStack.push(str);
			}
		}
	}
	cout << "total length: " <<total_len << endl;
}

void printTransCnt(){
	string s("abcdba");
	//cin>>s;
	int n = s.length();
	int i=0, j=n-1, cnt=0;
	while(i<j){
		if(s[i] != s[j]){
			cnt += abs(s[i]-s[j]);
		}
		i++;
		j--;
	}
	cout << cnt << endl;
}

string intToString(int n){
	stringstream ss;
	ss<<n;
	return ss.str();
}

int stringToInt(string s){
	stringstream ss(s);
	int i;
	ss>>i;
	return i;
}

int getMin(int n){
	// int to string
	string s = intToString(n);
	cout << "s: "<<s << endl;
	int i,j;
	int len = s.length();
	int min = INT_MAX;
	for(i=0; i<(len-1);i++){
		j=i+1;
		char c = (s[i] > s[j])? s[i]:s[j];
		string first = s.substr(0, i);
		cout << "first: "<<first << endl;
		string last = s.substr(j+1, len-1);
		cout << "last: "<<last << endl;
		string res = first;
		res.push_back(c);
		res.append(last);
		cout << "res: "<<res<<endl;
		// string to int
		int intVal = stringToInt(res);
		if(intVal < min)
			min = intVal;
	}
	return min;
}

