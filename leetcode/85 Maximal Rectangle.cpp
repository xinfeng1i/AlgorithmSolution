#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cstdio>
using namespace std;

int maximalRectangleInHistogram(vector<int> height) {
	int n = height.size();
	int ans = 0;
	
	stack<int> S;
	int i = 0;
	while (i < n) {
		if (S.empty() || height[i] >= height[S.top()]){
			S.push(i);
			i++;
		} else {
			int tp = S.top(); S.pop();
			int left_idx = S.empty() ? -1 : S.top();
			ans = max(ans, (i-left_idx-1)*height[tp]);
		}
	}
	
	while (!S.empty()) {
	    int tp = S.top(); S.pop();
	    int left_idx = S.empty() ? -1 : S.top();
	    ans = max(ans, (i-left_idx-1)*height[tp]);
	}
	return ans;
}


int maximalRectangle(vector<vector<char>>& M) {
	if (M.empty()) return 0;
	int m = M.size();
	int n = M[0].size();
	int ans = 0;
	
	vector<vector<int>> hist(m, vector<int>(n, 0));
	for (int j = 0; j < n; ++j) {
		if (M[0][j] == '1') hist[0][j] = 1;
	}
	
	for (int i = 1; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (M[i][j]=='0') {
				hist[i][j] = 0;
			} else {
				if (hist[i-1][j] == 0) hist[i][j] = 1;
				else hist[i][j] = hist[i-1][j] + 1;
			}
		}
	}
	
	//printf("The build Hist Matrix\n");
	//for (int i = 0; i < m; ++i) {
	//	for (int j = 0; j < n; ++j) {
	//		printf(" %d", hist[i][j]);
	//	}
	//	printf("\n");
	//}
	
	for (int i = m-1; i >= 0; --i) {
		int temp = maximalRectangleInHistogram(hist[i]);
		//printf("row = %d, area = %d\n", i, temp);
		ans = max(ans, temp);
	}
	return ans;
}


//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
int main()
{
	vector<char> r1 = {'1', '0', '1', '0', '0'};
	vector<char> r2 = {'1', '0', '1', '1', '1'};
	vector<char> r3 = {'1', '1', '1', '1', '1'};
	vector<char> r4 = {'1', '0', '0', '1', '0'};
	vector<vector<char>> M;
	M.push_back(r1);
	M.push_back(r2);
	M.push_back(r3);
	M.push_back(r4);
	cout << maximalRectangle(M) << endl;
	return 0;
}
