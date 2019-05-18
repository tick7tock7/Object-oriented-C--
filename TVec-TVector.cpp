#include<iostream>
#include<stdlib.h>

template <class T>
class TVec
{
private:
    T* vector;
    int size;

protected:
    int lower;
    int upper;

public:
    TVec(int = 1);
    ~TVec();
    TVec(const TVec&);
    T& operator=(const TVec&);
    T& operator[](int);
    int lowerbound() const;
    int upperbound() const;
};

template <class T>
TVec<T>::TVec(int s)
{
    if(s <= 0)
    {
        cout << "Invalid!" << cout;
        exit(1);
    }
    lower = 0;
    upper = s-1;
    size = s;
    vector = new T[s];
    if(!vector)
        exit(1);
}

template <class T>
TVec<T>::~TVec()
{
    delete [] vector;
}

template <class T>
TVec<T>::TVec(const TVec<T>& v)
{
    size = v.size;
    vector = new T[size];
    if(!vector)
        exit(1);
    for(int i = 0; i < size; i++)
        vector[i] = v.vector[i];
    lower = v.lower;
    upper = v.upper;
}

template <class T>
TVec<T>& TVec<T>::operator=(const TVec<T>& v)
{
    if(this != &v)
    {
        delete [] vector;
        size = v.size;
        vector = new T[size];
        if(!vector)
            exit(1);
        for(int i = 0; i < size; i++)
            vector[i] = v.vector[i];
        lower = v.lower;
        upper = v.upper;
    }
    return *this;
}

template <class T>
T& TVec<T>::operator[](int i)
{
    if(i < 0 || i > upper - lower)
        exit(1);
    return vector[i];
}

template <class T>
int TVec<T>::lowerbound() const
{
    return lower;
}

template <class T>
int TVec<T>::upperbound() const
{
    return upper;
}

template <class T>
class TVector : public TVec<T>
{
public:
    TVector(int, int);
    T& operator[](int);
};

template <class T>
TVector<T>::TVector(int low, int upp) : TVec<T>(upp - low + 1)
{
    lower = low;
    upper = upp;
}

template <class T>
T& TVector<T>::operator[](int i)
{
    return TVec<T>::operator[](i - lower);
}
