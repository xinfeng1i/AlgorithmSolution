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

    int binCnt = 1;
    int binSpace = 300;

    while (true)
    {
        while (true)
        {
            bool found = false;
            int i = n - 1;
            for (i = n - 1; i >= 0; --i)
            {
                if (item[i] <= binSpace && !visited[i])
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                break;
            }
            else
            {
            
                visited[i] = true;
                binSpace -= item[i];
            }
        }

        // if all items have been placed, break the whole loop
        if (find(visited.begin(), visited.end(), false) == visited.end())
        {
            break;
        }
        else    // if not, then add a bin, reset the binSpace
        {
            binCnt++;
            binSpace = 300;
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

    cout << "minBins: " << minBins(v) << endl;
    return 0;
}
