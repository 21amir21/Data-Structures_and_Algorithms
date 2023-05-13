#pragma once
class CircularQueue
{
public:
    int size;
    int front;
    int rear;
    int *arr;

    CircularQueue(int Size);
    bool isFull();
    bool isEmpty();
    void enQueue(int Data);
    int deQueue();
    void Display();
};
