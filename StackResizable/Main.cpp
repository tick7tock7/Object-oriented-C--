/*
* Main.cpp
*/

#include "Stack.h"

#include <iostream>
using namespace std;

void main()
{
	Stack st;


   for(int i = 0; i <  1000; i++)	{
		st.push(i);
	}

	// 
	while (!st.empty()) 
	{
		cout << st.pop();
	}
	cout << endl;
}
