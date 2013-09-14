#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<string> v(n);
    long long a = 0;
    long long b = 0;
    long long c = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b >> c;
        if (a + b - c > 0)
        {
            v[i] = "true";
        }
        else
        {
            v[i] = "false";
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << "Case #" << i + 1 << ": " << v[i] << endl;
    }
    
    return 0;
}
