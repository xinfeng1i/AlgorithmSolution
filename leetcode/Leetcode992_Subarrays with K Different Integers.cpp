#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

void addElem(map<int, int>& cnt, int elem) {
    if (cnt.find(elem) == cnt.end()) {
        cnt[elem] = 1;
    }
    else {
        cnt[elem] += 1;
    }
}

void removeElem(map<int, int>& cnt, int elem) {
    if (cnt[elem] >= 2) {
        cnt[elem] -= 1;
    }
    else if (cnt[elem] == 1) {
        cnt.erase(elem);
    }
}


// �������ھ������⣬ �ο����˵��������
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
int subarraysWithKDistinct(vector<int>& nums, int k) {
    int n = (int)nums.size();
    
    map<int, int> cnt;
    int ans = 0;

    int i = 0;
    int j = 0;
    while (j <  n) {
        // ��������ڵ��ַ�������Ҫ���Ҳ����󴰿�
        while (cnt.size() < k && j < n) {
            addElem(cnt, nums[j]);
            j++;
        }
        if (cnt.size() < k && j >= n) break;

        int prefix = 0;
        while (cnt.size() == k) {
            // �����������Ҫ����̶��Ҳ�j�������ƶ����i��
            // ÿ�ƶ�һ�Σ����ɵ�[i,j]���������Ҫ��ֱ����ര�ڵ���߽�λ��
            while (cnt.size() == k && cnt[nums[i]] > 1) {
                prefix++;
                removeElem(cnt, nums[i]);
                i++;
            }
            ans += prefix + 1;

            if (j >= n) break;
            // ����Ҳ���һ���ַ����Ѿ������ַ�������Ҫ�����µĴ���
            // ������ര��һ��λ��
            if (cnt.find(nums[j]) == cnt.end()) {
                removeElem(cnt, nums[i]);
                i++;
            } else {
                // ����Ҳ���һ��λ���ַ������ڴ����ڣ����������Ҫ��
                // �����Ҳര��һ��λ��
                addElem(cnt, nums[j]);
                j++;
            }

        }
    }
    return ans;
}

int main() {
    vector<int> v = { 1,2,1,2,3 };
    int k = 2;
    int ans = subarraysWithKDistinct(v, k);
    cout << ans << endl;
    return 0;
}