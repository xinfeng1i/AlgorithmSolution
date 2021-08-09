//
//  113_删除排序链表中的重复数字(二).cpp
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


/*
 * 删除重复元素（包括元素本身)，例如:
 * Input: 1->2->2->2->3
 * Output: 1->3
 */
ListNode * deleteDuplicates2(ListNode * head) {
    // zero or one element, cannot be duplicates.
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    ListNode* newHead = NULL;
    ListNode* prev = NULL;
    ListNode* cur = head;
    while (cur != NULL) {
        // 如果当前节点有后继节点，且后继节点与当前节点不同
        if (cur->next == NULL) {
            // assign
            if (prev != NULL) {
                prev->next = cur;
                prev = cur;
                cur = cur->next;
            } else {
                newHead = prev = cur;
                cur = cur->next;
            }
            
        } else if (cur->val != cur->next->val) {
            // assign
            if (prev != NULL) {
                prev->next = cur;
                prev = cur;
                cur = cur->next;
            } else {
                newHead = prev = cur;
                cur = cur->next;
            }
        } else {
            // complicate logical
            ListNode* q = cur->next;
            while (q != NULL && q->val == cur->val) {
                q = q->next;
            }
            
            cur = q;
        }
    }
    
    // Note: 易错点：如果加上这个条件判断，则会导致最后的尾部节点仍然包含重复节点（没有被跳过）
    if (prev != NULL) {
        prev->next = cur;
    }
    
    return newHead;
}

void printList7b(ListNode* head) {
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
// 1->1->1->2->2->3->3
int main() {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(1);
    ListNode* p3 = new ListNode(1);
    ListNode* p4 = new ListNode(2);
    ListNode* p5 = new ListNode(2);
    ListNode* p6 = new ListNode(3);
    ListNode* p7 = new ListNode(3);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;
    ListNode* head = p1;
    
    printf("before:");
    printList7b(head);
    
    ListNode* newHead = deleteDuplicates2(head);
    
    printf("after:");
    printList7b(newHead);
    
    return 0;
}
#endif // 0


// 0->1->1->2->3
#if 0
int main() {
    ListNode* p1 = new ListNode(0);
    ListNode* p2 = new ListNode(1);
    ListNode* p3 = new ListNode(1);
    ListNode* p4 = new ListNode(2);
    ListNode* p5 = new ListNode(3);
    
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    ListNode* h1 = p1;
    
    printf("before:");
    printList7b(h1);
    
    ListNode* newHead = deleteDuplicates2(h1);
    
    printf("after:");
    printList7b(newHead);
    
    return 0;
}
#endif // 0


// test case 3
// -14->-13->-12->-12->-11->-11->-11->-11->-11->-10->-10->-9->-9->-9->-8->-8->-7->-7->-6->-5->-5->-5->-5->-3->-3->-3->-3->-2->-1->-1->-1->-1->0->0->0->1->1->1->1->1->2->2->2->3->3->3->3->4->4->5->5->6->6->6->6->7->7->8->8->8->8->8->8->9->9->9->9->10->10->10->11->11->12->12->13->13->13->13->13->14->14->15->15->15->16->16->16->16->17->17->17->17->18->18->18->18->19->19->21->21->21->22->23->24->25->25->25->25->25->null
//
