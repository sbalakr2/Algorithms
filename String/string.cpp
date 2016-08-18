/*
 * string.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <string>
using namespace std;

int main(){
	string str = "The best thing about being a vegetarian is that you will be healthy being";
	string str2 = "being";
	string str3 = "hello world";
	cout << str.find(str2) << endl;
	cout << (str.find(str3)== string::npos) << endl;
	return 0;
}



