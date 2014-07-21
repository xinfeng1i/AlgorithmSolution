#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;


// SCC algorithm:
// STEP 1: First run DFS on the graph g, remember all the finishing time f[] of each node
// STEP 2: Second run DFS on the tranposed graph gr of g, this time in the for
//         loop travel all the nodes according to the decresing f[]
// STEP 3: Print all the components in STEP 2
class Graph
{
public:
    Graph(int n):V_(n)
    {
        adjList = new list<int>[n]; 
    }

    Graph(const Graph& other);

    void addEdge(int u, int v);

    Graph getTranspose() const;

    void printSCC();

    void DFSVisit(int src, vector<int>& visited);

    void printGraph();


private:
    void explore(int src, vector<int>& visited, stack<int>& curStack);
private:
    int V_;
    list<int>* adjList;
};

Graph::Graph(const Graph& other)
{
    V_ = other.V_;
    adjList = new list<int>[V_];
    for (int u = 0; u < V_; ++u)
    {
        for (auto it = other.adjList[u].begin(); it != other.adjList[u].end(); ++it)
        {
            int v = *it;
            adjList[u].push_back(v);
        }
    }
}

void Graph::addEdge(int u, int v)
{
    adjList[u].push_back(v);
}

void Graph::printGraph()
{
    for (int u = 0; u < V_; ++u)
    {
        cout << u << ":";
        for (auto it = adjList[u].begin(); it != adjList[u].end(); ++it)
        {
            int v = *it;
            cout << " " << v;
        }
        cout << "\n";
    }
}

Graph Graph::getTranspose() const
{
    Graph gr(V_);

    for (int u = 0; u < V_; ++u)
    {
        for (auto it = adjList[u].begin(); it != adjList[u].end(); ++it)
        {
            int v = *it;
            gr.adjList[v].push_back(u);
        }
    }

    return gr;
}


void Graph::explore(int src, vector<int>& visited, stack<int>& curStack)
{
    visited[src] = 1;

    for (auto it = adjList[src].begin(); it != adjList[src].end(); ++it)
    {
        int v = *it;
        if (!visited[v])
        {
            explore(v, visited, curStack);
        }
    }

    curStack.push(src);
}

void Graph::DFSVisit(int src, vector<int>& visited)
{
    visited[src] = 1;
    cout << src << " ";

    for (auto it = adjList[src].begin(); it != adjList[src].end(); ++it)
    {
        int v = *it;
        if (!visited[v])
        {
            DFSVisit(v, visited);
        }
    }
}

void Graph::printSCC()
{
    vector<int> visited(V_, 0);
    stack<int> s;

    // first DFS
    for (int u = 0; u < V_; ++u)
    {
        if (!visited[u])
        {
            explore(u, visited, s);            
        }
    }


    // get the transpose of the graph
    Graph gr(getTranspose());
    // gr.printGraph();
    
    // second DFS to get all the components
    for (int i = 0; i < V_; ++i) visited[i] = 0;
    while (!s.empty())
    {
        int u = s.top();        
        s.pop();

        if (!visited[u])
        {
            gr.DFSVisit(u, visited);
            cout << "\n";
        }
    }
}

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    //g.printGraph();

    g.printSCC();    
    return 0;
}

