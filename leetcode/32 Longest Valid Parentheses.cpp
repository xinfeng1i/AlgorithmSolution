#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


#if 0
/**
 * 解法一：括号匹配
 * 1. 从左至右扫描整个字符串
 * 2. 如果遇到左括号，进栈；
 * 3. 如果遇到右括号，如果栈不空且栈顶为左括号，退栈；否则，右括号进栈
 * 4. 结束时，若栈为空，则整个字符串合法
 * 5. 否则，栈中存放所有非法括号的位置，计算非法位置中间的序列长度，取最大长度
 */

int longestValidParentheses(string s) {
	int n = (int)s.size();
	stack<int> st;
	for (int i = 0; i < n; ++i) {
		// 遇到左括号，索引进栈
		if (s[i] == '(') {
			st.push(i);
	    // 遇到右括号
		} else {
			// 如果栈顶为左括号，匹配，退栈
			if (!st.empty() && s[st.top()] == '(') {
				st.pop();
			} else { // 否则如果栈顶也为右括号，进栈
				st.push(i);
			}
		}
	}

	int longest = 0;
	// 如果栈空，则整个字符串完全匹配
	if (st.empty()) {
		return n;
	} else {
		// 从右到左，寻找最优长度
		int right = n;
		int left = 0;

		// left 位置不匹配，则(left, right)之间必然匹配
		while (!st.empty()) {
			left = st.top();
			st.pop();
			longest = max(longest, right-left-1);
			right = left;
		}

		// 退出loop时，right指向第一个不匹配位置，还要计算[0, right)之间匹配的长度
		longest = max(longest, right);

		return longest;
	}
}
#endif //0

/**
 * 解法二：动态规划
 * 定义dp[i] = 到i结尾处的最长有效括号匹配长度
 * 如果当前是左括号，则dp[i] = 0
 * 如果当前是右括号，并且前一个位置是左括号,则dp[i] = 2 + dp[i-2] // 如下图pos = 5
 * 否则如果当前是右括号，前面一个也是右括号 (如pos=6),则dp[i-1]表示前一个已经匹配的
 * 长度，需要查看i-dp[i-1]-1的位置（pos=1）如果是左括号，则也能匹配到，这样新增长度2，
 * 同时还要加上该位置之前的匹配长度，即dp[i-dp[i-1]-2],
 * 综上：dp[i] = dp[i-1]+2+dp[i-dp[i-1]-2]
 * 需要注意所有索引位置必须大于等于0
 * 
 * /// 示例图
 * ) ( ( ) ( ) )
 * 0 1 2 3 4 5 6
 */

int longestValidParentheses(string s) {
	int n = int(s.size());
	vector<int> dp(n, 0);
	int longest = 0;
	for (int i = 1; i < n; ++i) {
		// 如果是左括号，不可能存在以左括号结尾的有效括号序列
		if (s[i] == '(') {
			dp[i] = 0;
		} else {
			if (i - 1 >= 0 && s[i-1] == '(') {
				dp[i] = 2 + (i-2 >= 0 ? dp[i-2]:0);
				longest = max(longest, dp[i]);
			} else if (i - 1 >= 0 && s[i-1] == ')' && i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(') {
				dp[i] = 2 + dp[i-1] + (i-dp[i-1]-2 >= 0 ? dp[i-dp[i-1]-2] : 0);
				longest = max(longest, dp[i]);
			}
		}
		//cout << "dp[" <<i << "] = " << dp[i] << endl;
	}
	return longest;
}

int main()
{
	int ans = longestValidParentheses(")(()())");
	cout << ans << endl;
	return 0;
}