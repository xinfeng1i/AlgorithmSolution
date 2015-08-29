#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

void combinationRecur(vector<int>& candidates, int startPos, int curTarget,
	vector<int>& curSet, vector<vector<int>>& ans)
{
	if (curTarget == 0)
	{
		if (find(ans.begin(), ans.end(), curSet) == ans.end())
		{
			ans.push_back(curSet);
			//for (size_t i = 0; i < curSet.size(); ++i) cout << " " << curSet[i];
			//cout << endl;
		}
		return;
		
	}

	else if (curTarget < 0)
	{
		return;
	}
	if (startPos >= candidates.size())
	{
		return;
	}

	// choose current number
	int tmp = candidates[startPos];
	curSet.push_back(tmp);
	combinationRecur(candidates, startPos + 1, curTarget - tmp, curSet, ans);
	curSet.pop_back();

	// not choose current number
	combinationRecur(candidates, startPos + 1, curTarget, curSet, ans);

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
	vector<vector<int>> ans;
	if (candidates.empty() || target <= 0) return ans;

	sort(candidates.begin(), candidates.end());
	vector<int> curSet;
	combinationRecur(candidates, 0, target, curSet, ans);

	return ans;
}

int main()
{
	vector<int> candidates;
	candidates.push_back(10);
	candidates.push_back(1);
	candidates.push_back(2);
	candidates.push_back(7);
	candidates.push_back(6);
	candidates.push_back(1);
	candidates.push_back(5);
	vector<vector<int>> ans = combinationSum2(candidates, 8);
	return 0;
}