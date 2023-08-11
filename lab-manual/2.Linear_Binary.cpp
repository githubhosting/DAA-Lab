#include <iostream>
using namespace std;
#include <time.h>
int Linear_search()
{
    int arr[10], n, i, num, index;
    clock_t start, end;
    cout << "Linear Search: Enter Number of elements: ";
    cin >> n;
    cout << "Enter the Elements";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cout << "\n Enter a Number to Search: ";
    cin >> num;
    start = clock();
    for (i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            index = i;
            break;
        }
    }
    cout << "\nFound at Index No." << index;
    end = clock();
    cout << "Time taken :" << (end - start) / CLOCKS_PER_SEC << " sec , Linear Search ";
    cout << endl;
    return 0;
}
int Binary_search()
{
    int i, arr[10], n, num, first, last, middle;
    clock_t start, end;
    cout << "Binary Search: Enter number of elements";
    cin >> n;
    cout << "Enter Elements (in ascending order): ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cout << "\nEnter Element to be Search: ";
    cin >> num;
    start = clock();
    first = 0;
    last = n - 1;
    middle = (first + last) / 2;
    while (first <= last)
    {
        if (arr[middle] < num)
            first = middle + 1;
        else if (arr[middle] == num)
        {
            cout << "\nThe number, " << num << " found at Position " << middle + 1;
            break;
        }
        else
            last = middle - 1;
        middle = (first + last) / 2;
    }
    if (first > last)
        cout << "\nThe number, " << num << " is not found in given Array";
    end = clock();
    cout << "Time taken :" << (end - start) / CLOCKS_PER_SEC << " sec , Binary Search ";
    cout << endl;
    return 0;
}
int main()
{
    Binary_search();
    Linear_search();
}
