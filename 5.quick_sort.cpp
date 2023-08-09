// C++ code to implement quicksort

#include <bits/stdc++.h>
#include <iostream>
#include <time.h>

using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {10, 7, 1, 9, 8, 5, 3, 76, 67, 23, 13, 75, 86};
    int N = sizeof(arr) / sizeof(arr[0]);

    clock_t start, end;
    start = clock();
    quickSort(arr, 0, N - 1);
    end = clock();
    cout << "Time taken for insertion sort: " << (float(end - start) / CLOCKS_PER_SEC) << " sec \n";

    cout << "Sorted array: " << endl;
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    return 0;
}