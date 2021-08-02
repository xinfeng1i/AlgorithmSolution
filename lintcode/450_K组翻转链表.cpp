//
//  450_K组翻转链表.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/8/2.
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


ListNode * reverseKGroup(ListNode* head, int k) {
    if (head == NULL) {
        return NULL;
    }
    
    if (k == 1) {
        return head;
    }
    
    ListNode* p1 = head;
    int num = 1;
    while (num < k && p1 != NULL) {
        p1 = p1->next;
        num += 1;
    }
    
    // case: length < k
    if (p1 == NULL) {
        return head;
    }
    
    // case: length >= k
    int curNum = 1;
    ListNode* pCur = head;
    while (curNum < k) {
        pCur = pCur->next;
        curNum += 1;
    }
    ListNode* pGroup1End = pCur;
    ListNode* pGroup2Begin = pCur->next;
    
    // 递归
    ListNode* subHead = reverseKGroup(pGroup2Begin, k);
    
    curNum = 1;
    pCur = head;
    ListNode* curNext = pCur->next;
    pCur->next = subHead;
    ListNode* curPrev = pCur;
    pCur = curNext;
    curNum += 1;
    while (curNum <= k) {
        curNext = pCur->next;
        pCur->next = curPrev;
        
        curPrev = pCur;
        pCur = curNext;
        curNum += 1;
    }
    
    
    return pGroup1End;
}


void printList6(ListNode* head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    
    ListNode* p = head;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("NULL\n");
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
    ListNode* head = p1;
    
    printf("before:\n");
    printList6(head);
    
    ListNode* newHead = reverseKGroup(head, 3);
    printf("after:\n");
    printList6(newHead);
    
    return 0;
}
#endif // 0
