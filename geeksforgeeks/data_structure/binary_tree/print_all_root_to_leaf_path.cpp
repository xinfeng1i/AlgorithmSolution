#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node
{
	int data_;
	Node* left_;
	Node* right_;

	Node(int d):data_(d),
	            left_(NULL),
				right_(NULL)
	{}
};

void InsertNode(Node* &root, int key)
{
	if (root == NULL)
	{
		root = new Node(key);
	}
	else if (key < root->data_)
	{
		InsertNode(root->left_, key);
	}
	else 
	{
		InsertNode(root->right_, key);
	}
}

void PrintAllPath(Node* root, vector<int> path)
{
	if (root == NULL) return;

	path.push_back(root->data_);	
	// leaf node, output all the node store in the path
	if (root->left_ == NULL && root->right_ == NULL)
	{
		for (int i = 0; i < path.size(); ++ i)
		{
			cout << " " << path[i];
		}
		cout << endl;
	}
	else
	{
		PrintAllPath(root->left_, path);
		PrintAllPath(root->right_, path);
	}
}

int main()
{
	Node* root = new Node(1);
	InsertNode(root, 5);
	InsertNode(root, 4);
	InsertNode(root, 2);
	InsertNode(root, 6);
	
	vector<int> v;
	PrintAllPath(root, v);
	return 0;
}
