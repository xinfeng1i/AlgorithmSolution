#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAX_SIZE 100

struct Node
{
    char ch_;
    int frequency_;
    Node* left_;
    Node* right_;

    Node(char ch, int freq):ch_(ch), 
                            frequency_(freq),
                            left_(NULL),
                            right_(NULL)
    {}
};

struct cmpNode
{
	bool operator()(const Node* a, const Node* b) const
	{
		assert(a != NULL);
		assert(b != NULL);
		if (a->frequency_ != b->frequency_)
			return a->frequency_ < b->frequency_;
		else
			return a->ch_ < b->ch_;
	}
};

// create the huffman tree, return the root of the tree
Node* CreateHuffmanTree(char ch[], int freq[], int n)
{
    // create the heap
    set<Node*, cmpNode> q;
    for (int i = 0; i < n; ++i)
    {
        q.insert(new Node(ch[i], freq[i]));
    }
    
    while (q.size() >= 2)
    {
        // find the min two freq nodes 
        Node* first = *(q.begin());
		//cout << "first:" << first->ch_ << " " << first->frequency_ << endl;
        q.erase(q.begin());
        Node* second = *(q.begin());
		//cout << "second:" << second->ch_ << " " << second->frequency_ << endl;
        q.erase(q.begin()); 

        // add to the new node
        Node* pnode = new Node('$', first->frequency_ + second->frequency_);
        pnode->left_ = first;
        pnode->right_ = second;

        // new node into heap
        q.insert(pnode);
    }

    Node* root = *(q.begin());

    return root;
}

void PreOrderVisit(Node* root)
{
	if (root == NULL) return;
	cout << root->ch_ << " " << root->frequency_ <<endl;
	PreOrderVisit(root->left_);
	PreOrderVisit(root->right_);
}

void InOrderVisit(Node* root)
{
	if (root == NULL) return;
	InOrderVisit(root->left_);
	cout << root->ch_ << " " << root->frequency_ << endl;
	InOrderVisit(root->right_);
}


void printHuffmanCode(Node* root, string path)
{
    if (root == NULL) return;

    // leaf node
    if (root->left_ == NULL && root->right_ == NULL)
    {
        cout << root->ch_ << " coding: " << path << endl;
    }
    else
    {
		printHuffmanCode(root->left_, path+"0");
		printHuffmanCode(root->right_, path+"1");
    }
    
}


int main()
{
    char a[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int n = sizeof(a) / sizeof(a[0]);

	Node* root = CreateHuffmanTree(a, freq, n);
	printHuffmanCode(root, "");

	//cout << "pre order huffman tree is " << endl;
	//PreOrderVisit(root);
	//cout << "The InOrder huffman Tree is:" << endl;
	//InOrderVisit(root);

    return 0;
}
