#include <iostream>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 哈希表典型应用
 * 不要吝啬使用哈希表
 */

int FirstNotRepeatingChar(string str) {
	int n = static_cast<int>(str.size());
	
	unordered_map<char, int> hash;
	for (int i = 0; i < n; ++i) {
		int ch = str[i];
		hash[ch] += 1;
	}
	
	for (int i = 0; i < n; ++i) {
		int ch = str[i];
		if (hash[ch] == 1) {
			return i;
		}
	}
	return -1;
}
