#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* mergeKLists(vector<ListNode*> &lists)
{
    int n = lists.size();
    if (n == 0) return NULL;
    if (n == 1) return lists[0];

    vector<ListNode*> p(n);
    for (int i = 0; i < n; ++i)
    {
        p[i] = lists[i];
    }

    ListNode* head = NULL;
    ListNode* cur = NULL;

    while (true)
    {
        // point to the first Not NULL node, pivot
        ListNode* minP = new ListNode(1000000000);
        int minI = -1;
        for (int i = 0; i < n; ++i)
        {
            if (p[i] != NULL && p[i]->val < minP->val)
            {
                minP = p[i];
                minI = i;
            }
        }

        // all list are empty, terminate loop
        if (minI == -1) break;
        
        // minP ponit to the min node

        if (cur == NULL)
        {
            head = minP;
            cur = minP;
        }
        else
        {
            cur->next = minP;
            cur = minP;         // update current point
        }
        p[minI] = p[minI]->next;
    }

    return head;
}

int main()
{
    vector<ListNode*> lists(3);
    lists[0] = new ListNode(1);
    lists[0]->next = new ListNode(3);
    lists[0]->next->next = new ListNode(7);

    lists[1] = new ListNode(2);
    lists[1]->next = new ListNode(6);
    lists[1]->next->next = new ListNode(9);

    lists[2] = new ListNode(5);
    lists[2]->next = new ListNode(8);
    lists[2]->next->next = new ListNode(10);
    
    ListNode* head = mergeKLists(lists);
    for (ListNode* p = head; p != NULL; p = p->next)
    {
        cout << " " << p->val;
    }
    cout << endl;
    return 0;
}
