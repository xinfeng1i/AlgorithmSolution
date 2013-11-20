#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    vector<int> stair(1000000010, 0);
    long long n;
    int m;
    cin >> n >> m;
    
    long long tmp;
    for (int i = 0; i < m; ++i)
    {
        cin >> tmp;
        stair[tmp] = 1;
    }

    long long cur = 1;
    while (cur <= n)
    {
        if (stair[cur] == 1)
        {
            cout << "NO" << endl;
            return 0;
        }
        
        if (cur + 1 > n)
        {
            cout << "YES" << endl;
            return 0;
        }
        else if (cur + 1 <= n && stair[cur + 1] == 0)
        {
            cur = cur + 1;
            continue;
        }
        else if (cur + 1 <= n && stair[cur + 1] == 1)
        {
            if (cur + 2 > n)
            {
                cout << "NO" << endl;
                return 0;
            }
            else if (cur + 2 <= n && stair[cur + 2] == 0)
            {
                cur = cur + 2;
                continue;
            }
            else if (cur + 2 <= n && stair[cur + 2] == 1)
            {
                if (cur + 3 > n)
                {
                    cout << "NO" << endl;
                    return 0;
                }
                if (cur + 3 <= n && stair[cur + 3] == 0)
                {
                    cur = cur + 3;
                    continue;
                }
                else if (cur + 3 <= n && stair[cur + 3] == 1)
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "YES" << endl;
    return 0;

}
