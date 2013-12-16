#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void printVector(const vector<int> &v)
{
    cout << "Number:" << endl;
    for (int i = 0; i < 10; ++i)
    {
        cout << v[i];
    }
    cout << endl;
}

long long toNumber(const vector<int> &v)
{
    long long ans = 0;
    for (int i = 0; i < 10; ++i)
    {
        ans += v[i] * pow(10, 9 - i);
    }
    return ans;
}

int main()
{
    long long sum = 0;

    vector<int> a(10, 0);
    for (int a0 = 1; a0 < 10; ++a0)
    {
        a[0] = a0;
        for (int a1 = 0; a1 < 10; ++a1)
        {
            a[1] = a1;
            if (a[1] != a[0])
            {
                for (int a2 = 0; a2 < 10; ++a2)
                {
                    a[2] = a2;
                    if (a[2] != a[1] && a[2] != a[0])
                    {
                        for (int a3 = 0; a3 < 10; a3 += 2)
                        {
                            a[3] = a3;
                            if (a[3] != a[2] && a[3] != a[1] && a[3] != a[0])
                            {
                                for (int a4 = 0; a4 < 10; ++a4)
                                {
                                    a[4] = a4;
                                    if (a[4] != a[3] && a[4] != a[2] && 
                                        a[4] != a[1] && a[4] != a[0] && (a[4] + a[3] + a[2]) % 3 == 0)
                                    {
                                        for (int a5 = 0; a5 < 10; a5 += 5)
                                        {
                                            a[5] = a5;
                                            if (a[5] != a[4] && a[5] != a[3] && 
                                                a[5] != a[2] && a[5] != a[1] && a[5] != a[0])
                                            {
                                                for (int a6 = 0; a6 < 10; a6++)
                                                {
                                                    a[6] = a6;
                                                    if (a[6] != a[5] && a[6] != a[4] && a[6] != a[3] &&
                                                        a[6] != a[2] && a[6] != a[1] && a[6] != a[0] &&
                                                        (a[6] + 10 * a[5] + 100 * a[4]) % 7 == 0)
                                                    {
                                                        for (int a7 = 0; a7 < 10; a7++)
                                                        {
                                                            a[7] = a7;
                                                            if (a[7] != a[6] && a[7] != a[5] && a[7] != a[4] &&
                                                                a[7] != a[3] && a[7] != a[2] && a[7] != a[1] &&
                                                                a[7] != a[0] &&
                                                                (a[7] + 10 * a[6] + 100 * a[5]) % 11 == 0)
                                                            {
                                                                for (int a8 = 0; a8 < 10; a8++)
                                                                {
                                                                    a[8] = a8;
                                                                    if (a[8] != a[7] && a[8] != a[6] && a[8] != a[5] &&
                                                                        a[8] != a[4] && a[8] != a[3] && a[8] != a[2] &&
                                                                        a[8] != a[1] && a[8] != a[0] &&
                                                                        (a[8] + 10 * a[7] + 100 * a[6]) % 13 == 0)
                                                                    {
                                                                        for (int a9 = 0; a9 < 10; a9++)
                                                                        {
                                                                            a[9] = a9;
                                                                            if (a[9] != a[8] && a[9] != a[7] &&
                                                                                a[9] != a[6] && a[9] != a[5] &&
                                                                                a[9] != a[4] && a[9] != a[3] &&
                                                                                a[9] != a[2] && a[9] != a[1] &&
                                                                                a[9] != a[0] &&
                                                                                (a[9] + 10 * a[8] + 100 * a[7])%17 == 0)
                                                                            {
                                                                                printVector(a); 
                                                                                //cout << toNumber(a) << endl;
                                                                                sum += toNumber(a);
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "***** The Final Answer is: *****" << endl;
    cout << sum << endl;
    return 0;
}

