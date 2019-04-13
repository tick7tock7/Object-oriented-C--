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

public:
	// създаване на празен стек
	LinkedStack();

	~LinkedStack();

	// селектори

	// проверка дали стек е празен
	bool empty() const;

	// намиране на елемента на върха на стека
	int peek() const;

	// мутатори

	// включване на елемент
	void push(int);

	// изключване на елемент
	int pop();


};


#endif /* STACK_H_ */
