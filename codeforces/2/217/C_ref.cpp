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

    sort(left.begin(), left.end());
    vector<int> right(left.begin(), left.end());
    for (int i = 0; i < n; ++i)
    {
        right[i] = left[ (i + (n / 2)) % n ];
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (left[i] != right[i])
        {
            cnt++;
        }
    }

    cout << cnt << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << left[i] << " " << right[i] << endl;
    }

    return 0;
}

// Summary:
// This solution is from the tutorial.
// Main Idea:
// sort the array as the number of frequecy of colors
// like: 2 2 2 1 1 3
// then if the max number of frequecy of colors is mx,
// if it is not more than n / 2. then all the students can have
// different mittens
// if mx > n / 2, the algorithm just find the max number of
// students that have different mitterns.
// Why ? still cannnot figure out. Todo
