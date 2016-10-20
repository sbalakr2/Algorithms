/*
 * spiral.cpp
 *
 *  Created on: Sep 6, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void printArray(int mx[4][4], int m, int n);
void shuffle(int arr[], int n);
void anagrams();
void printSpiralVector();
vector<int> spiralOrder(vector< vector<int> >& matrix);

int main(){
	/*int m=4,n=4;
	int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	printArray(matrix, m, n);*/
	/*int arr[] = {4,5,6,3,2,1,7,6,12,8,0,9};
	int n=12;
	shuffle(arr, n);*/
	//anagrams();
	printSpiralVector();
}

void printSpiralVector(){
	vector< vector<int> > matrix;
	int counter = 1;
	for(int i=1; i<=3; i++){
		vector<int> temp;
		for(int j=1; j<=3; j++){
			temp.push_back(counter);
			counter++;
		}
		matrix.push_back(temp);
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout << matrix.at(i).at(j) <<" ";
		}
		cout << endl;
	}
	vector<int> res = spiralOrder(matrix);
	// printing res
	for(size_t i=0; i<res.size(); i++){
			cout << res.at(i);
	}
}

vector<int> spiralOrder(vector< vector<int> >& matrix) {
    vector<int> res;
    int m = matrix.size();
    int n = matrix.at(0).size();
    int i=0, j=0, k=m-1, l=n-1;
   while(i<=k || j<=l){
       for(int b=j; b<=l; b++)
           res.push_back(matrix.at(i).at(b));
       i++;
       for(int a=i; a<=k; a++)
           res.push_back(matrix.at(a).at(l));
       l--;
       for(int b=l; b>=j; b--)
           res.push_back(matrix.at(k).at(b));
       k--;
       for(int a=k; a>=i; a--)
           res.push_back(matrix.at(a).at(j));
       j++;

   }
   return res;
}

bool isAnagram(string s1, string s2){
	if(s1.length() != s2.length())
		return false;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	int n = s1.length();
	for(int i=0; i<n; i++){
		if(s1[i] != s2[i])
			return false;
	}
	return true;
}

void anagrams(){
	string s1, s2;
	// sort s1 and s2 then compare
	cout << "Enter the first string: ";
	cin>>s1;
	cout << "Enter the second string: ";
	cin>>s2;
	cout << "Is Anagram: " << isAnagram(s1, s2);
}

void swap(int arr[], int n, int i){
	int temp = arr[n];
	arr[n] = arr[i];
	arr[i]=temp;
}

void printarr(int arr[], int n){
	for(int j=0; j<n; j++){
		cout << arr[j] <<" ";
	}
	cout<<endl;
}

void shuffle(int arr[], int n){
	int k=0;
	while(k<10){
		for(int i=(n-1); i>0; i--){
			// random number
			int num = rand() % i;
			swap(arr, num, i);

		}
		k++;
		printarr(arr, n);
	}
}

void printArray(int mx[4][4], int m, int n){
	int i=0,j=0,k=m-1,l=n-1;
	while(i<=k || j<=l){
		for(int b=j; b<=l; b++){
			cout << mx[i][b] << " ";
		}
		i++;
		for(int a=i; a<=k; a++){
			cout << mx[a][l] << " ";
		}
		l--;
		for(int b=l; b>=j; b--){
			cout << mx[k][b] << " ";
		}
		k--;
		for(int a=k; a>=i; a--){
			cout << mx[a][j] << " ";
		}
		j++;
	}
}


