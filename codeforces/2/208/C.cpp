#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int main()
{
    long n = 0;
    cin >> n;
    vector<long> cmd(n);
    for (long i = 0; i < n;++i)
    {
        cin >> cmd[i];
    }

    stack<long> s;
    queue<long> q;
    deque<long> d;

    for (long i = 0; i < n; ++i)
    {
        if (cmd[i] == 0)
        {
            int k = 0;
            string info("");
            if (!s.empty())
            {
                k++;
                info += " popStack"; 
            }
            if (!q.empty())
            {
                k++;
                info += " popQueue";
            }
            if (!d.empty())
            {
                k++;
                info += " popFront";
            }
            cout << k << info << endl;
            s = stack<long>();
            q = queue<long>();
            d.clear();
        }
        else
        {
            if (s.empty())
            {
                s.push(cmd[i]);
                cout << "pushStack" << endl;
                continue;
            }
            if (q.empty())
            {
                q.push(cmd[i]);
                cout << "pushQueue" << endl;
                continue;
            }
            if (d.empty())
            {
                d.push_front(cmd[i]);
                cout << "pushFront" << endl;
                continue;
            }

            long tmpmin = 1000000;
            char type;
            if (s.top() < tmpmin)
            {
                tmpmin = s.top();
                type = 's';
            }
            if (q.front() < tmpmin)
            {
                tmpmin = q.front();
                type = 'q';
            }
            if (d.front() < tmpmin)
            {
                tmpmin = d.front();
                type = 'd';
            }

            if (cmd[i] <= tmpmin)
            {
                d.push_back(cmd[i]);
                cout << "pushBack" << endl;
                continue;
            }
            else
            {
                if (type == 's')
                {
                    s.push(cmd[i]);
                    cout << "pushStack" << endl;
                }
                else if (type == 'q')
                {
                    q.push(cmd[i]);
                    cout << "pushQueue" << endl;
                }
                else
                {
                    d.push_front(cmd[i]);
                    cout << "pushFront" << endl;
                }

                continue;
            }
        }
    }
}
