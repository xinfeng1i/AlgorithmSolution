#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cassert>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*
 * 该题目是一个非常有意思的题
 * 1. 实际上就是求得一个序列，使得这个序列的值最小，换句话说，我们希望求的是排序
 *    规则，按照这个规则排序得到的值最小
 * 2. 因为有sort函数的存在，我们只需要定义任意两个元素的大小判断即可，那么最简单
 *    的方法就是比较ab排列和ba排列，取较小的即可
 *
 * 关键是要想要这个一个排序问题
 */
bool cmp(int a, int b) {
	char temp_a[64] = {'\0'};
	char temp_b[64] = {'\0'};
	sprintf(temp_a, "%d", a);
	sprintf(temp_b, "%d", b);
	string str_a(temp_a);
	string str_b(temp_b);
	return str_a+str_b < str_b+str_a;
}

string PrintMinNumber(vector<int> numbers) {
	sort(numbers.begin(), numbers.end(), cmp);
	string ans="";
	for (size_t i = 0; i < numbers.size(); ++i) {
		char temp[64] = {'\0'};
		sprintf(temp, "%d", numbers[i]);
		ans += string(temp);
	}
	return ans;
}

int main()
{
	vector<int> v = {3, 32, 321};
	cout << PrintMinNumber(v) << endl;
	return 0;
}
