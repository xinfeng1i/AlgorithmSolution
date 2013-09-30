#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    long n = 0;
    cin >> n;

    map<int, int>cnt;
    vector<int> numbers(n, 0);
    int tmp = 0;
    for (long i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        numbers[i] = tmp;
        cnt[tmp]++;
    }

    for (long i = 0; i < n; ++i)
    {
        if (cnt[numbers[i]] == 1)
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