#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};

ListNode* deleteDuplicates(ListNode* head)
{
	if (head == NULL) return NULL;
	if (head->next == NULL) return head;

	ListNode* cur = head;
	while (cur->next != NULL)
	{
		ListNode* pNext = cur->next;
		if (cur->val == pNext->val)
		{	// equal, delete next node
			ListNode* pTemp = pNext;
			cur->next = pNext->next;
			delete pTemp;
			pTemp = NULL;
		}
		else // not equal, check next node
		{
			cur = cur->next;
		}
	}

	return head;
}

int main()
{
	ListNode* head = NULL;
	head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(3);

	ListNode* newHead = deleteDuplicates(head);
	for (ListNode* cur = newHead; cur != NULL; cur = cur->next)
	{
		cout << " " << cur->val;
	}
	cout << endl;
	return 0;
}
