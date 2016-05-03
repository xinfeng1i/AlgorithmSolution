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

/**
 * 标准乘法操作
 * 注意进位数的计算，和leading zeros的移除操作
 */
string multiply(string num1, string num2) {
	int n1 = (int)num1.size();
	int n2 = (int)num2.size();
	string ans(n1+n2, '0');
	int k = n1 + n2 - 1;

	int i = n1 - 1;
	int j = n2 - 1;
	int carry = 0;

	for (j = n2 - 1; j >= 0; --j) {
		k = j + n1;
		carry = 0; // 计算进位数
		for (i = n1 - 1; i >= 0; --i) {
			int curNum = (num2[j] - '0') * (num1[i] - '0');
			curNum += (ans[k] - '0') + carry;
			ans[k] = (curNum % 10) + '0';
			carry = curNum / 10;
			k--;
		}

		// 如果进位数不等于0,则将进位数加入前面
		while (carry != 0) {
			ans[k--] = (carry % 10) + '0';
			carry /= 10;
		}
	}

	// 移除leading zeros
	size_t pos = ans.find_first_not_of('0');
	if (pos != string::npos) {
		ans = ans.substr(pos);
	} else { // 结果是全0
		ans = "0";
	}

	return ans;

}

#if 0
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << multiply(s1, s2) << endl;
	return 0;
}
#endif //0