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

// AC: 245pts
class TheSwapsDivTwo
{
public:
    int find(vector <int> sequence)
    {
        set<vector<int> > s;
        int n = sequence.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                vector<int> tmp(sequence.begin(), sequence.end());
                swap(tmp[i], tmp[j]); 
                s.insert(tmp);
            }
        }

        return s.size();
    }
};