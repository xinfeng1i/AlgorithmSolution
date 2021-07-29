/*
 * Lintcode: 计算链表的中间节点
 *
 * Created by xinfengli on 2021/07/24
 */

#include <iostream>
#include <string>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;

    ListNode(int value) {
        this->data = value;
        this->next = NULL;
    }
};

/**
 * 经典的快慢指针问题，当快指针到达末尾时，慢指针刚好位于中间。
 * 注意：边界条件 
 */
ListNode* findMiddleNode(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* pSlow = head;
    ListNode* pFast = head;

    while (pFast != NULL && pFast->next != NULL) {
        pFast = pFast->next->next;
        pSlow = pSlow->next;
    }

    return pSlow;
}


void printList(ListNode* head) {
    if (head == NULL) {
        printf("NULL\n");
    }

    ListNode* p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}


int main() {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);

    ListNode* head = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    printList(head);

    ListNode* middle = findMiddleNode(head);
    printList(middle);

    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}
