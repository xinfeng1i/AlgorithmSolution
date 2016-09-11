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
    ListNode* FindKthToTail(ListNode* head, unsigned int k) {
    	// whether k is valid
    	int n = 0;
 		for (ListNode* p = head; p != NULL; p = p->next) {
            n++;
        }
        if (k < 1 || k > n) return NULL;
    	
    	// nomal
        if (head == NULL) return NULL;
        unsigned int idx = 1;
        ListNode* fast = head;
        while (idx < k) {
            fast = fast->next;
            idx ++;
        }
        
        ListNode* slow = head;
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    
    }
};

int main()
{
	Solution sl;
	ListNode* p = new ListNode(1);
	p->next = new ListNode(2);
	p->next->next = new ListNode(3);
	ListNode* temp = sl.FindKthToTail(p, 4);
	cout << "temp: " << temp->val << endl;
	return 0;
}
