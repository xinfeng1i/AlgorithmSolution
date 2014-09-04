#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
using namespace std;

int binarySearch(const vector<int>& v, int key)
{
    int n = v.size();
    int left = 0;
    int right = n - 1;
    int mid = (left + right) / 2;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (key == v[mid])
        {
            return mid;
        }
        else if (key < v[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return -1;
}

int main()
{
    unsigned int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);
    for (size_t i = 0; i < n; ++i)
    {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end());

    for (size_t i = 0; i < n; ++i)
    {
        int y = m - v[i];
        int j = binarySearch(v, y);
        if (j == -1) 
        {
            continue;
        }
        else
        {
            if (i != j && v[i] <= v[j])
            {
                cout << v[i] << " " << v[j] << endl;
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}

/*
 * 采用二分查找可以将搜索时间从原来的O(N^2)
 * 降低到(NlogN)
 */
