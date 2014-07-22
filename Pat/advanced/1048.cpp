#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
using namespace std;

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
        for (size_t j = i + 1; j < n; ++j)
        {
            if (v[i] + v[j] == m)
            {
                printf("%d %d\n", v[i], v[j]);
                return 0;
            }
            else if (v[i] + v[j] > m)
            {
                break;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}
