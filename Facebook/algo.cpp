/*
 * algo.cpp
 *
 *  Created on: Aug 27, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <set>
#include <climits>
#include <vector>
#include <sstream>
#include <string>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

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

void numberToEnglish();
string getEnglishForNum(int n);

void print2d(char arr[][4], int m, int n);


/*You have an array of unique integer numbers and only one operation: MoveToFront(x) that
 * moves given number to the beginning of the array. Write a program to sort the array
 * using the minimum possible number of MoveToFront() calls.
 */
void sortElements();

/* A museum was represented by a square matrix that was filled with O, G, and W where
 * O represented open space G represented guards, and W represented walls.
 * Write a function that accepts the square matrix and returns another square matrix where
 * all of the O's in the matrix are replaced with the number of how many spaces they are away
 * from a guard, without being able to go through any walls.
 */
void museumProb();

/*You are given a string "abc" which is encoded like "123" where alphabets are mapped like
 * a => 1 to z => 26. Now find out how many string can be formed by reverse engineering encode string "123".
 * For ex. given string "123" we can form 3 string "abc"(1,2,3), "lc" (i.e 12,3), "aw"(1,23).
 * for string "1234" we have following possible combinations, I might be missing some of them but you get the idea
{12, 3, 4}
{1, 23, 4}
{1, 2, 3, 4}*/
void stringDecoder();

void reverseWords();
void getKthLargest();

/*Given an array and a number, add it in such a way where array is [0,0,1] and number is 4 output will be [0,0,5]
* Example 2 :array is [1] and number is 9 output will be [1,0]
*/
void addArray();

void reOrderArray();

void transformWord();

int main(){
	//numberToEnglish();
	//sortElements();
	//museumProb();
	//stringDecoder();
	//reverseWords();
	//getKthLargest(); // using priority queue
	//addArray();
	//reOrderArray();
	//transformWord();
	return 0;
}

void numberToEnglish(){
	int num;
	cout << "Enter the number: ";
	cin>>num;
	cout << "English representation: " << getEnglishForNum(num);
}

string getEnglishForNum(int n){
	string final = "";
	set<string> ones;


	return final;
}

void moveToFront(int arr[], int i){//rotates elements
	//cout <<"in move: "<<i << endl;
	int temp = arr[i];
	for(int k=i; k>0; k--){
		arr[k] = arr[k-1];
	}
	arr[0] = temp;
}

void getSortPoint(int arr[], int l, int r, bool flag){
	if(l < r){
		int max = INT_MIN;
		int k=0;
		for(int i=l; i<r; i++){
			if(arr[i] > max){
				max = arr[i];
				k = i;
			}
		}
		if(k == (r-1) && flag){
			getSortPoint(arr, l, r-1, true);
		} else{
			moveToFront(arr, k);
			getSortPoint(arr, l+1, r, false);
		}
	}
}

template<typename Tp>
void print(Tp arr[], int n){
	cout <<"Result: ";
	for(int i=0;i<n;i++){
		cout << arr[i] <<" ";
	}
}

void sortElements(){
	int n=9;
	int arr[] = {1, 3, 2, -1, 10, 10, 20, 4, 5};
	getSortPoint(arr, 0, n, true);
	print(arr,n);
}

// depth first search - some errors exist, when no guards are there
int findGuard(char matrix[][4], bool visited[][4], int m, int n, int i, int j, int cnt){
	visited[i][j] = true;
	for(int a=(i-1); a<=(i+1); a++){
		for(int b=(j-1); b<=(j+1); b++){
			if(a>=0 && a< m && b>=0 && b<n){
				cout << matrix[a][b] << endl;
				if(matrix[a][b] == 'G'){
					return cnt + 1;
				}else if(matrix[a][b] != 'W' && (a!=i || b!= j) && !visited[a][b]){
					return findGuard(matrix, visited, m, n, a, b, cnt+1);
				}
			}
		}
	}
	return cnt;
}

void museumProb(){
	int m=4,n=4;
	char matrix[][4] = {{'G','W','G','O'},
					   {'O','G','W','O'},
					   {'W','G','O','W'},
					   {'O','W','W','O'}};
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(matrix[i][j] == 'O'){
				bool visited[][4] = {{false}};
				print2d(matrix, m, n);
				int cnt = findGuard(matrix, visited, m, n, i, j, 0);
				matrix[i][j] = cnt + '0';
				print2d(matrix, m, n);
			}
		}
	}
}

void print2d(char arr[][4], int m, int n){
	cout << "result: "<<endl;
	for(int c=0; c<m; c++){
		for(int d=0; d<n; d++){
			cout<<arr[c][d] <<" ";
		}
		cout<<endl;
	}
}

void permuteDecoder(vector<char> &charArr, string s, int l, int r, vector< set<string> > &res){

	for(int i=l; i<r; i++){
		int a1 = s[i] - '0';
		cout << charArr.at(a1-1);
	}

}

// we are using vector as it is efficient to access elements and we're not going to perform
// any insertions or deletions in the charArr
void stringDecoder(){
	string s;
	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
			'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	vector<char> charArr(arr, arr+26);
	cout << "Enter the number: ";
	cin>>s;
	int len = s.length();
	vector< set<string> > res;
	permuteDecoder(charArr, s, 0, len, res);
	//printStrVector(res);
}

void reverseString(string &s, int l, int r);
void reverseWords(){
	string s = "dog hits man";
	// reverse the entire string and reverse each word
	//int len = s.length();
	//int l = 0, r = len-1;
	// reverse string
	//reverseString(s, l, r);
	reverse(s.begin(), s.end());
	cout << "reverse: "<<s<<endl;
	// reverse words
	//int a=0, b=0;
	/*while(b <= len){
		if(s[b] == ' ' || b == len){
			reverseString(s, a, b-1);
			a=b+1;
		}
		b++;
	}*/
	string::iterator it;
	string::iterator i;
	i = s.begin();
	for(it = i; it != s.end()+1; it++){
		if(*it == ' ' || it == s.end()){
			reverse(i, it);
			i = it+1;
		}
	}
	cout << "reverse: "<<s<<endl;
}

void reverseString(string &s, int l, int r){
	while(l < r){
		char temp = s[l];
		s[l] = s[r];
		s[r] = temp;
		l++; r--;
	}
}
class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs<rhs);
    else return (lhs>rhs);
  }
};

void getKthLargest(){
	int arr[] = {5, 2, 6, 1, 7, 3, 9, 10};
	int k = 4;
	//priority_queue<int> prArr(arr, arr+8);
	priority_queue<int,std::vector<int>,mycomparison> prArr(arr, arr+8);
	int len = prArr.size();
	if(len >= k){
		for(int i=0; i<(k-1); i++){
			prArr.pop();
		}
		cout << "K-th largest: " <<prArr.top();
	} else{
		cout << "Array is smaller than k";
	}
}

void getSummedArray(int arr[], int n, int m, vector<int> &res);
void addArray(){
	int n, m;
	cout << "Enter the number of elements:";
	cin>>n;
	int arr[n];
	cout <<"Enter the elements:";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	cout << "Enter the number to add:";
	cin>>m;
	vector<int> res(n+1,0);
	getSummedArray(arr,n,m,res);
	printVector(res);
}

void getSummedArray(int arr[], int n, int m, vector<int> &res){
	int carry = m;
	int i;
	for(i=(n-1); i>=0; i--){
		int sum = arr[i] + carry;
		if(sum <= 9){
			res.at(i+1) = sum;
			carry = 0;
		} else{
			res.at(i+1) = sum%10;
			carry = sum/10;
		}
	}
	if(carry > 0){
		res.at(i+1) = carry;
	}
}

template<typename Ts>
void swap(Ts arr[], int i, int j){
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void reOrderSort(char a[], int b[], int n){
	for(int i=0; i<n; i++){
		int temp = i;
		while(b[temp] != temp){
			swap(a, b[temp], temp);
			swap(b, b[temp], temp);
			temp = b[temp];
		}
	}
}

void reOrderArray(){
	int n=5;
	char a[] = {'C','D','E','F','G'};
	int b[] = {3,0,4,1,2};
	reOrderSort(a, b, n);
	print(a,n);
}

void transformWord(){ // less sophisticated
	string s1 = "cat";
	string s2 = "dog";
	// find the minimum number of steps to transform s1 to s2
	if(s1.length() != s2.length()){
		cout << "Strings are of different lengths";
	}
	else{
		int n = s1.length();
		int cnt = 0;
		for(int i=0; i<n; i++){
			if(s1[i] != s2[i]){
				cnt++;
			}
		}
		cout << "Number of transformations: "<<cnt<<endl;
	}

}
