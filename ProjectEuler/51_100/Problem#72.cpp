#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
using namespace std;

typedef pair<long, long> Fraction;

long gcd(long a, long b)
{
    if (a % b == 0)
    {
        return b;
    }

    return gcd(b, a % b);
}

/**
int main()
{
    set<Fraction> diffFractions;
    long d;
    cin >> d;
    
    Fraction f;
    f.first = 1;
    f.second = 1;
    for (long dd = 2; dd <= d; dd++)
    {
        cout << "current d is: " << dd << "..." << endl;
        for (long nn = 1; nn < dd; ++nn)
        {
            if (nn != 1 && dd % nn == 0)
            {
                continue;
            }
            long tmp = gcd(dd, nn);
            f.first = nn / tmp;
            f.second = dd / tmp;
            diffFractions.insert(f);
        }
    }

    cout << "different fractions under " << d << " is: "
         << diffFractions.size() << endl;
    return 0;
}
*/

int main()
{
    long limit = 1000000;
    vector<long> phi(1000001, 0);
    for (long i = 0; i <= 1000000; ++i)
    {
        phi[i] = i;
    }

    long long result = 0;
    for (long i = 2; i <= limit; i++)
    {
        if (phi[i] == i)
        {
            for (long j = i; j <= limit; j += i)
            {
                phi[j] = phi[j] / i * (i - 1);
            }
        }

        result += phi[i];
    }

    cout << result << endl;
    return 0;
}
