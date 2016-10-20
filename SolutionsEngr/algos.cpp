/*
 * algos.cpp
 *  Created on: Aug 22, 2016
 *      Author: Sindhu
 */
#include <iostream>
#include <stdlib.h> //qsort
#include <climits>
#include <sstream>
#include <cmath>
#include <string>
#include <set>
using namespace std;
/*
 * Problem: Given a sequence of nonnegative integers A and an integer T,
 * return whether there is a *continuous sequence* of A that sums up to exactly T
 * */
bool isContiguousSeqSum(int arr[], int n, int sum);
bool isContiguousSeqSum2(int arr[], int n, int sum);

/*
 * Given a list of integers and a target number, list all
 * pairs that sum up to that number
 */
void listPairsForSum(int arr[], int n, int sum);

/*
 * Determine if any 3 integers in an array sum to 0. Duplicates not allowed.
 */
int compare (const void *a, const void *b);
bool threeSum(int arr[], int n, int sum);
bool twoSum(int arr[], int n, int sum);
void print(int arr[], int n);

/*
 * Determine if any 3 integers in an array sum to 0. Duplicates not allowed.
 */
bool threeSumDup(int arr[], int n, int sum);
bool twoSumDup(int arr[], int n, int sum);

/*
 * Given an array of integers, write an in-place function to bring all the non-zero elements
 * to the left of the array keeping the original order.
 */
void allNonZeroToLeft();
void findClosestPoint();
void regexImplementation();
void nearbyPermutations();
set<string> getNearbyPermutations(string word, int index, set<string> &result);
set<string> get_NearbyPermutations(string word, int index);
void boggleGame();

int main(){
	/*int n = 10;
	int arr[10] = {4, 3, -1, 2, 5, 6, 1, 3, 4, 10};
	int sum;
	cout << "Enter sum value: ";
	cin>>sum;*/
	//cout<<"isC: "<<isContiguousSeqSum(arr, n, sum) << endl;
	//cout<<"isC: "<<isContiguousSeqSum2(arr, n, sum) << endl;
	//listPairsForSum(arr, n, sum);
	//cout << "isThreeSum: " << threeSum(arr, n, sum) << endl;
	//cout << "isTwoSum: " << twoSum(arr, n, sum) <<endl;
	//cout << "isThreeSumDup: " << threeSumDup(arr, n, sum) << endl;
	//cout << "isTwoSumDup: " << twoSumDup(arr, n, sum) <<endl;
	//allNonZeroToLeft();
	//findClosestPoint();
	//regexImplementation();
	//nearbyPermutations();

	boggleGame();
	return 0;
}

bool doDFSBoggle(char mx[][3], bool visited[][3], string s, int m, int n, int j, int k, int i){
	visited[j][k] = true;
	int len = s.length();
	if(i == (len-1)){//we have successfully traversed till the last character - means the string exists
		return true;
	}
	for(int a=(j-1); a<= (j+1); a++){
		for(int b=(k-1); b<= (k+1); b++){
			if(a>=0 && a<m && b>=0 && b<n){
				if((mx[a][b] == s[i+1]) && !visited[a][b]){
					cout<< mx[a][b] << endl;
					if(doDFSBoggle(mx, visited, s, m, n, a, b, i+1))
						return true;
				}
			}
		}
	}
	return false;
}

bool checkWordInBoggle(char mx[][3], string s, int m, int n){
	// search for first char
	int i = 0;
	char first = s[i];
	bool visited[3][3] = {{false}};
	// search for the occurrence of 'first' in 'm'
	for(int j=0; j<m; j++){
		for(int k=0; k<n; k++){
			if(mx[j][k] == first){
				if(doDFSBoggle(mx, visited, s, m, n, j, k, i)){
					return true;
				}
			}
		}
	}
	return false;
}

void boggleGame(){
	int m=3, n=3;
	char matrix[][3] = {{'G','I','Z'},{'G','E','K'},{'Q','S','E'}};
	cout << "Enter the string: ";
	string s;
	cin>>s;
	cout << "Is Word in Board: " << checkWordInBoggle(matrix, s, m, n);
}


void regexImplementation(){ // incomplete
	string regex, string, pattern = ".*";
	cout << "Enter the regex and the string: ";
	cin>>regex>>string;
	int n = regex.find(pattern);
	int lr = regex.length() - 1;
	int ls = string.length() - 1;
	bool match = true;
	for(int i=0; i<n; i++){
		if(regex[i] != string[i]){
			match = false;
		}
	}
	for(int j=lr, k=ls; j>(n+1); j--){
		if(regex[j] != string[k]){
			match = false;
		}
		k--;
	}
	cout <<"match: "<<match<<endl;
}

void findClosestPoint(){
	int arr[3][2] = {{1,1},{2,2},{3,3}};
	int x,y;
	cout << "Enter the x and y coordinates: ";
	cin>>x>>y;
	int n = sizeof(arr)/sizeof(arr[0]);
	int min = INT_MAX;
	int k;
	for(int i=0; i<n; i++){
		cout << arr[i][0] << " " << arr[i][1] <<endl;
		int dist = pow((x-arr[i][0]),2) + pow((y-arr[i][1]),2);
		if(dist < min){
			min = dist;
			k = i;
		}
		cout << dist << endl;
	}
	cout << "The closest point is (" << arr[k][0] <<"," <<arr[k][1] <<")" <<endl;
}

bool isContiguousSeqSum(int arr[], int n, int sum){
	int curSum = 0;
	int k=0,i=0;
	while(i<n || k<n){ // don't run two loops in one - then we need to handle the slow pointer-i
		if(i<n)// unnecessary
			curSum += arr[i];
		else{
			if(curSum < sum){
				break;
			}
		}
		if(curSum == sum){
			for(int a=k; a<=i; a++){
				cout << arr[a] <<",";
			}
			cout<<endl;
			return true;
		}
		if(curSum > sum){ // if not needed
			curSum -= arr[k];
			k++;
		}
		if(i<n)i++; // unnecessary
	}
	return false;
}

bool isContiguousSeqSum2(int arr[], int n, int sum){
	int curSum = 0;
	int i,j=0;
	for(i=0; i<n; i++){
		while(j<n && curSum < sum){
			curSum += arr[j];
			j++;
		}
		if(curSum == sum){
			cout<< "Sum found in the range: " << i << " to " << j-1 <<endl;
			return true;
		}
		curSum -= arr[i];
	}
	cout << "Sum not found!"<<endl;
	return false;
}

/*bool isContiguousSeqSum3(int arr[], int n, int sum){
	int curSum = arr[0];
	for(int i=1; i<n; i++){

	}
}*/

void listPairsForSum(int arr[], int n, int sum){
	qsort(arr, n, sizeof(int), compare);
	//1. we can sort the array and do binary search for each element O(n log n)
	//2. we can use O(n) space and check if the complement is found for each element

	int i = 0, j = n-1;
	while(i < j){
		int curSum = arr[i] + arr[j];
		if(curSum == sum){
			cout << arr[i] << " " << arr[j] << endl;
			i++;
			j--;
		}
		else if (curSum < sum){
			i++;
		} else{
			j--;
		}
	}
	/*for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			//cout << arr[i] << ", " << arr[j]<<endl;
			if((arr[i] + arr[j]) == sum){
				cout << "Result: " << arr[i] << " and " << arr[j] << endl;
			}
		}
	}*/
}

bool threeSum(int arr[], int n, int sum){
	qsort(arr, n, sizeof(int), compare);
	print(arr, n);
	for(int i=0; i<(n-2); i++){
		int curSum = 0;
		int j=i+1, k=n-1;
		while(j < k){
			curSum = arr[i] + arr[j] + arr[k];
			if(curSum == sum){
				cout << arr[i] << " and " << arr[j] << " and " << arr[k] << endl;
				return true;
			}
			if(curSum >  sum)
				k--;
			else
				j++;
		}
	}
	cout <<"Sum not found !"<<endl;
	return false;
}

int compare (const void *a, const void *b){
  return (*(int*)a - *(int*)b);
}

void print(int arr[], int n){
	for(int i=0;i<n;i++){
		cout << arr[i] << endl;
	}
}

bool twoSum(int arr[], int n, int sum){
	qsort(arr, n, sizeof(int), compare);
	//print(arr, n);
	int curSum = 0;
	int i=0 ,j = n-1;
	while(i < j){
		curSum = arr[i] + arr[j];
		if(curSum == sum){
			cout << arr[i] << " and " << arr[j] << endl;
			return true;
		}
		if(curSum > sum)
			j--;
		else
			i++;
	}
	return false;
}

bool threeSumDup(int arr[], int n, int sum){//O(n^2)
	qsort(arr, n, sizeof(int), compare);
	int i, curSum=0;
	for(i=0;i<n;i++){
		if(arr[i] == (sum/3)){
			cout << arr[i] << " and " << arr[i] << " and " << arr[i] << endl;
			return true;
		}
		int j=i, k=n-1;
		while(j<=k){ // compare equals to allow duplicates
			curSum = arr[i] +arr[j] + arr[k];
			if(curSum == sum){
				cout << arr[i] << " and " << arr[j] << " and " << arr[k] << endl;
				return true;
			}
			if(curSum > sum)
				k--;
			else
				j++;
		}
	}
	return false;
}

bool twoSumDup(int arr[], int n, int sum){//O(n)
	qsort(arr, n, sizeof(int), compare);
	print(arr,n);
	int curSum = 0;
	int i=0, j=n-1;
	while(i < j){
		if( arr[i] == (sum/2)){
			cout << arr[i] << " and " << arr[i] << endl;
			return true;
		}
		if( arr[j] == (sum/2)){
			cout << arr[j] << " and " << arr[j] << endl;
			return true;
		}
		curSum = arr[i] + arr[j];
		if(curSum == sum){
			cout << arr[i] << " and " << arr[j] << endl;
			return true;
		}
		if(curSum > sum)
			j--;
		else
			i++;
	}
	return false;
}

void moveNonZeroToLeft(int arr[], int n);
void allNonZeroToLeft(){
	int arr[10] = {5,0,1,0,0,2,7,0,0,9};
	moveNonZeroToLeft(arr, 10);
	print(arr, 10);
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void moveNonZeroToLeft(int arr[], int n){
	int j=0;
	int i=j-1;
	while(j < n){
		if(arr[j] != 0){
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
}
set<char> get_nearby_chars(char c){
	char mychars[] = {'f', 'g', 'h', 'i', 'o', 'k'};
	set<char> nearbydef;
	if(tolower(c) == 'g'){
		set<char> nearby(mychars, mychars+3);
		return nearby;
	}
	if(tolower(c) == 'i'){
		set<char> nearby(mychars+3, mychars+6);
		return nearby;
	}
	return nearbydef;
}

void nearbyPermutations(){
	string word;
	cout <<"Enter the word: "<<endl;
	cin>>word;
	set<string> result;
	if(word.length() > 0){
		set<string> res = getNearbyPermutations(word, 0, result);
		//set<string> res = get_NearbyPermutations(word, 0);
		set<string>::iterator it2;
		cout << "result: "<<res.size()<<endl;
		for(it2 = res.begin(); it2!=res.end();it2++){
			cout << *it2 << endl;
		}
	} else{
		cout <<"Word is empty!"<<endl;
	}
}

// Iterative solution to get all nearby permutations
set<string> getNearbyPermutations(string word, int index, set<string> &result){
	int length = word.length();
	set<string> permutations;
	//permutations.insert(word);//may not be valid
	for(int i=0; i<length; i++){
		char c = word[i];
		set<char> s = get_nearby_chars(c);
		set<char>::iterator it;
		set<string>::iterator it2;
		for(it = s.begin(); it!=s.end();it++){
			string str;
			if(permutations.empty()){
				str = word;
				str.replace(i, 1, 1, (*it));
				// check if it is a valid word
				permutations.insert(str);
			}
			for(it2 = permutations.begin(); it2!=permutations.end();it2++){
				string str = (*it2);
				str.replace(i, 1, 1, (*it));
				// check if it is a valid word
				permutations.insert(str);
			}
		}
	}
	return permutations;
}

// Recursive solution to get all nearby permutations
set<string> get_NearbyPermutations(string word, int index){
	int length = word.length();
	if(index >= length){
		set<string> st;
		st.insert("");
		return st;
	}
	set<string> sub_words = get_NearbyPermutations(word, index+1);
	set<char> nearby_letters = get_nearby_chars(word[index]);
	set<string> permutations;
	set<char>::iterator it;
	set<string>::iterator it2;
	for(it2 = sub_words.begin(); it2 != sub_words.end(); it2++){
		for(it = nearby_letters.begin(); it != nearby_letters.end(); it++){
			stringstream ss;
			string s;
			ss << *it;
			ss >> s;
			permutations.insert(s.append(*it2));
		}
	}
	return permutations;
}
