#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//  π”√≤„–Ú±È¿˙
Node* connect(Node* root) {
    if (root == NULL) return NULL;

    queue<Node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        int n = Q.size();
        for (int i = 0; i < n; ++i) {
            Node* node = Q.front();
            Q.pop();

            if (i < n - 1) node->next = Q.front();
            if (node->left != NULL) Q.push(node->left);
            if (node->right != NULL) Q.push(node->right);
        }

    }

    return root;
}
