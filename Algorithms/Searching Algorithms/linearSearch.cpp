#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[], int size, int n)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == n)
            return true;
    }

    return false;
}

int main()
{

    int arr[] = {2, 5, 7, 8, 21, 3, 5, 8, 10};
    int s = sizeof(arr) / sizeof(arr[0]);

    int numb;
    cout << "Enter the number to search for it " << endl;
    cin >> numb;

    if (linearSearch(arr, s, numb))
    {
        cout << "The number is found !!";
    }
    else
    {
        cout << "Not found !";
    }

    return 0;
}