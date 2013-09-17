#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

long maxSubsequenceSum(vector<long> &v, long &i, long &j)
{
    // special case, all < 0
    if (*max_element(v.begin(), v.end()) < 0)
    {
        i = 0;
        j = v.size() - 1;
        return 0;
    }

    i = 0;
    j = 0;
    long curSum = accumulate(v.begin() + i, v.begin() + j + 1, 0L);
    for (long k = 1; k < v.size(); ++k)
    {
        long tmp = accumulate (v.begin() + j + 1, v.begin() + k + 1, 0L);
        if (tmp > 0)
        {
            if (curSum > 0)
            {
                j = k;
                curSum = accumulate(v.begin() + i, v.begin() + j + 1, 0L);
            }
            else
            {
                i = j = k;
                curSum = v[k];
            }
        }
    }

    return curSum;
}

int main()
{
    long N;
    cin >> N;
    vector<long> v(N, 0);
    for (long k = 0; k < N; ++k)
    {
        cin >> v[k];
    }

    long beginIndex = 0;
    long endIndex = 0;
    cout << maxSubsequenceSum(v, beginIndex, endIndex)<< " " ;
    cout << v[beginIndex] << " " << v[endIndex] << endl;
    return 0;

}
