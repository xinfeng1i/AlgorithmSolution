#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int minBins(vector<int> item)
{
    sort(item.begin(), item.end());
    int n = item.size();
    vector<bool> visited(n, false);

    int curSpace = 300;
    int binCnt = 0;
    int j = n - 1;
    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            curSpace -= item[i];
            while ( (j > i) &&(visited[j] == true ||item[j] > curSpace) )
            {
                --j;
            }

            if (j <= i)
            {
                binCnt++;
                break;
            }
            else
            {
                visited[j] = true;
            }
            binCnt++;
            curSpace = 300;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            binCnt++;
        }
    }

    return binCnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    cout << minBins(v) << endl;

    return 0;
}
