#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > generate(int numRows) {
	vector<vector<int> > PascalTriangle(numRows);
	for (int i = 0; i < numRows; ++i) {
		PascalTriangle[i].resize(i+1);
		PascalTriangle[i][0] = 1; // first element
		PascalTriangle[i][i] = 1; // last element
		for (int j = 1; j <= i - 1; ++j) {
			PascalTriangle[i][j] = PascalTriangle[i-1][j-1] + PascalTriangle[i-1][j];
		}

	}
	return PascalTriangle;
}

int main()
{
	vector<vector<int> > ans = generate(5);
	for (size_t i = 0; i < ans.size(); ++i) {
		for (size_t j = 0; j < ans[i].size(); ++j) {
			cout << " " << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}
