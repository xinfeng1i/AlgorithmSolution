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


/*
 * Naive Algorithm:
 * Time: O(n * k), Space: O(1)
 * The solution will not be accepted. (TLE)
 */
vector<int> maxSlidingWindow_Method1(vector<int>& nums, int k) {
    vector<int> ans;
    int n = (int) nums.size();
    if (n < k) return ans;

    int j = k - 1;
    for (int i = 0; i <= n - k; ++i, ++j) {
        int maxNum = nums[i];
        for (int idx = i + 1; idx <= j; ++idx) {
            maxNum = max(maxNum, nums[idx]);
        }
        ans.push_back(maxNum);
    }
    return ans;   
}


// �������������ݼ����У�ͨ����ǰ�ų�����Ԫ���������ٶȣ��Լ������������
// �ռ临�Ӷȣ�O(n)
// ʱ�临�Ӷȣ�O(n)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    int n = (int)nums.size();
    if (n < k) return ans;

    // Note: the queue is store the INDEX not the NUMBER itself.
    deque<int> Q;
    // init the queue with first window
    int j = 0;
    for (j = 0; j <= k - 1; ++j) {
        while (!Q.empty() && nums[j] > nums[Q.back()]) Q.pop_back();
        Q.push_back(j);
    }
    ans.push_back(nums[Q.front()]);

    int i = 0;
    j = k - 1;
    while (i < n - k) {
        // ��������һ����λ����ʼλ��i��1����ֹλ��j��1
        i++;
        j++;
        // ����������λ���Ѿ����ٴ�����Чλ���ڣ����ų���Щλ��
        while (!Q.empty() && Q.front() < i) Q.pop_front();
        // ����ǰλ�� j ��ֵ�Ѿ��� k (<j) λ�õ�ֵ��Ļ�����ôkλ�õ�ֵ���Բ����ܳ�Ϊ
        // ֮�󴰿������ֵ�����Կ�����ǰ����Щλ���ų�����
        while (!Q.empty() && nums[j] > nums[Q.back()]) Q.pop_back();
        Q.push_back(j);
        ans.push_back(nums[Q.front()]);
    }
    return ans;
}

int main() {
    // vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
    // int k = 3;

    vector<int> nums = { 1, -1 };
    int k = 1;

    vector<int> ans = maxSlidingWindow(nums, k);
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}