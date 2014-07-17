#include <iostream>
#include <string>
#include <cassert>
using namespace std;

struct Node
{
	int key_;
	Node* left_;
	Node* right_;

	Node(int data):key_(data), left_(NULL), right_(NULL)
	{}
};

int getHeight(Node* root)
{
	if (root == NULL) return 0;
	int lh = getHeight(root->left_) + 1;
	int rh = getHeight(root->right_) + 1;
	return max(lh, rh);
}

int getBalanceFactor(Node* root)
{
	if (root == NULL) return 0;
	else return getHeight(root->left_) - getHeight(root->right_);
}

Node* leftRotation(Node* root)
{	
	Node* y = root->right_;
	Node* T2 = y->left_;

	y->left_ = root;
	root->right_ = T2;

	return y;
}

Node* rightRotation(Node* root)
{
	Node* y = root->left_;
	Node* T3 = y->right_; 

	y->right_ = root;
	root->left_ = T3;

	return y;
}

Node* insertNode(Node* root, int data)
{
	if (root == NULL)
	{
		root = new Node(data);
		return root;
	}
	else if (data < root->key_)
	{
		root->left_ = insertNode(root->left_, data);
	}
	else
	{
		root->right_ = insertNode(root->right_, data);
	}

	int bf = getBalanceFactor(root);
	int lbf = getBalanceFactor(root->left_);
	int rbf = getBalanceFactor(root->right_);
	if (bf == 2)
	{
		// left left
		if (lbf == 1)
		{
			return rightRotation(root);
		}
		// left right
		else if (lbf == -1)
		{
			root->left_ = leftRotation(root->left_);
			return rightRotation(root);
		}
	}
	else if (bf == -2)
	{
		// right right
		if (rbf == -1)
		{
			return leftRotation(root);	
		}
		// right left
		else if (rbf == 1)
		{
			root->right_ = rightRotation(root->right_);	
			return leftRotation(root);
		}
	}

	return root;
}

void destroyTree(Node*& root)
{
	if (root == NULL) return;
	destroyTree(root->left_);
	destroyTree(root->right_);
	delete root;
	root == NULL;
}

int main()
{
	int n;
	cin >> n;
	Node* root = NULL;
	int tmp;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		root = insertNode(root, tmp);
	}

	assert(root != NULL);
	int ans = root->key_;
	cout << ans << endl;
	return 0;
}
