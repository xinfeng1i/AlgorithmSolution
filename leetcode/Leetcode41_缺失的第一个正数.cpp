#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
#include <string>
using namespace std;


// ����һ�����Ͻ���ֱ����˾��ְ��������λ
int firstMissingPositive(vector<int>& nums) {
    int n = (int)nums.size();

    for (int i = 0; i < n; ++i) {
        if (nums[i] == i + 1) {
            ;
        }
        else if (nums[i] <= 0 || nums[i] >= n) {
            ;
        }
        else {
            while (nums[i] != i + 1 && nums[i] >= 1 && nums[i] <= n) {
                int toIdx = nums[i] - 1;
                // ע��swap������ toIdx λ����ֵ��ȣ���������ѭ�������� [1,1]
                if (nums[toIdx] != toIdx + 1) {
                    swap(nums[i], nums[toIdx]);
                }
                else {
                    break;
                }
            }
        }
    }

    int i = 0;
    for (i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            break;
        }
    }

    return i + 1;
}


// ������������ÿ��Ԫ�ظ�����Ǹ�Ԫ�صĴ�����
int firstMissingPositive(vector<int>& nums) {
    int n = (int)nums.size();

    const int VAL = n + 100;
    for (int i = 0; i < n; ++i) {
        if (nums[i] <= 0) {
            nums[i] = VAL;
        }
    }

    for (int i = 0; i < n; ++i) {
        int toIdx = abs(nums[i]) - 1;
        if (toIdx >= 0 && toIdx < n) {
            nums[toIdx] = -1 * abs(nums[toIdx]);
        }
    }

    int i = 0;
    for (i = 0; i < n; ++i) {
        if (nums[i] > 0) {
            break;
        }
    }
    return i + 1;

}