#include <iostream>
#include <string>
using namespace std;

struct RandomListNode
{
    int label;
    RandomListNode* next;
    RandomListNode* random;
    RandomListNode(int x):label(x), next(NULL), random(NULL){}
};

// Naive Algorithm:
// copy list without random pointer
// restore copy list random pointer with original list
// Time Complexity: O(n^2)
// Space Complexity: O(1)
RandomListNode* copyRandomList(RandomListNode* head)
{
    if (head == NULL) return NULL;

    // copy the first node
    RandomListNode* copyHead = new RandomListNode(head->label);
    RandomListNode* cur = copyHead;

    // copy the rest list without the random pointer
    for (RandomListNode* p = head->next; p != NULL; p = p->next)
    {
        cur->next = new RandomListNode(p->label); 
        cur = cur->next;
    }

    //
    for (RandomListNode* p = head, *copyP = copyHead; p != NULL; 
            p = p->next, copyP = copyP->next)
    {
        if (p->random == NULL)
        {
            copyP->random = NULL;
        }
        else
        {
            RandomListNode* randomP = head, *randomCopyP = copyHead;
            for (;randomP != p->random;
                randomP = randomP->next, randomCopyP = randomCopyP->next)
            {
                // do nothing 
            }
            copyP->random = randomCopyP;
        }
    }

    return copyHead;
}

// Method 2:
// copy each node in the original node after each node
// e.g. original: {1, 2, 3}
//      copy:     {1, 1, 2, 2, 3, 3}
// original->next->random = original->random->next
//
// restore these two list after setting random pointer as said
// Time Complexity: O(n)
// Space Complexity: O(1)
RandomListNode* copyRandomList2(RandomListNode* head)
{
    if (head == NULL) return NULL;
    // copy the N node after each node
    for (RandomListNode* p = head; p != NULL;)
    {
        RandomListNode* nextP = p->next;

        RandomListNode* tmp = new RandomListNode(p->label);
        tmp->next = p->next;
        p->next = tmp;

        p = nextP;
    }
    // change the random pointer in copy node
    for (RandomListNode* p = head; p != NULL; p = p->next->next)
    {
        if (p->random == NULL)
        {
            p->next->random = NULL;
        }
        else
        {
            p->next->random = p->random->next; 
        }
    }
    // restore each list
    RandomListNode* copyHead = head->next;
    for (RandomListNode* p = head; p != NULL;)
    {
        RandomListNode* nextP = p->next->next;

        RandomListNode* originalNode = p;
        RandomListNode* copyNode = p->next;
        if (p->next->next != NULL)
        {
            originalNode->next = originalNode->next->next;
            copyNode->next = copyNode->next->next;
        }
        else
        {
            originalNode->next = originalNode->next->next;
            copyNode->next = NULL;
        }

        p = nextP;
    }
    return copyHead;
}

int main()
{
    RandomListNode* head = new RandomListNode(1);
    RandomListNode* p1 = head;
    //head->next = new RandomListNode(2);
    //RandomListNode* p2 = head->next;
    //head->next->next = new RandomListNode(3);
    //RandomListNode* p3 = head->next->next;

    p1->random = NULL;
    //p2->random = p3;
    //p3->random = p1;

    for (RandomListNode* p = head; p != NULL; p = p->next)
    {
        cout << " " << p->label;
        if (p->random == NULL) cout << " " << "NULL" << endl;
        else cout << " " << p->random->label << endl;
    }
    cout << "\n\n" << endl;

    RandomListNode* copyHead = copyRandomList2(head);

    for (RandomListNode* p = copyHead; p != NULL; p = p->next)
    {
        cout << " " << p->label;
        if (p->random == NULL) cout << " " << "NULL" << endl;
        else cout << " " << p->random->label << endl;
    }
    
    return 0;
}
