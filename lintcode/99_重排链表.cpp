//
//  99_重排链表.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/8/10.
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


ListNode* findMiddleNode(ListNode* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return head;
    }

    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}


ListNode* reverseList(ListNode* head) {
    if (head == NULL) return NULL;
    
    ListNode* prev = NULL;
    ListNode* cur = head;
    while (cur != NULL) {
        ListNode* tempNext = cur->next;
        
        cur->next = prev;
        prev = cur;
        cur = tempNext;
    }
    
    return prev;
}

/*
 * Merge两个链表交替的，例如:
 * Input:
 * Head1: 1->2->3
 * Head2: 4->5->6->7
 * Output:
 *        1->4->2->5->3->6->7
 */
ListNode* mergeTwoListAlternately(ListNode* head1, ListNode* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    
    ListNode* head = NULL;
    ListNode* prev = NULL;
    ListNode* p1 = head1;
    ListNode* p2 = head2;
    bool flag = true;
    
    while (p1 != NULL && p2 != NULL) {
        if (flag) {
            // append p1
            if (prev == NULL) {
                head = prev = p1;
                p1 = p1->next;
            } else {
                prev->next = p1;
                prev = p1;
                p1 = p1->next;
            }
            flag = false;
        } else {
            // append p2;
            if (prev == NULL) {
                head = prev = p2;
                p2 = p2->next;
            } else {
                prev->next = p2;
                prev = p2;
                p2 = p2->next;
            }
            
            flag = true;
        }
    }
    
    if (p1 != NULL) {
        prev->next = p1;
    }
    
    if (p2 != NULL) {
        prev->next = p2;
    }
    
    return head;
}

void reorderList(ListNode * head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return;
    }
    
    // Step1: 寻找中间节点
    ListNode* mid = findMiddleNode(head);
    
    // Step2: 翻转后半链表节点
    ListNode* head2 = mid->next;
    mid->next = NULL;
    ListNode* newHead2 = reverseList(head2);
    
    // Step3: 交替Merge得到结果
    ListNode* result = mergeTwoListAlternately(head, newHead2);
}





void printList10(ListNode* head) {
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
    
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    
    ListNode* head = p1;
    printList10(head);
    
    reorderList(head);
    printList10(head);
    
    return 0;
}
#endif // 0
