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

// Trie树通配符搜索
struct TrieNode {
	TrieNode* children[26];
	bool is_word;

	TrieNode() {
		for (int i = 0; i < 26; ++i) {
			children[i] = NULL;
		}
		is_word = false;
	}
};

class WordDictionary {
public:
	WordDictionary() {
		root = new TrieNode();
	}

    // Adds a word into the data structure.
    void addWord(string word) {
        if (word.empty()) return;

		size_t i = 0;
		size_t n = word.size();
		TrieNode* p = root;
		while (i < n) {
			int ch = word[i];
			if (p->children[ch-'a'] == NULL) {
				p->children[ch-'a'] = new TrieNode;
			}
			p = p->children[ch-'a'];
			i++;
		}
		p->is_word = true;
    }

	bool search(TrieNode* pStart, string word) {
		// base case: 空串或者只有一个字符的串
		if (word.empty()) return true;
		if (word.size() == 1) {
			int ch = word[0];
			if (ch == '.') {
				if (pStart == NULL) return false;
				for (int i = 0; i < 26; ++i) {
					if (pStart->children[i] != NULL && 
						pStart->children[i]->is_word == true) {
						return true;
					}
				}
				return false;
			
			} else {
				if (pStart == NULL || pStart->children[ch-'a'] == NULL) {
					return false;
				} else {
					return pStart->children[ch-'a']->is_word == true;
				}
			}
		}

		int ch = word[0];
		if (ch == '.') {
			if (pStart == NULL) return false;
			for (int i = 0; i < 26; ++i) {
				if (pStart->children[i] != NULL) {
					bool ok = search(pStart->children[i], word.substr(1));
					if (ok) {
						return true;
					}
				}
			}
			return false;
			
		} else {
			if (pStart == NULL || pStart->children[ch-'a'] == NULL) return false;
			return search(pStart->children[ch-'a'], word.substr(1));
		}

	}

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(root, word);
    }
private:
	TrieNode* root;
};

#if 0
int main()
{
	WordDictionary wordDictionary;
	wordDictionary.addWord("a");
	wordDictionary.addWord("a");
	cout << wordDictionary.search(".a") << endl;

	return 0;
}
#endif //0
