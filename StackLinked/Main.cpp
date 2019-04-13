/*
* Main.cpp
*/

#include "LinkedStack.h"

#include <iostream>
using namespace std;

void main()
{
	// Прочитане на цяло положително число
	cout << "Number: ";
	int n;
	cin >> n;

	LinkedStack *st = new LinkedStack;

	int x = n;
	while (x)
	{
		st->push(x % 2);
		x /= 2;
	}

	// Извеждане на двоичното число
	while (!st->empty()) 
	{
		cout << st->pop();
	}
	cout << endl;

	delete st;
}
