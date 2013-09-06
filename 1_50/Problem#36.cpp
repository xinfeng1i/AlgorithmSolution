#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>

using namespace std;

bool isPalindromic(string s)
{
    // base case
    if (s.size() == 0)
    {
        return true;
    }
    
    if (s[0] == s[s.size() - 1])
    {
        return isPalindromic(s.substr(1, s.size()-2)); 
    }
    else
    {
        return false;
    }
}

string decimalToBinary(long long n)
{
    string result("");
    do
    {
        if ((n & 1) == 0)
        {
            result += "0";
        }
        else
        {
            result += "1";
        }

        n >>= 1;
    }while (n);

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    clock_t time_begin = clock();

    const long long UP_LIMIT = 1000000;

    long long sum = 0;
    for (long long i = 0; i < UP_LIMIT; i++)
    {
        if ( isPalindromic(to_string(i)) 
                && isPalindromic(decimalToBinary(i)) )
        {
            cout << i << endl;
            sum += i;
        }
    }
    cout << "The sum of numbers which are palindromic both in decimal " <<
        "and binary form is : " << sum << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << time_cost << endl;
    return 0;
}
