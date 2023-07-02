// C++ code to implement merge sort
#include <iostream>
using namespace std;

void Merge(int *a, int low, int high, int mid)
{
    int i, j, k, temp[high - low + 1];
    i = low;
    k = 0;
    j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }

    for (i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
}

void MergeSort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);

        Merge(a, low, high, mid);
    }
}

int main()
{
    int arr[] = {98, 37, 1, 25, 1, 72, 13, 74, 53, 0, 77, 73, 6, 74, 26, 66, 96, 38, 2, 22, 51, 83, 29, 18, 47, 33, 79, 25, 57, 23, 54, 97, 12, 17, 94, 14, 91, 74, 65, 51, 78, 79, 16, 94, 32, 84, 57, 84, 70, 39, 59, 94, 48, 83, 20, 97, 68, 59, 64, 41, 82, 72, 36, 96, 60, 96, 50, 36, 37, 5, 82, 36, 25, 88, 50, 36, 48, 95, 21, 16, 94, 28, 4, 22, 73, 67, 89, 27, 98, 63, 25, 69, 97, 72, 82, 64, 90, 38, 80, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    clock_t begin_time = clock();
    MergeSort(arr, 0, n - 1);
    cout << "Time taken by program is : " << float(clock() - begin_time) / float(CLOCKS_PER_SEC) << "\n";

    cout << "\nSorted Data: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}