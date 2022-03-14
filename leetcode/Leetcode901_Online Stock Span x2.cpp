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


class StockSpanner {
private:
    stack<pair<int, int>> st;
    bool isStart;
    int idx;
public:
    StockSpanner() {
        isStart = false;
        idx = -1;
    }

    int next(int price) {
        if (!isStart) {
            isStart = true;
            idx = 0;
        }

        int ans = 1;
        while (!st.empty() && st.top().second <= price) {
            pair<int, int> p = st.top(); st.pop();
            int prev = st.empty() ? -1 : st.top().first;
            ans = idx - prev;
        }
        st.push(make_pair(idx, price));
        idx++;

        return ans;
    }
};