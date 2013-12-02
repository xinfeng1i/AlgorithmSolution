#include <iostream>
#include <vector>

using namespace std;

const long MSIZE = 100000 + 5;
vector<long> ans;
vector<pair<long, int> > v[MSIZE];

/**
 * DFS to solve the problem
 * Original author: kia.masster
 * reimplemtation: python27 (add comments)
 *
 * Main Idea: dfs function return the number of edges which have weight 2. 
 *          1.It start by current node and the previous node of current
 *            node and the weight of these two, current node first define
 *            a temp variable 'sum = 0', 
 *          2.then find all the neighbours of current node but except 
 *            the prev node itself
 *            ----------------------------------------------------------
 *            1 ---- 2 ----5
 *            |\     |
 *            | \    |
 *            |  \   6
 *            3   4
 *
 *            for example if current node is 2, the prev node is 1, then 
 *            all neighbours(which is {1, 5, 6}) except the prev node (
 *            which is {1}) is {5, 6}
 *            -----------------------------------------------------------
 *
 *            order all the neighbours to find the edges(w=2) in 
 *            their branches, count by 'sum'
 *
 *          3.if all the branches cannot find these edges(w=2),which means
 *            sum == 0 && the current node and its prev node has the edge(w = 2)
 *            then we return the edge(prev-->cur) count(which is exactly 1). and
 *            all the branches under cur node has no edges(w=2), then the cur node
 *            is the first node we must repair it road to node first.
 *
 *          4.else sum != 0, we must find other edges(w = 2) in the branches under
 *            cur node, count them, no matter the edge prev--> cur is good or bad,
 *            we do not need to care. OR if the edge prev-->cur is good, then all
 *            we need to do is return edges count of all the branches under it.
 *
 */
int dfs(long cur, long prev, int weight)
{
    int sum = 0;
    for (long i = 0; i < v[cur].size(); ++i)
    {
        if (v[cur][i].first != prev)
        {
            sum += dfs(v[cur][i].first, cur, v[cur][i].second);
        }
    }

    if (sum == 0 && weight == 2)
    {
        ans.push_back(cur);
        return 1;
    }
    else
    {
        return sum;
    }
}

int main()
{
    long n;
    long s, e;
    int w;

    cin >> n;
    for (long i = 0; i < n - 1; ++i)
    {
        cin >> s >> e >> w;
        v[s].push_back(make_pair(e, w));
        v[e].push_back(make_pair(s, w));
    }

    dfs(1, -1, -1);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}

/**
 * Summary:
 * This is the first time I see the DFS algorithm can use by this way, very elegant
 * algorithm and code. Thanks to kia.masster
 */
