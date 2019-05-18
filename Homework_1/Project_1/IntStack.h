#include <iostream>

using namespace std;

int const MAX = 100;

class IntStack {
private:
    int *arr;
    int top;
    int size;

    bool full() const;
    void grow();

public:
    IntStack();
    IntStack(IntStack const &);
    ~IntStack();

    IntStack& operator=(IntStack const&);

    bool empty() const;
    int peek() const;

    int getTop() const;
    int getSize() const;

    void push(int);
    int pop();
    void print() const;
};

