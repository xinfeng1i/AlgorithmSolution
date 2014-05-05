#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MIN_VALUE = -1000000000;
const int MAX_VALUE = 1000000000;
struct Node
{
	int data1;
	int data2;
	Node* left;
	Node* right;
	Node(int k1, int k2):data1(k1),
						 data2(k2),
						 left(NULL),
						 right(NULL)
	{}
};

struct record
{
	int k1;
	int k2;
	int leftAdd;
	int rightAdd;
};

bool isBSTree(Node* root, int minValue, int maxValue)
{
	if (root == NULL)
		return true;

	// the value must in [minValue, maxValue]
	if (root->data1 < minValue || root->data1 > maxValue)
		return false;

	return isBSTree(root->left, minValue, root->data1 - 1) &&
		   isBSTree(root->right, root->data1 + 1, maxValue);
}

bool isHeapTree(Node* root, int minValue, int maxValue)
{
	if (root == NULL)
		return true;

	if (root->data2 < minValue || root->data2 > maxValue)
		return false;

	return isHeapTree(root->left, root->data2 + 1, maxValue) &&
		   isHeapTree(root->right, root->data2 + 1, maxValue);
}

void InOrder(Node* root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		cout << "k1:" << root->data1 << endl;
		InOrder(root->right);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	vector<record> v(n);
	vector<Node*> p(n);
	set<int> s;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].k1 >> v[i].k2 >> v[i].leftAdd >> v[i].rightAdd;
		cout << v[i].k1 << v[i].k2 << v[i].leftAdd << v[i].rightAdd << endl;
		//p[i] = new Node(v[i].k1, v[i].k2);
		//if (v[i].leftAdd != -1) s.insert(v[i].leftAdd);
		//if (v[i].rightAdd != -1) s.insert(v[i].rightAdd);
	}

	cout << "record:" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << v[i].k1 << " " << v[i].k2 << " "
			 << v[i].leftAdd << " " << v[i].rightAdd << endl;
	}

	// find root index
	int rootAdd = -1;
	for (int i = 0; i < n; ++i)
	{
		if (s.count(i) == 0)
		{
			rootAdd = i;
			break;
		}
	}
	cout << "root index:" << rootAdd << endl;

	// create binary tree
	for (int i = 0; i < n; ++i)
	{
		int index1 = v[i].leftAdd;
		int index2 = v[i].rightAdd;
		if (index1 != -1) p[i]->left = p[index1];
		if (index2 != -1) p[i]->right = p[index2];
	}

	Node* root = p[rootAdd];
	
	if (isBSTree(root, MIN_VALUE, MAX_VALUE) && 
		isHeapTree(root, MIN_VALUE, MAX_VALUE))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	printf("%p\n", p[2]);
	printf("%p\n", p[2]->left);
	printf("%p\n", p[0]);
	printf("%p\n", p[0]->left);
	printf("%p\n", p[0]->right);
	printf("%p\n", p[5]);
	printf("%p\n", p[5]->left);
	printf("%p\n", p[5]->right);
	printf("%p\n", p[1]->left);
	printf("%p\n", p[1]->right);

	cout << "travel in order:" << endl;
	InOrder(root);


	for (int i = 0; i < n; ++i)
	{
		delete p[i];
		p[i] = NULL;
	}

	
	return 0;
}
