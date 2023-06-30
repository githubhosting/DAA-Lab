// C++ code to implement quicksort
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Partition the array by swapping elements
// so that all elements less than the pivot
// are to the left of the pivot and all
// elements greater than the pivot are to
// the right of the pivot.

int partition(int arr[], int low, int high)
{
    // Select the last element as the pivot.
    int pivot = arr[high];

    // i is the index of the last element
    // that is less than the pivot.
    int i = (low - 1);

    // Iterate through the array, swapping
    // elements that are less than the pivot
    // with the element at index i+1.
    for (int j = low; j <= high - 1; j++)
    {
        // If the element at index j is less
        // than the pivot, swap it with the
        // element at index i+1.
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot with the element at index i+1.
    swap(arr[i + 1], arr[high]);

    // Return the index of the pivot.
    return (i + 1);
}

// Sort the array by recursively calling
// quicksort on the two halves.
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
    int arr[] = {10, 7, 1, 9, 8, 5};
    int N = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, N - 1);
    cout << "Sorted array: " << endl;
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    return 0;
}