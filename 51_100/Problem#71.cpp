#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

long gcd(long a, long b)
{
    while (b != 0)
    {
        long r = a % b;
        a = b;
        b = r;
    }

    return a;
}

class Fraction
{
private:
    long numerator;
    long denominator;
public:
    Fraction(long n, long d):numerator(n), denominator(d)
    {
        reduceFraction();
    }

    ~Fraction()
    {}

    bool operator==(const Fraction& other) const
    {
        return numerator * other.denominator == denominator * other.numerator;
    }

    bool operator<(const Fraction& other) const
    {
        return numerator * other.denominator < denominator * other.numerator;
    }

    void displayFraction() const
    {
        cout << numerator << "/" << denominator;
    }
private: // helper function
    void reduceFraction()
    {
        long tmp = gcd(numerator, denominator);
        numerator /= tmp;
        denominator /= tmp;
    }
};

int main()
{
    set<Fraction> s;
    const long UP_BOUND = 1000;
    for (long d = 2; d <= UP_BOUND; ++d)
    {
        for (long n = 1; n < d; ++n)
        {
            s.insert(Fraction(n, d));
        }
    }

    set<Fraction>::iterator it_third = s.find(Fraction(1, 3));
    set<Fraction>::iterator it_second = s.find(Fraction(1, 2));
    vector<Fraction> v(it_third, it_second);
    cout <<"The number of fractions between 1/3 and 1/2 is: "
        << v.size() - 1 << endl;
    return 0;
}
