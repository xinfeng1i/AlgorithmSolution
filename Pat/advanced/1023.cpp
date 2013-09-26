#include <iostream>
#include <string>
#include <vector>
using namespace std;

// given a big number, return the double value of it
string doubleNumber(string number)
{
    string result("");
    int a[30] = {0}; 
    int sz = number.size();
    for (int i = sz - 1; i >= 0; --i)
    {
        a[sz - 1 - i] = number[i] - '0';
    }

    for (int i = 0; i < 30; ++i)
    {
        a[i] *= 2;
    }

    for (int i = 0; i < 30; ++i)
    {
        if (a[i] >= 10)
        {
            a[i + 1] += a[i] / 10;
            a[i] = a[i] % 10;
        }
    }

    int nonzeroPos = 29;
    while (a[nonzeroPos] == 0)
    {
        nonzeroPos--;
    }

    for (int i = nonzeroPos; i >= 0; i--)
    {
        result += a[i] + '0';
    }

    return result;
}

bool isPermutation(string a, string b)
{
    int cnt_a[10] = {0};
    int cnt_b[10] = {0};
    for (int i = 0; i < a.size(); ++i)
    {
        cnt_a[a[i] - '0']++;
    }
    for (int i = 0; i < b.size(); ++i)
    {
        cnt_b[b[i] - '0']++;
    }

    for (int i = 0; i < 10; ++i)
    {
        if (cnt_a[i] != cnt_b[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    string doubleS = doubleNumber(s);
    if (isPermutation(s, doubleS))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    cout << doubleS << endl;
    return 0;
}
