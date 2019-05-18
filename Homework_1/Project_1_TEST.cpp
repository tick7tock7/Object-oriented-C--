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

    void push(int);
    int pop();
    void print() const;
};

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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = n; i >= 0; i--)
       for (j = n; j > n-i-1; j--)
           if (arr[j-1] > arr[j])
              swap(&arr[j-1], &arr[j]);
}

IntStack& sortStack(IntStack &s)
{

    int counter = 0;
    int tempArr[MAX];
    for(int i=0; s.getTop() != -1; i++)
    {
        counter++;
        tempArr[i] = s.pop();
    }
    bubbleSort(tempArr, counter);
    for(int i=0; i < counter; i++)
    {
        s.push(tempArr[i]);
    }
    return s;
}

int main()
{
    IntStack s;
    s.push(2);
    s.push(5);
    s.push(3);
    s.push(4);
    s.push(1);
    s.push(99);
    s.push(7);
    s.push(113);
    s.push(333);
    s.push(33);
    s.push(44);
    s.push(91);
    s.push(331);
    s.push(222);
    s.push(4441);
    s.print();
    cout << endl;
    sortStack(s);
    s.print();

    return 0;

    return 0;
}
