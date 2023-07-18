#include <iostream>
#include <algorithm>
using namespace std;

// Insertion Sort Algo
void insertionSort(int arr[], int n)
{

    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{

    int arr[] = {30, 80, 90, 20, 60, 70, 10, 100, 50, 40};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, arrSize);

    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}