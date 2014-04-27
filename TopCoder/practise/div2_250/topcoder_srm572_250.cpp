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

// AC: 242pts
class EasyHomework
{
public:
    
    string determineSign(vector <int> A)
    {
        int n = A.size();
        vector<int> b(A.size()); 
        for (int i = 0; i < n; ++i)
        {
            if (A[i] > 0) b[i] = 1;
            else if (A[i] < 0) b[i] = -1;
            else b[i] = 0;
        }

        int ans = 1;
        for (int i = 0; i < n; ++i)
        {
            ans *= b[i];
        }

        if (ans == 1) return "POSITIVE";
        else if (ans == 0) return "ZERO";
        else return "NEGATIVE";
    }
};