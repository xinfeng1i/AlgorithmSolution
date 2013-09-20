#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

unsigned long long toDecimalNumber(string s, int radix)
{
    unsigned long long ret = 0;
    int p = 0;
    auto it = s.rbegin();
    for (; it != s.rend(); ++it, ++p)
    {
        if ((*it) >= '0' && (*it) <= '9')
        {
            ret += ((*it) - '0') * pow(radix, p);
        }
        else
        {
            ret += (*it - 'a' + 10) * pow(radix, p);
        }
    }
    return ret;
}

int main()
{
    string N1, N2;
    int tag, radix;
    cin >> N1 >> N2 >> tag >> radix;

    if (tag == 2)
    {
        swap(N1, N2);
    }
    
    unsigned long long decimalN1 = toDecimalNumber(N1, radix);
   
    // calculate min radix for N2
    int minN2Radix = 0;
    auto pmaxDigit = max_element(N2.begin(), N2.end());
    if (*pmaxDigit >= '0' && *pmaxDigit <= '9')
    {
        minN2Radix = (*pmaxDigit - '0') + 1;
    }
    else
    {
        minN2Radix = (*pmaxDigit - 'a' + 10) + 1;
    }

#if 1
    unsigned long long decimalN2 = 0;
    unsigned long long tmpRadix = minN2Radix;
    bool found = false;
    while (true)
    {
        decimalN2 = toDecimalNumber(N2, tmpRadix);
        if (decimalN2 < decimalN1)
        {
            tmpRadix++;
        }
        else if (decimalN2 == decimalN1)
        {
            found = true;
            break;
        }
        else
        {
            found = false;
            break;
        }
    }
#endif 

#if 0
    unsigned long long decimalN2 = 0;
    unsigned long long maxN2Radix = ULLONG_MAX;
    unsigned long long midN2Radix = 0;
    bool found = false;
    while (minN2Radix <= maxN2Radix)
    {
        midN2Radix = (minN2Radix + maxN2Radix) / 2;
        decimalN2 = toDecimalNumber(N2, midN2Radix);
        if (decimalN2 == decimalN1)
        {
            found = true;
            break;
        }
        else if (decimalN2 < decimalN1)
        {
            minN2Radix = midN2Radix + 1;
        }
        else
        {
            maxN2Radix = minN2Radix  - 1;
        }
    }
#endif

    // find radix for N2 s.t. N2 == N1
    if (found)
    {
        cout << tmpRadix << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }

    return 0;
}
