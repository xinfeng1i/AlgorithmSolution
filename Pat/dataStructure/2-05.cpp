#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <numeric>
using namespace std;

double mean(vector<long long>& v)
{
    long long sz = v.size();
    double sum = 0.0;
    double m = accumulate(v.begin(), v.end(), 0.0) / (double)sz;
    for (vector<long long>::iterator it = v.begin(); it != v.end(); ++it)
    {
        sum += (*it - m) * (*it - m);
    }
    
    return sqrt(sum / sz);
}

int main()
{
    int N = 0;
    cin >> N;
    vector<long long> v(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }

    printf("%0.5f\n", mean(v));
    return 0;
}
