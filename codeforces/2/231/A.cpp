#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    string s;
    cin >> s;

    // find the + symbol
    int sgn = 0;
    while (s[sgn] != '+')
    {
        sgn++;
    }
    a = sgn;

    // get a, b, c
    while (s[sgn] != '=')
    {
        sgn++;
    }
    b = sgn - a - 1;
    c = s.size() - 1 - sgn;
    // cout << "a = " << a <<"; b = " << b << ";  c = " << c << endl;

    if (a + b == c)
    {
        cout << s << endl;
        return 0;
    }
    
    if (a - 1 + b == c + 1)
    {
        if (a >= b)
        {
            for (int i = 0; i < a - 1; ++i)
            {
                cout << "|";
            }
            cout << "+";
            for (int i = 0; i < b; ++i)
            {
                cout << "|";
            }
        }
        else
        {
            for (int i = 0; i < a; ++i)
            {
                cout << "|";
            }
            cout << "+";
            for (int i = 0; i < b - 1; ++i)
            {
                cout << "|";
            }
            
        }
        cout << "=";
        for (int i = 0; i < c + 1; ++i)
        {
            cout << "|";
        }
        cout << endl;
    }
    else if (a + 1 + b == c - 1)
    {
        for (int i = 0; i < a + 1; ++i)
        {
            cout << "|";
        }
        cout << "+";
        for (int i = 0; i < b; ++i)
        {
            cout << "|";
        }
        cout << "=";
        for (int i = 0; i < c - 1; ++i)
        {
            cout << "|";
        }
        cout << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }

    return 0;
}
