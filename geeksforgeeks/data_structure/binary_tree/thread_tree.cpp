#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

struct Node
{
public:
	int key_;
	Node* left_;
	Node* right_;
	bool isThread;
public:

	Node(int data = 0):key_(data), left_(NULL), right_(NULL), isThread(false){}
};

Node* LeftMost(Node* p)
{
	if (p == NULL) return NULL;
	while (p->left_ != NULL)
	{
		p = p->left_;
	}
	return p;
}

Node* InOrderNoRecursion(Node* root)
{
	Node* cur = LeftMost(root);
	while (cur != NULL)
	{

		// print current node
		cout << " " << cur->key_;
		// the thread is true, then right_ must pointer to successor, so update
		if (cur->isThread == true)
		{
			cur = cur->right_;
		}
		// if not, the right_ must point to some node q, the sucessor is the left most of q
		else
		{
			cur = LeftMost(cur->right_);
		}
	}
}

void InsertNode(Node* &root, int data)
{
	// base case
	if (root == NULL)
	{
		root = new Node(data);
		return;
	}

	if (data < root->key_)
	{
		InsertNode(root->left_, data);
	}
	else
	{
		InsertNode(root->right_, data);
	}
}

void InOrder(Node* root)
{
	if (root == NULL) return;
	
	InOrder(root->left_);
	cout << " " << root->key_;	
	InOrder(root->right_);
}

void DeleteTree(Node* &root)
{
	if (root == NULL) return;

	DeleteTree(root->left_);
	DeleteTree(root->right_);
	delete root;
	root = NULL;	
}

int main()
{
	Node* root = NULL;
	InsertNode(root, 6);
	InsertNode(root, 3);
	InsertNode(root, 8);
	InsertNode(root, 1);
	InsertNode(root, 5);
	InsertNode(root, 7);
	InsertNode(root, 11);
	InsertNode(root, 9);
	InsertNode(root, 13);
	root->left_->left_->right_ = root->left_;
	root->left_->left_->isThread = true;
	root->left_->right_->right_ = root;
	root->left_->right_->isThread = true;
	root->right_->left_->right_ = root->right_;
	root->right_->left_->isThread = true;
	root->right_->right_->left_->right_ = root->right_->right_;
	root->right_->right_->left_->isThread = true;
	
	cout << "In Order No recursion :" << endl;
	InOrderNoRecursion(root);
	cout << endl;	
	
	return 0;
}
