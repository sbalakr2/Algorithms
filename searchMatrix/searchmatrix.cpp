/*
 * searchmatrix.cpp
 *
 *  Created on: Oct 4, 2016
 *      Author: Sindhu
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector< vector<int> >& matrix, int target) {
        int m = matrix.size();
        int n = matrix.at(0).size();
        return checkRows(matrix, 0, m-1, n, target);
    }
private:
    bool checkRows(vector< vector<int> >& matrix, int i, int k, int n, int target){
        if((i==k) || ((i==k-1 && (matrix.at(k).at(0) > target)))){
            return checkColumns(matrix, i, 0, n-1, target);
        }
        if(i == (k-1)){
        	return checkColumns(matrix, k, 0, n-1, target);
        }
        if(i<k){
            int mid = (i+k)/2;
            int midVal = matrix.at(mid).at(0);
            if(target == midVal)
                return true;
            if(target < midVal)
            	return checkRows(matrix, i, mid-1, n, target);
            else
            	return checkRows(matrix, mid, k, n, target);
        }
        return false;
    }
    bool checkColumns(vector< vector<int> >& matrix, int row, int j, int l, int target){
    	if(j==l){
    		if(matrix.at(row).at(j) == target)
    			return true;
    	}
        if(j<l){
            int mid = (j+l)/2;
            int midVal = matrix.at(row).at(mid);
            if(target == midVal)
                return true;
            if(target < midVal){
                return checkColumns(matrix, row, j, mid-1, target);
            } else{
            	return checkColumns(matrix, row, mid+1, l, target);
            }
        }
        return false;
    }
};


int main(){
	Solution obj;
	vector< vector<int> > matrix;
	int counter = 5;
	for(int i=1; i<=3; i++){
		vector<int> temp;
		for(int j=1; j<=4; j++){
			cout << counter <<" ";
			temp.push_back(counter);
			counter++;
		}
		cout << endl;
		matrix.push_back(temp);
	}
	bool flag = obj.searchMatrix(matrix, 11);
	cout << flag;
	return 0;
}

