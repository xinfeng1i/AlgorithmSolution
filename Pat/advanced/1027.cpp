#include <iostream>
#include <string>
#include <stack>
using namespace std;

string toRadix13(int n)
{
    if (n == 0)
    {
        return "00";
    }
    string ans("");
    stack<char> s;
    while (n != 0)
    {
        int r = n % 13;
        if (r >= 0 && r <= 9)
        {
            s.push(r + '0');
        }
        else if (r == 10)
        {
            s.push('A');
        }
        else if (r == 11)
        {
            s.push('B');
        }
        else if (r == 12)
        {
            s.push('C');
        }

        n /= 13;
    }

    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }

    if (ans.size() == 1)
    {
        ans.insert(0, 1, '0');
    }

    return ans;
}

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    string red = toRadix13(r);
    string green = toRadix13(g);
    string blue = toRadix13(b);
    cout << "#" << red << green << blue << endl;
    return 0;
}
