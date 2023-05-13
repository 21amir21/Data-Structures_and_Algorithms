#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int Data;
    Node *left;
    Node *right;

    Node(int data)
    {
        Data = data;
        left = NULL;
        right = NULL;
    }
};

class BST
{

public:
    Node *rootNode;

    BST()
    {
        rootNode = NULL;
    }

    Node *insertNode(Node *pnode, int data)
    {

        if (pnode == NULL)
        {
            Node *newNode = new Node(data); // msh lazm hna a3ml newNode->left = NULL , newNode->right = NULL 3shan enta 3amlha fy el constr
            pnode = newNode;
        }
        else if (data < pnode->Data)
        {
            pnode->left = insertNode(pnode->left, data);
        }
        else
        {
            pnode->right = insertNode(pnode->right, data);
        }

        return pnode;
    }

    // hya hya bs bshkll mo5tsr FOR CALLING // it calls the other function // this is a helper function to the InserNode
    void inserNodeLite(int data)
    {
        rootNode = insertNode(rootNode, data);
    }

    // -----------------------------------------------------------------------
    // The Display() func has 3 ways in BST
    // 1. PreOrder = root -> left -> right
    // 2. InOrder = left -> root -> right
    // 3. PostOrder = left -> right -> root
    // -----------------------------------------------------------------------

    // 1. PreOrder = root -> left -> right
    void PreOrder(Node *pnode)
    {

        if (pnode == NULL)
            return;

        cout << pnode->Data << "\t";
        PreOrder(pnode->left);
        PreOrder(pnode->right);
    }

    // 2. InOrder = left -> root -> right
    void InOrder(Node *pnode)
    {

        if (pnode == NULL)
            return;

        InOrder(pnode->left);
        cout << pnode->Data << "\t";
        InOrder(pnode->right);
    }

    // 3. PostOrder = left - > right -> root
    void PostOrder(Node *pnode)
    {

        if (pnode == NULL)
            return;

        PostOrder(pnode->left);
        PostOrder(pnode->right);
        cout << pnode->Data << "\t";
    }

    Node *searchNode(Node *pnode, int data)
    { // u can change the return of the func make it bool and

        if (pnode == NULL)
            return NULL; // here return false;

        else if (data == pnode->Data)
        {
            return pnode; // here return true;
        }

        else if (data < pnode->Data)
        {
            return searchNode(pnode->left, data);
        }

        else
        {
            return searchNode(pnode->right, data);
        }
    }

    // we also need a helper function for searchnode func
    bool searchNodeLite(int data)
    {

        Node *result = searchNode(rootNode, data);

        if (result == NULL)
            return false;
        else
            return true;
    }

    // For Delete Function u need some helper functions
    // this function finds the Minimum Node
    Node *FindMin(Node *pnode)
    {

        if (pnode == NULL)
            return NULL;
        else if (pnode->left == NULL)
            return pnode;
        else
            return FindMin(pnode->left);
    }

    // this function finds the Maximum Node
    Node *FindMax(Node *pnode)
    {

        if (pnode == NULL)
        {
            return NULL;
        }

        else if (pnode->right == NULL)
            return pnode;
        else
            return FindMax(pnode->right);
    }

    Node *deleteNode(Node *pnode, int data)
    {

        if (pnode == NULL)
            return NULL;

        else if (data < pnode->Data) // item exist in the left sub-tree
            pnode->left = deleteNode(pnode->left, data);

        else if (data > pnode->Data) // item exist in the right sub-tree
            pnode->right = deleteNode(pnode->right, data);

        else
        { // here the item is in the pnode itself (parent node)

            if (pnode->left == NULL && pnode->right == NULL) // this is a leaf node
                pnode = NULL;

            else if (pnode->left != NULL && pnode->right == NULL)
            { // one child on the left
                pnode->Data = pnode->left->Data;
                delete pnode->left;
                pnode->left = NULL;
            }

            else if (pnode->left == NULL && pnode->right != NULL)
            { // one child on the right
                pnode->Data = pnode->right->Data;
                delete pnode->right;
                pnode->right = NULL;
            }

            else
            { // the node has 2 children

                // here i used the predecessor : replacing the deleted node with the largest node on its left
                // we could have also used the successor : replacing the deleted node with the smallest node on its right
                // but we will need to adjust the code a little bit

                Node *predecessor = FindMax(pnode->left);
                pnode->Data = predecessor->Data;
                pnode->left = deleteNode(pnode->left, predecessor->Data);
            }
        }

        return pnode;
    }

    // function to count the number of Leaf Nodes
    int LeafNodeCount(Node *pnode)
    {
        if (pnode == NULL)
            return 0;
        else if (pnode->left == NULL && pnode->right == NULL)
            return 1;
        else
            return LeafNodeCount(pnode->left) + LeafNodeCount(pnode->right);
    }

    // function to get the Height of the Tree // IMPORTANT!!! el impl da msh sh8aal asln bytl3 value 8lt zayda 1
    /*int getHeightOfTree(Node* pnode) {
        if (pnode == NULL)
            return 0;
        return (1 + fmax(getHeightOfTree(pnode->left), getHeightOfTree(pnode->right)));
    }*/

    int getHeightOfTree(Node *pnode)
    {

        int leftheight = -1;
        int rightheight = -1;

        if (pnode == NULL)
        {
            return 0;
        }

        if (pnode->left)
        {
            leftheight = getHeightOfTree(pnode->left);
        }

        if (pnode->right)
        {
            rightheight = getHeightOfTree(pnode->right);
        }

        return 1 + max(leftheight, rightheight);
    }

    // function to see if the tree is balanced or not
    bool isBalanced(Node *pnode)
    {
        if (pnode == NULL)
            return true;

        int heightDifference = getHeightOfTree(pnode->left) - getHeightOfTree(pnode->right);

        if (abs(heightDifference) > 1)
            return false;
        else
            return isBalanced(pnode->left) && isBalanced(pnode->right);
    }
};

int main()
{

    // 45, 15, 79, 90, 10, 55, 12, 20, 50
    BST btree;
    btree.inserNodeLite(45);
    btree.inserNodeLite(15);
    btree.inserNodeLite(79);
    btree.inserNodeLite(90);
    btree.inserNodeLite(10);
    btree.inserNodeLite(55);
    btree.inserNodeLite(12);
    btree.inserNodeLite(20);
    btree.inserNodeLite(50);

    cout << "Display the content of the tree\n";
    btree.PreOrder(btree.rootNode);
    cout << "\n..............................................................................\n";
    btree.InOrder(btree.rootNode);
    cout << "\n..............................................................................\n";
    btree.PostOrder(btree.rootNode);
    cout << "\n..............................................................................\n";

    // testing the search funcs // alter the value 55
    /*if (btree.searchNodeLite(55)) {
        cout << "Item is found\n";
    }
    else
        cout << "Sorry, item is not found\n";*/

    /*cout << "Find the Minimum\n";
    Node* min = btree.FindMin(btree.rootNode);
    if (min == NULL)
        cout << "No item exist\n";
    else
        cout << "The Minimum it is " << min->Data << "\n";


    cout << "Find the Maximum\n";
    Node* max = btree.FindMax(btree.rootNode);
    if (max == NULL)
        cout << "No item exist\n";
    else
        cout << "The Minimum it is " << max->Data << "\n";*/

    cout << "\n Delete Items \n";
    Node *result = btree.deleteNode(btree.rootNode, 12);
    cout << "PreOrder After deleting 12 \n";
    btree.PreOrder(result);

    // cout << "The No. of Leaf Nodes are " << btree.LeafNodeCount(btree.rootNode);

    // cout << "The height of the tree is " << btree.getHeightOfTree(btree.rootNode);

    return 0;
}