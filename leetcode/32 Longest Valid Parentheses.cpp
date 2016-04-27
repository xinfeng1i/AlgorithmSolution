#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


/**
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

int main()
{
	int ans = longestValidParentheses(")");
	cout << ans << endl;
	return 0;
}