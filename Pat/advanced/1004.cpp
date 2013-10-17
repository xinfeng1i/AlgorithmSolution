#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int id_;
    vector<Node*> children_;
    Node(int id):id_(id)
    {}
}

int main()
{
    int n, m;
    cin >> n >> m;

    map<int, vector<int> > table;
    int id, k, child;
    for (int i = 0; i < m; ++i)
    {
        cin >> id >> k;
        for (int j = 0; j < k; ++j)
        {
            cin >> child;
            table[id].push_back(child);
        }
    }

    Node* root = new Node(1);
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = table[q.front()->id_].size();
        for (int i =  0; i < sz; ++i)
        {
            Node* pnode = new Node(table[q.front()->id_][i]);
            q.front()->children_.push_back(pnode);
            q.push(pnode);
        }
        q.pop();
    }


}
