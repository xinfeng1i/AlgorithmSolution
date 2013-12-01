#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int tmp;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        if (tmp == 2 && k > 0)
        {
            k--;
        }
        else
        {
            m--;
        }
    }

    cout << (m < 0 ? -m : 0) << endl;

    return 0;
}
