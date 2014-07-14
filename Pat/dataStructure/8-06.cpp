#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 105;
int parent[N];
int rank2[N];

void MakeSet(int i)
{
    parent[i] = i;
    rank2[i] = 0;
}

int FindSet(int x)
{
    if (parent[x] != x)
    {
        parent[x] = FindSet(parent[x]);
        return parent[x];
    }
    else
    {
        return x;
    }
}

void UnionSet(int x, int y)
{
    int rootx = FindSet(x);
    int rooty = FindSet(y);
    if (rank2[rootx] > rank2[rooty])
    {
        parent[rooty] = rootx;
    }
    else
    {
        parent[rootx] = rooty;
        if (rank2[rootx] == rank2[rooty])
        {
            rank2[rooty] += 1;
        }
    }
}

struct Edge
{
    int start_;
    int end_;
    int cost_;
    int state_;

    bool operator< (const Edge& tmp) const
    {
        if (cost_ != tmp.cost_)
        {
            return cost_ < tmp.cost_;
        }
        else if (start_ != tmp.start_)
        {
            return start_ < tmp.start_;
        }
        else
        {
            return end_ < tmp.end_;
        }
    }
};

int main()
{
    for (int i = 0; i < N; ++i)
    {
        MakeSet(i);
    }

    vector<Edge> v;
    Edge tmp;
    int n; 
    cin >> n;
    for (int i = 0; i < n*(n-1)/2; ++i)
    {
        cin >> tmp.start_ >> tmp.end_ >> tmp.cost_ >> tmp.state_;
        if (tmp.state_ == 0)
        {
            v.push_back(tmp);
        }
        else
        {
            if (FindSet(tmp.start_) != FindSet(tmp.end_))
            {
                UnionSet(tmp.start_, tmp.end_);
            }
        }
    }
    
    int ans = 0;
    sort(v.begin(), v.end());
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        Edge edge = *it;
        if (FindSet(edge.start_) != FindSet(edge.end_))
        {
            UnionSet(edge.start_, edge.end_);
            ans += edge.cost_;
        }
    }
    
    cout << ans << endl;

    return 0;
}

