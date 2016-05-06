#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void PrintVec(const vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		cout << " " << v[i];
	}
	cout << endl;
}

int minimumTotal(vector<vector<int>>& triangle) {
	if (triangle.empty()) return 0;

	int n = (int)triangle.size();
	if (n == 1) return triangle[0][0];

	vector<int> firstRow(n, 0);
	vector<int> secondRow(n, 0);
	for (size_t j = 0; j < triangle[0].size(); ++j) {
		firstRow[j] = triangle[0][j];
	}

	for (int i = 1; i <= n - 1; ++i) {
		if (i % 2 == 1) {
			for (int j = 0; j <= i; ++j) {
				if (j - 1 < 0) {
					secondRow[j] = firstRow[j] + triangle[i][j];
				} else if (j == i) {
					secondRow[j] = firstRow[j-1] + triangle[i][j];
				} else {
					secondRow[j] = min(firstRow[j-1] + triangle[i][j], firstRow[j] + triangle[i][j]);
				}
			}
		} else {
			for (int j = 0; j <= i; ++j) {
				if (j - 1 < 0) {
					firstRow[j] = secondRow[j] + triangle[i][j];
				} else if (j == i) {
					firstRow[j] = secondRow[j-1] + triangle[i][j];
				
				} else {
					firstRow[j] = min(secondRow[j-1] + triangle[i][j], secondRow[j] + triangle[i][j]);
				}
			}
		}

		//printf("\n");
		//PrintVec(firstRow);
		//PrintVec(secondRow);
		

	}

	if ( (n - 1) % 2 == 1) {
		return *min_element(secondRow.begin(), secondRow.end());	
	} else {
		return *min_element(firstRow.begin(), firstRow.end());
	}
        
}

#if 0
int main()
{
	vector<vector<int>> m(4);
	m[0].push_back(2);
	
	m[1].push_back(3);
	m[1].push_back(4);

	m[2].push_back(6);
	m[2].push_back(5);
	m[2].push_back(7);

	m[3].push_back(4);
	m[3].push_back(1);
	m[3].push_back(8);
	m[3].push_back(3);

	cout << minimumTotal(m) << endl;
	return 0;
}
#endif //0