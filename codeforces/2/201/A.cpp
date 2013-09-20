#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    if (n >= 2)
    {
        swap(a[0], a[n-1]);
    }

    bool flag = false;
    for (int i = 0; i < n; ++i)
    {
        if (flag)
        {
            cout << " "; 
        }
        else
        {
            flag = true; 
        }
        cout << a[i];
    }
    cout << endl;
    return 0;
}
