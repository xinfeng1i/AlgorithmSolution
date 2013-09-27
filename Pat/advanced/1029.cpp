#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    vector<long> v1;
    vector<long> v2;
    long n1 = 0;
    long n2 = 0;

    cin >> n1;
    v1.resize(n1, 0);
    for (long i = 0; i < n1; ++i)
    {
        //cin >> v1[i];
        scanf("%ld", &v1[i]);
    }

    cin >> n2;
    v2.resize(n2, 0);
    for (long i = 0; i < n2; ++i)
    {
        //cin >> v2[i];
        scanf("%ld", &v2[i]);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<long> result(n1 + n2, 0);

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());

    long mid = (n1 + n2 - 1) / 2;

    //cout << result[mid] << endl;
    printf("%ld\n", result[mid]);

    return 0;
}


// Summany:
// If problem involves a lot of I/O operation, replace cin, cout
// with scanf, printf, can save a lot of time cost.
// Remember that.