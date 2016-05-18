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

int g_dist = INT_MAX;

set<string> GetUnvisitedNeighborWords(string word, unordered_set<string>& dict, map<string, bool>& visited) {
	set<string> ans;
	for (size_t i = 0; i < word.size(); ++i) {
		int ch = word[i];
		for (int k = 0; k < 26; ++k) {
			int ch2 = 'a' + k;
			if (ch2 != ch) {
				string temp = word;
				temp[i] = ch2;
				if (!visited[temp] && dict.find(temp) != dict.end()) {
					ans.insert(temp);
				}
			}
		}
	}
	return ans;
}

void func(const string& curword, const string& targetword, unordered_set<string> &dict,
		 map<string, bool>& visited,
		 vector<string>& cur,
		 vector<vector<string>>& ans) {

	// base case
	if (targetword == curword) {
		cur.push_back(curword);
		if (cur.size() < g_dist) {
			g_dist = cur.size();
			ans.clear();
			ans.push_back(cur);
		} else if (cur.size() == g_dist) {
			ans.push_back(cur);
		}
		cur.pop_back();
		return;
	}
	
	visited[curword] = true;
	cur.push_back(curword);
	set<string> nbrs = GetUnvisitedNeighborWords(curword, dict, visited);
	for (auto it = nbrs.begin(); it != nbrs.end(); ++it) {
		string nextword = *it;
		func(nextword, targetword, dict, visited, cur, ans);
	}
	visited[curword] = false;
	cur.pop_back();
}

vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &dict) {
	dict.insert(beginWord);
	dict.insert(endWord);
	vector<string> cur;
	vector<vector<string>> ans;
	map<string, bool> visited;
	for (auto it = dict.begin(); it != dict.end(); ++it) {
		visited[*it] = false;
	}
	
	func(beginWord, endWord, dict, visited, cur, ans);
	return ans;
}

void PrintVec(const vector<string>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		cout << " " << v[i];
	}
	cout << endl;
}

int main()
{
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	string s = "hit";
	string e = "cog";
    vector<vector<string>> ans = findLadders(s, e, dict);
    for (size_t i = 0; i < ans.size(); ++i) {
    	PrintVec(ans[i]);
	}
	return 0;
}
