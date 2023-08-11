#include <iostream>
using namespace std;
#include <time.h>

int Linear_search()
{
    int arr[10], n, i, num, index;
    clock_t start, end;
    cout << "Linear Search: Enter Number of elements: ";
    cin >> n;
    cout << "Enter the Elements: ";
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
    cout << "\nTime taken :" << (end - start) / CLOCKS_PER_SEC << " sec , Linear Search.";
    return 0;
}
int Binary_search()
{
    int i, arr[10], n, num, low, high, mid;
    clock_t start, end;
    cout << "Binary Search: Enter number of elements";
    cin >> n;
    cout << "Enter Elements (in ascending order): ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cout << "\nEnter Element to be Search: ";
    cin >> num;
    start = clock();
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] < num)
            low = mid + 1;
        else if (arr[mid] == num)
        {
            cout << "\nThe number, " << num << " found at Position " << mid + 1;
            break;
        }
        else
            high = mid - 1;
    }
    if (low > high)
        cout << "\nThe number, " << num << " is not found in given Array";
    end = clock();
    cout << "\nTime taken :" << (end - start) / CLOCKS_PER_SEC << " sec , Binary Search ";
    cout << endl;
    return 0;
}
int main()
{
    Linear_search();
    Binary_search();
}
