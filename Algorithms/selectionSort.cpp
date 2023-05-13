#include <iostream>
#include <algorithm>
using namespace std;

// Selection Sort Algo
void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int i_min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i_min])
            {
                i_min = j;
            }
        }
        swap(arr[i_min], arr[i]);
    }
}

int main()
{

    int arr[] = {30, 80, 90, 20, 60, 70, 10, 100, 50, 40};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, arrSize);

    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}