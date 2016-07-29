/*
 * decentnum.cpp
 *
 *  Created on: Apr 1, 2016
 *      Author: Sindhu
 */
//find the largest Decent Number having NN digits.

//A Decent Number has the following properties:

//Its digits can only be 3's and/or 5's.
//The number of 3's it contains is divisible by 5.
//The number of 5's it contains is divisible by 3.
//If there are more than one such number, we pick the largest one.
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

long long getDecent(int n){   // no of 3's-div by 5; no of 5's-div by 3
    long long val = -1;
    int res[n];
    int b=0, a=0;
    for(int i=0; i<n; i++){	// logically n = (5*b) + (3*a);
    	a = n - (5*b);
    	if(a%3 == 0){
    		break;
    	}
    	b=b+1;
    }
    if(a<0 || (a==n && b==n)){
    	return val;
    }
    int x=0;
    for(x=0;x<a;x++){
    	res[x]=5;
    }
    for(;x<n;x++){
        res[x]=3;
    }
    string str="";
    for(int k=0;k<n;k++){
    	str.push_back('0'+res[k]);
        // cout<<"in for--"<<k<<"--"<<str<<endl;
    }
    //cout<<"bef--"<<str<<endl;
    //cout<<"stoll"<<stoll(str)<<endl;
    //val = stoll(str);
    return val;
}

int main(){
    int t;
    cin >> t;
    long long arr[t];
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        arr[a0] = getDecent(n);
    }
    for(int a1 = 0; a1 < t; a1++){
        cout<<arr[a1]<<endl;
    }
    return 0;
}






