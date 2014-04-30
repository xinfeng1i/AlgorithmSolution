#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
using namespace std;

struct city
{
    int x;
    int y;
    long p;
    double dist;
};

struct cmpCity
{
    bool operator()(const city& a, const city& b)
    {
        return a.dist < b.dist;
    }
};

int main()
{
    //freopen("input.txt", "r", stdin);

    int n;
    long s;
    cin >> n >> s;
    vector<city> v(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].x >> v[i].y >> v[i].p;
        v[i].dist = sqrt(double(v[i].x * v[i].x + v[i].y * v[i].y));
        cnt += v[i].p;
    }

    if (s + cnt < 1000000)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        sort(v.begin(), v.end(), cmpCity());
        double ans_dist = 0.0;
        for (int i = 0; i < n; ++i)
        {
            if (s >= 1000000) break;
            s += v[i].p;
            ans_dist = v[i].dist;
        }
        
        printf("%f\n", ans_dist);
        return 0;
    }
}
