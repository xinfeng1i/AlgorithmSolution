#include <cstdio>
#include <cstdlib>
#include <climits>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;

/*
 * ��Ŀ����������һ�����������0��1��Ѱ���������1�����䳤��
 *
 * Method1: ʹ��˫ָ�룬���ϱ�������
 * ʱ�临�Ӷȣ�O(n)
 * �ռ临�Ӷȣ�O(1)
 */
int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = (int) nums.size();
    int ans = 0;

    int i = 0;
    while (i < n) {
        // ����֮ǰ��0
        while (i < n && nums[i] == 0) i++;
        if (i >= n) break;

        // j ָ�벻��Ѱ��������1
        int j = i + 1;
        while (j < n && nums[j] == 1) j++;
        ans = max(ans, j - i);
        i = j;
    }

    return ans;
}

/*
 * Method2: ��ָ������1��ʼ����������0��������
 * ʱ�临�Ӷȣ�O(n)
 * �ռ临�Ӷ�: O(1)
 */

int findMaxConsecutiveOnes2(vector<int>& nums) {
    int ans = 0;
    int cnt = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] == 1) {
            cnt++;
        } else {
            cnt = 0;
        }
        ans = max(ans, cnt);
    }
    return ans;
}


#if 0
int main() {
    vector<int> v1 = { 1, 1, 0, 1, 1, 1 };
    vector<int> v2 = { 1, 0, 1, 1, 0, 1 };

    int ans1 = findMaxConsecutiveOnes2(v1);
    int ans2 = findMaxConsecutiveOnes2(v2);

    printf("%d\n", ans1);
    printf("%d\n", ans2);

    return 0;
}
#endif // 0