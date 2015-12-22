#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// 对于第k栈灯它被toggle的次数，等于k个因子个数
// 如果是奇数个，则最后是on状态；反之是off状态
// 如果因子是奇数个，则其必然为完全平方数，所以直接判断
// 是否为完全平方数即可
int bulbSwitch(int n) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int mid = sqrt(double(i));
        if (mid * mid == i) {
            cnt += 1;
        }
    }
    return cnt;   
}

int main()
{
    int n = 6;
    cout << bulbSwitch(n) << endl;
    return 0;
}
