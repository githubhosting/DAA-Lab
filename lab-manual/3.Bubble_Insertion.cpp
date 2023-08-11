#include <iostream>
using namespace std;
#include <time.h>
void display(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
void insertionSort(int *array, int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = array[i]; // take value
        j = i;
        while (j > 0 && array[j - 1] > key)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key; // insert in right place
    }
}
void bubblesort(int *a, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < size - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}
int main()
{
    int n;
    clock_t start, end;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n], a[n]; // create an array with given number of elements

    cout << "Enter elements: Insertion Sort" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array before Sorting: Insertion Sort ";
    display(arr, n);
    start = clock();
    insertionSort(arr, n);
    end = clock();
    cout << "Time taken for Insertion sort:" << (double)(end - start) / CLOCKS_PER_SEC << " sec" << endl;
    cout
        << "Array after Sorting: Insertion Sort ";
    display(arr, n);
    cout << "Bubble sort: Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    display(a, n);
    start = clock();
    bubblesort(a, n);
    end = clock();
    cout << "Time taken for Bubble sort: " << (double)(end - start) / CLOCKS_PER_SEC << " sec" << endl;
    cout << "Array after Sorting: Bubble sort ";
    display(a, n);
}