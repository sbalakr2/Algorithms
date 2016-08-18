/*
 *  uniqueTri.cpp
 *  Count number of unique Triangles using STL | Set 1 (Using set)
 *	http://www.geeksforgeeks.org/count-number-of-unique-triangles-using-stl/
 *  Created on: May 23, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> iPair;

void sort(int &a, int &b, int &c);
void swap(int &x, int &y);
int main(){
	set < pair< int, iPair > > s;
	int n;
	cout<< "Enter the number of triangles: ";
	cin>>n;
	for(int i=0; i<n; i++){
		cout<< "Enter the dimensions of triangle "<<i+1<<endl;
		int a,b,c;
		cin>>a>>b>>c;
		sort(a,b,c);
		s.insert({a,{b,c}});
	}
	cout<<"Number of unique triangles: "<<s.size()<<endl;
	return 0;
}

void sort(int &a, int &b, int &c){
	if(a>b)swap(a,b);
	if(b>c)swap(b,c);
	if(a>b)swap(a,b);
}

void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

