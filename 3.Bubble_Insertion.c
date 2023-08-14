#include <stdio.h>
#include <time.h>

void bubbleSort(int arr[], int num)
{
    int x, y, temp;
    for (x = 0; x < num - 1; x++)
    {
        for (y = 0; y < num - x - 1; y++)
        {
            if (arr[y] > arr[y + 1])
            {
                temp = arr[y];
                arr[y] = arr[y + 1];
                arr[y + 1] = temp;
            }
        }
    }
}
void insertionSort(int *array, int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = array[i]; // take value
        j = i;          // take index
        while (j > 0 && array[j - 1] > key)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key; // insert in right place
    }
}

int main()
{
    int arr[50], n, x;
    printf("Please Enter the Number of Elements you want in the array: ");
    scanf("%d", &n);
    printf("Please Enter the Value of Elements: ");
    for (x = 0; x < n; x++)
        scanf("%d", &arr[x]);

    clock_t start, end;
    float cpu_time_used;
    start = clock();
    bubbleSort(arr, n);
    end = clock();
    cpu_time_used = ((float)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken for Bubble Sort: %f", cpu_time_used);

    start = clock();
    insertionSort(arr, n);
    end = clock();
    cpu_time_used = ((float)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken for Insertion Sort: %f \n", cpu_time_used);

    printf("Array after implementing sort: ");
    for (x = 0; x < n; x++)
    {
        printf("%d  ", arr[x]);
    }

    return 0;
}