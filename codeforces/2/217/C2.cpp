#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> left(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> left[i];
    }

    sort (left.begin(), left.end());

    vector<int> right(left.begin(), left.end());

    int Cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (left[i] != right[i])
        {
            continue; 
        }

        for (int j = 0; j < n; ++j)
        {
            if (j != i)
            {
                if (left[j] == right[j] && left[i] != left[j])
                {
                    right[i] = left[j];
                    right[j] = left[i];
                    Cnt += 2;
                    break;
                }
                else if (left[j] != right[j] && left[i] != right[j]
                        && left[j] != right[i])
                {
                    right[i] = right[j];
                    right[j] = left[i];
                    Cnt++;
                    break;
                }
            }
        }
    }

    cout << Cnt << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << left[i] << " " << right[i] << endl;
    }

    return 0;
}

// Summary:
// This time just follow the item, find the algorithm with O(N^2) algorithm
// good and elegant.
// What need to care is that you need to divide the situation.
