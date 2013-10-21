#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int findRootPos(int b, int e, const vector<int>& v)
{
    int nNodes = e - b + 1;
    int nLevel = log((double)(nNodes)) / log(2.0);
    int nExtraNodes = pow(2.0, nLevel - 1);
    int nFullLevelNodes = pow(2.0, nLevel) - 1;
    if (nFullLevelNodes + nExtraNodes <= nNodes)
    {
        return (nFullLevelNodes - 1) / 2 + nNodes - nFullLevelNodes + b;
    }
    else
    {
        return (nFullLevelNodes - 1) / 2 + nExtraNodes + b;
    }
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());


    int rootpos = findRootPos(0, n - 1, v);    
    q.push(v[rootpos]);
    q.push(v[findRootPos(0, rootpos - 1)]);
    q.push(v[findRootPos(rootpos - 1, n - 1)]);
    

}
