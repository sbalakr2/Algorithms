/*
 * flag.cpp
 *
 *  Created on: Mar 26, 2016
 *      Author: Sindhu
 */
/*
 * flag.cpp
 *
 *  Created on: Mar 26, 2016
 *      Author: Sindhu
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int stringToInt(char s){
	int i = s - 48;
	return i;
}
int main(){
	int t;
	cin>>t;
	string res[t];
	for(int i=0;i<t;i++){
		int n,m;
		cin>>n>>m;
		int arr[n][m];
		res[i] = "YES";
		for(int j=0;j<n;j++){
			string str;cin>>str;
			for(int k=0;k<m;k++){
				arr[j][k] = stringToInt(str[k]);
				if((k>0) && (arr[j][k] != arr[j][k-1])){
					res[i] = "NO";
				}
			}
			if((j>0) && (arr[j][0] == arr[j-1][0])){
				res[i] = "NO";
			}
		}
		/*for(int j1=0;j1<n;j1++){
			for(int k1=0;k1<m;k1++){
				cout<<arr[j1][k1];
			}
		}*/
	}
	for(int c=0; c<t; c++){
		cout<<res[c]<<endl;
	}
	return 0;
}



