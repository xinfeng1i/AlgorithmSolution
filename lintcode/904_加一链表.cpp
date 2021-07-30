//
//  904_加一链表.cpp
//  HelloXcode
//
//  思路：反转两次链表：反转->计算求和->反转
//
//  Created by xinfengli on 2021/7/29.
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


/* 反转列表 */
ListNode* reverseLinkList(ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    
    ListNode* prev = NULL;
    ListNode* cur = head;
    while (cur != NULL) {
        ListNode* next = cur->next;
        
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    
    return prev;
}


ListNode * plusOne(ListNode * head) {
    if (head == NULL) {
        return NULL;
    }
    
    // 第一次反转链表
    ListNode* rHead1 = reverseLinkList(head);
    
    // 链表内计算加法
    ListNode* prev = NULL;
    ListNode* p = rHead1;
    int addon = 1;
    while (p != NULL) {
        int temp = p->val + addon;
        p->val = temp % 10;
        addon = temp / 10;
        
        prev = p;
        p = p->next;
    }
    
    // 需要创建新节点
    if (addon != 0) {
        p = new ListNode(addon);
        prev->next = p;
    }
    
    // 第二次反转链表
    ListNode* rHead2 = reverseLinkList(rHead1);
    
    return rHead2;
}


void printList2(ListNode* head) {
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
    ListNode* p1 = new ListNode(9);
    ListNode* p2 = new ListNode(9);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    ListNode* p5 = new ListNode(9);
    p1->next = p2;
//    p2->next = p3;
//    p3->next = p4;
//    p4->next = p5;
    
    ListNode* head = p1;
    
    printf("before:\n");
    printList2(head);
    
    printf("after:\n");
    ListNode* newHead = plusOne(head);
    
    printList2(newHead);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    
    return 0;
}
