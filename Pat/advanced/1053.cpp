#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node
{
    int ID_;
    int weight_;
    vector<Node*> pChildren;

    Node(int id, int w):ID_(id), weight_(w)
    {}
};

struct cmpVector
{
    bool operator()(const vector<int>& v1, const vector<int>& v2) const
    {
        size_t k = min(v1.size(), v2.size());

        for (size_t i = 0; i < k; ++i)
        {
            if (v1[i] > v2[i])
            {
                return true; 
            }
            else if (v1[i] < v2[i])
            {
                return false;
            }
            else
            {
                continue;
            }
        }
        return v1.size() > v2.size();
    }
};

vector<vector<int> > globalPaths;

void DFS_Visit(Node* root, int curSum, int globalSum, vector<int> path)
{
    if (root == NULL) return;

    // curNode is leaf node
    if (root->pChildren.size() == 0)
    {
        path.push_back(root->weight_);
        if (curSum + root->weight_ == globalSum)
        {
            globalPaths.push_back(path);
        }
        return;
    }

    // if curnode is internal node, recursively
    path.push_back(root->weight_);
    for (size_t i = 0; i < root->pChildren.size(); ++i)
    {
        Node* tmp = root->pChildren[i];
        DFS_Visit(tmp, curSum + root->weight_, globalSum, path);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, m, s;
    cin >> n >> m >> s;

    vector<int> weight(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> weight[i];
    }

    // init the array of node*
    vector<Node*> nodes(n);
    for (int i = 0; i < n; ++i)
    {
        nodes[i] = new Node(i, weight[i]);
    }
    
    int curID; int nNeighbor; int neighbor;
    for (int i = 0; i < m; ++i)
    {
        cin >> curID >> nNeighbor;
        for (int j = 0; j < nNeighbor; ++j)
        {
            cin >> neighbor;
            (nodes[curID]->pChildren).push_back(nodes[neighbor]);
        }
    }

    Node* root = nodes[0];
    vector<int> path;
    DFS_Visit(root, 0, s, path);

    sort(globalPaths.begin(), globalPaths.end(), cmpVector());

    for (size_t i = 0; i < globalPaths.size(); ++i)
    {
        bool isFirst = true;
        for (size_t j = 0; j < globalPaths[i].size(); ++j)
        {
            if (isFirst) isFirst = false;
            else cout << " ";
            cout << globalPaths[i][j];
        }
        cout << endl;
    }

    return 0;

}

