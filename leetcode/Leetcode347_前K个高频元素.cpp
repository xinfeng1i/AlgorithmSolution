#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

struct Item {
    int value;
    int freq;
    Item(int v, int f) : value(v), freq(f) {}
};

struct cmp {
    bool operator()(Item& x, Item& y) {
        if (x.freq != y.freq) {
            return x.freq > y.freq;
        }
        else {
            return x.value > y.value;
        }
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;

        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            if (cnt.find(nums[i]) == cnt.end()) {
                cnt[nums[i]] = 1;
            }
            else {
                cnt[nums[i]]++;
            }
        }

        priority_queue<Item, vector<Item>, cmp> Q;
        unordered_map<int, int>::iterator it;
        for (it = cnt.begin(); it != cnt.end(); ++it) {
            Item item = Item(it->first, it->second);
            if (Q.size() < k) {
                Q.push(item);
            }
            else {
                if (item.freq > Q.top().freq) {
                    Q.pop();
                    Q.push(item);
                }
            }
        }

        vector<int> result;
        while (!Q.empty()) {
            Item item = Q.top();
            Q.pop();
            result.push_back(item.value);
        }

        return result;
    }
};


int main() {
    // vector<int> v = { 1,1,1,2,2,3 };
    vector<int> v = { 1 };
    Solution obj = Solution();
    vector<int> result = obj.topKFrequent(v, 1);

    cout << "result: " << endl;
    for (int x : result) {
        cout << " " << x;
    }
    cout << endl;
    return 0;
}