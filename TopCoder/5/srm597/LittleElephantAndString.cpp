#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX_CNT = 100;
int getNumber(string A, string B)
{
    string copyA(A);
    string copyB(B);
    sort(copyA.begin(), copyA.end());
    sort(copyB.begin(), copyB.end());
    if (copyA != copyB)
    {
        return -1;
    }

    // base case
    if (A == B)
    {
        return 0;
    }

    int minCnt = MAX_CNT; 
    int curCnt = 0;

    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] == B[0])
        {
            int diff = 1
            if (i == 0)
            {
                diff = 0;
            }
            else
            {
                diff = 1
            }

            curCnt = diff + getNumber(A.substr(0, i) + A.substr(i + 1), B.substr(1));

            if (curCnt < minCnt)
            {
                minCnt = curCnt;
            }
        }
    }

    return minCnt;
}

int main()
{
    freopen("input.txt", "r", stdin);
    string a, b;
    cin >> a >> b;
    int ans = getNumber(a, b);
    cout << ans << endl;
    return 0;
}
