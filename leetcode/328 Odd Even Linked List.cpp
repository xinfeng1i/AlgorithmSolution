#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <assert.h>
#include <stdio.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head) {
	if (head == NULL) return NULL;

	ListNode* copy_head = head;
	ListNode* head1 = new ListNode(0);
	ListNode* head2 = new ListNode(0);
	ListNode* p1 = head1;
	ListNode* p2 = head2;

	int cnt = 1;
	while (head) {
		if (cnt % 2 == 1) {
			p1->next = head;
			p1 = head;
		} else {
			p2->next = head;
			p2 = head;
		}
		head = head->next;
		cnt++;
	}

	p2->next = NULL;
	p1->next = head2->next;
	return head1->next;
}

