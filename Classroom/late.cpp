/*
 * late.cpp
 *
 *  Created on: Mar 26, 2016
 *      Author: Sindhu
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isClassCancelled(vector<int> arr, int thresh){
    bool flag = 1;
    int len = arr.size();
    int ontime = 0;
    for(int k=0; k<len; k++){
        if(arr[k] <= 0){
            ontime++;
        }
    }
    if(ontime < thresh) flag = 0;
    return flag;
}
int main(){
    int t;
    cin >> t;
    vector<bool> res;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        for(int a_i = 0;a_i < n;a_i++){
           cin >> a[a_i];
        }
        res.push_back(isClassCancelled(a,k));
    }
    for(int a1=0; a1<t; a1++){
        cout<<res[a1]<<endl;
    }
    return 0;
}
