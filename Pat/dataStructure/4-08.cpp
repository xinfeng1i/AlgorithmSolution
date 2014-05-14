#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

struct Node
{
	int flag_;
	string name_;
	vector<Node*> pChildren_;
	Node(int flag, string name):flag_(flag),
								name_(name)
	{}
};

bool cmpNode(Node* p1, Node* p2)
{
	if (p1->flag_ != p2->flag_)
	{
		return p1->flag_ > p2->flag_;
	}
	else
	{
		return p1->name_ < p2->name_;
	}
}

void sortTree(Node* root)
{
	if (root == NULL) return;
	sort(root->pChildren_.begin(), root->pChildren_.end(), cmpNode);
	for (size_t i = 0; i < root->pChildren_.size(); ++i)
	{
		sortTree(root->pChildren_[i]);
	}
}


Node* InsertNode(Node* root, Node* pnode)
{
	assert(pnode != NULL);
	assert(root != NULL);
	// search for whether pnode already in the tree
	// if it is, return the pointer
	for (size_t i = 0; i < root->pChildren_.size(); ++i)
	{
		if (root->pChildren_[i]->flag_ == pnode->flag_ &&
			root->pChildren_[i]->name_ == pnode->name_)
		{
			return root->pChildren_[i];
		}
	}
	
	// else, insert the node, and return the pointer
	root->pChildren_.push_back(pnode);
	return pnode;
}

void printTree(Node* root, int tabs)
{
	if (root == NULL) return;
	for (int i = 0; i < tabs; ++i)
	{
		cout << "  ";
	}
	cout << root->name_ << endl;
	for (int i = 0; i < root->pChildren_.size(); ++i)
	{
		printTree(root->pChildren_[i], tabs + 1);
	}
}

void destroyTree(Node* &root)
{
	if (root == NULL) return;
	for (int i = 0; i < root->pChildren_.size(); ++i)
	{
		destroyTree(root->pChildren_[i]);
	}
	delete root;
	root = NULL;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int n;
	scanf("%d\n", &n);
	string line;
	Node* root = new Node(1, "root");
	for (int i = 0; i < n; ++i)
	{
		vector<string> words;
		getline(cin, line);
		int n = line.size();

		int p1 = 0; int p2 = 0;
		while (p2 < n)
		{
			while (line[p2] != '\\' && p2 != n) p2++;
			words.push_back(line.substr(p1, p2 - p1));
			p2++;
			p1 = p2;
		}

		int nw = words.size();
		//cout << "the words:" << endl;
		//for (size_t i  = 0; i < nw; ++i)
		//{
		//	cout << words[i] << endl;
		//}


		Node* insertRoot = root;
		for (size_t i  = 0; i < nw - 1; ++i)
		{
			Node* pnode = new Node(1, words[i]);
			insertRoot = InsertNode(insertRoot, pnode);
		}
		if (line[n - 1] == '\\')
		{
			Node* pnode = new Node(1, words[nw - 1]);
			insertRoot = InsertNode(insertRoot, pnode);
		}
		else
		{
			Node* pnode = new Node(0, words[nw - 1]);
			insertRoot = InsertNode(insertRoot, pnode);
		}
	}

	sortTree(root);
	printTree(root, 0);	
	destroyTree(root);
	return 0;
}


