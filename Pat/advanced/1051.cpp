#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);

    for (int i = 0; i < k; ++i)
    {
        // read pop sequence
        vector<int> popSeq(n);
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &popSeq[j]);
        }

        bool flag = false;
        int num = 1;
        int cur_pop = 0;
        stack<int> ss;
        while (true)
        {
            if (num > n)
            {
                flag = false;
                break;
            }

            while ( num <= n && ss.size() < m &&
                    (ss.size() == 0 || ss.top() != popSeq[cur_pop]) )
            {
                //cout << "Push:" << num << endl;
                ss.push(num++);
            }

            if (ss.size() == m && ss.top() != popSeq[cur_pop])
            {
                flag = false;
                break;
            }

            if (ss.size() > m)
            {
                flag = false;
                break;
            }

            while (ss.size() > 0 && cur_pop < n &&
                   ss.top() == popSeq[cur_pop])
            {
                //cout << "Pop:" << ss.top() << endl;
                ss.pop();
                cur_pop++;
            }

            if (ss.size() == 0 && cur_pop == n)
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

    }

    return 0;
}
