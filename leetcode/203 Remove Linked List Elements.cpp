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
		ListNode* removeElements(ListNode* head, int val)
		{
			if (head == NULL) return NULL;
			
			ListNode* pPre = NULL;
			ListNode* pCur = head;
			while (pCur != NULL)
			{
				if (pCur->val == val)
				{
					// first node, need change head pointer
					if (pPre == NULL)
					{
						head = pCur->next;
						pCur = pCur->next;
					}
					else
					{
						pPre->next = pCur->next;
						pCur = pCur->next;
					}
				}
				else
				{
					pPre = pCur;
					pCur = pCur->next;
				}
			}
			return head;
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
	head->next->next = new ListNode(1);
	PrintList(head);
	
	ListNode* ans = s.removeElements(head, 1);
	PrintList(ans);
	
	return 0;

}



