#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

int a[10];
int main()
{
    for (int i = 0; i < 10;++i)
    {
        a[i] = 0;
    }

    string input;
    cin >> input;
    int n = input.size();
    for (int i = 0; i < n; ++i)
    {
        a[input[i]-'0']++;
    }

    for (int i = 0; i < 10; ++i)
    {
        if (a[i] != 0)
        {
            cout << i << ":" << a[i] << endl;
        }
    }
    cout << endl;
    return 0;
}
