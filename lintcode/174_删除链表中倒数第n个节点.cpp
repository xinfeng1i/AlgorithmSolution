//
//  174_删除链表中倒数第n个节点.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/7/30.
//

#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x) {
        this->val = x;
        this->next = NULL;
    }
};


ListNode * removeNthFromEnd(ListNode * head, int n) {
    if (head == NULL) {
        return NULL;
    }
    
    ListNode* prev = NULL;
    ListNode* p1 = head;
    ListNode* p2 = p1;
    
    for (int i = 0; i < n; ++i) {
        p2 = p2->next;
    }
    
    while (p2 != NULL) {
        prev = p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    
    if (prev == NULL) {
        head = p1->next;
    } else {
        prev->next = p1->next;
    }
    
    return head;
}


void printList3(ListNode* head) {
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


int main() {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    ListNode* p5 = new ListNode(5);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    
    printf("before:\n");
    ListNode* head = p1;
    printList3(head);
    
    printf("after:\n");
    ListNode* h2 = removeNthFromEnd(head, 1);
    printList3(h2);
    
    return 0;
}
