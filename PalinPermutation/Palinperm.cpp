/*
 * Palimperm.cpp
 *	Given a string, find all the palindrome permutations of the string
 *	http://www.geeksforgeeks.org/print-all-palindrome-permutations-of-a-string/
 *  Created on: May 22, 2016
 *      Author: Sindhu
 */
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

void checkAndPrintPalinPermutes(string s);
void printAllPermutations(string s, map<char, int> strMap);
string reverseString(string str);
int main(){
	string s;
	cout<< "Enter the string: ";
	cin>>s;
	checkAndPrintPalinPermutes(s);
	return 0;
}

void checkAndPrintPalinPermutes(string s){
	int n = s.length();
	map<char, int> strMap;
	//for(string::iterator it = s.begin(); it != s.end(); it++){} // valid
	for(int i=0; i<n; i++){
		map<char, int>::iterator it;
		it = strMap.find(s[i]);
		if(it == strMap.end())
			strMap.insert(pair<char, int>(s[i], 1));
		else
			it->second += 1;
	}
	int odd = 0;
	for(map<char,int>::iterator it= strMap.begin(); it != strMap.end(); it++){
		cout << it->first <<"~" << it->second << endl;
		if(it->second % 2 == 1)
			odd++;
	}
	cout<<"odd: "<<odd<<endl;
	if((n%2==0 && odd==0) || (n%2==1 && odd==1)){
		printAllPermutations(s, strMap);
	}else{
		cout<<"No palindrome permutations possible!"<<endl;
	}
}

void printAllPermutations(string s, map<char, int> strMap){
	int n = s.length();
	string half;
	char oddC;
	for(map<char,int>::iterator it= strMap.begin(); it != strMap.end(); it++){
		if(it->second % 2 == 1)
			oddC = it->first;
		half += string((it->second)/2, it->first);
	}
	cout<<"half: "<<half<<endl;
	do{
		string final = half;
		if(n%2 == 1)
			final += oddC;
		final += reverseString(half);
		cout<<"final: "<<final<<endl;
	}while(next_permutation(half.begin(), half.end()));
}

string reverseString(string str){
	string s = str;
	reverse(s.begin(), s.end());
	return s;
}



