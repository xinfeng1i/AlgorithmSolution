#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool isAllZero(long a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != 0)
        {
            return true;
        }
    }

    return false;
}

long minElem(long a[], int n)
{
    long min = 1000000;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != 0 && a[i] < min)
        {
            min = a[i];
        }
    }

    return min;
}

int main()
{
    long v;
    cin >> v;
    long a[10] = {0};
    for (int i = 1; i < 10; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < 10; ++i)
    {
        if (a[i] > v)
        {
            a[i] = 0;
        }
    }
    
    if (isAllZero(a, 10))
    {
        cout << -1 << endl;
        return 0;
    }

    long minimum = minElem(a, 10);
    for (int i = 9; i >= 1; --i)
    {
        if (a[i] == minimum)
        {
            
        }
    }
}
