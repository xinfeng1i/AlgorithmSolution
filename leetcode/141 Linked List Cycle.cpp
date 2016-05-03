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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// 经典问题: 快慢指针判断链表环
bool hasCycle(ListNode* head) {
	if (head == NULL) return false;
	ListNode* pSlow = head;
	ListNode* pFast = head;
	while (pSlow != NULL && pFast != NULL && pFast->next != NULL) {
		pSlow = pSlow->next;
		pFast = pFast->next->next;
		if (pFast == pSlow) {
			return true;
		}
	}

	return false;
}