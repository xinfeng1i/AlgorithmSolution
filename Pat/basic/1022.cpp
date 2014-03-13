#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long llong;

int main()
{
    llong a, b;
    int d;
    cin >> a >> b;
    cin >> d;

    llong c = a + b;
    if (c == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    stack<int> s;
    while (c != 0)
    {
        s.push(c % d);
        c /= d;
    }

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;

    return 0;
}
