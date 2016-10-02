#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 复制含有随机指针的链表
 * 1. 在每个节点A后面增加Clone一个节点A'
 * 2. 通过A指针的random域来赋值A'的random域
 *    即: A'->random = A->random->next // 注意此时A->random 可能为空
 * 3. 分离A节点所在链表和A'节点所在链表
 *
 */

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

void CloneNode(RandomListNode* head) {
	RandomListNode* p = head;
	while (p != NULL) {
		// remember the next node of current node
		RandomListNode* pNext = p->next;
		
		// clone and link the new node
		RandomListNode* pNewNode = new RandomListNode(p->label);
		pNewNode->next = p->next;
		p->next = pNewNode;
		
		// goto next node
		p = pNext;
	}
}

void SetRandomLink(RandomListNode* head) {
	RandomListNode* p = head;
	RandomListNode* pClone = p->next;
	while (p != NULL) {
		// set the random link
		// 注意此处：random指针有可能为空
		if (p->random == NULL) pClone->random = NULL;
		else pClone->random = p->random->next;
		
		// walk the list
		p = p->next->next;
		pClone = p->next;
	}
}

RandomListNode* SeperateRandomList(RandomListNode* head) {
	RandomListNode* head2 = NULL;
	RandomListNode* plast2 = NULL;
	
	RandomListNode* p = head;
	while (p != NULL) {
		RandomListNode* pNext = p->next->next;
		RandomListNode* pClone = p->next;
		
		// reset the original list link
		p->next = pClone->next;
		
		// Attch the even node to the list2
		if (plast2 == NULL) {
			head2 = plast2 = pClone;
		} else {
			plast2->next = pClone;
			plast2 = pClone;
		}
		
		// walk to the next node
		p = pNext;
	}
	return head2;
}



RandomListNode* Clone(RandomListNode* head) {
	if (head == NULL) return NULL;
	CloneNode(head);
	SetRandomLink(head);
	RandomListNode* pCloneHead = SeperateRandomList(head);
	return pCloneHead;
}
