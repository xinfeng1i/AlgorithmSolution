#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool isRowSafe(vector<vector<char> >&board, int row, int col)
{
	int n = board.size();
	for (int j = 0; j < n; ++j)
	{
		if (j != col && board[row][j] != '.' && board[row][j] == board[row][col])
		{
			return false;
		}
	}
	return true;
}

bool isColSafe(vector<vector<char> >&board, int row, int col)
{
	int n = board.size();
	for (int i = 0; i < n; ++i)
	{
		if (i != row && board[i][col] != '.' && board[i][col] == board[row][col])
		{
			return false;
		}
	}
	return true;
}

bool isGridSafe(vector<vector<char> >& board, int row, int col)
{
	int rowGrid = row / 3;
	int colGrid = col / 3;
	for (int i = rowGrid * 3; i < (rowGrid + 1) * 3; ++i)
	{
		for (int j = colGrid * 3; j < (colGrid + 1) * 3; ++j)
		{
			if (i != row || j != col)
			{
				if (board[i][j] != '.' && board[i][j] == board[row][col])
				{
					return false;
				}
			}
		}
	}
	return true;
}

bool isSafe(vector<vector<char> >&board, int i, int j)
{
	return isRowSafe(board, i, j) && isColSafe(board, i, j) && isGridSafe(board, i, j);

}

bool isFull(vector<vector<char> > &board)
{
	int n = board.size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (board[i][j] == '.') return false;
		}
	}
	return true;
}


bool solveSudokuUtility(vector<vector<char> > &board)
{
	// base case
	if (isFull(board))
	{
		return true;
	}

	int n = board.size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (board[i][j] == '.')
			{
				for (int x = '1'; x <= '9'; ++x)
				{
					// try a choice
					board[i][j] = x;
					if (isSafe(board, i, j) && solveSudokuUtility(board) == true)
					{
						return true;
					}
					// backtracking
					board[i][j] = '.';
				}
				return false;			
			}
		}
	}	
}

void solveSudoku(vector<vector<char> >& board)
{
	bool flag = solveSudokuUtility(board);
}

void PrintBoard(vector<vector<char> >& board)
{
	int n = board.size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	vector<vector<char> > board(9, vector<char>(9, '.'));

	board[0][0] = '5'; board[0][1] = '3'; board[0][4] = '7';
	board[1][0] = '6'; board[1][3] = '1'; board[1][4] = '9'; board[1][5] = '5';	
	board[2][1] = '9'; board[2][2] = '8'; board[2][7] = '6';

	board[3][0] = '8'; board[3][4] = '6'; board[3][8] = '3';
	board[4][0] = '4'; board[4][3] = '8'; board[4][5] = '3'; board[4][8] = '1';
	board[5][0] = '7'; board[5][4] = '2'; board[5][8] = '6';

	board[6][1] = '6'; board[6][6] = '2'; board[6][7] = '8';
	board[7][3] = '4'; board[7][4] = '1'; board[7][5] = '9'; board[7][8] = '5';
	board[8][4] = '8'; board[8][7] = '7'; board[8][8] = '9';

	PrintBoard(board);

	solveSudoku(board);

	PrintBoard(board);
	return 0;
}