#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long n = 0;
    cin >> n;

    vector<int> v(n, 0);
    for (long i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    string s;
    cin >> s;

    long smax = 0;
    do{
        int cur = 0;
        while (cur < n && s[cur] == '0')
        {
            cur++;
        }
        string ss = s.substr(cur, -1);

        long tmp = 0;
        for (long i = 0; i < ss.size(); ++i)
        {
            if (ss[i] == '1')
            {
                tmp += v[i];
            }
        }

        if (tmp > smax)
        {
            smax = tmp;
        }
    }while(prev_permutation(s.begin(), s.end()));

    cout << smax << endl;
    return 0;
}
