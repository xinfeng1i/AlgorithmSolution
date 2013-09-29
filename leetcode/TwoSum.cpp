#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution 
{
public:
    vector<int> twoSum(vector<int> &numbers, int target) 
    {
        vector<int> ans;
        long long sz = numbers.size();
        for (long long i = 0; i < sz; ++i)
        {
            for (long long j = i + 1; j < sz; ++j)
            {
                if (numbers[i] + numbers[j] == target)
                {
                    ans.push_back(i + 1);
                    ans.push_back(j + 1);
                    return ans;
                }
            }
        }
        return ans;
    }
};
