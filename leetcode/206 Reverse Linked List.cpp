#include<iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
	public:
		ListNode* reverseList(ListNode* head)
		{
			if (head == NULL) return head;
			
			ListNode* pPre = NULL;
			ListNode* pCur = head;
			
			while (pCur != NULL)
			{
				// remember the next node
				ListNode* pNext = pCur->next;
				// reverse
				pCur->next = pPre;
				// udpate
				pPre = pCur;
				pCur = pNext;
			}
			
			return pPre;
		}
		
};

void PrintList(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->next)
	{
		cout << " " << p->val;
	}
	cout << endl;
}

int main()
{
	Solution s;
	ListNode* head = new ListNode(0);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	PrintList(head);
	ListNode* ans = s.reverseList(head);
	PrintList(ans);
	return 0;
}


