#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class YahtzeeScore
{
public:

int maxPoints(vector<int> toss)
{
    vector<int> cnt(7, 0);
    for (int i = 0; i < toss.size(); ++i)
    {
        cnt[toss[i]]++;
    }

    int maxScore = 0;
    for (int i = 0; i <= 6; ++i)
    {
        if (cnt[i] * i > maxScore)
        {
            maxScore = cnt[i] * i;
        }
    }

    return maxScore;
}

};

