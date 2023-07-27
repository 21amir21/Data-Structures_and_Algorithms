#include <bits/stdc++.h>
using namespace std;

// An iterative binary search function.
int binarySearch(int arr[], int l, int r, int key)
{
    while (l <= r)
    {
        // its equal to m = (l + r) / 2
        // BUT the first one is better as it prevents potential integer overflow
        int m = l + (r - l) / 2;

        // Check if n is present at mid
        if (arr[m] == key)
            return m; // returing the index

        // If n greater, ignore left half
        if (arr[m] < key)
            l = m + 1;

        // If n is smaller, ignore right half
        else
            r = m - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearchRecursive(int arr[], int l, int r, int key)
{
    if (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == key)
            return m;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[m] > key)
            return binarySearchRecursive(arr, l, m - 1, key);

        // Else the element can only be present
        // in right subarray
        else
            return binarySearchRecursive(arr, m + 1, r, key);
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << binarySearch(arr, 0, 9, 6);

    return 0;
}