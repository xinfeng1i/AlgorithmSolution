#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#if 0
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// 经典问题：链表换检测，并判断环开始位置
ListNode *detectCycle(ListNode *head) {
	if (head == NULL) return NULL;

	bool foundCycle = false;
	ListNode* fast = head;
	ListNode* slow = head;
	while (slow != NULL && fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow) {
			foundCycle = true;
			break;
		}
	}

	if (!foundCycle) {
		return NULL;
	}

	ListNode* p1 = fast;
	ListNode* p2 = head;
	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}
#endif //0