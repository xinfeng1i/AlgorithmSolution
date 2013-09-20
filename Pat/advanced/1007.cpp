#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

long maxSubsequenceSum(vector<long long> &v, long &i, long &j)
{
    // special case, all < 0
    if (*max_element(v.begin(), v.end()) < 0)
    {
        i = 0;
        j = v.size() - 1;
        return 0;
    }
    
    long long maxSum = 0;
    long maxi = 0;
    long maxj = 0;
    for (i = 0; i < v.size(); ++i)
    {
        for (j = 0; j < v.size(); ++j)
        {
            long long curSum = accumulate(v.begin() + i, v.begin() + j + 1, 0);
            if (curSum > maxSum)
            {
                maxSum = 0;
                maxi = i;
                maxj = j;
            }
        }
            
    }
    i = maxi;
    j = maxj;

    return maxSum;
}

int main()
{
    int N = 0;
    cin >> N;
    vector<long long> v(N, 0);
    for (int k = 0; k < N; ++k)
    {
        cin >> v[k];
    }

    long beginIndex = 0;
    long endIndex = 0;
    cout << maxSubsequenceSum(v, beginIndex, endIndex)<< " " ;
    cout << v[beginIndex] << " " << v[endIndex] << endl;
    return 0;

}
