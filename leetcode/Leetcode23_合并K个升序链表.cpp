//
//  Leetcode23_合并K个升序链表.cpp
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
 * Method 1: Merge sort
 *
 * Time: O(N*k), where N is the total number of elements
 * Space: O(k)
 */
ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = (int) lists.size();
    vector<ListNode*> p(k, NULL);
    
    // init
    for (int i = 0; i < k; ++i) {
        p[i] = lists[i];
    }
    
    ListNode* pDummy = new ListNode(-1);
    ListNode* pCur = pDummy;
    
    while (true) {
        // S1: compare to find the minNumber of current k, pointed by q
        ListNode* q = NULL;
        int idx = -1;
        for (int i = 0; i < k; ++i) {
            if (p[i] == NULL) continue;
            if (q == NULL) {
                q = p[i];
                idx = i;
            } else if (p[i]->val < q->val) {
                q = p[i];
                idx = i;
            }
        }
        
        if (q == NULL) {
            break;
        }
        
        // S2: append this node to the result
        ListNode* temp = q->next;
        q->next = NULL;
        pCur->next = q;
        pCur = pCur->next;
        
        // S3: move to next
        p[idx] = temp;
    }
    
    return pDummy->next;
}


/*
 * Define function object used to compare the two ListNode* object
 */
struct cmp {
    bool operator()(ListNode* a, ListNode* b) const {
        return a->val > b->val;
    }
};


/*
 * Method II: use heap to get the min of current k elements
 *
 * Time: O(N*logk)
 * Space: O(k)
 */
ListNode* mergeKListsII(vector<ListNode*>& lists) {
    int k = (int) lists.size();
    
    // init
    vector<ListNode*> p(k, NULL);
    for (int i = 0; i < k; ++i) {
        p[i] = lists[i];
    }
    
    // build heap of size k
    priority_queue<ListNode*, vector<ListNode*>, cmp> Q;
    for (int i = 0; i < k; ++i) {
        if (p[i] != NULL) {
            Q.push(p[i]);
        }
    }
    
    ListNode* pDummy = new ListNode(-1);
    ListNode* pCur = pDummy;
    while (!Q.empty()) {
        // pop current min node of this k elements.
        ListNode* thisNode = Q.top();
        Q.pop();
        
        ListNode* next = thisNode->next;
        
        // append to the result
        thisNode->next = NULL;
        pCur->next = thisNode;
        pCur = pCur->next;
        
        // push next node to queue
        if (next != NULL) {
            Q.push(next);
        }
    }
    
    return pDummy->next;
}


int main() {
    ListNode* h1 = new ListNode(1);
    h1->next = new ListNode(4);
    h1->next->next = new ListNode(5);
    
    ListNode* h2 = new ListNode(1);
    h2->next = new ListNode(3);
    h2->next->next = new ListNode(4);
    
    ListNode* h3 = new ListNode(2);
    h3->next = new ListNode(6);
    
    vector<ListNode*> lists;
    lists.push_back(h1);
    lists.push_back(h2);
    lists.push_back(h3);
    
    ListNode* result = mergeKListsII(lists);
    ListNode* p = result;
    while (p != NULL) {
        cout << " " << p->val;
        p = p->next;
    }
    
    return 0;
}
