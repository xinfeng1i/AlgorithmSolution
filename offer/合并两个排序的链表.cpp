#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* Merge(ListNode* p1, ListNode* p2)
    {
        ListNode* p = new ListNode(-1); // dummy head node
        ListNode* last = p;
        
        while (p1 != NULL && p2 != NULL) {
            if (p1->val <= p2->val) {
                AttachNode(last, p1->val);
                p1 = p1->next;
            } else {
                AttachNode(last, p2->val);
                p2 = p2->next;
            }
        }
        
        while (p1 != NULL) {
            AttachNode(last, p1->val);
            p1 = p1->next;
        }
        
        while (p2 != NULL) {
            AttachNode(last, p2->val);
            p2 = p2->next;
        }
        
        ListNode* temp = p;
        p = p->next; // skip the dummpy head node
        delete temp;
        temp = NULL;
        return p;
    }
    
    void AttachNode(ListNode* &pLast, int val) {
        pLast->next = new ListNode(val);
        pLast = pLast->next;
    }
};
