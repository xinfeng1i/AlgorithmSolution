#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> numbers(n, 0);
    long inv = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
        for (int j = 0; j < i; ++j)
        {
            if (numbers[j] > numbers[i])
            {
                inv++;
            }
        }
    }

    double ans = 0.0;
    if (inv % 2 == 0)
    {
        ans = inv * 2.0;
    }
    else
    {
        ans = (inv - 1) * 2.0 + 1;
    }

    printf("%0.6f\n", ans);
    return 0;
}

// Summary:
// 1. I fingure out the basic idea, every time Jeff make the step minus one,
//    Furik make zero progress in expectation. But I didn't come up with the
//    conception of the number of inversion. Also a little trival, every two
//    step make 1 step progress.
// 2. If outputing double number, use printf is convenient.
//
// Created by python27
// 2013/10/07
