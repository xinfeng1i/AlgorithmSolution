#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

/**
 * Method1: ʹ��ǰ׺���飬ʱ�临�Ӷ� O(n^2)���ռ临�Ӷ� O(n)
 *          �÷�������ֳ�ʱTLE����Ҫ�Ż�ʱ�临�Ӷ�
 */
int shortestSubarray_Method1(vector<int>& nums, int k) {
    if (nums.empty()) return -1;

    int n = (int)nums.size();
    vector<int> prefix(nums.begin(), nums.end());
    for (int i = 1; i < n; ++i) prefix[i] = prefix[i - 1] + nums[i];

    int minDiff = INT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int curSum = prefix[j] - prefix[i] + nums[i];
            if (curSum >= k) {
                minDiff = min(minDiff, j - i + 1);
            }
        }
    }

    return minDiff == INT_MAX ? -1 : minDiff;
}


// ���������ǵ��͵ĵ����������⣬���˺ܳ�ʱ��ȥ���������ɵ�solution
//        ʱ�临�Ӷ�:O(n)���ռ临�Ӷ�:O(n)
int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    int ans = INT_MAX;
    deque<int> Q;
    for (int j = 0;j <= n; ++j) {
        // ���Ԫ��j�Ͷ���Ԫ��i�������Ѿ�����Ҫ����j+1֮��ı�Ȼ�������������(����)
        // ����û��Ҫ�жϺ�����j+1��ֱ���ж�i+1��ʼ��Ԫ�ؼ���
        while (!Q.empty() && prefix[j] - prefix[Q.front()] >= k) {
            ans = min(ans, j - Q.front());
            Q.pop_front();
        }

        // ���j�Ͷ�β��ȸ�С�Ļ�����ô������i��j��ͷ�������Ҫ�����Ȼ��ѡ��j����Ϊi
        // ��ʼ�Ļ����������(����)������û��Ҫ���ж���i��ͷ�������Ƿ�����Ҫ��
        while (!Q.empty() && prefix[j] < prefix[Q.back()]) {
            Q.pop_back();
        }
        
        Q.push_back(j);
    }
    return ans == INT_MAX ? -1 : ans;
}