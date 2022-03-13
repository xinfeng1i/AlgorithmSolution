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


// ����stack���⣺
// ������Ѱ��һ������[i,j]ʹ�� (j-i+1)*min_height([i,j])���
// �۲쵽���� x1 < x2����� h1 > h2���������ĳ��λ��y�õ�������
// ���x2�������㣬���Ȼx1�������㣻��������x2���Ӷ�������������
// ��������ѵ��
// Time: O(n), Space: O(n)
int largestRectangleArea(vector<int>& heights) {
    if (heights.empty()) return 0;

    // trick���ڱ�Ԫ�أ���֤��stack��������ʱ�������Ȼ�ܹ�����
    heights.push_back(0);

    // ��ʼ��stack
    int res = 0;
    stack<int> S;
    for (size_t i = 0; i < heights.size(); ++i) {
        // �����������������(S.top().top(), i) ����������ľ������
        while (!S.empty() && heights[S.top()] > heights[i]) {
            int idx = S.top(); S.pop();
            int h = heights[idx];

            int prevIndex = S.empty() ? -1 : S.top();
            int w = i - prevIndex - 1;
            res = max(res, w * h);
        }
        S.push(i);
    }

    // reset �ڱ�Ԫ��
    heights.pop_back();
    return res;
}


#if 0
int main() {
    vector<int> v = { 2, 1, 3, 1, 1, 1 };
    vector<int> v2 = { 2, 1, 5, 6, 2, 3 };
    vector<int> v3 = { 4, 2, 0, 3, 2, 5 };
    int ans = largestRectangleArea(v3);
    cout << ans << endl;
    return 0;
}
#endif // 0