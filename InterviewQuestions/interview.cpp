/*
 * interview.cpp
 *
 *  Created on: Aug 11, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <stdlib.h>
using namespace std;
void printMatrix(int matrix[4][4], int m, int n);
void printMatrixLoop(int matrix[4][4], int m, int n);
void matrixLoop();

int main(){
	matrixLoop();
}

void matrixLoop(){
	const int m=4,n=4;
	int matrix[m][n];
	static int count = 1;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			matrix[i][j] = count++;
		}
	}
	printMatrix(matrix, 4, 4);
	printMatrixLoop(matrix, 4, 4);
}

/*int** createMatrix(int m, int n){
	int** matrix = new int*[m];
	static int count = 1;
	for(int i=0; i<m; i++){
		matrix[i] = new int[n];
		for(int j=0; j<n; j++){
			matrix[i][j] = count++;
		}
	}
}*/
void printMatrix(int mx[4][4], int m, int n){
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cout<< mx[i][j] << " ";
		}
		cout<<endl;
	}
}

void printMatrixLoop(int matrix[4][4], int m, int n){
	cout<<"Result..."<<endl;
	int k=0,l=0,i;
	while(k<m && l<n){
		// first row
		for(i=l; i<n; i++){
			cout << matrix[k][i] << " ";
		}
		k++;
		// rightmost row
		for(i=k; i<m; i++){
			cout << matrix[i][n-1] << " ";
		}
		n--;
		//bottom row
		for(i=n-1; i>=l; i--){
			cout << matrix[m-1][i] << " ";
		}
		m--;
		for(i=m-1; i>=k; i--){
			cout << matrix[i][l] << " ";
		}
		l++;
	}
}


