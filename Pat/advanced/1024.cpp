#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/* First Algorithm for pat_1024
 * BUG: unsigned long long is still small for parameter
 * We need more BIG NUMBER to solve this problem
 */
#if 0 // algorithm #1
unsigned long long reverseNumber(unsigned long long n)
{
    string str_n = to_string(n);
    reverse(str_n.begin(), str_n.end());
    return atoll(str_n.c_str());
}

bool isPalindromicNumber(unsigned long long n)
{
    return n == reverseNumber(n);
}

int main()
{
    unsigned long long N = 0;
    int K = 0;
    cin >> N >> K;

    if (isPalindromicNumber(N))
    {
        cout << N << endl;
        cout << 0 << endl;
        return 0;
    }

    int cnt = 0;
    do{
        N += reverseNumber(N); 
        cnt++;
    }while(!isPalindromicNumber(N) && cnt < K);

    cout << N << endl;
    cout << cnt << endl;
    return 0;
}
#endif // Algorithm #1

string addTwoStrings(const string& s1, const string& s2)
{
    string ret("");

    int digitSum = 0;
    int carry = 0;

    int i = s1.size() - 1;
    int j = s2.size() - 1;
    for ( ; i >=0 || j >= 0; i--, j--)
    {
        if (i < 0)
        {
            digitSum = s2[j] - '0';
        }
        else if (j < 0)
        {
            digitSum = s1[i] - '0';
        }
        else
        {
            digitSum = s1[i] - '0' + s2[j] - '0';
        }

        digitSum += carry;
        ret.insert(ret.begin(), digitSum % 10 + '0');
        carry = digitSum / 10;
    }
    
    if (carry != 0)
    {
        ret.insert(ret.begin(), carry + '0'); 
    }

    return ret;
}

bool isPanlindromic(const string& s)
{
    // base case
    if (s.size() == 0)
    {
        return true;
    }
    
    int sz = s.size();
    if (s[0] != s[sz - 1])
    {
        return false;
    }
    else
    {
        return isPanlindromic(s.substr(1, sz - 2));
    }
}

int main()
{
    long long N = 0;
    int K = 0;
    cin >> N >> K;
    string str_N = to_string(N);
    if (isPanlindromic(str_N))
    {
        cout << N << endl;
        cout << 0 << endl;
        return 0;
    }

    int cnt = 0;
    string tmp;
    do{
        tmp = str_N;
        reverse(str_N.begin(), str_N.end());
        str_N = addTwoStrings(tmp, str_N);
        cnt++;
    }while(!isPanlindromic(str_N) && cnt < K);
    cout << str_N << endl;
    cout << cnt << endl;
    return 0;
}
