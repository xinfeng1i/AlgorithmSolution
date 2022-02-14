#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
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

int countNodeNumber(ListNode* head) {
    ListNode* p = head;
    int n = 0;
    while (p != NULL) {
        n++;
        p = p->next;
    }
    return n;
}


ListNode* reverseLinkList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* p = head;
    while (p != NULL) {
        ListNode* tempNext = p->next;
        
        p->next = prev;

        prev = p;
        p = tempNext;
    }

    return prev;
}


void printMyLinkList(ListNode* head) {
    ListNode* p = head;
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << "NULL" << endl;
    return;
}


void reorderList(ListNode* head) {
    // less than or equal to 2 nodes, no need to operation.
    if (head == NULL || head->next == NULL || head->next->next == NULL) return;

    // find middle
    int n = countNodeNumber(head);
    int half = (n + 1) / 2;

    ListNode* prev = NULL;
    ListNode* p = head;
    for (int i = 0; i < half; ++i) {
        prev = p;
        p = p->next;
    }

    // reverse the second list
    prev->next = NULL;
    ListNode* h1 = head;
    ListNode* h2 = p;
    ListNode* reverseH2 = reverseLinkList(h2);

    // chain the two list (h1, reverseH2) 
    ListNode* pDummy = new ListNode(-1);
    prev = pDummy;
    ListNode* p1 = h1;
    ListNode* p2 = reverseH2;
    bool flag = true;
    while (p1 != NULL && p2 != NULL) {
        if (flag) {
            prev->next = p1;
            prev = p1;
            p1 = p1->next;
            flag = false;
        }
        else {
            prev->next = p2;
            prev = p2;
            p2 = p2->next;
            flag = true;
        }
    }

    if (p1 != NULL) {
        prev->next = p1;
    }

    if (p2 != NULL) {
        prev->next = p2;
    }

    head = pDummy->next;
    return;
}





int main() {
    ListNode* p1 = new ListNode(0);
    ListNode* p2 = new ListNode(1);
    ListNode* p3 = new ListNode(2);
    ListNode* p4 = new ListNode(3);
    ListNode* p5 = new ListNode(4);
    ListNode* p6 = new ListNode(5);
    ListNode* p7 = new ListNode(6);
    ListNode* p8 = new ListNode(7);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;
    // p7->next = p8;

    ListNode* head = p1;
    printMyLinkList(head);

    reorderList(head);
    printMyLinkList(head);

    return 0;
}