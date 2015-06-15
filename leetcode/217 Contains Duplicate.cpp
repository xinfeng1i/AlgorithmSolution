#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool containsDuplicate(vector<int>& nums) 
{
	set<int> s;
	
	for (size_t i = 0; i < nums.size(); ++i)
	{
		if (s.find(nums[i]) == s.end())
		{
			s.insert(nums[i]);
		}
		else
		{
			return true;
		}
	}
	return false;
}
