/*
 * static.cpp
 *
 *  Created on: Aug 12, 2016
 *      Author: Sindhu
 */

#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int* getRandom( )
{
  int p[2] = {10,2};
  int *a = p;
  return a;
}

int main ()
{
	int *a = getRandom();
	cout<<*a<<endl;
   return 0;
}


