#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node
{
	int key_;
	int height_;
	Node* left_;
	Node* right_;

	Node(int data):key_(data),
				   height_(1),
				   left_(NULL), 
				   right_(NULL)
	{}
};

int getHeight(Node* root)
{
	if (root == NULL) return 0;
	int lh = getHeight(root->left_) + 1;
	int rh = getHeight(root->right_) + 1;
	return max(lh, rh);
}

int balanceFactor(Node* root)
{
	if (root == NULL) return 0;
	return getHeight(root->left_) - getHeight(root->right_);
}

Node* minValueNode(Node* root)
{
	Node* curNode = root;
	while (curNode->left_ != NULL)
	{
		curNode = curNode->left_;
	}

	return curNode;
}

Node* rightRotation(Node* root)
{
	Node* z = root;

	Node* y = z->left_;
	Node* T3 = y->right_;
	
	y->right_ = z;
	z->left_ = T3;

	y->height_ = max(getHeight(y->left_), getHeight(y->right_)) + 1;
	z->height_ = max(getHeight(z->left_), getHeight(z->right_)) + 1;

	return y;
}

Node* leftRotation(Node* root)
{
	Node* z = root;

	Node* y = z->right_;
	Node* T2 = y->left_;

	y->left_ = z;
	z->right_ = T2;

	y->height_ = max(getHeight(y->left_), getHeight(y->right_)) + 1;
	z->height_ = max(getHeight(z->left_), getHeight(z->right_)) + 1;

	return y;
}

Node* insertNode(Node* root, int data)
{
	// STEP 1: Normal insert
	if (root == NULL)
	{
		root = new Node(data);
		return root;
	}
	if (data < root->key_)
	{
		root->left_ = insertNode(root->left_, data);
	}
	else
	{
		root->right_ = insertNode(root->right_, data);
	}

	// Step 2: update height
	root->height_ = max(getHeight(root->left_), getHeight(root->right_)) + 1;

	// step 3: rotation
	if (balanceFactor(root) >= 2)
	{
		// Left left case
		if (balanceFactor(root->left_) >= 1)
		{
			return rightRotation(root);	
		}
		// left right case
		else if (balanceFactor(root->left_) <= -1)
		{
			root->left_ = leftRotation(root->left_);
			return rightRotation(root);
		}

	}
	else if (balanceFactor(root) <= -2)
	{
		// right right case
		if (balanceFactor(root->right_) <= -1)
		{
			return leftRotation(root);	
		}
		// right left case
		else if (balanceFactor(root->right_) >= 1)
		{
			root->right_ = rightRotation(root->right_);
			return leftRotation(root);
		}
	}

	return root;
}

Node* deleteNode(Node* root, int data)
{
	// STEP 1: delete the node normally
	if (root == NULL) return root;
	
	if (data < root->key_)
	{
		root->left_ = deleteNode(root->left_, data);	
	}
	else if (data > root->key_)
	{
		root->right_ = deleteNode(root->right_, data);
	}
	else
	{
		// has no children
		if (root->left_ == NULL && root->right_ == NULL)
		{
			delete root;
			root = NULL;
		}
		// has one child
		else if (  (root->left_ == NULL && root->right_ != NULL)
				 ||(root->left_ != NULL && root->right_ == NULL) )
		{
			Node* tmp = (root->left_ == NULL ? root->right_ : root->left_);
			
			root->left_ = tmp->left_;
			root->right_ = tmp->right_;
			root->key_ = tmp->key_;

			delete tmp;
		}
		// has both children
		else
		{
			Node* minValue = minValueNode(root->right_);	
			root->key_ = minValue->key_;
			root->right_ = deleteNode(root->right_, minValue->key_);
		}
	}

	// if has only one node, return NULL
	if (root == NULL) return NULL;

	// STEP 2: update the height
	root->height_ = max(getHeight(root->left_), getHeight(root->right_)) + 1;

	// STEP 3: rotation
	int ba = balanceFactor(root);
	if (ba >= 2)
	{
		// Left left case
		if (balanceFactor(root->left_) >= 0)
		{
			return rightRotation(root);	
		}
		// left right case
		else if (balanceFactor(root->left_) <= -1)
		{
			root->left_ = leftRotation(root->left_);	
			return rightRotation(root);
		}

	}
	else if (ba <= -2)
	{
		// right right case
		if (balanceFactor(root->right_) <= 0)
		{
			return leftRotation(root);	
		}
		// right left case
		else if (balanceFactor(root->right_) >= 1)
		{
			root->right_ = rightRotation(root->right_);
			return leftRotation(root);
		}
	}
	return root;
}

void preVisit(Node* root)
{
	if (root == NULL) return;
	printf("%d ", root->key_);
	preVisit(root->left_);
	preVisit(root->right_);
}

void inVisit(Node* root)
{
	if (root == NULL) return;
	inVisit(root->left_);
	printf("%d ", root->key_);
	inVisit(root->right_);
}


int main()
{
	Node* root = NULL;
	root = insertNode(root, 9);
	root = insertNode(root, 5);
	root = insertNode(root, 10);
	root = insertNode(root, 0);
	root = insertNode(root, 6);
	root = insertNode(root, 11);
	root = insertNode(root, -1);
	root = insertNode(root, 1);
	root = insertNode(root, 2);

	//cout << "root:" << root->key_ << endl;
	//cout << "roor->left_ :" << root->left_->key_ << endl;
	preVisit(root);
	printf("\n");
	inVisit(root);
	printf("\n");


	root = deleteNode(root, 10);
	printf("After delete Node 10\n");

	//cout << "root:" << root->key_ << endl;
	//cout << "roor->left_ :" << root->left_->key_ << endl;
	preVisit(root);
	printf("\n");
	inVisit(root);
	printf("\n");

	return 0;
}
