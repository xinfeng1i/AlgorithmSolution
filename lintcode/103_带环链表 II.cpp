//
//  103_带环链表 II.cpp
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

/*
 * 判断链表是否存在环，如果存在则返回环的入口节点；如果不存在，返回NULL\
 */
ListNode* detectCycle(ListNode * head) {
    // zero node
    if (head == NULL) return NULL;
    
    // one node (without or with cycle)
    if (head->next == NULL) return NULL;
    if (head->next == head) return head;
    
    // Now >=2 nodes
    ListNode* pSlow = head;
    ListNode* pFast = head;
    ListNode* pFrozen = NULL;
    bool hasCycle = false;
    while (pFast != NULL && pFast->next != NULL) {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
        
        // found cycle, remember meeting node
        if (pSlow == pFast) {
            pFrozen = pSlow;
            hasCycle = true;
            break;
        }
    }
    
    // result: no cycle
    if (!hasCycle) {
        return NULL;
    }
    
    // result: has cycle, find the entry node
    ListNode* p1 = head;
    ListNode* p2 = pFrozen;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}


#if 1
int main() {
    ListNode* p1 = new ListNode(-21);
    ListNode* p2 = new ListNode(10);
    ListNode* p3 = new ListNode(4);
    ListNode* p4 = new ListNode(5);
    
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p2;
    ListNode* head = p1;
    
    ListNode* entryNode = detectCycle(head);
    
    if (entryNode == NULL) {
        printf("no cycle\n");
    } else {
        printf("entry node value: %d\n", entryNode->val);
    }
    
    return 0;
}
#endif // 0
