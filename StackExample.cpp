#include<iostream>

using namespace std;

const int MAX_SIZE = 100;

class Stack
{
private:
    int A[MAX_SIZE];
    int top = -1;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }

    void push(int value)
    {
        if(top==MAX_SIZE-1)
        {
            cout << "Stack is FULL!" << endl;
        }
        else
        {
            top++;
            A[top] = value;
        }
    }

    void pop()
    {
        if(top==-1)
        {
            cout << "Can't delete from an empty stack!" << endl;
        }
        else
        {
            top--;
        }
    }

    void show_top()
    {
        if(isEmpty())
            cout << "Stack is empty!" << endl;
        else
            cout << "Top: " << A[top] << endl;
    }

    void displayStack()
    {
        if(isEmpty())
            cout << "Stack is empty!" << endl;
        else
        {
            for(int i=0; i<=top; i++)
            {
                cout << A[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Stack Test;

    Test.push(3);
    Test.push(6);
    Test.push(10);

    Test.show_top();

    cout << endl;

    Test.displayStack();

    return 0;
}
