#include<iostream>

using namespace std;

template <class T>
void swapOverload(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 4;
    int b = 9;

    swapOverload(a, b);

    cout << a << " " << b << endl;

    return 0;
}
