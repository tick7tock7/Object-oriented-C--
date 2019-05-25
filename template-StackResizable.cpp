#include <iostream>
#include <cstdlib>
#include <stdlib.h>

const int MAX_SIZE = 100;

using namespace std;

template <class T>
class MagicBox
{
private:
    T* box;
    int size;
    int top;

    bool full() const;
    void grow();

public:
    MagicBox();
    //MagicBox(MagicBox const&);
    ~MagicBox();

    void insert(T);
    T pop();
    bool empty() const;
    void list() const;
};

template <class T>
MagicBox<T>::MagicBox()
{
    size = MAX_SIZE;
    box = new T[size];
    top = -1;
}

/*template <class T>
MagicBox<T>::MagicBox(MagicBox const& M) : size(s.size), top(s.top)
{
    box = new T[size];
    for(int i = 0; i <= top; i++)
        box[i] = M.box[i];
}*/

template <class T>
MagicBox<T>::~MagicBox()
{
    delete [] box;
}

template <class T>
void MagicBox<T>::grow()
{
    T* newBox = new T[2*size];
    for(int i = 0; i < size; i++)
        newBox[i] = box[i];
    delete[] box;
    box = newBox;
    size *= 2;
}

template <class T>
bool MagicBox<T>::full() const
{
    return top == size - 1;
}

template <class T>
bool MagicBox<T>::empty() const
{
    return top == -1;
}

template <class T>
void MagicBox<T>::insert(T elem)
{
    if(full())
    {
        grow();
    }
    box[++top] = elem;
}

template <class T>
T MagicBox<T>::pop()
{
    if(empty())
    {
        cout << "Box is Empty!" << endl;
        return 0;
    }

    int randNum = (rand() % 100) / 10 + 1;
    cout << randNum << endl;
    T popped = box[randNum-1];
    cout << popped << endl;

    for(int i = randNum-1; i <= top; i++)
        box[i] = box[i+1];
    top--;
    return popped;
}

template <class T>
void MagicBox<T>::list() const
{
    for(int i = 0; i <= top; i++)
        cout << box[i] << " ";
    cout << endl;
}

int main()
{
    MagicBox<char> Boxie;
    Boxie.insert('b');
    Boxie.insert('m');
    Boxie.insert('p');
    Boxie.insert('a');
    Boxie.insert('c');
    Boxie.insert('!');
    Boxie.insert('/');

    Boxie.list();

    Boxie.pop();

    Boxie.list();

    return 0;
}

