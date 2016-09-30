#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> printListFromTailToHead(struct ListNode* head) {
    vector<int> ans;
    for (ListNode* p = head; p != NULL; p = p->next) {
        ans.push_back(p->val);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
