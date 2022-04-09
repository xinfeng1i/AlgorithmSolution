#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


vector<vector<int>> permutation(vector<int>& v, int left, int right) {
    vector<vector<int>> result;
    if (left > right) return result;
    if (left == right) {
        vector<int> lst;
        lst.push_back(v[left]);
        result.push_back(lst);
        return result;
    }
    for (int i = left; i <= right; ++i) {
        swap(v[left], v[i]);
        vector<vector<int>> subList = permutation(v, left + 1, right);
        for (vector<int> temp : subList) {
            vector<int> thisList;
            thisList.push_back(v[left]);
            for (int x : temp) thisList.push_back(x);
            result.push_back(thisList);
        }
        swap(v[left], v[i]);

    }
    return result;
}

vector<vector<int>> permute(vector<int>& nums) {
    int n = (int)nums.size();
    return permutation(nums, 0, n - 1);
}

int main() {
    vector<int> v = { 1,2,3 };
    int n = (int)v.size();
    vector<vector<int>> result = permutation(v, 0, n - 1);
    for (vector<int> lst : result) {
        for (int x : lst) cout << " " << x;
        cout << endl;
    }

    return 0;
}