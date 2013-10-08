#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

#define smax 65536

int main()
{
    hash<long> myhash;

    long n = 0;
    cin >> n;

    int cnt[smax] = {0};
    vector<int> numbers(n, 0);
    int tmp = 0;
    for (long i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        numbers[i] = tmp;
        cnt[myhash(tmp)]++;
    }

    for (long i = 0; i < n; ++i)
    {
        if (cnt[myhash(numbers[i])] == 1)
        {
            //cout << numbers[i] << endl;
            printf("%d\n", numbers[i]);
            return 0;
        }
    }

    printf("None\n");
    //cout << "None" << endl;
    return 0;
}
