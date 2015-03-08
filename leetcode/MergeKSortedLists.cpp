#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
	ListNode* newList = NULL;
	ListNode* preNode = NULL;

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minHeap;

	int n = lists.size();


	// push the first n elements into a Min-Heap
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		if (lists[i] != NULL) k++;
	}
	if (k == 0) return NULL;

	// Construct a min-Heap with the head-K elements
	for (int i = 0; i < n; ++i)
	{
		if (lists[i] != NULL)
		{
			minHeap.push(make_pair(lists[i]->val, i));
		}
	}

	// remove the min element, and insert to the answer list
	// until the heap is empty
	while (minHeap.size() > 0)
	{
		// pop the minimum element
		auto tmp = minHeap.top();
		minHeap.pop();

		// insert it into the answer list
		ListNode* pNewNode = new ListNode(tmp.first);
		if (preNode != NULL)
		{
			preNode->next = pNewNode;
			preNode = pNewNode;
		}
		else
		{
			newList = pNewNode;
			preNode = pNewNode;
		}

		// the pointer move to next
		lists[tmp.second] = lists[tmp.second]->next;
		// if not NULL, push the next element into heap so that
		// the heap size is still k
		// else not push element, the heap size is k - 1
		if (lists[tmp.second] != NULL)
		{
			minHeap.push(make_pair(lists[tmp.second]->val, tmp.second));
			//cout << "push:" << lists[tmp.second]->val << endl;
		}
	}


	return newList;
}

int main()
{
	ListNode* L1 = new ListNode(1);
	L1->next = new ListNode(2);
	L1->next->next = new ListNode(3);

	ListNode* L2 = new ListNode(4);
	L2->next = new ListNode(5);
	L2->next->next = new ListNode(6);

	vector<ListNode*> v;
	v.push_back(L1);
	v.push_back(L2);

	ListNode* ans = mergeKLists(v);
}