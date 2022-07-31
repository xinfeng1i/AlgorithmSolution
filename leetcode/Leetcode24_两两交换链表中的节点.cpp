//
//  Leetcode24_两两交换链表中的节点.cpp
//  HelloXcode
//
//  Created by xinfengli on 2022/7/31.
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

/*
 * Merge two list alternatively.
 */
ListNode* mergeTwoListAlternativelyUtils(ListNode* h1, ListNode* h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;
    
    ListNode* pDummy = new ListNode(-1);
    ListNode* pCur = pDummy;
    
    ListNode* p1 = h1;
    ListNode* p2 = h2;
    bool flag = true;
    while (p1 != NULL && p2 != NULL) {
        if (flag) {
            ListNode* temp = p2->next;
            p2->next = NULL;
            pCur->next = p2;
            pCur = pCur->next;
            
            p2 = temp;
            flag = !flag;
        } else {
            ListNode* temp = p1->next;
            
            p1->next = NULL;
            pCur->next = p1;
            pCur = pCur->next;
            
            p1 = temp;
            flag = !flag;
        }
    }
    
    if (p1 != NULL) {
        pCur->next = p1;
    }
    
    if (p2 != NULL) {
        pCur->next = p2;
    }
    
    return pDummy->next;
}


/*
 * Swap adjacent nodes
 *
 * Time: O(n)
 * Space: O(1)
 */
ListNode* swapPairs(ListNode* head) {
    ListNode* pDummy1 = new ListNode(-1);
    ListNode* pCur1 = pDummy1;
    
    ListNode* pDummy2 = new ListNode(-1);
    ListNode* pCur2 = pDummy2;
    
    // Step1: split the list into two lists: odd list and even list.
    ListNode* p = head;
    int cnt = 0;
    while (p != NULL) {
        cnt += 1;
        ListNode* temp = p->next;
        p->next = NULL;
        if (cnt % 2 == 1) {
            pCur1->next = p;
            pCur1 = pCur1->next;
        } else {
            pCur2->next = p;
            pCur2 = pCur2->next;
        }
        p = temp;
    }
    
    ListNode* h1 = pDummy1->next;
    ListNode* h2 = pDummy2->next;
    delete pDummy1;
    pDummy1 = NULL;
    delete pDummy2;
    pDummy2 = NULL;
    
    // Step2: merge the two list alternatively.
    ListNode* result = mergeTwoListAlternativelyUtils(h1, h2);
    
    return result;
}



int main() {
    ListNode* h = new ListNode(1);
    h->next = new ListNode(2);
    h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(4);
    h->next->next->next->next = new ListNode(5);
    
    ListNode* result = swapPairs(h);
    
    ListNode* p = result;
    while (p != NULL) {
        cout << " " << p->val;
        p = p->next;
    }
    cout << endl;
    
    return 0;
}
