#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

void combinationRecur(const string& digits, map<char, string>& hashtb,
	int curPos, string& curstr, vector<string>& ans)
{
	// base case
	if (curPos >= digits.size())
	{
		cout << curstr << endl;
		ans.push_back(curstr);
		return;
	}

	string alphas = hashtb[digits[curPos]];
	for (size_t i = 0; i < alphas.size(); ++i)
	{
		curstr.push_back(alphas[i]);
		combinationRecur(digits, hashtb, curPos + 1, curstr, ans);
		curstr.pop_back();

	}
}


vector<string> letterCombinations(string digits)
{
	string curstr;
	vector<string> ans;
	if (digits.empty()) return ans; // 字符串为空，特殊情况
	
	map<char, string> hashtable;
	hashtable['0'] = " ";
	hashtable['1'] = "";
	hashtable['2'] = "abc";
	hashtable['3'] = "def";
	hashtable['4'] = "ghi";
	hashtable['5'] = "jkl";
	hashtable['6'] = "mno";
	hashtable['7'] = "pqrs";
	hashtable['8'] = "tuv";
	hashtable['9'] = "wxyz";


	combinationRecur(digits, hashtable, 0, curstr, ans);
	return ans;
}

// 回溯算法，注意输入为空串的特殊情况

int main()
{
	vector<string> ans = letterCombinations("");
	return 0;
}