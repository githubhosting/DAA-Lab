#include <stdio.h>
#include <time.h>

int linearSearch(int arr[], int N, int x)
{
    for (int i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main(void)
{
    int arr[] = {5, 14, 19, 19, 44, 45, 46, 48, 73, 74, 81, 84, 90, 142, 142, 150, 158, 160, 160, 162, 187, 188, 188, 189, 192, 218, 218, 221, 221, 231, 240, 242, 251, 251, 255, 257, 260, 275, 295, 306, 311, 312, 312, 329, 343, 346, 350, 383, 385, 396, 405, 410, 415, 427, 433, 451, 457, 460, 460, 469, 479, 499, 500, 514, 521, 526, 533, 602, 628, 630, 631, 680, 687, 692, 706, 724, 753, 795, 797, 799, 842, 849, 852, 863, 873, 875, 900, 905, 913, 919, 920, 925, 932, 936, 946, 960, 972, 986, 987, 987};
    int x;
    printf("\nEnter the number to search: ");
    scanf("%d", &x);
    int N = sizeof(arr) / sizeof(arr[0]);

    clock_t start, end;
    float cpu_time_used;
    start = clock();
    int lresult = linearSearch(arr, N, x);
    end = clock();
    (lresult == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", lresult);
    cpu_time_used = ((float)(end - start)) / ((float)(CLOCKS_PER_SEC));
    printf("\nTime taken for Linear Search: %f", cpu_time_used);

    start = clock();
    int bresult = binarySearch(arr, 0, N - 1, x);
    end = clock();
    (bresult == -1)
        ? printf("\nElement is not present in array")
        : printf("\nElement is present at index %d", bresult);
    cpu_time_used = ((float)(end - start)) / ((float)(CLOCKS_PER_SEC));
    printf("\nTime taken for Binary Search: %f", cpu_time_used);
    return 0;
}