//
//  36_翻转链表(二).cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/7/31.
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
 * Notice: 提前记住start/end的前后节点，方便到时候取数不至于指向已经发生变化
 */
ListNode * reverseBetween(ListNode * head, int m, int n) {
    if (head == NULL) {
        return NULL;
    }
    
    if (m == n) {
        return head;
    }
    
    ListNode* prev = NULL;
    ListNode* p = head;
    int num = 1;
    
    // step1: 找到区间起始节点
    while (num < m) {
        prev = p;
        p = p->next;
        num += 1;
    }
    ListNode* pStart = p;
    ListNode* pStartPrev = prev;
    
    // step2: 找到区间终止节点
    while (num < n) {
        prev = p;
        p = p->next;
        num += 1;
    }
    ListNode* pEnd = p;
    ListNode* pEndNext = p->next;
    
    // step3: 区间反转
    prev = pStartPrev;
    p = pStart;
    ListNode* next = p->next;
    p->next = pEndNext;
    
    prev = p;
    p = next;
    while (p != pEndNext) {
        next = p->next;
        
        p->next = prev;
        prev = p;
        p = next;
    }
    
    // 判读起始节点是否为第一个节点
    if (pStartPrev != NULL) {
        pStartPrev->next = pEnd;
    } else {
        head = pEnd;
    }
    
    return head;
}


void printList5(ListNode* head) {
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
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;
    ListNode* head = p1;
    
    printf("before:\n");
    printList5(head);
    
    ListNode* rHead = reverseBetween(head, 1, 7);
    
    printf("after:\n");
    printList5(rHead);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete p6;
    delete p7;
    
    return 0;
}
#endif // 0
