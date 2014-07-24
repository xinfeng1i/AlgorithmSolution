#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int INF = 1000000;
const int NIL = -1;

struct Node
{
    int id_;
    int weight_;

    Node(int id, int w):id_(id), weight_(w)
    {}
};

class Graph
{
private:
    int V_;
    list<Node>* adjList;
public:
    Graph(int v):V_(v)
    {
        adjList = new list<Node>[v];
    }

    ~Graph()
    {
        delete[] adjList;
    }

    void addEdge(int u, int v, int weight)
    {
        adjList[u].push_back(Node(v, weight));
    }

    friend stack<int> topoSort(const Graph& g);
    friend void topoSortRecursively(const Graph& g, deque<bool>& visited, stack<int>& s, int u);
    friend void shortestPath(const Graph& g, int src, vector<int>& dist, vector<int>& parent);
};

stack<int> topoSort(const Graph& g)
{
    int n = g.V_;
    stack<int> s;
    deque<bool> visited(n, false);
    // This is a typical DFS traversal
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            topoSortRecursively(g, visited, s, i);
        }
    }
    return s;
}

// This function is a typical EXPLORE process in DFS
// Except that after every one's neighbor been called recursively
// the current node need to be push to the stack
// In Fact, when visited[u] = true, this is the start time 
//          when s.push(u), this is the ending time, According to CLRS
void topoSortRecursively(const Graph& g, deque<bool>& visited, stack<int>& s, int u)
{
    visited[u] = true;  // GRAY
    list<Node>::iterator it;
    for (it = g.adjList[u].begin(); it != g.adjList[u].end(); ++it)
    {
        int v = it->id_;
        int w = it->weight_;
        if (!visited[v])
        {
            topoSortRecursively(g, visited, s, v);
        }
    }
            
    s.push(u);  // BLACK
}

// The basic idea is
// First get the toposort of the graph
// Then relax each edge one by one according to the toposort of nodes
// Time Complexity: O(V+E)
void shortestPath(const Graph& g, int src, vector<int>& dist, vector<int>& parent)
{
    int n = g.V_;
    dist.resize(n); for (int i = 0; i < n; ++i) dist[i] = INF;
    dist[src] = 0;
    parent.resize(n); for (int i = 0; i < n; ++i) parent[i] = NIL;
    stack<int> s = topoSort(g);
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        
        list<Node>::iterator it;
        for (it = g.adjList[u].begin(); it != g.adjList[u].end(); ++it)
        {
            int v = it->id_;
            int w = it->weight_;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
}

void printPath(vector<int> parent, int dest)
{
    if (parent[dest] == NIL)
    {
        printf(" %d", dest);
    }
    else
    {
        printPath(parent, parent[dest]);
        printf(" %d", dest);
    }
}

int main()
{
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int s = 1;
    
    vector<int> dist;
    vector<int> parent;
    shortestPath(g, s, dist, parent);

    for (int i = 0; i < 6; ++i)
    {
        cout << s << "-" << i << " : ";
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

    for (int i = 0; i < 6; ++i)
    {
        cout << "To " << i << " : ";
        printPath(parent, i);
        cout << "\n";
    }

    return 0;
}
