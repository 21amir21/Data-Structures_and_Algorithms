#pragma once
class Stack
{
public:
    int size;
    int top_ptr;
    int *arr;

    Stack(int Size);
    bool isEmpty();
    bool isFull();
    void push(int Data);
    int pop();
    int top();
    int getSize();
    void Display();
};
