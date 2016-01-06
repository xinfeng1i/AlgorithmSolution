#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void subsetsRecursive(vector<int>& nums, int pos, vector<int>& curSet, set<vector<int> >& result);

vector<vector<int> > subsetsWithDup(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	
    set<vector<int> > result;
    vector<int> curSet;
    subsetsRecursive(nums, 0, curSet, result);
    
	vector<vector<int> > finalResult(result.begin(), result.end());
    
    return finalResult;
}

void subsetsRecursive(vector<int>& nums, int pos, vector<int>& curSet, set<vector<int> >& result) {
    if (pos >= nums.size()) {
        result.insert(curSet);
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
    int a[] = {1, 2, 2};
    vector<int> v(a, a + 3);
    vector<vector<int> > result = subsetsWithDup(v);
    cout << result.size() << endl;
    for (size_t i = 0; i < result.size(); ++i){
        PrintVec(result[i]);
    }
    return 0;
}
