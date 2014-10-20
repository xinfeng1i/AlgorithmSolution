#include <iostream>
#include <string>
#include <set>
using namespace std;

int CountDigit(long long x)
{
    string s = to_string(x);
    set<char> myset;
    for (size_t i = 0; i < s.size(); ++i)
    {
        myset.insert(s[i]);
    }
    return myset.size();
}

int main()
{
    long long A;
    long long K;
    cin >> A >> K;

    if (CountDigit(A) <= K)
    {
        cout << 0 << endl;
        return 0;
    }
    
    long long B = A;
    while (CountDigit(B) > K)
    {
        B++;
    }

    long long C = A;
    while (CountDigit(C) > K && A - C <= B - A)
    {
        C--;
    }

    if (C < 0) cout << B - A << endl;
    else cout << min(B-A, A-C) << endl;

    return 0;
}
