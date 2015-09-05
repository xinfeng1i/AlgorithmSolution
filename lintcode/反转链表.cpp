#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iterator>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

ListNode* reverse(ListNode* head) {
    if (head == NULL) return NULL;

    ListNode* pre = NULL;
    ListNode* cur = head;
    while (cur != NULL) {
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

int main()
{
    ListNode* head = NULL;
    //ListNode* head = new ListNode(1);
    //head->next = new ListNode(2);
    //head->next->next = new ListNode(3);
    ListNode* ans = reverse(head);
    for (ListNode* p = ans; p != NULL; p = p->next) {
        cout << " " << p->val;
    }
    cout << endl;
    return 0;
}