#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

/*
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
*/

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

    queue<int> q;
    q.push(1);

    bool flag = false;
    int cur_level_num = 1;
    int cur_level_cnt = 0;
    int elem;
    while (!q.empty())
    {
        int next_level_num = 0;
        cur_level_cnt = 0;
        for (int i = 0; i < cur_level_num; ++i)
        {
            int elem = q.front();
            if (table[elem].size() == 0)
            {
                cur_level_cnt++;
            }
            else
            {
                for (int j = 0; j < table[elem].size(); ++j)
                {
                    q.push(table[elem][j]);
                }

                next_level_num += table[elem].size();
            }
            q.pop();
        }

        if (flag)
        {
            cout << " ";
        }
        else
        {
            flag = true;
        }
        cout << cur_level_cnt;
        
        cur_level_num = next_level_num;
    }
    cout << endl;
    return 0;
}
