#include <iostream>
#include <vector>
using namespace std;

/**
 * 类似于二分搜索，只不过是二维表格的搜索
 * 以左下角或者右上角元素作为比较的mid元素，
 * 根据定义：其上面的元素必然比它小；
 *           其下面的元素必然比他大；
 * 因此，如果target大于mid元素，则可以排除其上面的元素，即所在列
 *       如果target小于mid元素，则可以排除其右面的元素，即所在行
 * 这样每次比较可以排除一行或者一列，因此总的复杂度为O(m+n)
 */
bool Find(vector<vector<int> > A,int target)
{
	if (A.empty()) return false;

	int m = static_cast<int>(A.size());
	int n = static_cast<int>(A[0].size());

	int i = m - 1;
	int j = 0;
	while (i >= 0 && j < n) {
		if (A[i][j] == target) {
			return true;
		} else if (A[i][j] < target) {
		    j++;
        } else {
            i--;
        }
	}
	return false;
}
