#include <iostream>

#include "IntStack.h"

using namespace std;

IntStack::IntStack()
{
    size = MAX;
    arr = new int[size];
    top = -1;
}

IntStack::IntStack(IntStack const& s): size(s.size), top(s.top)
{
    arr = new int[size];
    for(int i=0; i<=top; i++)
        arr[i] = s.arr[i];
}

IntStack::~IntStack()
{
    delete[] arr;
}

IntStack& IntStack::operator=(IntStack const& s)
{
    if(this != &s)
    {
        size = s.size;
        top = s.top;
        delete[] arr;
        arr = new int[size];
        for(int i=0; i<=top; i++)
            arr[i]=s.arr[i];
    }
    return *this;
}

void IntStack::grow()
{
    int *newArr = new int[2*size];
    for(int i=0; i<size; i++)
        newArr[i]=arr[i];
    delete[] arr;
    arr = newArr;
    size*=2;
}

bool IntStack::empty() const
{
    return top==-1;
}

int IntStack::peek() const
{
    if(empty())
    {
        cout << "Stack is empty!" << endl;
        return 0;
    }

    return arr[top];
}

int IntStack::getTop() const
{
    return top;
}

int IntStack::getSize() const
{
    return size;
}

void IntStack::push(int x)
{
    if(full())
    {
        grow();
    }
    arr[++top] = x;
}

bool IntStack::full() const
{
    return top == size-1;
}

int IntStack::pop()
{
    if(empty())
    {
        cout << "Stack is empty!" << endl;
        return 0;
    }
    return arr[top--];
}

void IntStack::print() const
{
    if(empty())
    {
        cout << "Stack is empty!" << endl;
        return;
    }

    for(int i=top; i>-1; i--)
        cout << arr[i] << " ";

    cout << endl;
}
