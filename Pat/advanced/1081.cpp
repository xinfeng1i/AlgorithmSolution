#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

long long gcdgcd(long long a, long long b)
{
    long long r = 0;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}


class FractionalNumber
{
public:
    long long numerator_;        // fenzi
    long long denominator_;      // fenmu
public:
    FractionalNumber(long long a = 1, long long b = 1):numerator_(a),denominator_(b)
    {}

    friend FractionalNumber operator+(const FractionalNumber& a, const FractionalNumber& b);
    friend std::istream& operator>>(std::istream& in, FractionalNumber& a);
};

FractionalNumber operator+(const FractionalNumber& a, const FractionalNumber& b)
{
    long long m = gcdgcd(a.denominator_, b.denominator_);
    if (m == 0) // 分母中有0的情况
    {
        if (a.denominator_ == 0 && b.denominator_ == 0)
        {
            return FractionalNumber(0, 1);
        }
        else if (a.denominator_ == 0)
        {
            return b;
        }
        else if (b.denominator_ == 0)
        {
            return a;
        }
    }

    long long n1 = a.numerator_ * (b.denominator_ / m); // 先化简再计算，防止溢出, 坑点2
    long long n2 = b.numerator_ * (a.denominator_ / m);
    long long fenzi = n1 + n2;
    long long fenmu = a.denominator_ / m * b.denominator_;
    long long g = gcdgcd((long long)fabs(fenzi), (long long)fabs(fenmu));
    if (g == 0)
    {
        if (fenzi == 0)
        {
            return FractionalNumber(0, 1);
        }
    }

    return FractionalNumber(fenzi / g, fenmu / g);
}

istream& operator>>(istream& in, FractionalNumber& a)
{
    char ch;
    in >> a.numerator_ >> ch >> a.denominator_;
    return in;
}

int main()
{
    int n = 0;
    cin >> n;
    
    vector<FractionalNumber> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i]; 
    }
    
    FractionalNumber ans = v[0];
    for (int i = 1; i < n; ++i)
    {
        ans = ans + v[i];
    }

    if (fabs(ans.numerator_) > fabs(ans.denominator_))
    {
        if (ans.numerator_ % ans.denominator_ == 0)
        {
            cout << ans.numerator_ / ans.denominator_ << endl;
           
        }
        else
        {
            long long intPart = ans.numerator_ / ans.denominator_;
            ans.numerator_ = (long long)(fabs(ans.numerator_)) % ans.denominator_;
            cout << intPart << " " << ans.numerator_ << "/" << ans.denominator_ << endl;
        }
    }
    else if (fabs(ans.numerator_) == fabs(ans.denominator_))
    {
        cout << ans.numerator_ << endl;
    }
    else if (fabs(ans.numerator_) < fabs(ans.denominator_))
    {
        if (fabs(ans.numerator_) == 0) // 分子为0，直接输出0，坑点
        {
            cout << 0 << endl;
        }
        else
        {
            cout << ans.numerator_ << "/" << ans.denominator_ << endl;
        }
    }
    return 0;
}


