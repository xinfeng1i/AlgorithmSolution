#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool containSameDigits(long n1, long n2)
{
    int digits1[10] = {0};
    int digits2[10] = {0};
    string str1 = to_string(n1);
    string str2 = to_string(n2);
    if (str1.size() != str2.size())
    {
        return false;
    }

    for (int i = 0; i < str1.size(); ++i)
    {
        digits1[str1[i] - '0']++;
        digits2[str2[i] - '0']++;
    }

    for (int i = 0; i < 10; ++i)
    {
        if (digits1[i] != digits2[i])
        {
            return false;
        }
    }
    return true;
}


int main()
{
    long n = 1;
    while (true)
    {
        if (containSameDigits(n, 2 * n) && containSameDigits(n, 3 * n) &&
            containSameDigits(n, 4 * n) && containSameDigits(n, 5 * n) &&
            containSameDigits(n, 6 * n) )
        {
            cout << "result is: " << n << endl;
            break;
        }
        ++n;
    }
    return 0;
}
