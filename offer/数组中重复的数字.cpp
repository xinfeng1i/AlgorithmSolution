#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 轮询交换元素
 */
bool duplicate(int numbers[], int length, int* duplication) {
	if (numbers == NULL) return false; // invalid input
	if (length <= 0) return false; // invalid input
	if (length == 1) return false; // cannot have duplicates
	
	for (int i = 0; i < length; ++i) {
		if (numbers[i] != i) {
			int num = numbers[i]; // 当前位置的元素拿走
			numbers[i] = -1;      // 置当前位置为空
			if (num == numbers[num]) { // 如果目标位置已有元素且相等、发现重复
				*duplication = num;
				return true;
			} else {
				// 如果目标位置不空，且元素不等于当前元素，则迭代
		        while (numbers[num] != -1 && num != numbers[num]) {
		            int temp = numbers[num];
                    numbers[num] = num;
                    num = temp;
				}
				if (numbers[num] == -1) { // 如果目标位置为空，则直接放入
					numbers[num] = num;
				} else if (numbers[num] == num) { // 反之，目标位置不空且相等，发现重复
					*duplication = num;
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	int a[] = {2, 1, 3, 1, 4};
	int n = 5;
	int dup = -1;
	cout << duplicate(a, n, &dup) << endl;
	cout << dup << endl;
	return 0;
}
