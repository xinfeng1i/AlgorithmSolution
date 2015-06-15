#include <vector>
#include <set>
#include <map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	map<int, int> table;
	
	for (size_t i = 0; i < nums.size(); ++i)
	{
		if (table.find(nums[i]) == table.end())
		{
			table[nums[i]] = i;
		}
		else
		{
			if (i - table[nums[i]] <= k)
			{
				return true;
			}
			else
			{
				table[nums[i]] = i;
			}
		}
	}
	return false;
}
