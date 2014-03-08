#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, p, k;
    cin >> n >> p >> k;
    int min_page = p - k;
    int max_page = p + k;
    if (min_page < 1)
    {
        min_page = 1;
    }

    if (max_page > n)
    {
        max_page = n;
    }

    // output
    if (min_page != 1)
    {
        cout << "<<";
    }

    for (int i = min_page; i <= max_page; ++i)
    {
        if (i != p)
        {
            cout << " " << i;
        }
        else
        {
            cout << " " << "(" << p << ")";
        }
    }
    
    if (max_page != n)
    {
        cout << " " << ">>";
    }
    cout << endl;

    return 0;
}
