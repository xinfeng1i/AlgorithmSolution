#include <iostream>
#include <string>
using namespace std;

bool IsLeapYear(long long x)
{
    return ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0));
}

int main()
{
    long long A, B;
    cin >> A >> B;
    long long cnt = 0;

    long long AA = A;
    long long BB = B;
    while (AA % 4 != 0) AA++;
    while (BB % 4 != 0) BB--;
    if (AA <= BB) cnt += (BB - AA) / 4 + 1;

    long long AAA = A;
    long long BBB = B;
    while (AAA % 100 != 0) AAA++;
    while (BBB % 100 != 0) BBB--;
    if (AAA <= BBB) cnt -= (BBB - AAA) / 100 + 1;

    long long AAAA = A;
    long long BBBB = B;
    while (AAAA % 400 != 0) AAAA++;
    while (BBBB % 400 != 0) BBBB--;
    if (AAAA <= BBBB) cnt += (BBBB - AAAA) / 400 + 1;

    cout << cnt << endl;

    return 0;
}

