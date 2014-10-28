#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdio>
using namespace std;

// Base Case: if cannot find any empty cell, return true
// Find an unsigned cell (x, y)
// for digit from 1 to 9
// 	   if there is not conflict for digit at (x, y)
//     assign (x, y) as digit and Recursively check if this lead to a solution
//     if success, return true
//     else remove the digit at (x, y) and try another digit
// if all digits have been tried and still have not worked out, return false to trigger backtracking

const int GRID_SIZE = 9;
const int SUB_GRID_SIZE = 3;
typedef vector<vector<int> > Grid;

bool IsSafe(const Grid& grid, int x, int y, int num);
bool FindEmptyCell(const Grid& grid, int& x, int& y);
bool Sudoku(Grid& grid);
void PrintSolution(const Grid& grid);

int main()
{
	freopen("sudoku.in", "r", stdin);	
	vector<vector<int> > grid(GRID_SIZE, vector<int>(GRID_SIZE, 0));
	for (int i = 0; i < GRID_SIZE; ++i)
	{
		for (int j = 0; j < GRID_SIZE; ++j)
		{
			cin >> grid[i][j];
		}
	}

	if (Sudoku(grid))
	{
		cout << "Find Solution " << endl;
		PrintSolution(grid);
		cout << endl;
	}
	else
	{
		cout << "Solution does not exist" << endl;
	}
	return 0;
}

bool Sudoku(Grid& grid)
{
	// base case
	int x = 0; int y = 0;
	if (!FindEmptyCell(grid, x, y)) return true;
	
	// for all the number 
	for (int num = 1; num <= 9; ++num)
	{
		if (IsSafe(grid, x, y, num))
		{
			// try one choice
			grid[x][y] = num;
			// if this choice lead to a solution
			if (Sudoku(grid)) return true;
			// otherwise, try an alternative choice
			else grid[x][y] = 0;
		}
	}

	return false;
}

bool IsSafe(const Grid& grid, int x, int y, int num)
{
	// check the current row
	for (int j = 0; j < grid[x].size(); ++j)
	{
		if (j != y && grid[x][j] == num) return false;
	}

	// check current col
	for (int i = 0; i < grid.size(); ++i)
	{
		if (i != x && grid[i][y] == num) return false;
	}

	// check the subgrid
	int ii = x / 3;
	int jj = y / 3;
	for (int i = ii * SUB_GRID_SIZE; i < (ii+1) * SUB_GRID_SIZE; ++i)
	{
		for (int j = jj * SUB_GRID_SIZE;  j < (jj+1) * SUB_GRID_SIZE; ++j)
		{
			if (i != x || j != y)
			{
				if (grid[i][j] == num) return false;
			}
		}
	}

	return true;
}

// Find next Empty Cell
bool FindEmptyCell(const Grid& grid, int& x, int& y)
{
	for (int i = 0; i < GRID_SIZE; ++i)
	{
		for (int j = 0; j < GRID_SIZE; ++j)
		{
			if (grid[i][j] == 0)
			{
				x = i;
				y = j;
				return true;
			}
		}
	}
	return false;
}

void PrintSolution(const Grid& grid)
{
	for (int i = 0; i < GRID_SIZE; ++i)
	{
		for (int j = 0; j < GRID_SIZE; ++j)
		{
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;
}
