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


ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* pDummy = new ListNode(0);
    pDummy->next = head;

    ListNode* pStart = NULL;
    ListNode* pStartPrev = NULL;
    ListNode* pEnd = NULL;
    ListNode* pEndNext = NULL;

    // find range [pStart, pEnd] to reverse
    ListNode* prev = pDummy;
    ListNode* p = head;
    int n = 0;
    while (p != NULL) {
        n++;
        if (n == left) {
            pStartPrev = prev;
            pStart = p;
        }

        if (n == right) {
            pEnd = p;
            pEndNext = pEnd->next;
        }
        prev = p;
        p = p->next;
    }

    // reverse range
    pEnd->next = NULL;
    prev = NULL;
    p = pStart;
    while (p != NULL) {
        ListNode* tempNode = p->next;
        p->next = prev;

        prev = p;
        p = tempNode;
    }

    // chain the whole list
    pStartPrev->next = pEnd;
    pStart->next = pEndNext;

    return pDummy->next;
}


void printMyList(ListNode* head) {
    ListNode* p = head;
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    ListNode* p5 = new ListNode(5);
    ListNode* p6 = new ListNode(6);
    ListNode* p7 = new ListNode(7);
    ListNode* p8 = new ListNode(8);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;

    ListNode* head = p1;
    printMyList(head);

    ListNode* head2 = reverseBetween(head, 1, 5);
    printMyList(head2);

    return 0;
}