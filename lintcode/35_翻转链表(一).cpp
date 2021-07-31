//
//  35_翻转链表(一).cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/7/31.
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


ListNode * reverse(ListNode * head) {
    if (head == NULL) {
        return NULL;
    }
    
    ListNode* prev = NULL;
    ListNode* cur = head;
    while(cur != NULL) {
        ListNode* next = cur->next;
        
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    
    return prev;
}


void printList4(ListNode* head) {
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
    // p1->next = p2;
    // p2->next = p3;
    
    ListNode* head = p1;
    
    printf("before:\n");
    printList4(head);
    
    ListNode* result = reverse(head);
    printf("after:\n");
    printList4(result);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    
    return 0;
}
#endif // 0
