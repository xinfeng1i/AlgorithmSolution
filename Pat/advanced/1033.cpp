#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

struct Station
{
    double price_;
    int dist_;
public:
    bool operator< (const Station& other) const
    {
        return dist_ < other.dist_;
    }
};

FindNextStation(int canRunDist, int curStation, const vector<Station>& v)
{
    int ans = -1;
    for (int i = curStation + 1; i < v.size(); ++i)
    {
        if (v[i].dist_ <= canRunDist && v[i].price_ < v[curStation].price_)
        {
            ans = i;
        }
    }
    return ans;
}

int cmax, D, Davg, N;
int main()
{
    cin >> cmax >> D >> Davg >> N;
    vector<Station> v(N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%lf %d", &v[i].price_, &v[i].dist_);
    }
    sort(v.begin(), v.end());

    if (v[0].dist_ != 0)
    {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }

    int curDist = 0;
    int curGas = 0;
    int curStation = 0;
    int nextStation = -1;
    //如果当前油量能够行使到一个更便宜的加油站，then先行驶到再说
    double curCanRun = (curGas + 0.0) / (Davg + 0.0) + curDist;
    double maxCanRun = cmax * (Davg + 0.0);
    for (int i = curStation+1; i < N; ++i)
    {
        if (v[i].dist_ <= curCanRun && v[i].price_ < v[curStation].price_)
        {
            nextStation = i; 
        }
    }
    if (nextStation != -1)
    {
        curDist = v[nextStation].dist_;
        curGas -= (v[nextStation].dist_ - v[curStation].dist_) /(Davg + 0.0);
        curStation = nextStation;
    }
    // 如果加一些油能够到达更便宜的加油站，then加一些
    else if (FindNextStation(maxCanRun, curStation, v) != -1)
    {
               
    }
}
