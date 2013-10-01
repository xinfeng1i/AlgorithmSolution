#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

long g_begin = 0;
long g_end = 0;
////////////////////////////////////////////////////////////
// Classical Dynamic Programming Problem
// Max sum of subSequence
//
// Define subproblem as:
// sum[j] = the max subsequce sum ending up with j
// for the next element indexed as j + 1
// if sum[j] < 0, the elem[j+1] will indenpent, so
// sum[j + 1] = elem[j+1]
// else, the elem[j+1] must append the sum[j]
// sum[j+1] += elem[j+1]
//
// Recursive Relation:
// ********************************
// * sum[j] = v[j]   sum[j-1] < 0 *
// * sum[j] += v[j]  other wise   *
// ********************************
// Constrain: array must have at least one nonpositive element
// Special Case: all elems are negetive
// 
// Input:
// v - array
// Output:
// max sum of subsequence of array
//////////////////////////////////////////////////////////////
long maxSubsequenceSum(const vector<long>& v)
{
    if (*max_element(v.begin(), v.end()) < 0)
    {
        g_begin = 0;
        g_end = static_cast<long>(v.size()) - 1;        
        return 0;
    }
    long max_sum_ending = v[0];
    long tmp_start = 0;
    long tmp_end = 0;

    long max_sum_sofar = v[0];
    long sofar_start = 0;
    long sofar_end = 0;

    for (long i = 1; i < v.size(); ++i)
    {
        if (max_sum_ending < 0)
        {
            max_sum_ending = v[i];
            tmp_start = i;
            tmp_end = i;
        }
        else
        {
            max_sum_ending += v[i];
            tmp_end = i;
        }

        if (max_sum_ending > max_sum_sofar)
        {
            max_sum_sofar = max_sum_ending;
            sofar_start = tmp_start;
            sofar_end = tmp_end;
        }
    }
    g_begin = sofar_start;
    g_end = sofar_end;

    return max_sum_sofar;
}

int main()
{
    int k = 0;
    cin >> k;
    vector<long> v(k, 0);
    for (int i = 0; i < k; ++i)
    {
        cin >> v[i];
    }

    cout << maxSubsequenceSum(v);
    cout << " " << v[g_begin] << " " << v[g_end] << endl;
    return 0;
}
