#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) {
	vector<int> firstRow(rowIndex + 1, 0);
	vector<int> secondRow(rowIndex + 1, 0);

	firstRow[0] = 1;
	int flag = 1;
	for (int i = 1; i <= rowIndex; ++i) {
		if (flag == 1) {
			flag = 2;
			secondRow[0] = 1;
			secondRow[i] = 1;
			for (int j = 1; j < i; ++j) {
				secondRow[j] = firstRow[j-1] + firstRow[j];
			}
		}
		else if (flag == 2)	{
			flag = 1;
			firstRow[0] = 1;
			firstRow[i] = 1;
			for (int j = 1; j < i; ++j) {
				firstRow[j] = secondRow[j-1] + secondRow[j];
			}
		}
	}

	if (rowIndex % 2 == 0) return firstRow;
	else return secondRow;
}

int main()
{
	vector<int> ans = getRow(5);
	for (size_t i = 0; i < ans.size(); ++i) 
		cout << " " << ans[i];
	cout << endl;
	return 0;
}
