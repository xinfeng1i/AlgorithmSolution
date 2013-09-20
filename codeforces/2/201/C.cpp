#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<long long> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }


    // Alice opration
    bool Alicefound = false;
    long long diff = 0;
    while (true)
    {
AliceOperation:for (int i = 0; i < v.size(); ++i)
        {
            for (int j = i + 1; j < v.size(); ++j)
            {
                diff = abs(v[i] - v[j]);
                if (count(v.begin(), v.end(), diff) == 0)
                {
                    v.push_back(diff);
                    Alicefound = true;
                    goto BobOperation;
                }
            }
        }

        if (!Alicefound)
        {
            cout << "Bob" << endl;
            break;
        }

        // Bob operation
BobOperation: for (int i = 0; i < v.size(); ++i)
        {
            for (int j = i + 1; j < v.size(); ++j)
            {
                diff = abs(v[i] - v[j]);
                if (count(v.begin(), v.end(), diff) == 0)
                {
                    v.push_back(diff);
                    Alicefound = false;
                    goto AliceOperation;
                }
            }
        }

        if (Alicefound)
        {
            cout << "Alice" << endl;
            break;
        }
    }
    return 0;
}
