#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    long n, k, l, r, sall, sk;
    cin >> n >> k >> l >> r >> sall >> sk;

    long avg1 = sk / k;
    for (long i = 0; i < k; ++i)
    {
        cout << avg1 + (i < sk % k ? 1 : 0) << " ";
    }

    if (k < n)
    {
        long avg2 = (sall - sk) / (n - k);
        long r2 = (sall - sk) % (n - k);
        for (long i = k; i < n; ++i)
        {
            cout << avg2 + (i - k < r2 ? 1: 0) << " ";
        }
    }

    cout << endl;

    return 0;
}
