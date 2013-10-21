#include <iostream>
#include <string>
using namespace std;

struct BigInt
{
    int a[25];  // the unsigned big int
    bool flag;  // positive or negative

    explicit BigInt(string s)
    {
        if (s[0] == '-')
        {
            flag = false;
            s = s.substr(1);
        }
        else
        {
            flag = true;
        }
        for (int i = 0; i < 25; ++i)
        {
            a[i] = 0;
        }
        int sz = s.size();
        for (int i = 0; i < sz; ++i)
        {
            a[i] = s[sz - 1 - i] - '0';
        }
    }

    void printBigInt();
    friend BigInt operator+(const BigInt& aa, const BigInt& bb);
    bool greaterZero();
    friend bool absGreater(const BigInt& aa, const BigInt& bb);
};

bool absGreater(const BigInt& aa, const BigInt& bb)
{
    string str1("");
    string str2("");
    for (int i = 24; i >=0; --i)
    {
        str1 += aa.a[i] + '0';
    }
    for (int i = 24; i >= 0; --i)
    {
        str2 += bb.a[i] + '0';
    }
    return str1 > str2;
}


bool BigInt::greaterZero()
{
    if (flag == false)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < 25; ++i)
        {
            if (a[i] != 0)
            {
                return true;
            }
        }
        return false;
    }
}

void BigInt::printBigInt()
{
    if (flag == false)
    {
        cout << "-";
    }
    int noZeroPos = 24;
    while (noZeroPos >= 0 && a[noZeroPos] == 0)
    {
        noZeroPos--;
    }
    if (noZeroPos < 0)
    {
        cout << endl;
        return;
    }
    else
    {
        for (int i = noZeroPos; i >= 0; i--)
        {
            cout << a[i];
        }
        cout <<endl;
        return;
    }
}

BigInt operator+(const BigInt& aa, const BigInt& bb)
{
    BigInt ans("0");
    if (aa.flag == bb.flag)
    {
        ans.flag = aa.flag;
        for (int i = 0; i < 25; ++i)
        {
            ans.a[i] = aa.a[i] + bb.a[i];
        }
        for (int i = 0; i < 24; ++i)
        {
            if (ans.a[i] >= 10)
            {
                ans.a[i+1] += ans.a[i] / 10;
                ans.a[i] = ans.a[i] % 10;
            }
        }
    }
    else
    {
        if (absGreater(aa, bb))
        {
            ans.flag = aa.flag;
            for (int i = 0; i < 25; ++i)
            {
                ans.a[i] = aa.a[i];                
            }

            for (int i = 0; i < 24; ++i)
            {
                if (ans.a[i] >= bb.a[i])
                {
                    ans.a[i] = ans.a[i] - bb.a[i];
                }
                else
                {
                    ans.a[i+1] -= 1;
                    ans.a[i] = 10 + ans.a[i] - bb.a[i];
                }
            }
        }
        else
        {
            ans.flag = bb.flag;
            for (int i = 0; i < 25; ++i)
            {
                ans.a[i] = bb.a[i];
            }

            for (int i = 0; i < 24; ++i)
            {
                if (ans.a[i] >= aa.a[i])
                {
                    ans.a[i] = ans.a[i] - aa.a[i];
                }
                else
                {
                    ans.a[i+1] -= 1;
                    ans.a[i] = 10 + ans.a[i] - aa.a[i];
                }
            }
        }
    }
    return ans;
}


int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        BigInt a(s1);
        BigInt b(s2);
        BigInt c(s3);
        c.flag = !c.flag;
        BigInt ans = a + b + c;
        if (ans.greaterZero())
        {
            cout << "Case #" << i + 1 << ": true" << endl;
        }
        else
        {
            cout << "Case #" << i + 1 << ": false" << endl;
        }
    }
    return 0;
}

// Method 2: other's elegant code
#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a, b, c;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b >> c;
        long long a1 = a / 3;
        long long b1 = b / 3;
        long long c1 = c / 3;
        long long r1 = a % 3;
        long long r2 = b % 3;
        long long r3 = c % 3;
        long long sum1 = a1 + b1 + (r1 + r2) / 3;
        long long sum2 = (r1 + r2) % 3;
        if (sum1 > c1 || sum1 == c1 && sum2 > r3)
        {
            cout << "Case #" << i + 1 << ": true" << endl;
        }
        else
        {
            cout << "Case #" << i + 1 << ": false" << endl;
        }
    }

    return 0;

}
#endif


// Summary:
// 1. This problem seems that you need implement a self-defined BinInt
//    class, but in fact you really need
// 2. you only need to worry about the largest and smallest bound value.
// 3. other's code main idea:
//    since we want to juege whether:   a + b > c
//    it is equivalent with:            (a + b) / 3 > c / 3
