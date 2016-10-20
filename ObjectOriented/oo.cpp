/*
 * oo.cpp
 *
 *  Created on: Sep 17, 2016
 *      Author: Sindhu
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
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
};

int main(){
	Solution s;
	cout << s.isAnagram("god", "dog");
	return 0;
}

