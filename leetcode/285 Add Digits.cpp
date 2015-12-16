#include <iostream>
#include <string>
using namespace std;

/*
 * 对于整数，其结果是周期性的1-9然后再次1-9
 * 所以只需要判断mod 9的余数即可
 * 注意如果恰好能够整除9，应该返回9，而不是0
 */
int addDigits(int num) {
	if (num == 0) return 0;

	if (num % 9 == 0) return 9;
	else return num % 9;
}