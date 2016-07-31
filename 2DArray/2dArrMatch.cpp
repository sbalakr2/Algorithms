/*
 * 2dArrMatch.cpp
 *
 *  Created on: Apr 4, 2016
 *      Author: Sindhu
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

bool checkAtIndex(int k, vector<string> G, vector<string> P, vector<size_t> posArr){
    int posArrSize = posArr.size();
    int height = P.size();
    for(int n=0;n<posArrSize;n++){
        size_t curPos = posArr.at(n);
        int i=1;
        while(i<height){
            size_t pos = G[k+i].find(P[i],curPos);
            if(pos != curPos) break;
            i++;
        }
        if(i == height){
            return true;
        }
    }
    return false;
}

bool isPattern(int R, int C, int r, int c, vector<string> G, vector<string> P){
    bool isFound = false;
    // code to check pattern
    for(int k=0;k<(R-1);k++){
        vector<size_t> posArr;
        size_t pos = G[k].find(P[0],0);
        while(pos != string::npos){
            posArr.push_back(pos);
            pos = G[k].find(P[0],pos+1);
        }
        int len = posArr.size();
        if(len > 0){
            isFound = checkAtIndex(k, G, P, posArr);
           // cout<<"in if.."<<isFound<<endl;
        }
        if(isFound) break;
    }
    return isFound;
}
int main(){
    int t;
    cin >> t;
    int arr[t];
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
           cin >> P[P_i];
        }
        arr[a0] = isPattern(R,C,r,c,G,P);
    }
    for(int a1=0;a1<t;a1++){
        if(arr[a1] == 0) cout<<"NO"<<endl;else cout<<"YES"<<endl;
    }
    return 0;
}



