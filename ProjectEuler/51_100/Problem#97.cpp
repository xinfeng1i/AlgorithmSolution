#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const long long coefficient = 28433;
const long long power_c = 7830457;
const long long remainer = 10000000000LL;

/*
 * compute the last n digits Large Number N is:
 * N % (10^n);
 *
 * besides, mod law:
 * (a + b) mod n = ((a mod n) + (b mod n)) mod n;
 * (a * b) mod n = ((a mod n) * (b mod n)) mod n;
 *
 * This can be used to compute Large Number Problem
 *
 */
int main()
{
    long long result = coefficient;
    for (int i = 1; i <= power_c; ++i)
    {
        result = (result * 2) % remainer;
    }
    cout << (result + 1) % remainer << endl;
    return 0;
}
