#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int elem):data(elem), left(NULL), right(NULL){}
};

void InsertNode(Node* &root, int elem)
{
	Node* pnode = new Node(elem);
	if (root == NULL)
	{
		root = pnode;
		return;
	}
	else if (elem < root->data)
	{
		InsertNode(root->left, elem);
	}
	else
	{
		InsertNode(root->right, elem);
	}
}

void InsertNodeMirror(Node* &root, int elem)
{
	Node* pnode = new Node(elem);
	if (root == NULL)
	{
		root = pnode;
		return;
	}
	else if (elem >= root->data)
	{
		InsertNodeMirror(root->left, elem);
	}
	else
	{
		InsertNodeMirror(root->right, elem);
	}
}

void PreOrder(Node* root, vector<int> &v)
{
	if (root != NULL)
	{
		v.push_back(root->data);
		PreOrder(root->left, v);
		PreOrder(root->right,v);
	}
}

void PostOrder(Node* root, vector<int> &v)
{
	if (root != NULL)
	{
		PostOrder(root->left, v);
		PostOrder(root->right, v);
		v.push_back(root->data);
	}
}

void DestoryTree(Node* &root)
{
	if (root == NULL)
		return;
	DestoryTree(root->left);
	DestoryTree(root->right);
	delete(root);
	root = NULL;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);

	Node* root1 = NULL;
	Node* root2 = NULL;

	int tmp;
	vector<int> v(n, 0);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &tmp);	
		v[i] = tmp;
		InsertNode(root1, tmp);
		InsertNodeMirror(root2, tmp);
	}
	
	vector<int> v1, v2;
	PreOrder(root1, v1);
	PreOrder(root2, v2);
	//cout << "v1:";
	//for (int i = 0; i < n; ++i) cout << " " << v1[i];
	//cout << endl;
	//cout << "v2:";
	//for (int i = 0; i < n; ++i) cout << " " << v2[i];
	//cout << endl;

	bool flag1 = true;
	bool flag2 = true;
	for (int i = 0; i < n; ++i)
	{
		if (v[i] != v1[i]) 
		{
			flag1 = false;
			break;
		}
	}

	for(int i = 0; i < n; ++i)
	{
		if (v[i] != v2[i])
		{
			flag2 = false;
			break;
		}
	}

	if (flag1 || flag2)
	{
		printf("YES\n");
		vector<int> ans1, ans2;
		if (flag1)
		{
			PostOrder(root1, ans1);
			bool isFirst = true;
			for (int i = 0; i < n; ++i)
			{
				if (isFirst) {isFirst = false; printf("%d", ans1[i]);}
				else { printf(" %d", ans1[i]); }
			}
			printf("\n");
		}
		else if (flag2)
		{
			PostOrder(root2, ans2);
			bool isFirst = true;
			for (int i = 0; i < n; ++i)
			{
				if (isFirst) {isFirst = false; printf("%d", ans2[i]);}
				else { printf(" %d", ans2[i]); }
			}
			printf("\n");
		}
	}
	else
	{
		printf("NO\n");
	}

	DestoryTree(root1);
	DestoryTree(root2);

	return 0;
}
