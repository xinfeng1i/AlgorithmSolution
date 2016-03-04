#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

// build list and convert to struct sorting
struct InputNode {
	int curAddr;
	int key;
	int nextAddr;
};

struct ListNode {
	int key;
	int addr;
	ListNode* next;
	ListNode(int k, int a) : key(k), addr(a), next(NULL) {}
};

struct VecNode {
	int key;
	int addr;
	VecNode(int key_, int addr_) : key(key_), addr(addr_) {}

	bool operator<(const VecNode& other) const {
		if (key != other.key) {
			return key < other.key;
		} else {
			return addr < other.addr;
		}
	}
};

const int MAXN = 100000;
InputNode inputs[MAXN];

ListNode* ConstructList(int startAddr) {
	if (startAddr == -1) return NULL;

	ListNode* head = NULL;
	ListNode* last = NULL;
	int addr = startAddr;
	while (addr != -1) {
		ListNode* temp = new ListNode(inputs[addr].key, inputs[addr].curAddr);
		if (last == NULL) {
			head = last = temp;
		} else {
			last->next = temp;
			last = temp;
		}
		addr = inputs[addr].nextAddr;
	}

	return head;
}

void PrintList(ListNode* head) {
	if (head == NULL) return;

	for (ListNode* p = head; p != NULL; p = p->next) {
		if (p->next != NULL) {
			printf("%05d %d %05d\n", p->addr, p->key, p->next->addr);
		} else {
			printf("%05d %d -1\n", p->addr, p->key);
		}
	}
}

// quiksort for linklist si too slow
void SortList(ListNode* head, ListNode* lastNext) {
	// only 0 or 1 nodes, no need to sort
	if (head == NULL || head == lastNext || head->next == lastNext) return;

	// pivot point to the last node
	ListNode* pivot = head;
	while (pivot->next != lastNext) {
		pivot = pivot->next;
	}

	ListNode* pi = NULL;
	ListNode* pj = head;
	for (pj = head; pj != pivot; pj = pj->next) {
		if (pj->key <= pivot->key) {
			if (pi == NULL) {
				pi = head;
			} else {
				pi = pi->next;
			}
			// swap the content of pi and pj
			int temp_key = pi->key;
			int temp_addr = pi->addr;
			pi->key = pj->key;
			pi->addr = pj->addr;
			pj->key = temp_key;
			pj->addr = temp_addr;
		}
	}

	// swap the pivot the middle the list
	if (pi == NULL) {
		pi = head;
	} else {
		pi = pi->next;
	}
	int temp_key = pi->key;
	int temp_addr = pi->addr;
	pi->key = pj->key;
	pi->addr = pj->addr;
	pj->key = temp_key;
	pj->addr = temp_addr;

	SortList(head, pi);
	if (pi != NULL) {
		SortList(pi->next, lastNext);
	}
}

void PrintVec(const vector<VecNode>& v) {
	int n = v.size();
	for (int i = 0; i < n; ++i) {
		if (i == n-1) {
			printf("%05d %d -1\n", v[i].addr, v[i].key);
		} else {
			printf("%05d %d %05d\n", v[i].addr, v[i].key, v[i+1].addr);
		}
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	int n = 0; int startAddr;
	scanf("%d %d", &n, &startAddr);

	int curAddr = 0; int key = 0; int nextAddr = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &curAddr, &key, &nextAddr);
		inputs[curAddr].curAddr = curAddr;
		inputs[curAddr].key = key;
		inputs[curAddr].nextAddr = nextAddr;
	}

	// build list
	ListNode* head = ConstructList(startAddr);


	// before sorting
	//PrintList(head);

	/*
	SortList(head, NULL);

	int cnt = 0;
	for (ListNode* p = head; p != NULL; p = p->next) {
		cnt++;
	}

	if (cnt == 0) {
		printf("0 -1\n");
	} else {
		printf("%d %05d\n", cnt, head->addr);
		PrintList(head);
	}
	*/

	vector<VecNode> v;
	for (ListNode* p = head; p != NULL; p = p->next) {
		VecNode temp(p->key, p->addr);
		v.push_back(temp);
	}

	sort(v.begin(), v.end());
	size_t cnt = v.size();
	if (cnt == 0) {
		printf("0 -1\n");
	} else {
		printf("%d %05d\n", cnt, v[0].addr);
		PrintVec(v);
	}

	return 0;
}