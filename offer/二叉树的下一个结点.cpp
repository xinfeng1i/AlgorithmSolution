#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cassert>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

/*
 * 线索二叉树的遍历:
 * 1. 如果该节点是NULL，返回NULL
 * 2. 如果该节点的右子树非空，则下一个节点为右子树中的"最左"节点
 * 3. 如果该节点的右子树为空，找到其父节点
 *    3.1 其父节点为NULL，返回NULL
 *    3.2 该节点为父节点的左孩子，则父节点极为下一个节点
 *    3.3 该节点为父节点的有孩子，则节点不断上移，直到发现3.1和3.2的情况为止
 */
TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (pNode == NULL) return NULL;
	// 右子树不空，则最左节点为下一个节点
	if (pNode->right != NULL) {
		TreeLinkNode* p = pNode->right;
		while (p->left != NULL) {
			p = p->left;
		}
		return p;
	} else {
	// 右子树为空
		TreeLinkNode* parentNode = pNode->next;
		while (true) {
		    // 1. 没有父节点，也就没有后续节点
		    if (parentNode == NULL) {
				return NULL;
		    } else {
		    	// 2. 父节点不空，同时当前节点是父节点的左孩子，则父节点为下一个节点
		    	if (parentNode->left == pNode) {
		    		return parentNode;
				} else {
					// 3. 父节点不空，同时当前节点是父节点的右孩子，则指针上移
					pNode = parentNode;
					parentNode = pNode->next;
				}
			}
	    }
	}
	return NULL;
}
