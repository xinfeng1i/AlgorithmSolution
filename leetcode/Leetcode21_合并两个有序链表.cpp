//
//  Leetcode21_合并两个有序链表.cpp
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
 * classic merge operation.
 * Time: O(m+n)
 * Space: O(1)
 */
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* p1 = list1;
    ListNode* p2 = list2;
    
    ListNode* pDummy = new ListNode(-1);
    ListNode* pCur = pDummy;
    while (p1 != NULL && p2 != NULL) {
        if (p1->val <= p2->val) {
            ListNode* temp = p1->next;
            
            p1->next = NULL;
            pCur->next = p1;
            pCur = pCur->next;
            
            p1 = temp;
        } else {
            ListNode* temp = p2->next;
            
            p2->next = NULL;
            pCur->next = p2;
            pCur = pCur->next;
            
            p2 = temp;
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


#if 0
int main() {
    ListNode* h1 = new ListNode(1);
    h1->next = new ListNode(3);
    h1->next->next = new ListNode(5);
    
    ListNode* h2 = new ListNode(2);
    h2->next = new ListNode(4);
    h2->next->next = new ListNode(6);
    
    
    ListNode* result = mergeTwoLists(h1, h2);
    
    ListNode* p = result;
    while (p != NULL) {
        cout << " " << p->val;
        p = p->next;
    }
    cout << endl;
    
    return 0;
    
}
#endif // 0
