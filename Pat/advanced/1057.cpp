#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    long n;
    scanf("%ld", &n);

    stack<long> S;
    multiset<long> ordered;
    char input[20];
    long key;
    for (long i = 0; i < n; ++i)
    {
        scanf("%s", input);

        // push operation
        if (input[1] == 'u')
        {
            scanf("%ld", &key);
            S.push(key);
            ordered.insert(key);
        }
        // pop operation
        else if (input[1] == 'o')
        {
            if (S.size() <= 0)
            {
                printf("Invalid\n");
            }
            else
            {
                printf("%ld\n", S.top());
                ordered.erase(S.top());
                S.pop();
            }
        }
        // peek median
        else if (input[1] == 'e')
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
                printf("Invalid\n");
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
                printf("%ld\n", *it);
            }
        }
    }

    return 0;
}
