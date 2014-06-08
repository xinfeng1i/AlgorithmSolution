#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lowbit(int x)
{
	int ans = 1;
	while ((x & 1) == 0)
	{
		x = (x >> 1);
		ans *= 2;
	}
	return ans;
}

/* the lowbit function can also be compute by the following
 *
 * refer other's elegant code
 */
int lowbit2(int x)
{
    return x & (-x);
}

int main()
{
    int sum, limit;
    cin >> sum >> limit;

    vector<int> v;
    v.reserve(limit);
    for (int x = limit; x >= 1 && sum > 0; --x)
    {
        int low = lowbit(x);
        if (low <= sum)
        {
            sum -= low;
            v.push_back(x);
        }
    }
    
    if (sum != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        cout << v.size() << endl;
        for (size_t i = 0; i < v.size(); ++i)
        {
            if (i != 0) cout << " " << v[i];
            else cout << v[i];
        }
        cout << endl;
    }
	return 0;
}
