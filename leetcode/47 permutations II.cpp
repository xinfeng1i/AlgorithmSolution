#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void permuteUniqueRecursive(vector<int>& nums, int pos, vector<vector<int> >& result) {
    // base case
    if (pos >= nums.size()) {
        result.push_back(nums);
        return;
    }
    
    set<int> visited;
    for (size_t i = pos; i < nums.size(); ++i) {
        // this number has been swapped, skip it
        if (visited.find(nums[i]) != visited.end()) continue;
        
        // otherwise, swap this number and marked it as swapped
        visited.insert(nums[i]);
        swap(nums[pos], nums[i]);
        permuteUniqueRecursive(nums, pos + 1, result);
        swap(nums[pos], nums[i]);
    }
}

vector<vector<int> > permuteUnique(vector<int>& nums) {
    vector<vector<int> > result;
    permuteUniqueRecursive(nums, 0, result);
    return result;
}

// test
void PrintVec(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    
    vector<vector<int> > result = permuteUnique(v);
    
    for (size_t i = 0; i < result.size(); ++i) {
        PrintVec(result[i]);
    }
    
    return 0;
}
