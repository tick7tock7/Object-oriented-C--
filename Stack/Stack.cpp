/*
* Stack.cpp
*/

#include "Stack.h"

#include <iostream>
using namespace std;

Stack::Stack()
{
	top = -1; // ������ ����
}

bool Stack::empty() const 
{
	return top == -1;
}

int Stack::peek() const 
{
	if (empty()) {
		cout << "������: ���� �� ���������� � ������ ����!\n";
		return 0;
	}

	return arr[top];
}

void Stack::push(int x) {
	if (full()) {
		cout << "������: ���� �� ��������� � ����� ����!\n";
	}
	else
		arr[++top] = x;
}

bool Stack::full() const {
	return top == MAX - 1;
}

int Stack::pop() {
	if (empty()) {
		cout << "������: ���� �� ���������� �� ������ ����!\n";
		return 0;
	}
	return arr[top--];
}
