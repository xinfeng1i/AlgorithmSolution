#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 丑数 bottom to up
 * 1. 关键问题是下一个丑数如何产生？下一个丑数肯定是由比当前丑数小的某个数
 *    乘以2，乘以3，乘以5得到的三个数中的最小者
 * 2. 所以需要不断的追踪这三个比当前丑数小的最大的那个数在哪里？我们用三个
 *    索引来表示，为了使其最大化，每个更新后需要不断的将三个索引步进，直到
 *    哪怕再乘以一个2,3,5因此也会大于当前丑数为止
 */

int GetUglyNumber_Solution(int index) {
	if (index <= 0) return 0;
	if (index == 1) return 1;
	vector<int> v(index, 0);
	v[0] = 1;
	int idx2 = 0;
	int idx3 = 0;
	int idx5 = 0;
	int cur_index = 0;
	while (cur_index < index-1) {
		int nextUgly = min(min(v[idx2]*2, v[idx3]*3), v[idx5]*5);
		v[cur_index+1] = nextUgly;
		
		while (idx2 < index && v[idx2] * 2 <= nextUgly) idx2++;
		while (idx3 < index && v[idx3] * 3 <= nextUgly) idx3++;
		while (idx5 < index && v[idx5] * 5 <= nextUgly) idx5++;
		cur_index++;
	}
	
	return v[index-1];
}

int main()
{
	cout << GetUglyNumber_Solution(30) << endl;
	return 0;
}
