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

/** 
 * Office solution: greedy algorithm
 * you can always invite friends with shy level 0, since
 * if you can invite other people with shy level k (k > 0)
 * to make sure all people stand out, then you can replace these
 * people with shy level 0, the solution will also succeed.
 */
#if 0
int main()
{
	freopen("data.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);
	int T = 0;
	cin >> T;
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		int smax = 0;
		string shyArray;
		cin >> smax >> shyArray;
		
		// current stand people
		int standPeople = 0;
		int minInvite = 0;
		for (int k = 0; k <= smax; ++k)
		{
			// if you want shy level k people to stand, you must
			// have at least k people stand, since there already be
			// standPeople stand out, therefore, you need at least
			// k - standPeople to invite to make sure this level people
			// can stand
			minInvite = max(k - standPeople, 0);
			standPeople += shyArray[k] - '0';
		}

		cout << "Case #" << nCase << ": " << minInvite << endl;
	}
	return 0;

}
#endif //0