#include <iostream>

#include "IntStack.h"

using namespace std;

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
    int* tempArr = new int[s.getSize()];
    while(s.getTop()!=-1)
    {
        tempArr[counter] = s.pop();
        counter++;
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
    s.push(5);
    s.push(2);
    s.push(4);
    s.push(3);
    s.push(1);
    s.push(0);
    s.push(100);
    s.push(55);
    s.push(72);

    s.print();
    cout << endl;

    sortStack(s);

    s.print();
    cout << endl;

    return 0;
}
