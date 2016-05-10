#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// Trie树/前缀树的实现
struct TrieNode {
	TrieNode* children[26]; // 代表26个字母的指针
	bool isWord; // 标注当前节点是否构成一个完整的单词

	TrieNode() {
		for (int i = 0; i < 26; ++i) {
			children[i] = NULL;
		}
		isWord = false;
	}
};


class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
		if (word.empty()) return;

		size_t i = 0;
		size_t n = word.size();
		TrieNode* p = root;
		while (i < n) {
			int ch = word[i];
			if (p->children[ch-'a'] == NULL) {
				p->children[ch-'a'] = new TrieNode();
			}
			p = p->children[ch-'a'];
			i++;
		}
		p->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
		if (word.empty()) return true;

		size_t i = 0;
		size_t n = word.size();
		TrieNode* p = root;

		while (i < n) {
			int ch = word[i];
			if (p->children[ch-'a'] == NULL) {
				return false;
			} else {
				p = p->children[ch-'a'];
				i++;
			}
		}

		if (p->isWord == true) return true;
		else return false;
        
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
		if (prefix.empty()) return true;

		size_t i = 0;
		size_t n = prefix.size();
		TrieNode* p = root;
		while (i < n) {
			int ch = prefix[i];
			if (p->children[ch-'a'] == NULL) {
				return false;
			} else {
				p = p->children[ch-'a'];
				i++;
			}
		}
		return true;
    }

private:
    TrieNode* root;
};
