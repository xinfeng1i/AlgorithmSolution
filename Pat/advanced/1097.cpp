#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

#if 1
struct InputNode {
	int Address;
	int key;
	int Next;
};

struct Node {
	int Address;
	int key;
	Node* next;
	Node(int addr, int value) : Address(addr), key(value), next(NULL) {}
};

map<int, InputNode> hashtable;

Node* ConstructLinkList(int startAddress) {
	if (startAddress == -1) return NULL;
	
	Node* head = NULL;
	Node* pLast = NULL;
	int addr = startAddress;
	while (addr != -1) {
		InputNode temp = hashtable[addr];
		Node* pNewNode = new Node(temp.Address, temp.key);
		if (head == NULL) {
			head = pLast = pNewNode;
		} else {
			pLast->next = pNewNode;
			pLast = pNewNode;
		}
		addr = temp.Next;
	}
	return head;
}

void RemoveDuplicateNodesWithEqualAbsolutes(Node* head, Node* &newHead, Node* &duplicateHead)
{
	newHead = NULL;
	duplicateHead = NULL;
	Node* pDuplicateLast = NULL;
	if (head == NULL) return;

	set<int> absValues;
	Node* pre = NULL;
	Node* p = head;
	
	while(p != NULL) {
		int temp = abs(p->key);
		if (absValues.find(temp) == absValues.end()) {
			absValues.insert(temp);
			pre = p;
			p = p->next;
		} else {
			Node* pDuplicateNode = p;
			// skip this node
			p = p->next;
			pre->next = p;

			// insert this duplicate node in a new list
			pDuplicateNode->next = NULL;
			if (duplicateHead == NULL) {
				duplicateHead = pDuplicateLast = pDuplicateNode;
			} else {
				pDuplicateLast->next = pDuplicateNode;
				pDuplicateLast = pDuplicateNode;
			}
		}
	}

	newHead = head;
	return;
}

void PrintList(Node* head) {
	// NOTICE: if list is NULL, then print nothing not -1
	for (Node* p = head; p != NULL; p = p->next) {
		if (p->next == NULL) {
			printf("%05d %d -1\n", p->Address, p->key);
		} else {
			printf("%05d %d %05d\n", p->Address, p->key, p->next->Address);
		}
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	int startAddress; int n;
	cin >> startAddress >> n;
	InputNode temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp.Address >> temp.key >> temp.Next;
		hashtable[temp.Address] = temp;
	}

	Node* head = ConstructLinkList(startAddress);
	Node* pNewHead;
	Node* pDuplicateHead;
	RemoveDuplicateNodesWithEqualAbsolutes(head, pNewHead, pDuplicateHead);
	PrintList(pNewHead);
	PrintList(pDuplicateHead);

	return 0;
}
#endif //0