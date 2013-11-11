#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    long long n;
    long long k;
    cin >> n >> k;
    vector<int> v(n);
    for (long long i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    vector<long long> dp(n + 1, 0LL);


    // init
    long long minIndex = 0;
    long long minSum = 0;
    for (long long i = 0; i < k; ++i)
    {
        minSum += v[i];
    }

    for (long long i = k; i < n + 1 - k; ++i)
    {
        
    }

    cout << minIndex + 1 << endl;
    return 0;
}
