#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct ListNode
{
	int coef;
	int expn;
	ListNode* next;
	
	// 由于没有初始化 next 的指针引发的系统崩溃，谨记！
	ListNode(int _coef, int _expn) : coef(_coef), expn(_expn), next(NULL) {}
};

/* 追加一项到原有的多项式最后 */
void AttachNode(ListNode* &head, ListNode* &last, int coef, int expn)
{
	if (last == NULL) {
		head = last = new ListNode(coef, expn);
	} else {
		last->next = new ListNode(coef, expn);
		last = last->next;
	}
}

/* 计算两个多项式乘积，返回新的多项式作为结果 */
ListNode* MultiPoly(ListNode* L1, ListNode* L2)
{
	if (L1 == NULL || L2 == NULL) return NULL;
	
	ListNode* p1 = L1;
	ListNode* p2 = L2;
	ListNode* head = NULL;
	ListNode* last = NULL;
	
	// L1多项式的第一项与L2的各项相乘，计算初始结果的多项式
	while (p2 != NULL) {
		int c = p1->coef * p2->coef;
		int e = p1->expn + p2->expn;
		if (c != 0) {
			AttachNode(head, last, c, e);
		}
		p2 = p2->next;
	}
	
	p1 = p1->next;
	while (p1 != NULL) {
		// 计算L1的一项与L2每一项乘积的结果
		for (p2 = L2; p2 != NULL; p2 = p2->next) {
			int c = p1->coef * p2->coef;
			int e = p1->expn + p2->expn;
			
			// 在结果多项式中寻找合适的位置进行插入或者合并
			ListNode* pre = NULL;
			ListNode* cur = head;
			while (cur != NULL && cur->expn > e) {
				pre = cur;
				cur = cur->next;
			}
			// 所有指数都比当前项要大，直接插到最后面
			if (cur == NULL) {
				ListNode* newNode = new ListNode(c, e);
				if (pre == NULL) head = newNode;
				else pre->next = newNode;
			} else {
				// 找到指数相等的，需要合并
				if (cur->expn == e) {
					cur->coef += c;
					// 合并后指数刚好为0，需要删除该项
					if (cur->coef == 0) {
						ListNode* tmp = cur;
						if (pre == NULL) head = head->next;
						else pre = pre->next;
						delete tmp;
					}
				} else if (cur->expn < e) { // 找到指数比其小的，需要插入到后面
					ListNode* newNode = new ListNode(c, e);
					if (pre == NULL) {
						newNode->next = head;
						head = newNode;
					} else {
						newNode->next = pre->next;
						pre->next = newNode;
					}
				}
			}
		}
		p1 = p1->next;
	}
	return head;
}


/* 计算两个多项式的和，返回新的多项式作为结果 */
ListNode* AddPoly(ListNode* L1, ListNode* L2)
{
	ListNode* p1 = L1;
	ListNode* p2 = L2;
	ListNode* head = NULL;
	ListNode* last = NULL;
	
	while (p1 != NULL && p2 != NULL) {
		if (p1->expn == p2->expn) {
			if (p1->coef + p2->coef != 0) {
				AttachNode(head, last, p1->coef + p2->coef, p1->expn);
			}
			p1 = p1->next;
			p2 = p2->next;
		} else if (p1->expn > p2->expn) {
			if (p1->coef != 0) {
				AttachNode(head, last, p1->coef, p1->expn);
			}
			p1 = p1->next;
		} else {
			if (p2->coef != 0) {
				AttachNode(head, last, p2->coef, p2->expn);
			}
			p2 = p2->next;
		}
	}
	
	while (p1 != NULL) {
		AttachNode(head, last, p1->coef, p1->expn);
		p1 = p1->next;
	}
	
	while (p2 != NULL) {
		AttachNode(head, last, p2->coef, p2->expn);
		p2 = p2->next;
	}
	
	return head;
}


void PrintPoly(ListNode* L)
{
	if (L == NULL) {
		cout << "0 0" << endl;
		return;
	}
	
	bool isFirst = true;
	for (ListNode* p = L; p != NULL; p = p->next) {
		if (isFirst) {
			isFirst = false;
			cout << p->coef << " " << p->expn;
		} else {
			cout << " " << p->coef << " " << p->expn;
		}
		
	}
	cout << endl;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int n1, n2;
	int coef, expn;
	ListNode* head1 = NULL; ListNode* last1 = NULL;
	ListNode* head2 = NULL; ListNode* last2 = NULL;
	cin >> n1;
	for (int i = 0; i < n1; ++i) {
		cin >> coef >> expn;
		AttachNode(head1, last1, coef, expn);
	}
	cin >> n2;
	for (int i = 0; i < n2; ++i) {
		cin >> coef >> expn;
		AttachNode(head2, last2, coef, expn);
	}
	
	ListNode* ans1 = MultiPoly(head1, head2);
	PrintPoly(ans1);
	ListNode* ans2 = AddPoly(head1, head2);
	PrintPoly(ans2);
	return 0;
}
