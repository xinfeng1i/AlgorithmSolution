#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void addNeighborWords(string word, unordered_set<string>& dict, queue<string>& q) {
	dict.erase(word);
	for (size_t i = 0; i < word.size(); ++i) {
		int ch = word[i];
		for (int k = 0; k < 26; ++k) {
			int ch2 = 'a' + k;
			if (ch2 != ch) {
				string temp = word;
				temp[i] = ch2;
				if (dict.find(temp) != dict.end()) {
					q.push(temp);
					dict.erase(temp);
				}
			}
			
		}
	}
}

int ladderLength(string beginWord, string endWord, unordered_set<string>& dict) {
	dict.insert(endWord);
	
	queue<string> q;
	addNeighborWords(beginWord, dict, q);
	int dist = 2;
	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; ++i) {
			string temp = q.front();
			if (temp == endWord) return dist;
			q.pop();
			addNeighborWords(temp, dict, q);
		}
		dist++;
	}
	return 0;
}

int main()
{
	unordered_set<string> dict;
	dict.insert("a");
	dict.insert("b");
	dict.insert("c");
	cout << ladderLength("a", "c", dict);
	return 0;
}
