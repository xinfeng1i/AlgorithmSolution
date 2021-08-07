//
//  102_带环链表.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/8/7.
//

#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x) {
        this->val = x;
        this->next = NULL;
    }
};


/* 快慢指针，判断是否存在环，经典问题 */
bool hasCycle(ListNode * head) {
    // zero node
    if (head == NULL) return false;
    
    // one node
    if (head->next == head) return true;
    if (head->next == NULL) return false;
    
    // more than one node
    ListNode* pSlow = head;
    ListNode* pFast = head;
    while (pFast != NULL && pFast->next != NULL) {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        if (pSlow == pFast) {
            return true;
        }
    }
    
    return false;
}

#if 1
int main() {
    ListNode* p1 = new ListNode(21);
    ListNode* p2 = new ListNode(10);
    ListNode* p3 = new ListNode(4);
    ListNode* p4 = new ListNode(5);
    
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    //p4->next = p2;
    ListNode* head1 = p1;
    
    bool ok = hasCycle(head1);
    
    if (ok) {
        printf("has cycle\n");
    } else {
        printf("no cycle\n");
    }
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    
    return 0;
}
#endif // 1
