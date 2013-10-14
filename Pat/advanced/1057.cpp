#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    freopen("1057data.txt", "r", stdin);

    long n;
    cin >> n;

    stack<long> S;
    multiset<long> ordered;
    string input;
    long key;
    for (long i = 0; i < n; ++i)
    {
        cin >> input;
        if (input == "Push")
        {
            cin >> key;
            S.push(key);
            ordered.insert(key);
        }
        else if (input == "Pop")
        {
            if (S.size() <= 0)
            {
                cout << "Invalid" << endl;
            }
            else
            {
                cout << S.top() << endl;
                ordered.erase(S.top());
                S.pop();
            }
        }
        else if (input == "PeekMedian")
        {
            long mid;
            if (S.size() % 2 == 0)
            {
                mid = S.size() / 2;
            }
            else
            {
                mid = (S.size() + 1) / 2;
            }
            
            if (mid <= 0)
            {
                cout << "Invalid" << endl;
            }
            else
            {
                multiset<long>::iterator it = ordered.begin();
                int cur = 0;
                while (cur < mid - 1)
                {
                    it++;
                    cur++;
                }
                cout << *it << endl;
                //ordered.erase(it);
            }
        }
    }

    return 0;
}
