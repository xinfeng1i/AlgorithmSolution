#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#define NINF -10000
using namespace std;

struct adjListNode
{
    int v;
    int weight;
    
    adjListNode(int vv, int w):v(vv), weight(w){}
};

class Graph
{
private:
    int V;
    list<adjListNode>* adjList;
private:
    void topoSortFrom(int u, bool visited[], stack<int>& s);
public:
    Graph(int n);
    void addEdge(int u, int v, int w);
    void longestPath(int src);
};

Graph::Graph(int n):V(n)
{
    adjList = new list<adjListNode>[n];
}
void Graph::addEdge(int u, int v, int w)
{
    adjList[u].push_back(adjListNode(v, w));
}

// topo sort from node u
void Graph::topoSortFrom(int u, bool visited[], stack<int>& s)
{
    visited[u] = true;
    list<adjListNode>::iterator it;
    for (it = adjList[u].begin(); it != adjList[u].end(); ++it)
    {
        int v = it->v;
        if (!visited[v])
        {
            topoSortFrom(v, visited, s);
        }
    }
    s.push(u);
}

void Graph::longestPath(int src)
{
    // topo sort
    bool visited[V];
    stack<int> s;
    for (int i = 0; i < V; ++i) visited[i] = false;
    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            topoSortFrom(i, visited, s);
        }
    }
    
    // find longest path
   vector<int> dist(V, NINF); 
   dist[src] = 0;

   while (!s.empty())
   {
        int u = s.top();
        s.pop();

        list<adjListNode>::iterator it;
        for (it = adjList[u].begin(); it != adjList[u].end(); ++it)
        {
            int v = it->v;
            int weight = it->weight;
            if (dist[u] != NINF && dist[v] < dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
            }
        }
   }

   cout << "The longest path dist from node " << src << "is : " << endl;
   for(int i = 0; i < V; ++i)
   {
       dist[i] == NINF ? cout << " NINF" : cout <<" " << dist[i];
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
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int s = 1;
    g.longestPath(s);

    return 0;
}
