#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int minPacks(int K, int A, int B, int C, int D);

int main()
{
    int k, a, b, c, d;
    cin >> k >> a >> b >> c >> d;
    cout << "Minimum packages: " << minPacks(k, a, b, c, d) << endl;
    return 0;
}


int minPacks(int K, int A, int B, int C, int D)
{
    vector<int> v(K, 0);
    
    // generate array x[]
    v[0] = A;
    for (int i = 1; i < K; ++i)
    {
        //v[i] = (v[i - 1] * B + C) % D + 1;
        v[i] = (((v[i - 1] % D) * (B % D)) % D + C % D) % D + 1;
    }

    int ansPacks = 0;
    for (int i = 0; i < K; ++i)
    {
        if (v[i] >= K)
        {
            ansPacks += v[i] / K;
            v[i] %= K;
        }
    }

    sort(v.begin(), v.end(), greater<int>());
    int minPos = K - 1;
    while (v[minPos] == 0)
    {
        minPos--;
    }

    while (minPos >= 0)
    {
        if (v[0] >= minPos + 1)
        {
            v[0] = 0;
            ansPacks += 1;
            sort(v.begin(), v.end(), greater<int>());
        }
        else
        {
            for (int i = 0; i <= minPos; ++i)
            {
                v[i] -= 1;
            }
            ansPacks += 1;
        }

        while (v[minPos] == 0)
        {
            minPos--;
        }
    }

    return ansPacks;
}
