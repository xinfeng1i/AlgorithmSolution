//
//  165_合并两个排序链表.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/8/3.
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


ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    // both not null
    ListNode* resultHead = NULL;
    ListNode* prev = NULL;
    
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->val <= p2->val) {
            if (resultHead == NULL) {
                resultHead = p1;
            } else {
                prev->next = p1;
            }
            prev = p1;
            p1 = p1->next;
        } else {
            if (resultHead == NULL) {
                resultHead = p2;
            } else {
                prev->next = p2;
            }
            prev = p2;
            p2 = p2->next;
        }
    }
    
    if (p1 == NULL) {
        prev->next = p2;
    }
    
    if (p2 == NULL) {
        prev->next = p1;
    }
    
    return resultHead;
}


void printList8(ListNode* head) {
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


#if 1
int main() {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(3);
    ListNode* p3 = new ListNode(8);
    ListNode* p4 = new ListNode(11);
    ListNode* p5 = new ListNode(15);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    ListNode* head1 = p1;
    
    ListNode* q1 = new ListNode(2);
    ListNode* q2 = new ListNode(3);
    ListNode* q3 = new ListNode(4);
    q1->next = q2;
    q2->next = q3;
    ListNode* head2 = q1;
    
    printf("before:");
    printList8(head1);
    printList8(head2);
    
    
    ListNode* newHead = mergeTwoLists(head1, head2);
    
    printf("after:");
    printList8(newHead);
    
    return 0;
}
#endif
