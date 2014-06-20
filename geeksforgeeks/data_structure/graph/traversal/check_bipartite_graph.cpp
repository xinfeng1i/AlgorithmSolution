#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <queue>
using namespace std;

class Graph
{
private:
    int V;
    list<int>* adjList;
public:
    Graph(int n);
    void addEdge(int u, int v);
    bool isBipartiteGraph(int src);
};

Graph::Graph(int n):V(n)
{
    adjList = new list<int>[n];
}

void Graph::addEdge(int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

bool Graph::isBipartiteGraph(int src)
{
    vector<int> color(V, -1);
    queue<int> q;

    color[src] = 1;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        list<int>::iterator it;
        for (it = adjList[u].begin(); it != adjList[u].end(); ++it)
        {
            int v = *it;

            // if have not been colored, color it with a different color
            if (color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
            }
            // if have been colored && color is equal to its neighbor, false
            else if (color[v] == color[u])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    /*
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    */
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 0);

    bool ans = g.isBipartiteGraph(0);

    if (ans) cout << "Yes" << endl;
    else cout << "no" << endl;

    return 0;
}
