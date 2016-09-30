#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 链表的简单打印和反转
 */
vector<int> printListFromTailToHead(struct ListNode* head) {
    vector<int> ans;
    for (ListNode* p = head; p != NULL; p = p->next) {
        ans.push_back(p->val);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
