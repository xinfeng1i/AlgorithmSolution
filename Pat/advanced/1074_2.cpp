#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

const int MAXN = 100010;
struct InputNode {
	int addr;
	int value;
	int nextAddr;
};

struct ListNode {
	int addr;
	int value;
	ListNode* next;
	ListNode(int d, int k):addr(d), value(k), next(NULL) {}
};

InputNode inputs[MAXN];

ListNode* BuildList(int startAddr) {
	int curAddr = startAddr;
	if (curAddr == -1) return NULL;

	ListNode* head = NULL; ListNode* last = NULL;
	while (curAddr != -1) {
		ListNode* temp = new ListNode(inputs[curAddr].addr, inputs[curAddr].value);
		if (head == NULL) {
			head = last = temp;
		} else {
			last->next = temp;
			last = temp;
		}
		curAddr = inputs[curAddr].nextAddr;
	}
	return head;
}

void ReverseList(ListNode* &head, int k) {
	if (head == NULL) return;

	// 计算链表长度
	int len = 0;
	for (ListNode* p = head; p != NULL; p = p->next) {
		len++;
	}

	int MAX_LEN = len - len % k;
	
	int i = 0;
	ListNode* pLastSegmentFirst = NULL; // 记住上一组的第一个元素
	ListNode* pCurSegmentFirst = head;  // 记住当前组的第一个元素
	ListNode* cur = head;
	ListNode* prev = NULL;
	while (cur != NULL) {
		ListNode* next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		i++;
		if (i % k == 0) {
			if (pLastSegmentFirst == NULL) {
				head = prev;
			} else {
				pLastSegmentFirst->next = prev;
			}
			pLastSegmentFirst = pCurSegmentFirst;
			pCurSegmentFirst = cur;
			prev = NULL;	// 每组开始的第一个元素前驱重置为NULL以保证不无限循环
		}
		if (i == MAX_LEN) {
			pLastSegmentFirst->next = cur;
			return;
		}
	}
}

void PrintList(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->next) {
		if (p->next == NULL) printf("%05d %d -1\n", p->addr, p->value);
		else printf("%05d %d %05d\n", p->addr, p->value, p->next->addr);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int startAddr = -1; int n = 0; int k = 0;
	scanf("%d %d %d", &startAddr, &n, &k);

	int addr = 0; int data = 0; int nextAddr = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &addr, &data, &nextAddr);
		inputs[addr].addr = addr;
		inputs[addr].nextAddr = nextAddr;
		inputs[addr].value = data;
	}

	// construct list
	ListNode* head = BuildList(startAddr);

	// reverse list every k nodes, extra nodes are not reversed
	ReverseList(head, k);

	PrintList(head);

	return 0;

}