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


void addElement(map<int, int>& cnt, int elem) {
    if (cnt.find(elem) == cnt.end()) {
        cnt[elem] = 1;
    }
    else {
        cnt[elem] += 1;
    }
}


int totalFruit(vector<int>& fruits) {
    if (fruits.empty()) return 0;

    map<int, int> cnt;
    int n = (int)fruits.size();
    int i = 0;
    int j = 0;
    int ans = 0;
    while (j < n) {
        while (j < n && cnt.size() < 2) {
            addElement(cnt, fruits[j]);
            j++;
        }
        if (j >= n && cnt.size() < 2) {
            ans = max(ans, j - i);
            break;
        }

        while (cnt.size() == 2 && j < n && cnt.find(fruits[j]) != cnt.end()) {
            addElement(cnt, fruits[j]);
            j++;
        }
        ans = max(ans, j - i);
        while (cnt.size() == 2 && cnt[fruits[i]] >= 2) {
            cnt[fruits[i]]--;
            i++;
        }

        cnt.erase(fruits[i]);
        i++;
    }
    return ans;
}


int main() {
    vector<int> v1 = { 1, 2, 1 };
    vector<int> v2 = { 0, 1, 2, 2 };
    vector<int> v3 = { 1, 2, 3, 2, 2 };

    cout << totalFruit(v1) << endl;
    cout << totalFruit(v2) << endl;
    cout << totalFruit(v3) << endl;
    return 0;
}