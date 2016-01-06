#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void subsetsRecursive(vector<int>& nums, int pos, vector<int>& curSet, vector<vector<int> >& result);
vector<vector<int> > subsets(vector<int>& nums) {
	sort(nums.begin(), nums.end());
    vector<vector<int> > result;
    vector<int> curSet;
    subsetsRecursive(nums, 0, curSet, result);
    return result;
}

void subsetsRecursive(vector<int>& nums, int pos, vector<int>& curSet, vector<vector<int> >& result) {
    if (pos >= nums.size()) {
        result.push_back(curSet);
        return;
    }

    // choose the pos-th element
    curSet.push_back(nums[pos]);
    subsetsRecursive(nums, pos+1, curSet, result);
    curSet.pop_back(); // reset
    
    // not choose pos-th element
    subsetsRecursive(nums, pos+1, curSet, result);
}

void PrintVec(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

int main()
{
    int a[] = {1, 2, 3};
    vector<int> v(a, a + 3);
    vector<vector<int> > result = subsets(v);
    cout << result.size() << endl;
    for (size_t i = 0; i < result.size(); ++i){
        PrintVec(result[i]);   
    }
    return 0;
}
