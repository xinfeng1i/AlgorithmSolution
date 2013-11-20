#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool isCoolNumber(int number)
{
    vector<int> cnt(10, 0);
    int tmp = 0;
    while (number != 0)
    {
        tmp = number % 10;
        cnt[tmp]++;
        number /= 10;
    }

    for (int i = 0; i < 10; ++i)
    {
        if (cnt[i] >= 2)
        {
            return false;
        }
    }

    return true;
}

int getNumber(int N)
{}

int main()
{
    cout << "enter a number:" << endl;
    int n;
    while (cin >> n)
    {
        cout << "is cool number ? " << isCoolNumber(n) << endl;
    }

    return 0;
}
