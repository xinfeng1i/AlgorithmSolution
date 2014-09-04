#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int N, K;
string name1, name2;
int weight;
map<string, vector<string> > adjList;
map<string, vector<string> >::iterator it;
map<string, int> degree;
map<string, bool> visited;
map<string, int> ans;

int totalWeight = 0;
int maxWeight = 0;
int nMember = 0;
string curHead;

void DFS(string src)
{
    visited[src] = true;

    totalWeight += degree[src];
    nMember++;
    if (degree[src] > maxWeight)
    {
        maxWeight = degree[src];
        curHead = src;
    }
    else if (degree[src] == maxWeight && src < curHead)
    {
        curHead = src;
    }

    for (vector<string>::iterator it = adjList[src].begin(); it != adjList[src].end(); ++it)
    {
        string v = *it;
        if (!visited[v])
        {
            DFS(v);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> name1 >> name2 >> weight; 
        adjList[name1].push_back(name2);
        adjList[name2].push_back(name1);
        degree[name1] += weight;
        degree[name2] += weight;
        visited[name1] = false;
        visited[name2] = false;
    }
    
    for (auto it = adjList.begin(); it != adjList.end(); ++it)
    {
        if (!visited[it->first])
        {
            totalWeight = 0;
            maxWeight = 0;
            curHead = it->first;
            nMember = 0;

            DFS(it->first);

            if (totalWeight / 2 > K && nMember > 2)
            {
                ans[curHead] = nMember;
            }
        }
    }

    cout << ans.size() << endl;
    for (auto it = ans.begin(); it != ans.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}

/*
 * DFS algorithm, AC
 * But why not Union-Find algorithm cannot passed ?
 */
