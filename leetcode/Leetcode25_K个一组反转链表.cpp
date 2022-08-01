//
//  Leetcode25_K个一组反转链表.cpp
//  HelloXcode
//
//  Created by xinfengli on 2022/8/1.
//

#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverseListUtil(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* p = head;
    while (p != NULL) {
        ListNode* temp = p->next;
        p->next = prev;
        
        prev = p;
        p = temp;
    }
    return prev;
}


ListNode* reverseEveryKNodes(ListNode* head, int k) {
    if (head == NULL) return NULL;
    if (k == 1) return head;
    
    // resulting list
    ListNode* pDummy = new ListNode(-1);
    ListNode* pLast = pDummy;
    
    ListNode* pStart = head;
    while (true) {
        // counting k nodes
        ListNode* p = pStart;
        int cnt = 0;
        while (p != NULL) {
            cnt += 1;
            if (cnt == k) {
                break;
            }
            p = p->next;
        }
        
        // if there is less than k nodes, no need to reverse
        if (cnt < k) {
            break;
        }
        
        // reverse this k nodes
        ListNode* pEnd = p;
        ListNode* pNextGroup = pEnd->next;
        pEnd->next = NULL;
        ListNode* reverseHead = reverseListUtil(pStart);
        
        // append this k nodes to result
        pLast->next = reverseHead;
        pLast = pStart;
        
        // move to next iteration
        pStart = pNextGroup;
    }
    
    // append the remain nodes to resulting list
    pLast->next = pStart;
    
    return pDummy->next;
}


int main() {
    ListNode* h = new ListNode(1);
    h->next = new ListNode(2);
    h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(4);
    h->next->next->next->next = new ListNode(5);
    h->next->next->next->next->next = new ListNode(6);
    h->next->next->next->next->next->next = new ListNode(7);
    
    int k = 5;
    
    ListNode* result = reverseEveryKNodes(h, k);
    
    ListNode* p = result;
    while (p != NULL) {
        cout << " " << p->val;
        p = p->next;
    }
    cout << endl;
    
    return 0;
    
}
