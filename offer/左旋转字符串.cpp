#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 经典的左旋转问题:
 * 注意除数为0的情况，即空串情况
 */
string LeftRotateString(string str, int k) {
	if (str.empty()) return str;
	int n = static_cast<int>(str.size());
	k = k % n;
	reverse(str.begin(), str.begin()+k);
	reverse(str.begin()+k, str.end());
	reverse(str.begin(), str.end());
	return str;
}

int main()
{
	cout << LeftRotateString("abcXYZdef", 3) << endl;
	return 0;
}
