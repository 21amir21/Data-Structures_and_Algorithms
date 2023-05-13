#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
    headNode = nullptr;
}

// bn7ooot node fy el awll 5alss
void LinkedList::addNodeToBegining(int data)
{
    // hna 3amlna newNode w 7atyna fyha el data el hwa da5lha
    Node *newNode = new Node();
    newNode->Data = data;

    // me7tagen ne3ml temp hna w n5lyh yshawrr 3la el newNode el hya hatkon awl wahdaa
    Node *tempNode = newNode;

    if (headNode != NULL)
    {
        newNode->nextNode = headNode;
    }

    headNode = tempNode; // hwa fy far2 hna low 5aleteha tshawr 3la el newNode?? ,,, headNode = newNode
}

void LinkedList::AppendNodeToEnd(int data)
{
    if (headNode == nullptr)
    {
        headNode = new Node();
        headNode->Data = data;
    }
    else
    {
        Node *tempNode = headNode;
        while (tempNode->nextNode != nullptr)
        {
            tempNode = tempNode->nextNode;
        }
        Node *newNode = new Node();
        newNode->Data = data;
        newNode->nextNode = nullptr;
        tempNode->nextNode = newNode;
    }
}

void LinkedList::inserNode(int data, int location)
{
    Node *newNode = new Node();
    newNode->Data = data;

    Node *tempNode = headNode;

    if (location == 1)
    {
        if (headNode != nullptr)
            newNode->nextNode = headNode;
        headNode = newNode;
    }
    else if (location > Size())
    { // msh moshkla el error da delw2ty l7d ma a3ml Size() func
        cout << "Location is Out of Bound " << endl;
    }
    else
    {
        for (int i = 2; i < location; i++)
        {
            if (tempNode->nextNode != NULL)
            {
                tempNode = tempNode->nextNode;
            }
        }
        newNode->nextNode = tempNode->nextNode;
        tempNode->nextNode = newNode;
    }
}

void LinkedList::deleteNode(int data)
{
    Node *tempNode = headNode;
    Node *prevNode = nullptr;

    if (tempNode == NULL)
    {
        return;
    }
    else if (tempNode->Data == data)
    {
        headNode = tempNode->nextNode;
        delete tempNode;
    }
    else
    {
        while (tempNode != nullptr && tempNode->Data != data)
        {
            prevNode = tempNode;
            tempNode = tempNode->nextNode;
        }
        if (tempNode != NULL)
        {
            prevNode->nextNode = tempNode->nextNode;
            delete tempNode;
        }
    }
}

bool LinkedList::searchDatainNodes(int data)
{
    Node *tempNode = headNode;

    while (tempNode != nullptr)
    {
        if (tempNode->Data == data)
            return true;

        tempNode = tempNode->nextNode;
    }

    return false;
}

int LinkedList::Size()
{
    int counter = 0;
    Node *tempNode = headNode;

    if (tempNode != nullptr)
    {
        do
        {
            counter++;
            tempNode = tempNode->nextNode;
        } while (tempNode != nullptr);
    }
    return counter;
}

void LinkedList::Display()
{
    Node *tempNode = headNode;

    if (tempNode != nullptr)
    {
        do
        {
            cout << tempNode->Data << " ";
            tempNode = tempNode->nextNode;
        } while (tempNode != nullptr);
    }
}

void LinkedList::ReverseLinkedList(Node *before)
{
    if (before->nextNode == NULL)
        headNode = before;
    return;

    ReverseLinkedList(before->nextNode);

    Node *newNode = before->nextNode;
    newNode->nextNode = before;
    before->nextNode = nullptr;
}

void LinkedList::ReverseLinkedListIterative()
{
    Node *before = nullptr;
    Node *temp = headNode;
    Node *after = nullptr;

    while (temp != NULL)
    {
        before = temp;
        temp = temp->nextNode;
        after = temp->nextNode;

        temp->nextNode = before;
    }

    headNode = before;
}

Node *LinkedList::getHeadNode()
{
    return headNode;
}
