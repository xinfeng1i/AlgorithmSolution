//
//  112_删除排序链表中的重复元素.cpp
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


ListNode * deleteDuplicates(ListNode * head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    ListNode* prev = head;
    ListNode* cur = head->next;
    while (cur != NULL) {
        ListNode* next = cur->next;
        if (cur->val != prev->val) {
            prev = cur;
            cur = next;
        } else {
            prev->next = cur->next;
            cur = next;
        }
    }
    
    return head;
}

void printList7(ListNode* head) {
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
    ListNode* p2 = new ListNode(1);
    ListNode* p3 = new ListNode(1);
    ListNode* p4 = new ListNode(2);
    ListNode* p5 = new ListNode(2);
    ListNode* p6 = new ListNode(3);
    ListNode* p7 = new ListNode(3);
    p1->next = p2;
//    p2->next = p3;
//    p3->next = p4;
//    p4->next = p5;
//    p5->next = p6;
//    p6->next = p7;
    ListNode* head = p1;
    
    printf("before:");
    printList7(head);
    
    ListNode* newHead = deleteDuplicates(head);
    
    printf("after:");
    printList7(newHead);
    
    return 0;
}
