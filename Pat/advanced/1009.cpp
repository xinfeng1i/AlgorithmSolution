#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <cmath>
using namespace std;

const double EPS = 1e-9;
int main()
{
    int K1 = 0;
    cin >> K1;
    vector<pair<int, double> > p1(K1, pair<int, double>(0, 0.0));
    for (int i = 0; i < K1; ++i)
    {
        cin >> p1[i].first >> p1[i].second;
    }

    int K2 = 0;
    cin >> K2;
    vector<pair<int, double> > p2(K2, pair<int, double>(0, 0.0));
    for (int j = 0; j < K2; ++j)
    {
        cin >> p2[j].first >> p2[j].second;
    }


    map<int, double> result;
    pair<int, double> tmp(0, 0.0);
    for (int i = 0; i < K1; ++i)
    {
        for(int j = 0; j < K2; ++j)
        {
            tmp.first = p1[i].first + p2[j].first;
            tmp.second = p1[i].second * p2[j].second;
            result[tmp.first] += tmp.second;
        }
    }
    
    // erase zero-items
    for (auto it = result.begin(); it != result.end(); ++it)
    {
        if (abs(it->second) < EPS)
        {
            result.erase(it);
        }
    }

    long sz = result.size();
    cout << sz;
    for (auto it = result.rbegin(); it != result.rend(); ++it)
    {
        cout << " " << it->first << " ";
        printf("%0.1f", it->second);
    }
    cout << endl;

    return 0;
}
