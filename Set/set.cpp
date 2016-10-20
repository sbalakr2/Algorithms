/*
 * set.cpp
 *
 *  Created on: Sep 20, 2016
 *      Author: Sindhu
 */

// unordered_set::erase
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k);

int main (){

	cout << endl;
	return 0;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if((nums.size() < 2) || (k == 0)){
        return false;
    }
    unordered_set<int> st;
    vector<int>::iterator it;
    int count = 0;
    for(it = nums.begin(); it != nums.end(); ++it){
        auto ret = st.emplace(*it);
        if(!ret.second){
            return true;
        }
        if(count == k){
            //remove the first inserted element
            st.erase(st.begin());
        }
        count++;
    }
    return false;
}


