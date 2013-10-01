#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Method 1: Brute Force
//
// Main Idea:
// stimulate the scene, every time choose the minimum elem (O(N)), 
// for other elems not minimum minus one, till all the elems equal
// zero.
// Shortage: cost too much time

/*
int main()
{
    long n = 0;
    cin >> n;
    vector<long long> v(n, 0);
    for (long i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    long long cnt = 0;
    while (*max_element(v.begin(), v.end()) != 0)
    {
        auto it = min_element(v.begin(), v.end());
        for (auto iter = v.begin(); iter != v.end(); ++iter)
        {
            if (iter != it)
            {
                *iter -= 1;
                if (*iter < 0)
                {
                    *iter = 0;
                }
            }
        }
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}
*/

// Method 2: Math simplify
// Main Idea:
// For each round, elems except minimum, minus one, all the elems minus
// n - 1, so calculate how many round it can last, plus one
// OR, the special case, the max elem has to decend to zero, it needs
// at least max_elem rounds
// compare the two cases, choose the largest
int main()
{
    long n = 0;
    cin >> n;
    long long max_elem = -10000;
    long long sum = 0;
    long long elem = 0;
    for (long i = 0; i < n; ++i)
    {
        cin >> elem;
        max_elem = max(max_elem, elem);
        sum += elem;
    }

    long long case1_round_num = (sum - 1) / (n - 1) + 1;
    long long case2_round_num = max_elem;
    cout << max(case1_round_num, case2_round_num) << endl;
    return 0;
}

