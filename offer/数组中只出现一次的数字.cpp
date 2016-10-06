#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 简单版本：
 * 对于只出现仅有一个数字出现一次，而其他数字均出现两次的问题，可以通过
 * 将所有数字直接异或得到结果
 *
 * 复杂版本：
 * 可以通过将原数组分割为两个子数组，使得每个子数组中刚好包含其中一个数字，
 * 这样问题就转换为简单版本的问题
 * 1. 首先通过将所有数字异或可以得到 num1 ^ num2
 * 2. 由于两个数字不相等，所以必然存在某个bit位，在该位上一个为1一个为0
 * 3. 找到这样的bit位后，将所有该位上为1的数字归为一组；为0的归为另一组；
 *    即可转换为简单版本的问题
 */
void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
	int n = static_cast<int>(data.size());

	int xor_result = 0;
	for (int i = 0; i < n; ++i) {
		xor_result = xor_result ^ data[i];
	}

	*num1 = 0;
	*num2 = 0;
	int low_bit_mask = xor_result & (-xor_result);
	for (int i = 0; i < n; ++i) {
		if (data[i] & low_bit_mask) {
			*num1 ^= data[i];
		} else {
			*num2 ^= data[i];
		}
	}
	return;
}

int main()
{
	vector<int> v = {5, 3, 2, 1, 2, 5};
	int n1 = 0; int n2 = 0;
	FindNumsAppearOnce(v, &n1, &n2);
	cout << n1 << endl;
	cout << n2 << endl;
	return 0;
}
