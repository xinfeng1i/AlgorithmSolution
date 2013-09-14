#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v(N, 0);
    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }

    vector<int> v1, v2, v3, v4, v5;
    int a1, a2, a3, a5;
    double a4 = 0.0;
    for (int i = 0; i < N; ++i)
    {
        if (v[i] % 5 == 0)
        {
            if (v[i] % 2 == 0)
            {
                v1.push_back(v[i]);
            }
        }
        else if (v[i] % 5 == 1)
        {
            v2.push_back(v[i]);
        }
        else if (v[i] % 5 == 2)
        {
            v3.push_back(v[i]);
        }
        else if (v[i] % 5 == 3)
        {
            v4.push_back(v[i]);
        }
        else if (v[i] % 5 == 4)
        {
            v5.push_back(v[i]);
        }
    }

    if (v1.size() == 0)
    {
        cout << "N ";
    }
    else
    {
        a1 = accumulate(v1.begin(), v1.end(), 0);
        cout << a1 << " ";
    }

    if (v2.size() == 0)
    {
        cout << "N ";
    }
    else
    {
        int tmp = 0;
        for (int i = 0; i < v2.size(); ++i)
        {
            if (i % 2 == 0)
                tmp += v2[i];
            else
                tmp += -v2[i];
        }
        a2 = tmp;
        cout << a2 << " ";
    }

    if (v3.size() == 0)
    {
        cout << "N ";
    }
    else
    {
        a3 = v3.size();
        cout << a3 << " ";
    }
    
    if (v4.size() == 0)
    {
        cout << "N ";
    }
    else
    {
        a4 = accumulate(v4.begin(), v4.end(), 0.0) / v4.size();
        printf("%0.1f ", a4);
    }

    if (v5.size() == 0)
    {
        cout << "N" << endl;
    }
    else
    {
        sort(v5.begin(), v5.end());
        a5 = v5[v5.size()-1];
        cout << a5 << endl;
    }

    return 0;
}
