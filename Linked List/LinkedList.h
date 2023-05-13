#pragma once
#include <iostream>
using namespace std;

struct Node
{
    int Data;
    Node *nextNode;

    /*Node(int data) {
        Data = data;
        nextNode = NULL;
    }*/
};

class LinkedList
{
private:
    Node *headNode;

public:
    LinkedList();
    void addNodeToBegining(int data);
    void AppendNodeToEnd(int data);
    void inserNode(int data, int location);
    void deleteNode(int data);
    bool searchDatainNodes(int data);
    int Size();
    void Display();

    void ReverseLinkedList(Node *root);

    void ReverseLinkedListIterative();

    Node *getHeadNode();
};
