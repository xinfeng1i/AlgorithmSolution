#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 15000;

vector<vector<int> > matrix;
vector<bool> visited;
void init(int n);
void dfs(int i);
int component();
vector<vector<int> > floyd();

void init(int n)
{
    matrix.resize(n+1);
    for (int i = 0; i < n + 1; ++i)
    {
        matrix[i].resize(n+1);
    }

    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            matrix[i][j] = 0;
        }
    }

    visited.resize(n+1);
    for (int i = 0; i < n + 1; ++i)
    {
        visited[i] = false;
    }
}

void dfs(int i)
{
    int n = visited.size() - 1;
    visited[i] = true;
    for (int j = 1; j < n + 1; ++j)
    {
        if (j != i && matrix[i][j] != 0 && !visited[j])
        {
            dfs(j);
        }
    }
}

int component()
{
    int n = visited.size() - 1;
    int cnt = 0;
    for (int i = 1; i < n + 1; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}

vector<vector<int> > floyd()
{
    int n = visited.size() - 1;


    // init 
    vector<vector<int> > ans(n + 1);
    for (int i = 0; i < n + 1; ++i)
    {
        ans[i].resize(n + 1, INF);
    }
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            if (matrix[i][j] == 1)
            {
                ans[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < n + 1; ++i)
    {
        ans[i][i] = 0;
    }

    // floyd
    for (int k = 1; k < n + 1; ++k)
    {
        for (int i = 1; i < n + 1; ++i)
        {
            for (int j = 1; j < n + 1; ++j)
            {
                int tmp = ans[i][k] + ans[k][j];
                if (tmp < ans[i][j])
                {
                    ans[i][j] = tmp;
                }
            }
        }
    }

    return ans;
}


int main()
{
    int n; 
    cin >> n;

    init(n);
    int s, e;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> s >> e;
        matrix[s][e] = 1;
        matrix[e][s] = 1;
    }

    int cmpts = component();

    //cout << cmpts << endl;
    if (cmpts > 1)
    {
        cout << "Error: " << cmpts << " components" << endl;
        return 0;
    }
    
    vector<vector<int> > ans = floyd();
    int maxLength = 0;
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            if (ans[i][j] < INF && ans[i][j] > maxLength)
            {
                maxLength = ans[i][j];
            }
        }
    }

    set<int> ret;
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            if (ans[i][j] == maxLength)
            {
                ret.insert(i);
                ret.insert(j);
            }
        }
    }

    for (set<int>::iterator it = ret.begin();
                            it != ret.end();
                            ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
