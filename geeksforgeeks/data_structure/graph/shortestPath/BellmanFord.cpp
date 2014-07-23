#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int INF = 1000000;
const int NIL = -1;
struct Edge
{
    int src_;
    int dest_;
    int weight_;

    Edge(int s, int d, int w):src_(s), dest_(d), weight_(w)
    {}
};

class Graph
{
private:
    int V_;
    int E_;
    vector<Edge> edges_;
public:
    Graph(int v, int e):V_(v), E_(e)
    {
        edges_.reserve(e);
    }

    void addEdge(int u, int v, int w)
    {
        edges_.push_back(Edge(u,v,w));
    }

public:
    friend int BellmanFord(const Graph& g, int src, vector<int>& dist, vector<int>& parent);
};


// Negative weights are found in BellmanFord Algorithm
// BellmanFord Algorithm works well than Dijkstra Algorithm for distributed
// System, because edges are considered one by one.
// ----------------------
// Time Complexity: O(VE)
int BellmanFord(const Graph& g, int src, vector<int>& dist, vector<int>& parent)
{
    int nNode = g.V_;
    int nEdge = g.E_;

    // INIT
    dist.resize(nNode); 
    for (int i = 0; i < nNode; ++i) dist[i] = INF;
    dist[src] = 0;
    parent.resize(nNode);
    for (int i = 0; i < nNode; ++i) parent[i] = NIL;

    // LOOP for |V| - 1 times, for each edge, RELAX
    for (int k = 0; k < nNode - 1; ++k)
    {
        for (size_t i = 0; i < g.edges_.size(); ++i)
        {
            Edge curEdge = g.edges_[i];
            int u = curEdge.src_;
            int v = curEdge.dest_;
            int w = curEdge.weight_;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
    
    // CHECK ONE MORE TIME, IF Can RELAX again, WRONG
    for (size_t i = 0; i < g.edges_.size(); ++i)
    {
        Edge curEdge = g.edges_[i];
        int u = curEdge.src_;
        int v = curEdge.dest_;
        int w = curEdge.weight_;
        if (dist[u] + w < dist[v])
        {
            cerr << "There is a NEGATIVE LOOP in the Graph" << endl;
            return -1;
        }
    }

    return 0;
}

void printPath(const vector<int>& parent, int src, int dest)
{
    if (parent[dest] == NIL)
    {
        printf(" %d", dest);
    }
    else
    {
        printPath(parent, src, parent[dest]);
        printf(" %d", dest);
    }
}

int main()
{
    Graph g(5, 8);
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);
    
    vector<int> dist;
    vector<int> parent;
    BellmanFord(g, 0, dist, parent);
    
    for (size_t i = 0; i < dist.size(); ++i)
    {
        cout << 0 << "-" << i << ":" << dist[i] << endl;
    }

    printf("\n\nShortest Path:\n\n");
    for (size_t i = 0; i < dist.size(); ++i)
    {
        printPath(parent, 0, i);
        printf("\n\n");
    }
}
