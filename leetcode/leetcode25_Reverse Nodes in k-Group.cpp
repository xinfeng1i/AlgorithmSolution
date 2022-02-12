#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* p = head;
    while (p != NULL) {
        ListNode* temp = p->next;
        p->next = prev;

        prev = p;
        p = temp;
    }
    return prev;
}

void printList(ListNode* head) {
    ListNode* p = head;
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* pDummy = new ListNode(0);
    pDummy->next = head;

    ListNode* pGroupStart = pDummy;
    ListNode* pGroupEnd = pDummy;

    while (true) {
        // count k elements
        int cnt = 0;
        while (pGroupEnd != NULL) {
            pGroupEnd = pGroupEnd->next;
            if (pGroupEnd != NULL) cnt++;
            if (cnt == k) {
                break;
            }
        }
        // do not have k elements, end the full running
        if (cnt < k) break;

        // remember the first the and last elements of current group
        ListNode* pStart = pGroupStart->next;
        ListNode* pEnd = pGroupEnd;
        pGroupEnd = pGroupEnd->next;

        // reverse current group
        pEnd->next = NULL;
        pGroupStart->next = reverseList(pStart);
        pStart->next = pGroupEnd;

        // reset to move to next group
        pGroupStart = pStart;
        pGroupEnd = pStart;
    }

    return pDummy->next;
}


/*
 * 方法1：常规模拟法，每次反转k个元素，加入 dummy 节点
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
ListNode* reverseKGroupII(ListNode* head, int k) {
    ListNode* pDummpy = new ListNode(0);
    pDummpy->next = head;

    ListNode* pPrevGroup = pDummpy;
    ListNode* pNextGroup = pDummpy;

    while (true) {
        // counting k elements
        int n = 0;
        while (pNextGroup != NULL) {
            pNextGroup = pNextGroup->next;
            if (pNextGroup != NULL) n++;
            if (n == k) break;
        }

        // don't have k elements, terminate
        if (n < k) break;

        // init this group range
        ListNode* pStart = pPrevGroup->next;
        ListNode* pEnd = pNextGroup;
        pNextGroup = pNextGroup->next;

        // reverse this group
        pEnd->next = NULL;
        pPrevGroup->next = reverseList(pStart);
        pStart->next = pNextGroup;

        // reset to move to next iteration
        pPrevGroup = pStart;
        pNextGroup = pStart;
    }

    return pDummpy->next;
}


/*
 * 方法二：递归解法
 */
ListNode* reverseKGroupIII(ListNode* head, int k) {
    ListNode* p = head;
    
    // couting the k elmenents
    int n = 0;
    while (p != NULL) {
        n++;
        if (n == k) break;
        p = p->next;
    }

    // don't have k elements, no need to reverse.
    if (n < k) return head;

    // reverse the k elements
    ListNode* pStart = head;
    ListNode* pEnd = p;
    ListNode* nextGroup = pEnd->next;
    pEnd->next = NULL;
    
    ListNode* prev = NULL;
    p = head;
    while (p != NULL) {
        ListNode* tempNext = p->next;
        p->next = prev;

        prev = p;
        p = tempNext;
    }

    // recursion
    pStart->next = reverseKGroupIII(nextGroup, k);
    return prev;
}


#if 0
int main() {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    ListNode* p5 = new ListNode(5);
    ListNode* p6 = new ListNode(6);
    ListNode* p7 = new ListNode(7);
    ListNode* p8 = new ListNode(8);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;
    p7->next = p8;

    ListNode* head1 = p1;
    
    cout << "before:" << endl;
    printList(head1);

    cout << "after" << endl;
    ListNode* head2 = reverseKGroupIII(head1, 3);
    printList(head2);

    return 0;
}
#endif // 0


