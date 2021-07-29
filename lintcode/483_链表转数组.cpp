//
//  LintCode: 483-链表转数组
//  HelloXcode
//
//  Created by xinfengli on 2021/7/28.
//

#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x) {
        this->val = x;
        this->next = NULL;
    }
};


vector<int> toArrayList(ListNode * head) {
    vector<int> result;
    
    if (head == NULL) {
        return result;
    }
    
    ListNode* p = head;
    while (p != NULL) {
        result.push_back(p->val);
        p = p->next;
    }
    
    return result;
}

#if 0
int main() {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    
    ListNode* head = p1;
    
    vector<int> result = toArrayList(head);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    
    for (auto x: result) {
        printf("%d ", x);
    }
    printf("\n");
}
#endif //0
 
