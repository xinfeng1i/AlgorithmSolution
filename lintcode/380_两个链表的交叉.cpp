//
//  380_两个链表的交叉.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/8/13.
//

#include<cstdio>
#include<iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};


ListNode* findCycleEntry(ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == head) return head;

    ListNode* pSlow = head;
    ListNode* pFast = head;
    ListNode* pFrozen = NULL;
    while (pFast != NULL && pFast->next != NULL) {
        pFast = pFast->next->next;
        pSlow = pSlow->next;

        if (pFast == pSlow) {
            pFrozen = pFast;
            break;
        }
    }

    // case1: no cycle
    if (pFrozen == NULL) {
        return NULL;
    }

    // case2: has cycle
    pSlow = head;
    pFast = pFrozen;
    while (pSlow != pFast) {
        pSlow = pSlow->next;
        pFast = pFast->next;
    }

    return pSlow;
}

bool hasCommonNode(ListNode* h1, ListNode* h2) {
    if (h1 == NULL || h2 == NULL) return false;
    
    ListNode* p1 = h1;
    while (p1->next != NULL) {
        p1 = p1->next;
    }
    
    ListNode* p2 = h2;
    while (p2->next != NULL) {
        p2 = p2->next;
    }
    
    if (p1 == p2) {
        return true;
    } else {
        return false;
    }
}


ListNode* getIntersectionNode(ListNode* h1, ListNode* h2) {
    bool flag = hasCommonNode(h1, h2);
    if (!flag) {
        return NULL;
    }
    
    // find the last node
    ListNode* p1 = h1;
    while (p1->next != NULL) {
        p1 = p1->next;
    }
    ListNode* pLastFrozen = p1;
    
    // build the cycle
    pLastFrozen->next = h1;
    
    // find the entry node of cycle
    ListNode* entryNode = findCycleEntry(h2);
    
    // reverse the list to none cycle
    pLastFrozen->next = NULL;
    
    return entryNode;
}


/*
 //         / 1 \
 //        2     0
 //         \    /
 // 12->10->3->4
 //
 */
void testCycle1() {

    ListNode* p0 = new ListNode(0);
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);

    p0->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p0;

    ListNode* q1 = new ListNode(12);
    ListNode* q2 = new ListNode(10);
    q1->next = q2;
    q2->next = p3;

    ListNode* head = q1;

    ListNode* entry = findCycleEntry(head);

    if (entry == NULL) {
        printf("No Cycle!\n");
    } else {
        printf("Has Cycle: entry node: %d\n", entry->val);
    }
}


/*
 * 1->self
 */
void testCycle2() {
    ListNode* head = new ListNode(1);
    head->next = head;
    
    ListNode* entry = findCycleEntry(head);

    if (entry == NULL) {
        printf("No Cycle!\n");
    } else {
        printf("Has Cycle: entry node: %d\n", entry->val);
    }
}

/*
 * 1->2->reback to 1
 */
void testCycle3() {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    
    ListNode* head = p1;
    p1->next = p2;
    p2->next = p1;
    
    ListNode* entry = findCycleEntry(head);
    if (entry == NULL) {
        printf("No Cycle!\n");
    } else {
        printf("Has Cycle: entry node: %d\n", entry->val);
    }
}

/*
 * 1->2->reback to 2
 */
void testCycle4() {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    
    ListNode* head = p1;
    p1->next = p2;
    p2->next = p2;
    
    ListNode* entry = findCycleEntry(head);
    if (entry == NULL) {
        printf("No Cycle!\n");
    } else {
        printf("Has Cycle: entry node: %d\n", entry->val);
    }
}


void testFindCommon() {
    ListNode* p0 = new ListNode(0);
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    
    ListNode* h1 = p0;
    p0->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    
    ListNode* q1 = new ListNode(12);
    ListNode* q2 = new ListNode(10);
    ListNode* h2 = q1;
    q1->next = q2;
    q2->next = p3;
    
    ListNode* node = getIntersectionNode(h1, h2);
    if (node == NULL) {
        printf("No Intersection !\n");
    } else {
        printf("First Intersection node: %d\n", node->val);
    }
}



int main() {
    testFindCommon();
    return 0;
}
