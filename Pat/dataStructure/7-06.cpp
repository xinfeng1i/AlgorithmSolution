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

struct Country
{
    int goldNum;
    int totalNum;
    int population;
};

#if 0
int main()
{
    freopen("pat_data-structure_706data.txt", "r", stdin);
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    vector<Country> v(n);
    vector<int> v1(n);
    vector<int> v2(n);
    vector<double> v3(n);
    vector<double> v4(n);
    int tmpGoldNum, tmpTotalNum; 
    double tmpPopulation;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d %d", &v[i].goldNum, &v[i].totalNum, &v[i].population);
        v1[i] = v[i].goldNum;
        v2[i] = v[i].totalNum;
        v3[i] = v[i].goldNum / (double)v[i].population;
        v4[i] = v[i].totalNum / (double)v[i].population;
    }
    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end(), greater<int>());
    sort(v3.begin(), v3.end(), greater<double>());
    sort(v4.begin(), v4.end(), greater<double>());

    int tmp;
    bool isFirst = true;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &tmp);
        int minRank = 300;
        int minComp = 0;
        int rank = 0;
        for (int i = 0; i < v1.size(); ++i)
        {
            rank = lower_bound(v1.begin(), v1.end(), v[tmp].goldNum, greater<int>()) - v1.begin() + 1;
            if (rank < minRank) { minRank = rank; minComp = 1;}
        }
        for (int i = 0; i < v2.size(); ++i)
        {
            rank = lower_bound(v2.begin(), v2.end(), v[tmp].totalNum, greater<int>()) - v2.begin() + 1;
            if (rank < minRank) { minRank = rank; minComp = 2;}
        }
        for (int i = 0; i < v3.size(); ++i)
        {
            rank = lower_bound(v3.begin(), v3.end(), v[tmp].goldNum / (double)v[tmp].population, greater<double>()) - v3.begin() + 1;
            if (rank < minRank) { minRank = rank; minComp = 3;}
        }
        for (int i = 0; i < v4.size(); ++i)
        {
            rank = lower_bound(v4.begin(), v4.end(), v[tmp].totalNum / (double)v[tmp].population, greater<double>()) - v4.begin() + 1;
            if (rank < minRank) { minRank = rank; minComp = 4;}
        }
        if (isFirst)
        {
            printf("%d:%d", minRank, minComp);
            isFirst = false;
        }
        else
        {
            printf(" %d:%d", minRank, minComp);
        }
    }
    printf("\n");
    return 0;
}
#endif //0