#pragma once

#include <iostream>
using namespace std;

template <class T>
struct StackElement {
	T data;
	StackElement<T>* next;
};

template <class T>
class Stack {
private:
	StackElement<T>* top;
	void copyStack(Stack<T> const&);
	void deleteStack();
public:
	// ��������� �� ������ ����
	Stack();
	// ����������� �� ��������
	Stack(Stack<T> const&);

	~Stack();

	// �������� =
	Stack<T>& operator=(Stack<T> const &);

	// ���������

	// �������� ���� ���� � ������
	bool empty() const;

	// �������� �� �������� �� ����� �� �����
	T peek() const;

	// ��������

	// ��������� �� �������
	void push(T);

	// ���������� �� �������
	T pop();


};

template <class T>
Stack<T>::Stack() {
	top = NULL;
}

template <class T>
void Stack<T>::deleteStack() {
	StackElement<T> *toDelete;
	while (top != NULL) {
		toDelete = top;
		top = top->next;
		delete toDelete;
	}
}

template <class T>
Stack<T>::~Stack() {
	deleteStack();
}

template <class T>
void Stack<T>::copyStack(Stack<T> const& s) {
	if (s.top != NULL)
	{
		StackElement<T> *toCopy = s.top, *newElement = NULL, *prevElement = NULL;
		newElement = new StackElement<T>;
		newElement->data = toCopy->data;
		newElement->next = NULL;
		top = newElement;
		prevElement = top;
		toCopy = toCopy->next;
		while (toCopy != NULL) {
			newElement = new StackElement<T>;
			newElement->data = toCopy->data;
			newElement->next = NULL;
			prevElement->next = newElement;
			prevElement = newElement;
			toCopy = toCopy->next;
		}
	}
	else
		top = NULL;
}

template <class T>
Stack<T>::Stack(Stack<T> const& s) {
	copyStack(s);
}
template <class T>
Stack<T>& Stack<T>::operator=(Stack<T> const & s) {
	if (this != &s)
	{
		deleteStack();
		copyStack(s);
	}
	return *this;
}

template <class T>
bool Stack<T>::empty() const {
	return top == NULL;
}

template <class T>
T Stack<T>::peek() const {
	if (empty()) {
		cout << "������: ���� �� ���������� � ������ ����!\n";
		return 0;
	}
	return top->data;
}

template <class T>
void Stack<T>::push(T x) {
	StackElement<T>* p = new StackElement<T>;
	p->data = x;
	p->next = top;
	top = p;
}

template <class T>
T Stack<T>::pop() {
	if (empty()) {
		cout << "������: ���� �� ���������� �� ������ ����!\n";
		return 0;
	}
	// top != NULL

	StackElement<T>* p = top;
	top = top->next;
	T x = p->data;
	delete p;
	return x;
}