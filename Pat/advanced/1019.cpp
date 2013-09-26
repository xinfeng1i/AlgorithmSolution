#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <deque>
using namespace std;


deque<long> toDifferentRadix(long n, long b)
{
    deque<long> result;    
    
    do{
        long r = n % b;
        result.push_front(r);
        n /= b;
    }while(n != 0);

    return result;
}

bool isPalindromic(deque<long> d)
{
    long first = 0;
    long last = d.size() - 1;
    for (; first < last; first++, last--)
    {
        if (d[first] != d[last])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    long n, b;
    cin >> n >> b;
    deque<long> ans = toDifferentRadix(n, b);
    bool palindromic = isPalindromic(ans);

    if (palindromic)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    bool flag = false;
    for (auto it = ans.begin(); it != ans.end(); ++it)
    {
        if (flag)
        {
            cout << " ";
        }
        else
        {
            flag = true;
        }
        cout << *it;
    }
    cout << endl;
   
    return 0;
}

// Be careful about the expression of different radix
//            about the symbols of of different radix
// IntegerToDifferentRadix using do...while loop is better 
