#include <iostream>
using namespace std;
#include <time.h>

long int middle_school(long int m, long int n)
{
    long int i, gcd;
    clock_t start, end;
    start = clock();
    for (i = 1; i <= m && i <= n; ++i)
    {
        if (m % i == 0 && n % i == 0)
            gcd = i;
    }
    end = clock();
    cout << "Time taken: " << (float(end - start) / CLOCKS_PER_SEC) << " sec , GCD ";
    return gcd;
}

long int euclid(long int m, long int n)
{
    clock_t start, end;
    start = clock();
    long int r;
    while (n != 0)
    {
        r = m % n;
        m = n;
        n = r;
    }
    end = clock();
    cout << "Time taken: " << (float(end - start) / CLOCKS_PER_SEC) << " sec , GCD ";
    return m;
}

long int sub(long int m, long int n)
{
    clock_t start, end;
    start = clock();
    m = (m < 0) ? -m : m;
    n = (n < 0) ? -n : n;

    while (m != n)
    {
        if (m > n)
        {
            m = m - n;
        }
        else
        {
            n = n - m;
        }
    }

    end = clock();
    cout << "Time taken: " << (float(end - start) / CLOCKS_PER_SEC) << " sec , GCD ";
    return m;
}

main()
{
    long int x, y;
    cout << "\t\t ANALYSIS OF THE TWO ALGORITHMS" << endl;
    cout << "GCD : Enter Two numbers: ";
    cin >> x >> y;
    cout << "\nGCD-Middle School : " << middle_school(x, y);
    cout << "\nGCD-Euclid : " << euclid(x, y);
    cout << "\nGCD-Subtraction : " << sub(x, y);
}
