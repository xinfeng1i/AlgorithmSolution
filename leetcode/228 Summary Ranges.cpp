#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

string ToString(int x) {
	char a[512] = {'\0'};
    sprintf(a, "%d", x);
    return string(a);
}

string rangeStr(int x, int y) {
    char a[1024] = {'\0'};
    sprintf(a, "%d->%d", x, y);
    return string(a);
}

vector<string> summaryRanges(vector<int>& nums) {
    int i = 0, j = i + 1;
    int n = nums.size();
    int minNum = 0, maxNum = 0;
    vector<string> ans;
    while (i < n) {
        j = i + 1;
        while (j < n && nums[j] == nums[j-1] + 1) j++;
        
        string s = "";
        if (j - 1 == i) {
		   s = ToString(nums[i]);
        } else {
        	 minNum = nums[i];
        	 maxNum = nums[j-1];
        	 s = rangeStr(minNum, maxNum);
        }
        ans.push_back(s);
        i = j;
    }
    return ans;
}

int main()
{
    int a[6] = {0, 1, 2, 4, 5, 7};
    vector<int> v(a, a + 6);
    vector<string> ans = summaryRanges(v);
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
