#include <iostream>
#include <string>
#include <vector>

using namespace std;

int theCount(vector<int> seq)
{

    int n = seq.size();
    if (seq.size() == 1)
    {
        return -1;
    }

    if (seq.size() == 2)
    {
        int a = seq[0];
        int b = seq[1];
        int c1 = 2 * b - a;
        if (b % a != 0)
        {
            return 1;
        }
        else
        {
            int c2 = b * b / a;
            return c1 == c2 ? 1 : 2;
        }
    }

    bool isArithemic = true;
    int constant = seq[1] - seq[0];
    for (int i = 1; i < n; ++i)
    {
        if (seq[i] - seq[i-1] != constant)
        {
            isArithemic = false;
        }
    }
    int append1 = seq[n - 1] + constant;

    bool isGeometric = true;
    if (seq[1] % seq[0] != 0)
    {
        isGeometric = false;
    }
    else
    {
        int ratio = seq[1] / seq[0];
        for (int i = 1; i < n; ++i)
        {
            if (seq[i] / seq[i-1] != ratio)
            {
                isGeometric = false;
                break;
            }
        }
    }

    if (!isArithemic && !isGeometric)
    {
        return 0;
    }
    else if (isArithemic && !isGeometric)
    {
        return 1;
    }
    else if (!isArithemic && isGeometric)
    {
        return 1;
    }
    else
    {
        int append2 = seq[1] / seq[0] * seq[n-1];

        return append1 == append2 ? 1 : 2;
    } 
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    cout << theCount(v) << endl;

    return 0;
}
