#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
	char ch_;
	int freq_;
	Node* left_;
	Node* right_;

	Node(char ch, int freq):ch_(ch),
							freq_(freq),
							left_(NULL),
							right_(NULL)
	{}
};

struct cmpNode
{
	bool operator()(const Node* a, const Node* b) const
	{
		if (a->freq_ != b->freq_) return a->freq_ > b->freq_;
		else return a->ch_ > b->ch_;
	}
};

typedef priority_queue<Node*, vector<Node*>, cmpNode> PQ;

// return the min Node in the queue q1, q2;
// this helper function can help reduce the complexity of the code
// make the main function more elegant
Node* FindMinNode(PQ& q1, PQ& q2)
{
	if (q1.empty())
	{
		Node* ans = q2.top();
		q2.pop();
		return ans;
	}
	
	if (q2.empty())
	{
		Node* ans = q1.top();
		q1.pop();
		return ans;
	}

	if (q1.top()->freq_ < q2.top()->freq_)
	{
		Node* ans = q1.top();
		q1.pop();
		return ans;
	}
	else
	{
		Node* ans = q2.top();
		q2.pop();
		return ans;
	}
}

Node* CreateHuffmanTree(char ch[], int freq[], int n)
{
	// min heap
	priority_queue<Node*, vector<Node*>, cmpNode> q1, q2;

	// init
	for (int i = 0; i < n; ++i)
	{
		q1.push(new Node(ch[i], freq[i]));
	}
	//cout << "q1 size:" << q1.size() << endl;

	Node* first = NULL; 
	Node* second = NULL;
	while (q1.size() + q2.size() > 1)
	{
		/*
		if (q2.empty())
		{
			//cout << "------------from q1:" << endl;
			first = q1.top(); q1.pop();
			second = q1.top(); q1.pop();

		}
		else if (q1.empty())
		{
			//cout << "------------from q2:" << endl;
			first = q2.top(); q2.pop();
			second = q2.top(); q2.pop();
		}
		else
		{
			//cout << "------------from q1 and q2" << endl;
			if (q1.top()->freq_ < q2.top()->freq_)
			{
				first = q1.top(); q1.pop();
			}
			else
			{
				first = q2.top(); q2.pop();
			}

			if (q1.empty())
			{
				second = q2.top();
				q2.pop();
			}
			else if (q2.empty())
			{
				second = q1.top();
				q1.pop();
			}
			else if (q1.top()->freq_ < q2.top()->freq_)
			{
				second = q1.top(); q1.pop();
			}
			else
			{
				second = q2.top(); q2.pop();
			}
		}
		*/

		first = FindMinNode(q1, q2);
		second = FindMinNode(q1, q2);

		Node* pnew = new Node('$', first->freq_ + second->freq_);
		pnew->left_ = first;
		pnew->right_ = second;

		//cout << "first:" << first->ch_ << " " << first->freq_ << endl;
		//cout << "second:" << second->ch_ << " " << second->freq_ << endl;
		//cout << "new" << pnew->ch_ << " " << pnew->freq_ << endl;
		q2.push(pnew);
		//cout << "q2.top" << q2.top()->ch_ << " " << q2.top()->freq_ <<endl;
	}

	if (q1.size() == 0) return q2.top();
	else return q1.top();
}

void PrintHuffmanTree(Node* root, string path)
{
	if (root == NULL) return;

	if (root->left_ == NULL && root->right_ == NULL)
	{
		cout << root->ch_ << " coding: " << path << endl;	
	}
	else
	{
		PrintHuffmanTree(root->left_, path + "0");
		PrintHuffmanTree(root->right_, path + "1");
	}
}

void PreOrder(Node* root)
{
	if (root == NULL) return;
	cout << root->ch_ << " " << root->freq_ << endl;
	PreOrder(root->left_);
	PreOrder(root->right_);
}

int main()
{
	char a[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int freq[] = {5, 9, 12, 13, 16, 45};
	int n = sizeof(a) / sizeof(a[0]);

	Node* root = CreateHuffmanTree(a, freq, n);
	PrintHuffmanTree(root, "");

	//cout << "PreOrder:" << endl;
	//PreOrder(root);

	return 0;
}
