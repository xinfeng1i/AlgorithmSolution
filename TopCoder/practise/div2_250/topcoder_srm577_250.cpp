#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

// AC code: 75pts
class EllysNewNickname
{
public:
    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch== 'i' || ch == 'o' || ch == 'u' || ch == 'y';
    }

    int getLength(string nickname)
    {
        int n = nickname.size();
        int cnt = 0;
        for (int i = 1; i < n; ++i)
        {
            if (isVowel(nickname[i-1]) && isVowel(nickname[i]))
            {
                cnt++; 
            }
               
        }
        return n - cnt;
    }
};
