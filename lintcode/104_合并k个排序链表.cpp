//
//  104_合并k个排序链表.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/8/7.
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

ListNode *mergeKLists(vector<ListNode *> &lists) {
    int n = (int)lists.size();
    
    ListNode* prev = NULL;
    ListNode* resultHead = NULL;
    
    // init
    vector<ListNode*> p;
    for (int i = 0; i < n; ++i) {
        p.push_back(lists[i]);
    }
    
    // init
    while (true) {
        // 1. find the min node
        ListNode* curMinNode = NULL;
        int curMinIndex = -1;
        bool isAllNull = true;
        for (int i = 0; i < n; ++i) {
            if (p[i] != NULL) {
                isAllNull = false;
                if (curMinNode == NULL) {
                    curMinNode = p[i];
                    curMinIndex = i;
                } else {
                    if (p[i]->val < curMinNode->val) {
                        curMinNode = p[i];
                        curMinIndex = i;
                    }
                }
            }
        }
        
        // 2. break if all ends
        if (isAllNull) {
            break;
        }
        
        // 3. insert the min node into result list
        if (prev == NULL) {
            resultHead = prev = curMinNode;
        } else {
            prev->next = curMinNode;
            prev = curMinNode;
        }
        p[curMinIndex] = p[curMinIndex]->next;
    }
    
    return resultHead;
}


void printList9(ListNode* head) {
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

// test case 1
#if 0
int main() {
    ListNode* h1 = new ListNode(2);
    h1->next = new ListNode(4);
    
    ListNode* h2 = NULL;
    
    ListNode* h3 = new ListNode(-1);
    vector<ListNode*> v;
    v.push_back(h1);
    v.push_back(h2);
    v.push_back(h3);
    
    ListNode* result = mergeKLists(v);
    printList9(result);
    
    return 0;
}
#endif // 0

#if 0
int main() {
    ListNode* h1 = new ListNode(2);
    h1->next = new ListNode(6);
    
    ListNode* h2 = new ListNode(5);
    
    ListNode* h3 = new ListNode(7);
    
    vector<ListNode*> v;
    v.push_back(h1);
    v.push_back(h2);
    v.push_back(h3);
    
    ListNode* result = mergeKLists(v);
    printList9(result);
    
    return 0;
}
#endif // 0
