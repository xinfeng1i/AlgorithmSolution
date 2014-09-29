#include <iostream>
#include <vector>
using namespace std;


const int NUM_QUEUE = 4;
const int BOARD_SIZE = 4;
typedef vector<vector<int> > Grid;

void PlaceQueue(Grid& grid, int row, int col);
void RemoveQueue(Grid& grid, int row, int col);
bool IsSafe(Grid& grid, int row, int col);
bool NQueue(Grid& grid, int curcol);
void PrintSolution(const Grid& grid);


int main()
{
	vector<vector<int> > grid(BOARD_SIZE, vector<int>(BOARD_SIZE, 0));
	if (NQueue(grid, 0))
	{
		cout << "Find Solution" << endl;
		PrintSolution(grid);
	}
	else
	{
		cout << "Cannot Find Solution" << endl;
	}

	return 0;
}

void PlaceQueue(Grid& grid, int row, int col)
{
	grid[row][col] = 1;
}

void RemoveQueue(Grid& grid, int row, int col)
{
	grid[row][col] = 0;
}

bool IsSafe(Grid& grid, int row, int col)
{
	int i = 0;
	int j = 0;

	// check row
	for (j = 0; j < BOARD_SIZE; ++j)
	{
		if (j != col && grid[row][j] == 1) return false;	
	}

	// check col
	for (i = 0; i < BOARD_SIZE; ++i)
	{
		if (i != row && grid[i][col] == 1) return false;
	}

	// check left upper diag
	for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (grid[i][j] == 1) return false;
	}

	// check left lower diag
	for (i = row + 1, j = col - 1; i < BOARD_SIZE && j >= 0; i++, j--)
	{
		if (grid[i][j] == 1) return false;
	}

	return true;
}

bool NQueue(Grid& grid, int curcol)
{
	// Base case
	if (curcol == BOARD_SIZE)
	{
		return true;
	}

	for (int i = 0; i < BOARD_SIZE;++i)
	{
		if (IsSafe(grid, i, curcol))
		{
			// try a choice
			PlaceQueue(grid, i, curcol);
			// if this choice lead a solution, return
			bool success = NQueue(grid, curcol + 1);
			if (success) return true;
			// else unmake this choice, try an alternative choice
			else RemoveQueue(grid, i, curcol);
		}
	}

	return false;
}

void PrintSolution(const Grid& grid)
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
