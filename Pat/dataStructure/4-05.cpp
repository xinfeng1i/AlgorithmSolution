#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

struct Node
{
	string name_;
	int level_;
	Node* parent_;
	vector<Node*> children_;
	Node(){};
};

void printNode(Node* p)
{
	cout << "---Node Name:" << p->name_ << endl;
	cout << (p->parent_ == NULL ? "NULL" : p->parent_->name_) << endl;
	cout << "---end" << endl;
}



int main()
{
	freopen("input.txt", "r", stdin);
	int n, m;
	scanf("%d %d\n", &n, &m);
	
	map<string, Node*> table;
	string line, curName;
	int curLevel;
	Node* curNode = NULL;
	for (int i = 0; i < n; ++i)
	{
		getline(cin, line);
		int nspace = 0;
		for (int k = 0; k < line.size(); ++k)
		{
			if (line[k] == ' ') nspace++;
			else break;
		}
		curName = line.substr(nspace);
		curLevel = nspace / 2;
		
		if (curNode == NULL)
		{
			curNode = new Node();
			curNode->name_ = curName;
			curNode->level_ = curLevel;
			curNode->parent_ = NULL;
			table[curName] = curNode;
		}
		else
		{
			Node* newNode =	new Node();
			newNode->name_ = curName;
			newNode->level_ = curLevel;
			
			// find the parent of newNode, pointed by curNode;
			if (newNode->level_ <= curNode->level_)
			{
				int btrack = curNode->level_ - newNode->level_ + 1;
				for (int k = 0; k < btrack; ++k)
				{
					curNode = curNode->parent_;
				}

			}

			newNode->parent_ = curNode;
			curNode->children_.push_back(newNode);
			table[newNode->name_] = newNode;

			//update curNode repoint the newNode
			curNode = newNode;
		}

	}

	string nameX, isword, aword, nameY, ofword, relation;
	for (int i = 0; i < m; ++i)
	{	
		getline(cin, line); 
		istringstream iss(line);
		iss >> nameX >> isword >> aword >> relation >> ofword >> nameY;
		
		if (relation == "child")
		{
			if (table[nameX]->parent_ == table[nameY])
			{
				cout << "True" << endl;
			}
			else
			{
				cout << "False" << endl;
			}
		}
		else if (relation == "parent")
		{
			if (table[nameY]->parent_ == table[nameX])
			{
				cout << "True" << endl;
			}
			else
			{
				cout << "False" << endl;
			}
		}
		else if (relation == "sibling")
		{
			if (table[nameX]->parent_ == table[nameY]->parent_)
			{
				cout << "True" << endl;
			}
			else
			{
				cout << "False" << endl;
			}
		}
		else if (relation == "descendant")
		{
			Node* p = table[nameX];
			assert(p != table[nameY]);
			int cnt = 0;
			while (p != NULL && p != table[nameY])
			{
				p = p->parent_;
				cnt++;
			}
			if (p == table[nameY] && cnt >= 1)
			{
				cout << "True" << endl;
			}
			else
			{
				cout << "False" << endl;
			}
		}
		else if (relation == "ancestor")
		{
			Node* py = table[nameY];
			int cnt = 0;
			while (py != NULL && py != table[nameX])
			{
				py = py->parent_;
				cnt++;
			}
			if (py == table[nameX] && cnt >= 1)
			{
				cout << "True" << endl;
			}
			else
			{
				cout << "False" << endl;
			}
		}
		else
		{
			cerr << "Error" << endl;
			return -1;
		}
	}

	for (auto it = table.begin(); it != table.end(); ++it)
	{
		delete it->second;
	}

	/*
	for (auto it = table.begin(); it != table.end(); ++it)
	{
		printNode(it->second);
	}
	*/

	return 0;
}
