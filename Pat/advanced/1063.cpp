#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int n = 0;
    //cin >> n;
    scanf("%d", &n);
    vector<set<long> > setList(n);

    long m = 0;
    long tmp = 0;
    for (int i = 0; i < n; ++i)
    {
        //cin >> m;
        scanf("%ld", &m);
        for (int j = 0; j < m; ++j)
        {
            //cin >> tmp;
            scanf("%ld", &tmp);
            setList[i].insert(tmp);
        }
    }

    int k = 0;
    //cin >> k;
    scanf("%d", &k);
    int s, e;

    vector<long> interSet(10000);
    vector<long> unionSet(20000);
    for (int i = 0; i < k; ++i)
    {
        //cin >> s >> e;
        scanf("%d %d", &s, &e);
        auto it1 = set_intersection(setList[s-1].begin(), setList[s-1].end(),
                                    setList[e-1].begin(), setList[e-1].end(),
                                    interSet.begin());
        int sz1 = it1 - interSet.begin();
        auto it2 = set_union(setList[s-1].begin(), setList[s-1].end(),
                             setList[e-1].begin(), setList[e-1].end(),
                             unionSet.begin());
        int sz2 = it2 - unionSet.begin();

        double rate = (double)sz1 / (double)sz2 * 100;

        printf("%0.1f%%\n", rate);
    }

    return 0;
}
