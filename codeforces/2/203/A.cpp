#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    int a_min = 101;
    int a_max = 0;
    int a = 0; 
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        a_min = min(a_min, a);
        a_max = max(a_max, a);
    }

    int a_tl = max(a_max, 2 * a_min);


    int b_min = 101;
    int b_max = 0;
    int b = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> b;
        b_min = min(b_min, b);
        b_max = max(b_max, b);
    }
    int b_tl = b_min - 1;

    if (b_tl >= a_tl)
    {
        cout << a_tl << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
