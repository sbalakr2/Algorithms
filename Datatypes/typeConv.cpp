/*
 * typeConv.cpp
 *
 *  Created on: Mar 26, 2016
 *      Author: Sindhu
 */
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
using namespace std;

void strConv();
string intToString(int n);
int stringToInt(string s);
int main(){
	//convert an integer to string
	string str("25859346537");
	char a = str[4];
	char b = str[7];
	cout<<"char a : "<<a<<endl;cout<<"char b : "<<b<<endl;
	cout<< (a>b) << endl;
	cout<< (a<b) << endl;
	str.replace(4,1,"X");
	cout<<"after "<<str<<endl;

	char c = '2';
	cout << (c-'0')+3 <<endl;


	//strConv();
	return 0;
}

int stringToInt(string s){
	stringstream ss(s);
	int i;
	ss>>i;
	return i;
}
string intToString(int n){
	stringstream ss;
	ss<<n;
	return ss.str();
}

void strConv(){
	string str = intToString(1125);
	cout << str << endl;
	cout << str[1] << endl;

	//convert a string to integer
	string myStr = "100";
	int i = stringToInt(myStr);
	cout << i << endl;
	cout << i+50 << endl;

	// convert string to integer - using stoi
	string myStr2 = "200";
	int j = stoi(myStr2);
	int k = atoi(myStr2.c_str());
	long long l = stoll(myStr2);
	cout << j << endl;
	cout << j+50 << endl;
	cout << "k-"<<k << endl;
	cout << k+50 << endl;
	cout << l+230<<endl;

	//char to int
	char ch = '2';
	int ab = ch - '0';
	cout<<ab<<endl;

	//int to char
	int bc = 2;
	char cd = bc + '0';
	cout<<cd<<endl;
}



