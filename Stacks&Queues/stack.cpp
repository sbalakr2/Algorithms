/*
 * stack.cpp
 *
 *  Created on: Aug 12, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;


class multiStack{
	private:
		int numberOfStacks;
		int sizeOfEachStack;
		vector<int> values;
		vector<int> size;

	public:
		multiStack(int n, int m): numberOfStacks(n), sizeOfEachStack(m){
			values.resize(n*m);
			size.resize(n);
		}
		int getSize(int num){
			return size.at(num);
		}
		void push(int num, int val){
			if(num < numberOfStacks){
				int curSize = this->getSize(num);
				//cout<<"cursize: "<<curSize<<endl;
				int index = curSize + num*sizeOfEachStack;
				if(index < (num+1)*sizeOfEachStack){
					values.at(index) = val;
					size.at(num) +=1;
				} else{
					cout << "stack "<<num<<" is full"<<endl;
				}
			} else{
				cout<<"Stack doesn't exist"<<endl;
			}
		}
		int pop(int num){
			int curSize = size.at(num);
			if(curSize > 0){
				int index = num*sizeOfEachStack + (curSize - 1);
				size.at(num) = curSize - 1;
				return values.at(index);
			} else{
				return -1;
			}
		}
		int peek(int num){
			int curSize = size.at(num);
			int index = num*sizeOfEachStack + (curSize - 1);
			return values.at(index);
		}
};

void multiStackTest(){
	multiStack ms(3, 5);
	ms.push(0, 1);
	ms.push(0, 2);
	ms.push(1, 7);
	ms.push(1, 8);

	int peekval2 = ms.peek(1);
	cout<<"peekval: "<<peekval2<<endl;

	ms.push(0, 3);
	ms.push(0, 4);
	ms.push(0, 5);
	ms.push(0, 6);

	int val = ms.pop(0);
	if(val != -1)
		cout << "popped: "<<val<<endl;
	else
		cout<<"Empty!"<<endl;

	int peekval = ms.peek(0);
	cout<<"peekval: "<<peekval<<endl;
}


class StackWithMin{
	stack<int> st;
	stack<int> stMin;

public:
	void push(int v){
		if(v < min()){
			stMin.push(v);
		}
		st.push(v);
	}

	void pop(){
		if(!st.empty()){
			int top = st.top();
			if(top == min()){
				stMin.pop();
			}
			st.pop();
		}
	}

	int min(){
		if(!stMin.empty()){
			return stMin.top();
		}
		return INT_MAX;
	}
};



void stackWithMin(){
	StackWithMin st;
	st.push(10);
	st.push(20);
	st.push(3);
	st.push(8);
	cout << "min: " << st.min() <<endl;
	st.pop();
	st.pop();
	cout << "min: " << st.min() <<endl;
}

class SetOfStacks{
	vector< stack<int> > stackList;
	int eachStackCapacity;

public:
	SetOfStacks(int c):eachStackCapacity(c){}

	void createNewStack(){
		stack<int> st;
		stackList.push_back(st);
	}

	void push(int v){
		int vsiz = stackList.size();
		cout << "vector size: " << vsiz << endl;
		if(vsiz == 0){
			createNewStack();
		}
	}

	void pop(){

	}
};

void setOfStacks(){
	SetOfStacks stObj(3);
	stObj.push(10);
}

int main(){
	//multiStackTest();
	//stackWithMin(); // push, pop and min in const time
	setOfStacks();
	return 0;
}



