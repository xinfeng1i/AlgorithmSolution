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

/**��һ��������������һ���������ظ������ֵ�����λ�ã���������ڣ����� -1��
 */
int findPosition(vector<int>& nums, int target) {
    if (nums.empty()) return -1;

    int left = 0;
    int right = (int)nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}


#if 0
int main() {
    vector<int> v = { 1,2,2,4,5,5 };
    int target = 6;

    int ans = findPosition(v, target);
    cout << ans << endl;

    return 0;
}
#endif // 0