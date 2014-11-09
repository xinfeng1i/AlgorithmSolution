#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

// Method 1:
// Count the number of node in the loop, say, k
// set p1 = head, p2 = the kth node after head,
// both p1 and p2 step one by one, when they equal,
// they find the starting node of the loop
ListNode* detectCycle(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        // found loop
        if (slow != NULL && fast != NULL && slow == fast)
        {
            // calculate the number of nodes in the loop
            ListNode* loopNode = slow;
            int cnt = 1;
            while (fast->next != loopNode)
            {
                fast = fast->next;
                cnt++;
            }

            // reset slow point to head, and fast point to cnt-th Node 
            // after head, they will meet at the start node of the loop
            slow = head;
            fast = head;
            for (int i = 0; i < cnt; ++i)
            {
                fast = fast->next; 
            }

            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }
    return NULL;
}

// Method2:
// first use slow and fast pointer to find the loop and loopNode
// p1 start the from the head one by one,use p2 to check whether p1
// is in the loop, if not, p1 move one step, if yes, find it
ListNode* detectCycle2(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        // found loop
        if (slow != NULL && fast != NULL && slow == fast)
        {
            ListNode* loopNode = slow;
            ListNode* p1 = head;
            ListNode* p2 = loopNode;

            while (true)
            {
                // p2 always start from the loop node to the end
                p2 = loopNode;
                while (p2->next != loopNode && p2->next != p1)
                {
                    p2 = p2->next;
                }
                
                // found p1 in the loop
                if (p2->next == p1) return p1;
                // not found p1 in the loop, p1 move one step
                if (p2->next == loopNode) p1 = p1->next;
            }

        }
    }
    return NULL;
}

int main()
{
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = head->next->next;
    ListNode* ans = detectCycle2(head);
    cout << ans->val << endl;
    return 0;
}
