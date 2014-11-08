#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode* p1 = l1;
	ListNode* p2 = l2;

	ListNode* l = NULL;
	ListNode* p = l;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->val <= p2->val)
		{
			ListNode* pNewNode = new ListNode(p1->val);
			if (p != NULL) { p ->next = pNewNode; p = p->next; }
			else { l = p = pNewNode; }
			p1 = p1->next;
		}
		else
		{
			ListNode* pNewNode = new ListNode(p2->val);
			if (p != NULL) { p ->next = pNewNode; p = p->next; }
			else { l = p = pNewNode; }
			p2 = p2->next;
		}

	}
	
	if (p1 == NULL)
	{
		while (p2 != NULL)
		{
			ListNode* pNewNode = new ListNode(p2->val);
			if (p != NULL) { p ->next = pNewNode; p = p->next; }
			else { l = p = pNewNode; }
			p2 = p2->next;
		}
	}

	if (p2 == NULL)
	{
		while (p1 != NULL)
		{
			ListNode* pNewNode = new ListNode(p1->val);
			if (p != NULL) { p->next = pNewNode; p = p->next; }
			else { l = p = pNewNode; }
			p1 = p1->next;
		}
	}

	return l;
}

