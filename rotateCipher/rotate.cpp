#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
using namespace std;

int findOrg(int i, string s, int k, string r);
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k;
    cin>>n>>k;
    string s, res = "";
    cin>>s;
    for(int i=0; i<n; i++){
        int ch = findOrg(i, s, k, res);
        char c = '1';
        if(ch == 0){
        	c = '0';
        }
        cout<< "c: " << c <<endl;
        res.push_back(c);
        cout<<"res: " <<res << endl;
    }
    cout<< res << endl;
    return 0;
}

int findOrg(int i, string s, int k, string r){
    if(i==0)
        return s[i];
    else{
        int cnt = 0;
        int op;
        cout<<"loop: "<<i<<endl;
        for(int a=i-1; a>=0; a--){
        	cout<<"a: "<<a << endl;
        	if(cnt == (k-1)) break;
            if(cnt == 0){
            	cout<< s[i] << "~" << r[a];
                op = s[i] ^ r[a];
                cout << " / op1: " << op << endl;
            }
            else{
            	cout<< op << "~" << (r[a]-'0');
                op = op ^ (r[a]-'0');
                cout << " / op2: " << op << endl;
            }
            cnt++;
        }
        cout<<"o: "<< op << endl;
        return op;
    }
}
