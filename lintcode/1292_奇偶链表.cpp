//
//  1292_奇偶链表.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/7/28.
//

#include <vector>
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

// 1 -> 2 -> 3 -> 4 -> 5
//
ListNode* oddEvenList(ListNode * head) {
    // 只有0个或者1个节点，不需要重排
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    ListNode* p1 = head;
    ListNode* p2 = p1->next;
    
    ListNode* pFirstEvenNode = p1->next;
    ListNode* pLastEvenNode = p1->next;
    ListNode* pLastOddNode = p1;
    int cnt = 1;
    
    while (p1->next != NULL) {
        p1->next = p2->next;
        
        // move
        p1 = p2;
        p2 = p2->next;
        cnt += 1;
        if (cnt % 2 == 1) {
            pLastOddNode = p1;
        } else {
            pLastEvenNode = p1;
        }
    }
    
    // 最后再将奇数最后一个节点，指向偶数的第一个节点
    pLastOddNode->next = pFirstEvenNode;
    pLastEvenNode->next = NULL;
    
    return head;
}


void printList(ListNode* head) {
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
    
    ListNode* head = p1;
    
    printf("before:\n");
    printList(head);
    
    printf("after:\n");
    ListNode* newHead = oddEvenList(head);
    printList(newHead);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}
