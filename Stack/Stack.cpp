#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int Size)
{
    size = Size;
    top_ptr = -1;
    arr = new int[Size];
}

bool Stack::isEmpty()
{
    if (top_ptr == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::isFull()
{
    if (top_ptr >= size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack::push(int Data)
{
    if (isFull() == false)
    {
        top_ptr++;
        arr[top_ptr] = Data;
    }
    else
    {
        cout << "Stack is full can not add another element" << endl;
    }
}

int Stack::pop()
{
    if (isEmpty() == false)
    {
        return arr[top_ptr--];
    }
    else
    {
        cout << "Stack is empty you can not remove elements" << endl;
    }
}

int Stack::top()
{
    if (isEmpty() == false)
    {
        return arr[top_ptr];
    }
    else
    {
        cout << "Stack is empty you can not remove elements" << endl;
    }
}

int Stack::getSize()
{
    return top_ptr + 1;
}

void Stack::Display()
{
    for (int i = 0; i <= top_ptr; i++)
    {
        cout << "Element at position " << i + 1 << " : " << arr[i] << endl;
    }
}
