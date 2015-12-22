#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    // 计算两个数的XOR值，如果该值的某位为1，则必然说明
    // a，b在该位上一个为0，一个为1
    int aXORb = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        aXORb ^= nums[i];
    }
    
    // 找出右端开始的第一个bit为1的值
    int rightmost_bit_set = (~(aXORb - 1)) & aXORb;
    
    int x = 0;
    int y = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        // 如果当前值在该位为1，则进入x集合
        if (nums[i] & rightmost_bit_set) {
            x ^= nums[i];
        // 否则进入y集合
        } else {
            y ^= nums[i];
        }
    }
    
    // a, b必然一个在x集合，一个在y集合
    vector<int> v;
    v.push_back(x);
    v.push_back(y);
    return v;
}

int main()
{
    int a[6] = {1, 2, 1, 3, 2, 5};
    vector<int> v(a, a + 6);
    vector<int> ans = singleNumber(v);
    cout << ans[0] << endl;
    cout << ans[1] << endl;
    return 0;
}
