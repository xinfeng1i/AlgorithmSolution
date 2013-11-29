#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


long n;
vector<vector<int> > matrix(n+1, vector<int>(n+1, 0));
vector<bool> visited(n+1);
vector<int> path;

void dfs(long i)
{
    visited[i] = true;
    for (long j = 1; j <= n; ++j)
    {
        if (matrix[i][j] != 0 && !visited[j])
        {
            visited[j] = true;
            path.push_back(j);
            if (j == 1)
            {
                return;
            }
            else
            {
                dfs(j);
            }
        }
    }
}

void resetVisited()
{
    for (long i = 0; i <= n; ++i)
    {
        visited[i] = false;
    }
}

void resetPath()
{
    path.clear();
}


int main()
{
    cin >> n;
    matrix.resize(n+1);
    for (long i = 0; i <= n; ++i)
    {
        matrix[i].resize(n+1);
    }

    visited.resize(n+1);

    long start, end;
    int state;
    for (long i = 1; i <= n - 1; ++i)
    {
        cin >> start >> end >> state;
        matrix[start][end] = state;
        matrix[end][start] = state;
    }

#if 0
    cout << "matrix" << endl;
    for (long i = 1; i <= n; ++i)
    {
        for (long j = 1; j <=n; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
#endif 
    vector<vector<long> > paths(n+1);

    for (long i = 2; i <= n; ++i)
    {
        paths[i].push_back(i);
    }
    
    for (long i = 2; i <= n; ++i)
    {
        resetVisited();
        resetPath();
        dfs(i);
        for (long k = 0; k < path.size(); k++)
        {
            paths[i].push_back(path[k]);
        }
    }

#if 0
    // cout paht
    for (long i = 2; i <= n; ++i)
    {
        cout << i << " paths:" << endl;
        for (long j = 0; j < paths[i].size(); ++j)
        {
            cout << paths[i][j] << " ";
        }
        cout << endl;
    }
#endif
    vector<vector<long> > finalPaths(n+1);
    for (long i = 2; i <= n; ++i)
    {
        vector<long> tmp;
        
        int j = 0;
        while (paths[i][j] != 1)
        {
            tmp.push_back(paths[i][j]);
            j++;
        }

        tmp.push_back(1);

        for (long k = 0; k < tmp.size(); ++k)
        {
            finalPaths[i].push_back(tmp[k]);
        }
    }
#if 0
    // cout paht
    for (long i = 2; i <= n; ++i)
    {
        cout << i << " paths:" << endl;
        for (long j = 0; j < finalPaths[i].size(); ++j)
        {
            cout << finalPaths[i][j] << " ";
        }
        cout << endl;
    }
#endif

    // Todo: handle the key part
    vector<long> cnt(n+1, 0);
    for (long i = 2; i <= n; ++i)
    {
        vector<long> tmp(finalPaths[i].begin(), finalPaths[i].end());
        for (long k = 0; k + 1 < tmp.size(); ++k)
        {
            long s = tmp[k];
            long e = tmp[k+1];
            if (matrix[s][e] == 2)
            {
                cnt[i]++;
            }
        }
    }

    auto maxCntIter = max_element(cnt.begin(), cnt.end());
    int maxIndex = maxCntIter - cnt.begin();
    for (long k = 0; k < finalPaths[maxIndex].size(); ++k)
    {
        long s = finalPaths[maxIndex][k];
        long e = finalPaths[maxIndex][k+1];
        if (matrix[s][e] == 2)
        {
            matrix[s][e] = 1;
        }
    }

    return 0;
}
