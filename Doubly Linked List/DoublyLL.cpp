#include "DoublyLL.h"
#include <iostream>
using namespace std;

DoublyLL::DoublyLL()
{
    headNode = nullptr;
    tailNode = nullptr;
}

void DoublyLL::insertFirst(int Data)
{
    Node *newNode = new Node(Data);

    if (headNode != NULL)
    {
        newNode->next = headNode;
        newNode->prev = nullptr;
        headNode = newNode;
    }
    else
    {
        headNode = tailNode = newNode;
        newNode->next = newNode->prev = nullptr;
    }
}

void DoublyLL::Append(int Data)
{
    Node *newNode = new Node(Data);

    if (headNode == NULL)
    {

        headNode = tailNode = newNode;
    }
    else
    {
        newNode->prev = tailNode;
        tailNode->next = newNode;
        newNode->next = nullptr;
        tailNode = newNode;
    }
}

void DoublyLL::Insert(int Data, int index)
{
    if (index > this->Size() - 1)
    {
        cout << "Index out of bounds! " << endl;
    }
    else if (headNode == NULL)
    {
        cout << "Empty List, append 1 or more nodes first." << endl;
    }
    else if (index == 0)
    { // insert at the start of the DoublyLL
        insertFirst(Data);
    }
    else if (index == this->Size() - 1)
    { // at the end of the DoublyLL (Append)
        Append(Data);
    }
    else
    {
        Node *tempNode = headNode;

        for (int i = 0; i < index; i++)
        {
            tempNode = tempNode->next;
        }
        Node *newNode = new Node(Data);
        newNode->prev = tempNode->prev;
        newNode->next = tempNode;
        tempNode->prev->next = newNode;
        tempNode->prev = newNode;
    }
}

void DoublyLL::Delete(int Data)
{
    Node *tempNode = headNode;
    Node *tempTail = tailNode;

    if (tempNode == nullptr)
    {
        return;
    }
    else if (tempNode->data == Data)
    { // if its in the first node, no need to handle others
        headNode = tempNode->next;
        delete tempNode;
    }
    else if (tempTail->data == Data)
    { // if its in the final node, no need to handle others
        tailNode = tempTail->prev;
        tailNode->next = nullptr;
        delete tempTail;
    }
    else
    {
        while (tempNode != NULL && tempNode->data != Data)
        {
            tempNode = tempNode->next;
        }

        if (tempNode != NULL)
        {
            tempNode->prev->next = tempNode->next;
            tempNode->next->prev = tempNode->prev;
            delete tempNode;
        }
    }
}

bool DoublyLL::Search(int Data)
{
    Node *tempNode = headNode;

    while (tempNode != NULL)
    {
        if (tempNode->data == Data)
        {
            return true;
        }
        else
        {
            tempNode = tempNode->next;
        }
    }
    return false;
}

void DoublyLL::Display()
{
    Node *tempNode = headNode;

    while (tempNode != NULL)
    {
        cout << tempNode->data << " ";
        tempNode = tempNode->next;
    }
}

int DoublyLL::Size()
{
    int counter = 0;
    Node *tempNode = headNode;

    while (tempNode != NULL)
    {
        counter++;
        tempNode = tempNode->next;
    }

    return counter;
}

void DoublyLL::displayFromEnd()
{
    Node *temp = tailNode;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    /*Node* temp_nodeHolder = tailNode;
    if (temp_nodeHolder != nullptr)
    {
        do
        {
            cout << temp_nodeHolder->data << " ";
            temp_nodeHolder = temp_nodeHolder->prev;
        } while (temp_nodeHolder != nullptr);
    }*/
}
