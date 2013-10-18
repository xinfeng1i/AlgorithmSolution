#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

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

        // read every level nodes.
        for (int i = 0; i < cur_level_num; ++i)
        {
            int elem = q.front();

            // every node in the level with no any child, count into
            // current level leaves
            if (table[elem].size() == 0)
            {
                cur_level_cnt++;
            }
            // every node in the level with some children, the number
            // of children count into next level node of the tree
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

        // printf current level leaves number of nodes
        if (flag)
        {
            cout << " ";
        }
        else
        {
            flag = true;
        }
        cout << cur_level_cnt;
        
        // update the the number of nodes with next level number of nodes
        cur_level_num = next_level_num;
    }
    cout << endl;
    return 0;
}

// summary:
// 1. It seems that it's a tree data structure problem, but in fact
//    you really don't need to implement a tree data structrue.
// 2. I figure out that this is a BFS problem, but with a little different
//    since that you not only need to travel the whole tree with a queue
//    but also need to travel it by each level, so I have to set a var to
//    remember the number of node in current and next level, push and pop
//    every node in the each level, the update the current level number of
//    node.
// 3. A good problem.
