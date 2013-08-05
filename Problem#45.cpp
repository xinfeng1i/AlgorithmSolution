#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

long long genTriangle(long long n)
{
    return n * (n + 1) / 2;
}

long long genPentagonal(long long n)
{
    return n * (3 * n - 1) / 2;
}

long long genHexagonal(long long n)
{
    return n * (2 * n - 1);
}

int main()
{
    clock_t time_begin = clock();

    vector<long long> tvec;
    vector<long long> pvec;
    vector<long long> hvec;

    for (long long n = 1; n <= 60000; n++)
    {
        tvec.push_back(genTriangle(n));
        pvec.push_back(genPentagonal(n));
        hvec.push_back(genHexagonal(n));
    }

    for (size_t i = 0; i < tvec.size(); i++)
    {
        if (binary_search(pvec.begin(), pvec.end(), tvec[i]) &&
            binary_search(hvec.begin(), hvec.end(), tvec[i]))
        {
            cout << "Common Number: " << "T_" << i + 1 << " = " << tvec[i] << endl;
        }
    }

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << time_cost * 1000 << " ms" << endl;
    return 0;
}
