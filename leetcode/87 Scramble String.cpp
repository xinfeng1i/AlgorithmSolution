#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isScramble(string s1, string s2) {
	if (s1 == s2) return true;
	int n1 = s1.size();
	int n2 = s2.size();
	if (n1 != n2) return false;
	
	if (n1 == 1 && n2 == 1 && s1 == s2) return true;
	if (n1 == 2 && n2 == 2 && s1[0] == s2[1] && s1[1] == s2[0]) return true;
	
	// 剪枝BEGIN，对于字母数不想等的字符串，不用判断即可知道其必然不是scramble
	// 这个简单的措施可以避免TLE
	int cnt[26] = {0};
	for (int i = 0; i < n1; ++i) {
		cnt[s1[i]-'a']++;
	}
	for (int i = 0; i < n2; ++i) {
		cnt[s2[i]-'a']--;
	}
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] != 0) return false;
	}
	// 剪枝END
	
	for (int len = 1; len <= n1-1; ++len) {
		string s1_prefix = s1.substr(0, len);
		string s1_suffix = s1.substr(len);
		string s2_prefix = s2.substr(0, len);
		string s2_suffix = s2.substr(len);
		bool ok1 = isScramble(s1_prefix, s2_prefix) && isScramble(s1_suffix, s2_suffix);
		if (ok1) return true;
		
		string s2_prefix2 = s2.substr(0, n1-len);
		string s2_suffix2 = s2.substr(n1-len);
		bool ok2 = isScramble(s1_prefix, s2_suffix2) && isScramble(s1_suffix, s2_prefix2);
		
		if (ok2) return true;
	}
	return false;
}

int main()
{
	string s1 = "great";
	string s2 = "rgtae";
	cout << isScramble(s1, s2) << endl;
	return 0;
}
