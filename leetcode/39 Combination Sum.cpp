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
		for (size_t i = 0; i < curSet.size(); ++i) cout << " " << curSet[i];
		cout << endl;
		ans.push_back(curSet);
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
	combinationRecur(candidates, startPos, curTarget - tmp, curSet, ans);
	curSet.pop_back();

	// not choose current number
	combinationRecur(candidates, startPos + 1, curTarget, curSet, ans);

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
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
	candidates.push_back(2);
	candidates.push_back(3);
	candidates.push_back(6);
	candidates.push_back(7);
	vector<vector<int>> ans = combinationSum(candidates, 10);
	return 0;
}