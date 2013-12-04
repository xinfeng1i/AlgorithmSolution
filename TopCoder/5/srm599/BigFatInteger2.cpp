// BEGIN CUT HERE

// END CUT HERE
#line 5 "BigFatInteger2.cpp"
#include <cstdlib>  
#include <cctype>  
#include <cstring>  
#include <cstdio>  
#include <cmath>  
#include <algorithm>  
#include <vector>  
#include <string>  
#include <iostream>  
#include <sstream>  
#include <map>  
#include <set>  
#include <queue>  
#include <stack>  
#include <fstream>  
#include <numeric>  
#include <iomanip>  
#include <bitset>  
#include <list>  
#include <stdexcept>  
#include <functional>  
#include <utility>  
#include <ctime>  
using namespace std;
class BigFatInteger2 
{
public:
map<long long, long long> divideNumber(long long n)
{
    map<long long, long long> cnt;
    if (isPrime(n))
    {
        cnt[n] = 1;
        return cnt;
    }

    long long cur = 2;
    while (n != 1)
    {
        if (!isPrime(cur))
        {
            cur++;
            continue;
        }
        else
        {
            if (n % cur != 0)
            {
                cur++;
                continue;
            }
            else
            {
                do
                {
                    n /= cur;     
                    cnt[cur]++;
                }while(n % cur == 0);
            }
        }
    }

    return cnt;
}

string isDivisible(int A, int B, int C, int D)
{
    map<long long, long long> ans1, ans2;
    ans1 = divideNumber(A);
    ans2 = divideNumber(C);

    map<long long, long long>::iterator it1, it2; 
    for (it2 = ans2.begin(); it2 != ans2.end(); ++it2)
    {
        if (ans1.count(it2->first) == 0)
        {
            return "not divisible";
        }
        else
        {
            if (ans1[it2->first] * B < ans2[it2->first] * D)
            {
                return "not divisible";
            }
        }
    }

    return "divisible";

}

};

// BEGIN CUT HERE  
int main()  
{  
        BigFatInteger2 ___test;  
        ___test.run_test(-1);  
        return 0;  
}  
// END CUT HERE 
