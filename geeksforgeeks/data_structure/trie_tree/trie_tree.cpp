#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ALPHABETA_SIZE = 26;

// utility function
int char2Index(char ch)
{
    return ch - 'a'; 
}

struct TrieNode
{
    int value;                              // indicate leaf node
    TrieNode* children[ALPHABETA_SIZE];     // point to all its children

// constructor
    TrieNode(int data = 0):value(data)
    {
        for (int i = 0; i < ALPHABETA_SIZE; ++i)
        {
            children[i] = NULL;
        }
    }
};

struct TrieTree
{
    TrieNode* root;
    int count;
};

TrieTree CreateTrieTree()
{
    TrieTree tt;
    tt.root = new TrieNode();
    tt.count = 0;
    return tt;
}

void InsertTrieNode(TrieTree& tt, string key)
{
    int n = key.size();
    tt.count++;
    TrieNode* pcrawl = tt.root;
    for (int level = 0; level < n; ++level)
    {
        int index = char2Index(key[level]);
        if (pcrawl->children[index] == NULL)
        {
            pcrawl->children[index] = new TrieNode();
        }
        pcrawl = pcrawl->children[index];
    }
    pcrawl->value = tt.count;
    //cout << "pcraw->value:" << tt.count << endl;
}

bool SearchTrieNode(TrieTree tt, string key)
{
    int n = key.size();
    TrieNode* pcrawl = tt.root;
    for (int level = 0; level < n; ++level)
    {
        int index = char2Index(key[level]);
        if (pcrawl->children[index] == NULL)
        {
            return false;
        }
        pcrawl = pcrawl->children[index];
    }
    return (pcrawl != NULL && pcrawl->value != 0);
}

void PreOrderTrieTree(TrieNode* root)
{
    // base case 1
    if (root == NULL) return;

    // visit root node
    cout << "value = " << root->value << endl;
    for (int i = 0; i < ALPHABETA_SIZE; ++i)
    {
        if (root->children[i] != NULL)
        {
            char ch = i + 'a';
            cout << "\tchar:" << ch << endl;
        }
    }
    
    for (int i = 0; i < ALPHABETA_SIZE; ++i)
    {
        PreOrderTrieTree(root->children[i]);
    }
}

int main()
{
    cout << "Enter the number of input words N:" << endl;
    int n;
    cin >> n;

    cout << "Enter all the input words:" << endl;
    vector<string> inputString(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> inputString[i];
    }


    // create the trie tree
    TrieTree tt = CreateTrieTree(); 
    for (int i = 0; i < n; ++i)
    {
        InsertTrieNode(tt, inputString[i]);
    }

    cout << "PreOrder Travsal" << endl;
    PreOrderTrieTree(tt.root);

    cout << "Enter the number of query words N2: " << endl;
    int n2;
    cin >> n2;
    cout << "Enter all the query words:" << endl;
    vector<string> queryString(n2); 
    for (int i = 0; i < n2; ++i)
    {
        cin >> queryString[i];
    }
    
    // output result
    for (int i = 0; i < n2; ++i)
    {
        string word = queryString[i];
        if (SearchTrieNode(tt, word))
        {
            cout << word << " IN the dict" << endl;
        }
        else
        {
            cout << word << " NOT IN the dict" << endl;
        }
    }
    
    return 0;
}
