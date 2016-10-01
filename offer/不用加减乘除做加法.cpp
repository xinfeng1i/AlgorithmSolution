#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 使用位运算计算加法
 * 用 [异或] 运算符来更新不进位的结果
 * 用 [与] 元算符类更新进位的结果，最后将两者相加
 *
 */
int Add(int num1, int num2)
{

	int sum = num1 ^ num2;
	int carry = num1 & num2;
	if (carry == 0) {
		return sum;
	} else {
		return Add(sum, (carry<<1));
	}

}

int main()
{
	cout << Add(1, 2) << endl;
	cout << Add(8, 13) << endl;
	cout << Add(-21, -36) << endl;
	cout << Add(21, -15) << endl;
	return 0;
}
