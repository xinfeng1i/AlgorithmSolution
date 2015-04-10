#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

vector<int> ConvertRow(vector<int>& initRow)
{
	int n = initRow.size();
	vector<int> finalRow;
	finalRow.reserve(n);

	int pos = 0;
	while (pos < n)
	{
		if (pos + 1 < n && initRow[pos] != 0 && initRow[pos] == initRow[pos+1])
		{
			finalRow.push_back(initRow[pos] * 2);
			pos += 2;
		}
		else
		{
			finalRow.push_back(initRow[pos]);
			pos++;
		}
	}
	return finalRow;
}

void MoveRight(vector<vector<int>>& grid)
{
	int n = grid.size();
	for (int i = 0;	i < n; ++i)
	{
		vector<int> curRow; curRow.reserve(n);
		for (int j = n - 1; j >= 0; j--)
		{
			if (grid[i][j] != 0) 
			{
				curRow.push_back(grid[i][j]);
				grid[i][j] = 0;
			}
		}

		vector<int> finalRow = ConvertRow(curRow);

		int k, j;
		for (k = 0, j = n - 1; k < finalRow.size(); k++, j--)
		{
			grid[i][j] = finalRow[k];	
		}
	}
}

void MoveLeft(vector<vector<int>>& grid)
{
	int n = grid.size();
	for (int i = 0;	i < n; ++i)
	{
		vector<int> curRow; curRow.reserve(n);
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] != 0) 
			{
				curRow.push_back(grid[i][j]);
				grid[i][j] = 0;
			}
		}

		vector<int> finalRow = ConvertRow(curRow);

		int k, j;
		for (k = 0, j = 0; k < finalRow.size(); k++, j++)
		{
			grid[i][j] = finalRow[k];	
		}
	}
}

void MoveUp(vector<vector<int>>& grid)
{
	int n = grid.size();
	for (int j = 0; j < n; ++j)
	{
		vector<int> curCol; curCol.reserve(n);
		for (int i = 0; i < n; ++i)
		{
			if (grid[i][j] != 0) 
			{
				curCol.push_back(grid[i][j]);
				grid[i][j] = 0;
			}
		}

		vector<int> finalCol = ConvertRow(curCol);
		int k, i;
		for (k = 0, i = 0; k < finalCol.size(); k++, i++)
		{
			grid[i][j] = finalCol[k];
		}
	}
}

void MoveDown(vector<vector<int>>& grid)
{
	int n = grid.size();
	for (int j = 0; j < n; ++j)
	{
		vector<int> curCol; curCol.reserve(n);
		for (int i = n - 1; i >= 0; --i)
		{
			if (grid[i][j] != 0) 
			{
				curCol.push_back(grid[i][j]);
				grid[i][j] = 0;
			}
		}

		vector<int> finalCol = ConvertRow(curCol);
		int k, i;
		for (k = 0, i = n - 1; k < finalCol.size(); k++, i--)
		{
			grid[i][j] = finalCol[k];
		}
	}
}


void PrintGrid(const vector<vector<int>>& grid)
{
	int n = grid.size();
	for (int i = 0; i < n; ++i)
	{
		bool isFirst = true;
		for (int j = 0; j < n; ++j)
		{
			if (!isFirst) cout << " " << grid[i][j];
			else { cout << grid[i][j]; isFirst = false; }
		}
		cout << endl;
	}
}

int main()
{
	//freopen("data.in", "r", stdin);
	//freopen("B-small-practice.in", "r", stdin);
	//freopen("B-small-practice.out", "w", stdout);
	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);

	int T = 0;
	cin >> T;

	for (int nCase = 1; nCase <= T; ++nCase)
	{
		int N = 0;
		string DIR;
		cin >> N >> DIR;

		vector<vector<int>> grid(N, vector<int>(N, 0));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> grid[i][j];
			}
		}

		cout << "Case #" << nCase << ":" << endl;

		if (DIR == "left") MoveLeft(grid);
		else if (DIR == "right") MoveRight(grid);
		else if (DIR == "up") MoveUp(grid);
		else if (DIR == "down") MoveDown(grid);

		PrintGrid(grid);

	}
	return 0;
}