#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int id_;
    vector<Node*> children;
}

int main()
{
    int n, m;
    cin >> n >> m;

    map<int, set<int> > childrenList;
    int parent, nChildren, child;
    for (int i = 0; i < m; ++i)
    {
        cin >> parent >> nChildren; 
        for (int j = 0; j < nChildren; ++j)
        {
            cin >> child;
            childrenList[parent].insert(child);
        }

    }

    vector<bool> created(n); 
    
}
