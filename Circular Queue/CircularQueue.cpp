#include "CircularQueue.h"
#include <iostream>
using namespace std;

CircularQueue::CircularQueue(int Size)
{
    size = Size;
    front = -1;
    rear = -1;
    arr = new int[Size];
}

bool CircularQueue::isFull()
{
    if (front == 0 && rear == size - 1)
    {
        return true;
    }
    else if (front == rear + 1)
    {
        return true;
    }

    return false;
}

bool CircularQueue::isEmpty()
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

void CircularQueue::enQueue(int Data)
{
    if (isFull())
    {
        cout << "Queue is Full can't add any elements" << endl;
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = Data;
    }
}

int CircularQueue::deQueue()
{
    int x;
    if (isEmpty())
    {
        cout << "The Queue is Empty can't remove elements" << endl;
        return -1;
    }
    else
    {
        x = arr[front];

        // this if mas2ola 3n ta7reek amakn el front w el rear
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }

        return x;
    }
}

void CircularQueue::Display()
{
    // Function to display status of Circular Queue
    int i;
    if (isEmpty())
    {
        cout << endl
             << "Empty Queue" << endl;
    }
    else
    {
        cout << "Front -> " << front;
        cout << endl
             << "Items - > ";
        for (i = front; i != rear; i = (i + 1) % size)
            cout << arr[i];
        cout << arr[i]; // hya hya low 2olt arr[rear] // 3shan hya hya hatkon a5er value b3d ma y5ls el loop
        cout << endl
             << "Rear -> " << rear;
    }
}
