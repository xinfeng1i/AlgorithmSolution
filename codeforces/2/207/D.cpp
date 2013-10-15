#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        int tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

int main()
{
    long long n, m;
    cin >> n >> m;
    string a, b;
    cin >> a;
    cin >> b;
    long long sz1 = a.size();
    long long sz2 = b.size();

    long long gcd12 = gcd(sz1, sz2);
    long long beishu = (sz1 / gcd12) * (sz2 / gcd12) * gcd12;

    long long round1 = n * sz1 / beishu;
    long long round2 = m * sz2 / beishu;

    long long cnt = 0;
    string str1;
    string str2;
    for (long long i = 0; i < beishu / sz1; ++i)
    {
        str1 += a;
    }

    for (long long i = 0; i < beishu / sz2; ++i)
    {
        str2 += b;
    }

    for (long long i = 0; i < str1.size(); ++i)
    {
        if (str1[i]  != str2[i])
        {
            cnt++;
        }
    }

    cout << cnt * round1 << endl;
    return 0;
}
