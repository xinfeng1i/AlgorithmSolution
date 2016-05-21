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

// 双向BFS搜索
// --------                     ----------
// |       |                    |        |
// |words1 |  <---------------> | words2 |
// |       |                    |        |
// ---------                    ----------   
// 不断地从两端向中心搜索，直至搜索到中间单词temp在另一个词袋中
int searchwithDoubleBFS(unordered_set<string>& words1, unordered_set<string>& words2,
	unordered_set<string>& dict, int level) {
	
	if (words1.empty()) return 0;		
	if (words1.size() > words2.size()) 
		return searchwithDoubleBFS(words2, words1, dict, level);
	
	unordered_set<string> words3;
	for (auto it = words1.begin(); it != words1.end(); ++it) {
		string word = *it;
		for (size_t i = 0; i < word.size(); ++i) {
			int ch = word[i];
			for (int k = 0; k < 26; ++k) {
				int ch2 = 'a' + k;
				if (ch2 != ch) {
					string temp = word;
					temp[i] = ch2;
					if (words2.find(temp) != words2.end()) {
						return level+1;
					} else {
						if (dict.find(temp) != dict.end()) {
							dict.erase(temp);
							words3.insert(temp);
						}
					}
					
				}
			}
		}
	}
	return searchwithDoubleBFS(words3, words2, dict, level+1);
}


int ladderLength(string beginWord, string endWord, unordered_set<string>& dict) {
	if (beginWord == endWord) return 1;
	unordered_set<string> words1, words2;
	words1.insert(beginWord);
	dict.erase(beginWord);
	words2.insert(endWord);
	dict.erase(endWord);
	return searchwithDoubleBFS(words1, words2, dict, 1);
}

int main()
{
	unordered_set<string> dict;
	dict.insert("a");
	dict.insert("b");
	dict.insert("c");
	string s = "a";
	string e = "c";
	cout << ladderLength(s, e, dict) << endl;
	return 0;
}