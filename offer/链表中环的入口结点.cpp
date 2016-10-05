#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

ListNode* EntryNodeOfLoop(ListNode* head)
{
	if (head == NULL) return NULL;
	if (head->next == NULL) return NULL;
	
	// slow, fast pointers to find the intersection
	ListNode* slow = head;
	ListNode* fast = head;
	do {
		slow = slow->next;
		fast = fast->next->next;
	} while (slow != fast);
	
	// from the intersection, find the entry of loop
	ListNode* temp = slow;
	ListNode* p1 = head;
	ListNode* p2 = temp;
	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}
