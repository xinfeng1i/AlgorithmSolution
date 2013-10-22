#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
private:
    int nodeNum_;
    long edgeNum_;
    vector<int> visited_;
    vector<vector<int> > edges_;
public:
    Graph(int N, long M):nodeNum_(N), edgeNum_(M)
    {
        visited_.resize(N + 1);
        edges_.resize(N + 1);
        for (int i = 0; i < N + 1; ++i)
        {
            edges_[i].resize(N + 1);
        }
        
        for (int i = 0; i < N + 1; ++i)
        {
            for (int j = 0; j < N + 1; ++j)
            {
                edges_[i][j] = 0;
            }
        }
    }

    void addEdge(int start, int end)
    {
        edges_[start][end] = 1;    // No-directed graph, the adjancency matrix
        edges_[end][start] = 1;     // is symmetric
    }

    void setAllFalse()
    {
        for (int i = 1; i <= nodeNum_; ++i)
        {
            visited_[i] = 0;
        }
    }

    void setTrue(int v)
    {
        visited_[v] = 1;
    }

    void explore(int v)
    {
        visited_[v] = 1;
        for (int j = 1; j <= nodeNum_; ++j)
        {
            if (edges_[v][j] == 1 && !visited_[j])
            {
                explore(j);
            }
        }
    }

    int cntConnectedParts(int excluedV)
    {
        int cnt = 0;
        for (int i = 1; i <= nodeNum_; ++i)
        {
            if (i != excluedV && !visited_[i])
            {
                explore(i);
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    int N = 0;
    long M = 0;
    int K = 0;
    cin >> N >> M >> K;

    Graph g(N, M);
    int s, e;
    for (long i = 0; i < M; ++i)
    {
        cin >> s >> e;
        g.addEdge(s, e);
    }

    int v = 0;
    for (int i = 0; i < K; ++i)
    {
        cin >> v;
        g.setAllFalse();
        g.setTrue(v);
        int d = g.cntConnectedParts(v);
        cout << d - 1 << endl;
    }

    return 0;
}
