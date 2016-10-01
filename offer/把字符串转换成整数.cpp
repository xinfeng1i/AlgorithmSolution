#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 经典库函数实现问题：字符串转整数
 * 1. 注意正负号问题
 * 2. 注意整型溢出问题，所以首先要使用 long long 类型
 *
 */

int StrToInt(string str) {
	if (str.empty()) return 0;
	int flag = 1; // positive or negative
	if (str[0] == '+' || str[0] == '-') {
		if (str[0] == '-') flag = -1;
		str = str.substr(1);
	}
	
	// only has a sign, not legal.
	if (str.empty()) return 0;
	
	long long num = 0LL;
	for (size_t i = 0; i < str.size(); ++i) {
		if (!(str[i] >= '0' && str[i] <= '9')) {
			return 0;
		} else {
			int digit = str[i] - '0';
			num = 10 * num + digit;
			if (flag == 1 && num > INT_MAX) {
				return 0;  // positive number overflow
			} else if (flag == -1 && -num < INT_MIN) {
				return 0;  // negative number overflow
			}
		}
	}
	return num * flag;
}

int main() {
	cout << StrToInt("-2147483648") << endl;
	cout << StrToInt("1a33") << endl;
	return 0;
}
