#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int Size)
{
    size = Size;
    front = -1;
    rear = -1;
    arr = new int[Size];
}

bool Queue::isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Queue::isFull()
{
    if (rear == (size - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Queue::enqueue(int Data)
{
    if (isFull())
    {
        cout << "Queue is FUll can't add elements" << endl;
    }
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
        arr[rear] = Data;
    }
    else
    {
        rear++;
        arr[rear] = Data;
    }
}

int Queue::dequeue()
{
    int x = 0;
    if (isEmpty())
    {
        cout << "Queue is Empty can't remove element" << endl;
        return x;
    }
    else if (front == rear)
    {
        x = arr[front];
        arr[front] = 0;
        front = -1;
        rear = -1;
        return x;
    }
    else
    {
        x = arr[front];
        arr[front] = 0;
        front++;
        return x;
    }
}

void Queue::Display()
{
    if (!isEmpty())
    {
        cout << "The Values in the Queue are - " << endl;
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int Queue::getSize()
{
    return (rear - front + 1);
}

bool Queue::Search(int val)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
        {
            return true;
        }
    }
    return false;
}
