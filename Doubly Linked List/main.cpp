#include <iostream>
#include "DoublyLL.h"
using namespace std;

int main()
{

    int input;
    DoublyLL DLL;
    cout << "Add numbers, enter -1 to stop adding then display from end" << endl;
    cin >> input;

    while (input != -1)
    {
        DLL.Append(input);
        cin >> input;
    }

    // DLL.displayFromEnd();
    // DLL.Display();

    // cout << DLL.Size() << endl;

    /*if (DLL.Search(3)) {
        cout << "Mawgooda " << endl;
    }
    else {
        cout << "msh mawgodaa" << endl;
    }*/

    DLL.Display();
    cout << endl;

    DLL.insertFirst(21);
    DLL.Display();
    cout << endl;

    // DLL.Delete(5);
    // DLL.Display();
    // cout << endl;

    DLL.Insert(20, 2);
    DLL.Display();
    cout << endl;

    return 0;
}