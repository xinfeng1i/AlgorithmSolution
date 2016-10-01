#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 双翻转问题变种：
 * 现对单词级别做反转，然后反转整个句子
 */
string ReverseSentence(string str) {
	if (str.empty()) return str;
	int n = static_cast<int>(str.size());
	int i = 0;
	while (i < n) {
		while (i < n && str[i] == ' ') i++;
		if (i < n) {
			int j = i;
			while (j < n && str[j] != ' ') j++;
			// reverse the current word
			reverse(str.begin()+i, str.begin()+j);
			i = j;
		}
	}
	// reverse the whole sentence
	reverse(str.begin(), str.end());
	return str;
}

int main()
{
	cout << ReverseSentence("  student  . a am      I") << endl;
	return 0;
}
