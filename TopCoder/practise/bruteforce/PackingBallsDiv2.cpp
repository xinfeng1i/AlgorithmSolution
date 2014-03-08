#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

int minPacks(int R, int G, int B);

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    cout << "Min packages: " << minPacks(r, g, b) << endl;
    return 0;
}

int minPacks(int R, int G, int B)
{
    vector<int> v(3, 0);
    v[0] = R;
    v[1] = G;
    v[2] = B;
    sort(v.begin(), v.end(), greater<int>());

    int ans = v[2];
    v[0] -= v[2];
    v[1] -= v[2];

    ans += v[0] / 3 + v[1] / 3;
    v[0] %= 3;
    v[1] %= 3;

    if (v[0] + v[1] >= 3)
    {
        ans += 2;
    }
    else if (v[0] + v[1] > 0)
    {
        ans += 1;
    }
    else
    {
        ans += 0;
    }

    return ans;
}
