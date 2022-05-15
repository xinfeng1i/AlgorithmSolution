#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


pair<ListNode*, ListNode*> getKthNode(ListNode* dummy, int k) {
    ListNode* pNULL = NULL;
    ListNode* head = dummy->next;
    if (head == NULL) return make_pair(pNULL, pNULL);

    int cnt = 0;
    ListNode* prev = dummy;
    ListNode* p = head;
    while (p != NULL) {
        cnt++;
        if (cnt == k) break;

        prev = p;
        p = p->next;
    }

    assert(cnt == k);
    if (cnt == k) return make_pair(prev, p);
    else return make_pair(pNULL, pNULL);
}

ListNode* reverseMyList(ListNode* head) {
    if (head == NULL) return NULL;

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


ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* pDummpy = new ListNode(-1);
    pDummpy->next = head;

    pair<ListNode*, ListNode*> res1 = getKthNode(pDummpy, left);
    pair<ListNode*, ListNode*> res2 = getKthNode(pDummpy, right);

    ListNode* prev1 = res1.first;
    ListNode* p1 = res1.second;
    ListNode* prev2 = res2.first;
    ListNode* p2 = res2.second;
    ListNode* next2 = p2->next;

    p2->next = NULL;
    ListNode* reHead = reverseMyList(p1);
    prev1->next = reHead;
    p1->next = next2;

    ListNode* result = pDummpy->next;
    delete pDummpy;
    pDummpy = NULL;

    return result;
}


void printMyList(ListNode* head) {
    ListNode* p = head;
    while (p != NULL) {
        cout << " " << p->val;
        p = p->next;
    }
    cout << endl;
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

    printMyList(head);
    ListNode* result = reverseBetween(head, 1, 1);
    printMyList(result);

    return 0;
}