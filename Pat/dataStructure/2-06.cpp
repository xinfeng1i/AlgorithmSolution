#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
    int A = 0;
    long N = 0;
    cin >> A >> N;

    if (N == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    
    vector<long> sum(2 * N, 0);

    for (long i = 0; i < N; ++i)
    {
        sum[i] = (N - i) * A;  
    }

    for (long i = 0; i < 2 * N; ++i)
    {
        if (sum[i] > 10)
        {
           sum[i+1] += sum[i] / 10;
           sum[i] = sum[i] % 10;
        }
    }

    long nonzero = 2 * N - 1;
    while (sum[nonzero] == 0)
    {
        nonzero--;
    }

    if (nonzero < 0)
    {
        cout << 0 << endl;
    }
    else
    {
        for (long j = nonzero; j >= 0; j--)
        {
            cout << sum[j];
        }
        cout << endl;
    }

    return 0;
}

