#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    
    // 后缀数组: b[j] = a[j+1]*a[j+2]*a[j+3]*...*a[n-1]
    vector<int> b(n, 0);
    b[n - 1] = 1;
    for (int j = n - 2; j >= 0; --j) {
        b[j] = nums[j + 1] * b[j + 1];
    }
    
    // 前缀数组
    int temp = nums[0];
    nums[0] = 1;
    for (int j = 1; j < n; ++j) {
        int temp2 = nums[j];
        nums[j] = nums[j-1] * temp;
        temp = temp2;
    }
    
    // 结果 c[j] = a[j] * b[j]
    for (int j = 0; j < n; ++j) {
        b[j] = b[j] * nums[j];
    }
    
    return b;
}

void PrintVec(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

int main()
{
    int a[4] = {18, 12};
    vector<int> v(a, a + 2);
    vector<int> ans = productExceptSelf(v);
    PrintVec(ans);
    return 0;
    
}
