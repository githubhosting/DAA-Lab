#include <iostream>
#include <time.h>

using namespace std;
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
    cout << endl
         << "Time taken : " << (end - start)/CLOCKS_PER_SEC << " sec ";
    return m;
}
int main(){
    int m;
    int n;
    cin>>m>>n;
    int res = euclid(m, n);
    cout << res;
    return 0;
}