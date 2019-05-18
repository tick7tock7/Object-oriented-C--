/*
* Main.cpp
*/

#include "Stack.h"

#include <iostream>
using namespace std;

void main()
{
	// ��������� �� ���� ����������� �����
	cout << "Number: ";
	int n;
	cin >> n;

	Stack st;

	int x = n;
	while (x)
	{
		st.push(x % 2);
		x /= 2;
	}

	// ��������� �� ��������� �����
	while (!st.empty())
	{
		cout << st.pop();
	}
	cout << endl;
}
