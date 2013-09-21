#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Graph
{
private:
    int nodeNum_;
    long edgeNum_;
    vector<set<int> > edges_;
    vector<bool> visited_;
public:
    Graph(int N, long M):nodeNum_(N), edgeNum_(M)
    {
        edges_.resize(N + 1);
        visited_.resize(N + 1);
    }
    void addEdge(int s, int e)
    {
        edges_[s].insert(e);
        edges_[e].insert(s); 
    }

    void setAllFalse()
    {
        for (int i = 0; i <= nodeNum_; ++i)
        {
            visited_[i] = false;
        }
    }
    void setTrue(int v)
    {
        visited_[v] = true;
    }

    void explore(int v)
    {
        visited_[v] = true;
        for (auto it = edges_[v].begin(); it != edges_[v].end(); ++it)
        {
            if (!visited_[*it])
            {
                explore(*it);
            }
        }
    }

    int cntConnectedParts(int excludedV)
    {
        int cnt = 0;
        for (int i = 1; i <= nodeNum_; ++i)
        {
            if (i != excludedV && !visited_[i])
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
    int start, end;
    for (long i = 0; i < M; ++i)
    {
        cin >> start >> end;
        g.addEdge(start, end);
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
