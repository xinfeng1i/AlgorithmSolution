#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    long n = 0;
    cin >> n;
    vector<string> v(n);
    for (long i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    long cnt = 1;
    long pre = 0;
    long cur = 1;
    while (cur < n)
    {
        if (v[pre][1] == v[cur][0])
        {
            cnt++;
        }
        pre++;
        cur++;
    }
    cout << cnt << endl;
    return 0;
    
}
