#include <iostream>
#include <istream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

long gcdgcd(long a, long b)
{
    int remainder = 0;
    while (b != 0)
    {
        remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}


class FractionalNumber
{
public:
    long numerator_;        // fenzi
    long denominator_;      // fenmu
public:
    FractionalNumber(int a = 1, int b = 1):numerator_(a),denominator_(b)
    {}

    friend FractionalNumber operator+(const FractionalNumber& a, const FractionalNumber& b);
    friend std::istream& operator>>(std::istream& in, FractionalNumber& a);
};

FractionalNumber operator+(const FractionalNumber& a, const FractionalNumber& b)
{
    long m = gcdgcd(a.denominator_, b.denominator_);
    m = m * (a.denominator_ / m) * (b.denominator_ / m);
    long n1 = a.numerator_ * (m / a.denominator_);
    long n2 = b.numerator_ * (m / b.denominator_);
    long n = n1 + n2;
    long g = gcdgcd(abs(m), abs(n));

    return FractionalNumber(n / g, m / g);
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

    if (abs(ans.numerator_) > abs(ans.denominator_))
    {
        if (ans.numerator_ % ans.denominator_ == 0)
        {
            cout << ans.numerator_ / ans.denominator_ << endl;
           
        }
        else
        {
            long intPart = ans.numerator_ / ans.denominator_;
            ans.numerator_ = abs(ans.numerator_) % ans.denominator_;
            cout << intPart << " " << ans.numerator_ << "/" << ans.denominator_ << endl;
        }
    }
    else if (abs(ans.numerator_) == abs(ans.denominator_))
    {
        cout << ans.numerator_ << endl;
    }
    else
    {
        cout << ans.numerator_ << "/" << ans.denominator_ << endl;
    }
    return 0;
}

