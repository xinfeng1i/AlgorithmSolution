#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <climits>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> v(N, 0);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &v[i]);
    }

    int low = 0; 
    int high = 0;
    int cursum = v[0];
    int minDist = INT_MAX;

    bool flag = false;
    vector<pair<int, int> > ans;
    vector<pair<int, int> > ans2;
    while (low < N && high < N && low <= high)
    {
        // 如果当前和小于目标，high++;
        if (cursum < M)
        {
            if (high + 1 < N) cursum += v[high+1];
            high++;
        }
        // 如果当前和等于给定目标，记录结果；low++, high++;
        else if (cursum == M)
        {
            flag = true;
            ans.push_back(make_pair(low, high));
            if (high + 1 < N)
            {
                cursum = cursum - v[low] + v[high+1];
            }
            low++;
            high++;
        }
        // 如果当前和大于给定目标, ++low
        else if (cursum > M)
        {
            // 如果差值更小，清空之前的答案，记录当前答案; low++
            if (cursum - M < minDist)
            {
                minDist = cursum - M;
                ans2.clear(); 
                ans2.push_back(make_pair(low, high));

            }
            // 如果差值相等，直接记录结果即可, low++;
            else if (cursum - M == minDist)
            {
                ans2.push_back(make_pair(low, high));

            }

            // 如果只有一个数已经大于给定值，在++low的同时需要++high
            if (low == high)
            {
                low++;
                high++;
                if (low < N) cursum = v[low];
            }
            // 否则只需要更新high即可
            else if (low < high)
            {
                cursum = cursum - v[low];
                low++;
            }

        }
    }

    vector<pair<int, int> >::iterator it;
    if (flag)
    {
        for (it = ans.begin(); it != ans.end(); ++it)
        {
            printf("%d-%d\n", it->first+1, it->second+1);
        }
    }
    else 
    {
        for (it = ans2.begin(); it != ans2.end(); ++it)
        {
            printf("%d-%d\n", it->first+1, it->second+1);
        }
    }
    return 0;
}

