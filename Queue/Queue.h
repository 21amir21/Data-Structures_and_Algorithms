#pragma once
class Queue
{
public:
    int size;
    int front;
    int rear;
    int *arr;

    Queue(int Size);
    bool isEmpty();
    bool isFull();
    void enqueue(int Data);
    int dequeue();
    void Display();

    // These are functions added in the 4th Question (Q4)
    int getSize();
    bool Search(int val);
};
