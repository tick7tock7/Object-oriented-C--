/*
* Stack.h
*/

#ifndef STACK_H
#define STACK_H

int const MAX = 100;

class Stack
{
private:
	int *arr;	    // ��������� ����� � ���������� �� �����
	int top;	    // ������ �� ��������� �������
	int size;

	// �������� ���� ������ � �����
	bool full() const;

	void grow();

public:

	// ��������� �� ������ ����
	Stack();
	// ���������
	~Stack();

	// ������� �� ������

	// �������� ���� ���� � ������
	bool empty() const;

	// �������� �� �������� �� ����� �� �����
	int peek() const;

	// ��������

	// ��������� �� �������
	void push(int);

	// ���������� �� �������
	int pop();

};

#endif /* STACK_H_ */