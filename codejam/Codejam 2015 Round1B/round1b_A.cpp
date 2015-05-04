#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

#if 0
typedef long long llong;
llong reverse_number(llong n)
{
	string str = std::to_string(n);
	std::reverse(str.begin(), str.end());
	size_t i = 0;
	while (i < str.size() && str[i] == '0') i++;
	string ans = str.substr(i);
	return std::stoll(str);
}


/*
void solve()
{
	llong N = 0;
	cin >> N;
	llong cnt = 1;
	llong i = 1;
	while (i < N)
	{	
		llong r = reverse_number(i);

		if (r > N)
		{
			i += 1;
		}
		else
		{
			i = max(r, i + 1);
		}
		
		cnt++;
	}
	cout << cnt << endl;

}
*/

void solve()
{
	llong N = 0;
	cin >> N;

	//cout << "N = " << N << endl;
	vector<llong> dp(N + 1, 1);
	for (llong i = 1; i <= min(9LL, N); i++) dp[i] = i;
	for (llong i = 10; i <= N; i++)
	{
		if (i % 10 != 0)
		{
			llong r = reverse_number(i);
			if (r < i)
			{
				dp[i] = min(dp[r] + 1, dp[i-1] + 1);
			}
			else
			{
				dp[i] = dp[i-1] + 1;
			}
		}
		else
		{
			dp[i] = dp[i-1] + 1;
		}
		//cout << "dp[i] = " << dp[i] << endl;
	}
	cout << dp[N] << endl;

}

int main()
{
	//freopen("A-small-attempt2.in", "r", stdin);
	//freopen("A-small-attempt2.out", "w", stdout);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	int T = 0;
	cin >> T;
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		cout << "Case #" << nCase << ": ";
		solve();
	}
	
	return 0;
}
#endif //0