/*
* LinkedStack.h
*/

#ifndef STACK_H
#define STACK_H

struct StackElement {
	int data;
	StackElement* next;
};

class LinkedStack {
private:
	StackElement* top;
	void copyStack(LinkedStack const&);
	void deleteStack();
public:
	// ��������� �� ������ ����
	LinkedStack();
	// ����������� �� ��������
	LinkedStack(LinkedStack const&);

	~LinkedStack();

	// �������� =
	LinkedStack& operator=(LinkedStack const &);

	// ���������

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