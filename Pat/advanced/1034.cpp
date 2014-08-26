#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

struct Edge
{
    string name1;
    string name2;
    int weight;
};

int N, K;
map<string, int> myrank;
map<string, string> parent;
map<string, int> degree;

void MakeSet(const string& x)
{
    myrank[x] = 0;
    parent[x] = x;
}

string Find(const string& x)
{
    if (x != parent[x])
    {
        parent[x] = Find(parent[x]);
    }
    return parent[x];
}

void Union(const string& rootx, const string& rooty)
{
    if (myrank[rootx] < myrank[rooty])
    {
        parent[rootx] = rooty;
    }
    else
    {
        parent[rooty] = rootx;
        if (myrank[rootx] == myrank[rooty])
        {
            myrank[rootx] += 1;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> N >> K;

    vector<Edge> v(N);
    string name1, name2; int weight;
    for (int i = 0; i < N; ++i)
    {
        cin >> name1 >> name2 >> weight;
        v[i].name1 = name1;
        v[i].name2 = name2;
        v[i].weight = weight;
        parent[name1] = name1;
        parent[name2] = name2;
        myrank[name1] = 0;
        myrank[name2] = 0;
        degree[name1] += weight;
        degree[name2] += weight;
    }

    string root1, root2;
    for (int i = 0; i < N; ++i)
    {
        name1 = v[i].name1;
        name2 = v[i].name2;
        weight = v[i].weight;
        root1 = Find(name1);
        root2 = Find(name2);
        if (root1 != root2) Union(name1, name2);
    }

    map<string, string>::iterator it;
    set<string> allparents;
    for (it = parent.begin(); it != parent.end(); ++it)
    {
        //cout << it->first << " parent: " << it->second << endl;
        allparents.insert(it->second);
    }

    map<string, int> ans;
    int ansNum = 0;
    for (set<string>::iterator iter = allparents.begin(); iter != allparents.end(); ++iter)
    {
        string curParent = *iter;
        int nMember = 0;
        int curWeight = 0;
        string curBang;
        int totalWeight = 0;
        for (it = parent.begin(); it != parent.end(); ++it)
        {
            if (it->second == curParent)
            {
                nMember++;
                totalWeight += degree[it->first];
                if (degree[it->first] > curWeight)
                {
                    curWeight = degree[it->first];
                    curBang = it->first;
                }
                else if (degree[it->first] == curWeight && it->first < curBang)
                {
                    curWeight = degree[it->first];
                    curBang = it->first;
                }
            }
        }
        totalWeight /= 2;
        if (totalWeight > K && nMember > 2)
        {
            //cout << curBang << " " << nMember << endl;
            ans[curBang] = nMember;
            ansNum++;
        }
    }

    cout << ansNum << endl;
    for (map<string, int>::iterator it = ans.begin(); it != ans.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    
    return 0;
}
