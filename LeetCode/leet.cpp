/*
 * leet.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <map>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
void happyNumber();
void print(int *a, int n);
void powerofTwo();
void powerOfThree();
void romanNumeral();
void arrayIntersection();
void arrayDupliates();
bool isDup(int arr[], int n);
void validAnagram();
bool isAnagram(string s, string t);
bool isAnagram2(string s, string t);
void excelColumn();
void uglyNumber();
void countPrimes();
bool isPrime(int i);

template<class T>
void printVector(vector<T> &v){
	typename vector<T>::iterator it;
	cout <<"Size: " <<v.size() << endl;
	cout << "Printing: ";
	for(it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout<<endl;
}

int compare(const void* a, const void* b){
	return ( *(int*)a - *(int*)b );
}

int main(){
	//happyNumber();
	//powerofTwo();
	//powerOfThree();
	//romanNumeral();
	//arrayIntersection();
	//arrayDupliates();
	//validAnagram();
	//excelColumn();
	//uglyNumber();
	countPrimes();
	return 0;
}

void countPrimes() {
	int n = 18;
	int cnt = 0;
	for(int i=0; i<n; i++){
		// check if i is prime and inc cnt
		if(isPrime(i)){
			cout << i << endl;
			cnt++;
		}
	}
	cout<< cnt;
}

bool isPrime(int i){
	if(i<2) return false;
	for(int k=2; k<=(i/2); k++){
		if(i%k == 0)
			return false;
	}
	return true;
}

bool isUgly(int num){
	if(num<=0)
		return false;
	if(num==1)
		return true;
	while(num % 2 == 0){
		num = num/2;
	}
	for(int i=3; i<=sqrt(num); i=i+2){
		while(num % i == 0){
			if((i != 3) && (i != 5)){
				return false;
			}
			num = num/i;
		}
	}
	if((num > 2) && (num !=3) && (num !=5))
		return false;
	return true;
}

void uglyNumber(){
/*	cout << "Enter the number: ";
	int n;
	cin>>n;*/
	cout << "is ugly: " << isUgly(11);
}

void excelColumn(){
	string s;
	cout<<"Enter the column: "<<endl;
	cin>>s;
	int n = s.length();
	int sum = 0;
	for(int i=0; i<n ;i++){
		if(i==0){
			sum += s[n-1-i] - 64;
		}else{
			sum += (s[n-1-i] - 64)*26;
		}
	}
	cout << sum;
}

void validAnagram(){
	string s,t;
	cout << "Enter s: ";
	cin>>s;
	cout << "Enter t: ";
	cin>>t;
	//transform(s.begin(), s.end(), s.begin(), ::tolower);
	if(isAnagram2(s,t))
		cout << "They are anagrams!"<<endl;
	else
		cout << "They are not anagrams!"<<endl;
}

bool isAnagram(string s, string t){
	// sort and find
	int n1 = s.length();
	int n2 = t.length();
	if(n1 != n2)
		return false;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	int i=0;
	while(i<n1){ // length is same, so use one index
		if(s[i] != t[i])
			return false;
		i++;
	}
	return true;
}

/* anagram solution with space usage
 * but space is still O(1) as it is constant and
 * does not depend upon n
 * O(n) time
 */
bool isAnagram2(string s, string t){
	int n1 = s.length();
	int n2 = t.length();
	if(n1 != n2)
		return false;
	int arr[26] = {0};
	int i=0;
	while(i<n1){
		arr[s[i]-97]++;
		arr[t[i]-97]--;
		i++;
	}
	for(int j=0; j<26; j++){
		if(arr[j] != 0){
			return false;
		}
	}
	return true;
}

void arrayDupliates(){
	int arr[] = {2, 4, 12, 24, 5, 10, 132};
	// check if array contains duplicate elements
	//sort
	int n = sizeof(arr)/sizeof(int);
	if(isDup(arr, n)) cout<< "Duplicates found!";
	else cout << "No Duplicates!";
}

bool isDup(int arr[], int n){
	// corner case
	if(n == 0) return false;
	qsort(arr, 7, sizeof(int), compare);
	int i=0,j=1;
	while(i<n && j<n){
		if(arr[i] == arr[j]){
			return true;
		}
		i++;
		j++;
	}
	return false;
}

void print(int *a, int n){
	cout << "Printing array...";
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void arrayIntersection(){
	int n1,n2;
	cout << "No of elements in array 1: "<<endl;
	cin>>n1;
	int *arr1 = new int[n1];
	cout << "Enter the elements:";
	for(int i=0; i<n1; i++){
		cin>>arr1[i];
	}
	cout << "No of elements in array 2: "<<endl;
	cin>>n2;
	int *arr2 = new int[n2];
	cout << "Enter the elements:";
	for(int i=0; i<n2; i++){
		cin>>arr2[i];
	}
	//print the intersecting elements
	qsort(arr1, n1, sizeof(int), compare);
	qsort(arr2, n2, sizeof(int), compare);
	//print(arr1, n1);
	//print(arr2, n2);
	vector<int> res;
	int a=0, b=0;
	while(a<n1 && b<n2){
		if(arr1[a] == arr2[b]){
			res.push_back(arr1[a]);
			a++;b++;
		} else if(arr1[a] < arr2[b]){
			a++;
		} else{
			b++;
		}
	}
	printVector(res);
}

void romanNumeral(){
	map<char, int> romanMap; //= {{'I', 1}, {'V', 5}, {'X',10}, {'L',50},{'C'}};
	romanMap['I'] = 1;
	romanMap['V'] = 5;
	romanMap['X'] = 10;
	romanMap['L'] = 50;
	romanMap['C'] = 100;
	string s;
	cin>>s;
	int n = s.length();
	int sum = 0;
	for(int i= (n-1); i>=0; i--){
		sum += romanMap[toupper(s[i])];
		if((s[i] != s[i-1]) && (romanMap[toupper(s[i-1])] < romanMap[toupper(s[i])])){
			sum -= romanMap[toupper(s[i-1])];
			i--;
		}
	}
	cout << sum;
}

// power of 4 can be checked using bits
// if there is only 1 bit set and it is followed by 4 zeros
void powerOfThree(){
	int n;
	cin>>n;
	while(n != 1){
		if(n % 3 != 0){
			break;
		}
		n /= 3;
	}
	if( n != 1)cout << "Not a power of three";
	else cout << "Power of three";
}

void powerofTwo(){
	int n;
	cin>>n;
	// check if n is a power of 2
	if((n != 0) && (n & (n-1)) == 0)
		cout << "Power of 2";
	else
		cout << "Not a power of 2";

}

bool isHappy(int n){
	int sum=0;
	while(n != 0){
		sum += pow((n%10),2);
		n /= 10;
		if((n==0) && (sum != 1)){
			n = sum;
			sum = 0;
		}
	}
	if(sum == 1)
		return true;
	return false;
}

void happyNumber(){
	/*int n;
	cin>>n;*/
	//print if the number is happy
	cout << "Happy Number" << isHappy(2);
}



