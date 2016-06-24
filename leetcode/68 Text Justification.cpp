#include <iostream>
#include <sstream>
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
#include <cassert>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<string> ans;
	size_t i = 0;
	size_t n = words.size();
	while (i < n) {
		size_t j = i;
		int curWidth = (int) words[j].size();
		while (curWidth <= maxWidth) {
			j++;
			if (j >= n) break;
			curWidth += (int) words[j].size() + 1;
		}
		int nwords = j - i;
		int nspaces = j - i - 1;

		int wordLength = 0;
		for (size_t k = i; k < j; ++k) {
			wordLength += words[k].size();
		}
		int spaceLengthMin = 0; 
		int spaceRemaiders = 0; 
		if (nspaces != 0) {
			spaceLengthMin = (maxWidth - wordLength) / nspaces;
			spaceRemaiders = (maxWidth - wordLength) % nspaces;
		}
		string curLine = words[i];
		for (int k = i + 1; k < j; ++k) {
			curLine += string(spaceLengthMin, ' ');
			if (spaceRemaiders-- > 0) curLine += ' ';
			curLine += words[k];
		}
		// has only one word in this line, should be 'left aligned'
		if (nwords == 1) curLine.resize(maxWidth, ' '); 
		ans.push_back(curLine);

		i = j;
	}
	
	if (!ans.empty()) {
		string lastLine = ans.back();
		ans.pop_back();
		std::istringstream iss(lastLine);

		vector<string> v; // words in the last line
		string w;
		while (iss >> w) {
			v.push_back(w);
		}

		string newLastLine;
		for (size_t i = 0; i < v.size(); ++i) {
			if (i == 0) newLastLine += v[i];
			else newLastLine += ' ' + v[i];
		}
		newLastLine.resize(maxWidth, ' ');
		ans.push_back(newLastLine);
	}
	return ans;
}

int main()
{
	string a[] = {"Listen", "to", "many", "speak", "to", "a", "few."};
	vector<string> v(a, a+7);
	int maxWidth = 6;
	vector<string> ans = fullJustify(v, maxWidth);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}