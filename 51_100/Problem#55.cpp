#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

bool isPalindromic(string s)
{
    if (s == "")
    {
        return true;
    }
    int sz = s.size();
    if (s[0] != s[sz-1])
    {
        return false;
    }
    else
    {
        return isPalindromic(s.substr(1,sz - 2));
    }
}

long long reverseLLinteger(long long n)
{
    long long rev = 0;
    while (n > 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}


bool isLychrel(long long n) 
{
    long long cnt = 0;
    do
    {
        n += reverseLLinteger(n);
        cnt++; 
    }while (!isPalindromic(to_string(n)) && cnt <= 50);
    
    return cnt > 50;
}

int main()
{
    const long long UP_BOUND = 10000;
    long long cntLychrel = 0;
    for (long long i = 1; i <= UP_BOUND; ++i)
    {
        if (isLychrel(i))
        {
            cntLychrel++;
        }
    }
    cout << "The number of lychrels below " << UP_BOUND
        << " is : " << cntLychrel << endl;
    return 0;
}

// Summany:
//
//  Nothing difficult, just a implementation problem, I didn't take much 
//  consideration about the parameter limit, use 'long' as integer type, which
//  cause the overflow and further more get the wrong answer.
//
//  It take massive effort to find the bug is about the integer overflow.
// 
// Lessions:
//  Be Careful about every parameter type you choose. find out the limits.
//  MAX_Int :       32767 (2^15 - 1)            2 Bytes     about 30000
//  MAX_LONG:       2147483647 (2^31 - 1)       4 Bytes     about 21 * 10^8
//  MAX_LONGLONG:   9223372036854775807(2^63-1) 8 Bytes     about 922 * 10^16
//
// created by python27, Sep. 12th 2013