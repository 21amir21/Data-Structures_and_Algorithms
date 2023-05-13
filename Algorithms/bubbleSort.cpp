#include <iostream>
#include <algorithm>
using namespace std;

// Bubble Sort Algo
void bubbleSort(int arr[], int n)
{

    for (int i = 0; i < n; i++) // the first loop is for the passes number
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{

    int arr[] = {30, 80, 90, 20, 60, 70, 10, 100, 50, 40};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, arrSize);

    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}