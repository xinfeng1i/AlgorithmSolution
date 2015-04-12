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
vector<int> AddFriend(const string& str, int k)
{
	vector<int> ans(str.size(), 0);
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (i == 0) ans[i] = str[i] - '0' + k;
		else ans[i] = str[i] -'0';
	}
	return ans;
}

bool CanSuccess(int smax, const vector<int>& shyArray)
{
	if (shyArray.size() <= 1) return true;

	int n = shyArray.size();
	int standPeople = shyArray[0];
	int tobePos = 1;

	if (tobePos < n && standPeople < tobePos) return false;

	while (tobePos < n)
	{
		if (tobePos < n && standPeople < tobePos) return false;

		int nextStandPeople = standPeople;
		for (int i = tobePos; i < n && i <= standPeople; i++)
		{
			nextStandPeople += shyArray[i];
		}

		tobePos = standPeople + 1;
		standPeople = nextStandPeople;
	}

	return true;
}

int main()
{
	//freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);
	int T = 0;
	cin >> T;
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		int smax = 0;
		string shyArray;
		cin >> smax >> shyArray;
		
		for (int k = 0; k <= smax; ++k)
		{
			vector<int> people = AddFriend(shyArray, k);
			if (CanSuccess(smax, people))
			{
				cout << "Case #" << nCase << ": " << k << endl;
				break;
			}
		}
	}
	return 0;
}
#endif //0