/*
 * vector.cpp
 *
 *  Created on: Apr 2, 2016
 *      Author: Sindhu
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

void vectorOperations();
void findMaxMin();
void reverse();
void passingVector();
void printVector(vector<int> v);
void passVecByVal(vector<int> v);
void passVecByRef(vector<int>& v);
typedef vector<int> vint;

int main(){
	//vectorOperations();
	// reverse();
	//findMaxMin();
	passingVector();
	return 0;
}

void passingVector(){
	vector<int> newVec;
	//passVecByVal(newVec);
	passVecByRef(newVec);
	printVector(newVec);
}

void passVecByVal(vector<int> v){ // passes a copy
	v.push_back(1);
	v.push_back(12);
	v.push_back(123);
}
void passVecByRef(vector<int>& v){ // passes a reference
	v.push_back(1);
	v.push_back(12);
	v.push_back(123);
}

void printVector(vector<int> v){
	cout<<"Printing.."<<endl;
	vector<int>::iterator it = v.begin();
	for(; it!= v.end(); ++it)
		cout<< *it<<endl;
}

void findMaxMin(){
	int arr[] = {1,12,23,43,15};
	vint vectorArr(arr, arr+ sizeof(arr)/sizeof(int));
	vector<int>::iterator it = vectorArr.begin();
	for(; it!= vectorArr.end(); ++it)
		cout<< *it<<endl;
	cout<<"Max element is.."<< *max_element(vectorArr.begin(), vectorArr.end())<<endl;
	cout<<"Min element is.."<< *min_element(vectorArr.begin(), vectorArr.end())<<endl;

	auto result = minmax(vectorArr.begin(), vectorArr.end());
	cout<<"Min.."<< *(result.first) <<"  Max.."<< *(result.second)<<endl;

	auto result1 = minmax({1,12,23,43,15});
	cout<<"Min.."<< result1.first <<"  Max.."<< result1.second<<endl;
}

void reverse(){
	int arr[] = {1,12,23,43,15};
	vint vectorArr(arr, arr+ sizeof(arr)/sizeof(int));
	vector<int>::iterator it = vectorArr.begin();
	for(; it!= vectorArr.end(); ++it)
		cout<< *it<<endl;
	cout<<"Reversing.."<<endl;
	reverse(vectorArr.begin(), vectorArr.end());
	vector<int>::iterator it1 = vectorArr.begin();
		for(; it1!= vectorArr.end(); ++it1)
			cout<< *it1<<endl;
}

void vectorOperations(){
	vint first;
		first.push_back(10);
		first.push_back(20);
		vector<int> second(4,100); // fill constructor
		vector<int> third (second.begin(),second.end()); // range constructor
		vector<int> fourth (first); // copy constructor
		cout<<"First front.."<<first.front()<<endl;
		cout<<second.front()<<endl;
		cout<<third.size()<<endl;
		cout<<third.front()<<endl;
		cout<<fourth.front()<<endl;

		int arr[5] = {22,42,17,52,11};
		vector<int> fifth(arr, arr + sizeof(arr)/sizeof(int) );
		cout<<"what is this.."<<arr + sizeof(arr)/sizeof(int)<<endl;
		cout<<fifth.front()<<endl;
		cout<< "Contents of fifth are.."<<endl;
		// working with vector iterators
		for(vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it){
			cout << *it << endl;
		}

		// Assign - assigns new contents
		first.assign(5,150);
		cout<<first.front()<<endl;
		vector<int>:: iterator it1 = fifth.begin();
		second.assign(it1, fifth.end());
		cout<< "Contents of second are.."<<endl;
		for(vector<int>::iterator it2 = second.begin(); it2 != second.end(); ++it2){
				cout << *it2 << endl;
		}

		//Reverse iterator
		cout<< "Contents of fifth on reverse iterating are.."<<endl;
		for(vector<int>::reverse_iterator itr = fifth.rbegin(); itr != fifth.rend(); ++itr){
				cout << *itr << endl;
		}
		// Similarly - cbegin() and cend() are constant iterators: contents cannot be changed
		// crbegin() and crend() which are reverse constant iterators

		// At keyword
		cout<<"At 3.."<<fifth.at(3)<<endl; // can also be used to assign
		cout<<"At front.."<<fifth.front()<<endl;
		cout<<"At back.."<<fifth.back()<<endl;
		cout<<"capacity of fifth.."<<fifth.capacity()<<endl;
		cout<<"size of fifth.. "<<fifth.size()<<endl;
}


