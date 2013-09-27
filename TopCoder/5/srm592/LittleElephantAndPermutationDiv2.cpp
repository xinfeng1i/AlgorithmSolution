#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long magic(vector<int> a, vector<int> b)
{
    long long sum = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        sum += max(a[i], b[i]);
    }

    return sum;
}

long long getNumber(int N, int K)
{
    long long cnt = 0;
    vector<int> a(N, 0);
    for (int i = 0; i < N; ++i)
    {
        a[i] = i + 1;
    }

    do{
        vector<int> b(N, 0);
        for (int i = 0; i < N; ++i)
        {
            b[i] = i + 1;
        }

        do{
            if (magic(a, b) >= K)
            {
                cnt++;
            }
        }while(next_permutation(b.begin(), b.end()));

    }while(next_permutation(a.begin(), a.end()));

    return cnt;
}

int main()
{
    int N, K;
    cin >> N;
    cin >> K;
    cout << getNumber(N, K) << endl;
    return 0;
}
