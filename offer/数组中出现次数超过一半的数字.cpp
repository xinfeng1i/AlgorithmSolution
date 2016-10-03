#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 寻找出现次数超过一半的元素
 * 1. 设置当前元素为寻找元素，并置flag=1
 * 2. 对于每一个元素，如果其与当前元素相等，则flag++; 否则，则flag--
 * 3. 任何时候flag = 0，则重置当前元素为待选元素，flag = 1
 * 4. 验证，所找元素是否真的是出现过半
 */
int MoreThanHalfNum_Solution(vector<int> numbers) {
	if (numbers.empty()) return 0;
	
	int n = static_cast<int>(numbers.size());
	int flag = 1;
	int cur = numbers[0];
	for (int i = 1; i < n; ++i) {
		if (flag == 0) {
			flag = 1;
			cur = numbers[i];
		} else {
			if (numbers[i] == cur) flag += 1;
			else flag -= 1;
		}
	}
	
	if (flag == 0) {
		return 0;
	} else {
	    // verify whether the number is truly more than half
	    int cnt = 0;
	    for (int i = 0; i < n; ++i) {
		    if (numbers[i] == cur) cnt++;
	    }
	    
	    if (cnt * 2 > n) return cur;
	    else return 0;

	}
}

int main()
{
	vector<int> v = {1,2,3,2,4,2,5,2,3};
	//cout << "v.size():" << v.size() << endl;
	cout << MoreThanHalfNum_Solution(v) << endl;
	return 0;
}
