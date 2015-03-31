#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

#define CHAR_TO_INDEX(c) ((int)(c) - (int)('a')) 
const int ALPHA_SIZE = 26;

struct TrieNode
{
public:
	int nWords;
	TrieNode* children[ALPHA_SIZE];
public: // constructor
	TrieNode() : nWords(0)
	{
		for (int i = 0; i < ALPHA_SIZE; ++i) children[i] = NULL;
	}
};

struct TrieTree
{
	int count;
	TrieNode* root;
};

TrieTree* InitTrieTree()
{
	TrieTree* ans = new TrieTree();
	ans->count = 0;
	ans->root = new TrieNode();
	return ans;
}

void InsertKey(TrieTree* pTrie, string s)
{
	int length = s.size();
	TrieNode* pCrawl = pTrie->root;
	pTrie->count++;

	for (int i = 0; i < length; ++i)
	{
		char ch = s[i];
		int index = CHAR_TO_INDEX(ch);
		if (pCrawl->children[index] == NULL)
		{
			pCrawl->children[index] = new TrieNode();
		}		
		pCrawl = pCrawl->children[index];
		pCrawl->nWords++;
	}
}

int SearchKey(TrieTree* pTrie, string s)
{
	TrieNode* pCrawl = pTrie->root;
	int length = s.size();

	for (int i = 0; i < length; ++i)
	{
		char ch = s[i];
		int index = CHAR_TO_INDEX(ch);
		if (pCrawl->children[index] == NULL)
		{
			return 0;
		}
		pCrawl = pCrawl->children[index];
	}

	if (pCrawl != NULL) return pCrawl->nWords;
	else return 0;
}

bool IsValidWord(const string& s)
{
	if (s.size() > 10) return false;
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] < 'a' || s[i] > 'z') return false;
	}
	return true;
}

int main()
{
	//freopen("data.in", "r", stdin);
	int n, m;
	cin >> n;
	vector<string> mydicts(n);

	TrieTree* pTrie = InitTrieTree();

	for (int i = 0; i < n; ++i)
	{
		cin >> mydicts[i];
		if (IsValidWord(mydicts[i]))
		{
			InsertKey(pTrie, mydicts[i]);
		}
	}

	cin >> m;
	string temp;
	for (int i = 0; i < m; ++i)
	{
		cin >> temp;
		cout << SearchKey(pTrie, temp) << endl;
	}

	return 0;
}

