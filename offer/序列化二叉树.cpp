#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    char* Serialize(TreeNode *root) {
    	char* str = new char[4096];
    	memset(str, '\0', sizeof(str));
    	char* p = str;
    	
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* temp = q.front();
			q.pop();
			
			if (temp == NULL) {
				if (p == str) {*p = '^'; p++;}
				else {*p = '|'; p++; *p = '^'; p++;}
			} else {
				//*p = (temp->val)+'0'; p++;
				
				char buf[64] = {'\0'};
				memset(buf, '\0', sizeof(buf));
				sprintf(buf, "%d", temp->val);
				
				if (p == str) {
					strcpy(p, buf);
					p += strlen(buf);
				} else {
					*p = '|'; p++;
					strcpy(p, buf);
					p += strlen(buf);
				}
				
				q.push(temp->left);
				q.push(temp->right);
			}
		}
		
		return str;

    }
    TreeNode* Deserialize(char *str) {
    	char* p = str;
    	if (str == NULL || *p == '^') return NULL;
    	
    	//queue<int> q;
		queue<TreeNode*> q2;
		
		if (*p == '|') p++;
		char* nextp = p;
		while (nextp && *nextp != '|') nextp++;
		char num[64] = {'\0'}; char* pnum = num;
		while(p != nextp) *pnum++ = *p++;
		int val = atoi(num);
		//cout << "val = " << val << endl;
		
    	TreeNode* root = new TreeNode(val);
    	q2.push(root);
    	while (!q2.empty()) {
    		//char temp = q.front(); q.pop();
    		TreeNode* pnode = q2.front(); q2.pop();
    		//cout << "pnode->val = " << pnode->val << endl;
    		if (pnode != NULL) {
    			if (*p == '|') p++;
    			char val1 = *p;
    			if (val1 != '^') {
    			
					if (*p == '|') p++;
					nextp = p;
					while (nextp && *nextp != '|') nextp++;
					memset(num, '\0', sizeof(num));
					pnum = num;
					while(p != nextp) *pnum++ = *p++;
					int val11 = atoi(num);
					
	                pnode->left = new TreeNode(val11);
	                //q.push(val1);
					q2.push(pnode->left);
				} else {
					p++;
				}
				
				if (*p == '|'); p++;
				char val2 = *p;
    			if (val2 != '^') {
				    if (*p == '|') p++;
					nextp = p;
					while (nextp && *nextp != '|') nextp++;
					memset(num, '\0', sizeof(num));
					pnum = num;
					while(p != nextp) *pnum++ = *p++;
					int val22 = atoi(num);

				    pnode->right = new TreeNode(val22);
				    //q.push(val2);
				    q2.push(pnode->right);
				} else {
					p++;
				}
			}
		}
    	
    	return root;
    }
    
};

int main()
{
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	Solution sl;
	char* ans = sl.Serialize(root);
	printf("%s\n", ans);
	
	char* str = "100|^|200|300|^|^|^";
	TreeNode* t = sl.Deserialize(str);
	queue<TreeNode*> q;
	q.push(t);
	while (!q.empty()) {
		TreeNode* temp = q.front(); q.pop();
		if (temp == NULL) {
			printf(" -1");
		} else {
			printf(" %d", temp->val);
			q.push(temp->left);
			q.push(temp->right);
		}

	}
	
	
	return 0;
}
