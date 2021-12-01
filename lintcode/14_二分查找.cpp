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
using namespace std;

/**
 * ����һ��������������飨���򣩺�һ��Ҫ���ҵ����� target��
 * ��O(logn)���ҵ�target��һ�γ��ֵ��±꣨��0��ʼ�������target�������������У�����-1��
 */


int binarySearch(vector<int>& nums, int target) {
    int left = 0;
    int right = (int)nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        }
        else if (nums[mid] > target) {
            right = mid - 1;
        }
        else {
            right = mid;
        }
    }

    if (nums[left] == target) return left;
    else return -1;
}


int main() {
    vector<int> v = { 1, 2, 3, 3, 4, 5, 10 };
    int target = 3;

    int ans = binarySearch(v, target);
    printf("%d\n", ans);

    return 0;
}