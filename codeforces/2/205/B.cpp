#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    vector<int> myhash(100, 0);
    vector<int> v(2*n, 0);
    for (int i = 0; i < 2 * n; ++i)
    {
        cin >> v[i];
        myhash[v[i]]++;
    }

    vector<int> flag(2*n, 0);
}
