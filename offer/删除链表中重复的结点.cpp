#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

/*
 * 复杂的链表删除问题
 * 1. 注意下一个节点是否与当前节点重复操作是完全不同的，因此需要flag标记
 * 2. 确定了需要删除的情况后，要考虑删除的刚好是head的节点时，需要重置
 *    头指针
 */

ListNode* deleteDuplication(ListNode* head)
{
	if (head == NULL) return NULL;
	if (head->next == NULL) return head;
	
	ListNode* newHead = head;
	ListNode* prev = NULL;
	ListNode* p1 = head;
	while (p1 != NULL) {
		ListNode* p2 = p1->next;
		bool found = false;
		while (p2 != NULL && p2->val == p1->val) {
			found = true;
			p2 = p2->next;
		}
		
		if (!found) {
			prev = p1;
			p1 = p2;
		} else {
			if (prev == NULL) {
				prev = NULL;
				p1 = p2;
				newHead = p2;
			} else {
				prev->next = p2;
				p1 = p2;
			}
		}
		
	}

	return newHead;
}

void PrintList(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->next) {
		cout << " " << p->val;
	}
	cout << endl;
}

int main()
{
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	ListNode* p3 = new ListNode(3);
	ListNode* p4 = new ListNode(3);
	ListNode* p5 = new ListNode(4);
	ListNode* p6 = new ListNode(4);
	ListNode* p7 = new ListNode(5);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p7;
	ListNode* head = p1;
	
	cout << "List:" << endl;
	PrintList(head);
	
	ListNode* head2 = deleteDuplication(head);
	cout << "New List:" << endl;
	PrintList(head2);
	return 0;
}
