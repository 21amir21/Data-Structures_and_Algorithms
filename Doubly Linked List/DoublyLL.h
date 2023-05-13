#pragma once

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int Data)
    {
        data = Data;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLL
{
public:
    Node *headNode;
    Node *tailNode;

    DoublyLL();
    void insertFirst(int Data);
    void Append(int Data);
    void Insert(int Data, int index);
    void Delete(int Data);
    bool Search(int Data);
    void Display();
    int Size();

    void displayFromEnd();
};
