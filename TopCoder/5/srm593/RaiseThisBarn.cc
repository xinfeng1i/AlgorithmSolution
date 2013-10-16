#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int calc(string str)
{
    vector<int> acc_cnt(str.size(), 0);
    int total = 0;

    if (str[0] == 'c')
    {
        total++;
        acc_cnt[0] = 1;
    }

    for (int i = 1; i < str.size(); ++i)
    {
        if (str[i] == 'c')
        {
            total++;
            acc_cnt[i] = acc_cnt[i-1] + 1;
        }
        else
        {
            acc_cnt[i] = acc_cnt[i-1];
        }
    }

    int sum = 0;
    for (int k = 0; k < str.size() - 1; ++k)
    {
        if (acc_cnt[k] == total - acc_cnt[k])
        {
            sum++;
        }
    }

    return sum;
}

int main()
{
    string s;
    cin >> s;
    cout << calc(s) << endl;
    return 0;
}
