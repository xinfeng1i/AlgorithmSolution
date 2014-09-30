#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int BOARD_SIZE = 4;
enum GridState {Gray, White, Green};

const int DIRECTION_NUM = 2;
const int dx[DIRECTION_NUM] = {0, 1};
const int dy[DIRECTION_NUM] = {1, 0};
typedef vector<vector<GridState> > Grid;


bool IsSafe(Grid& grid, int x, int y);
bool SolveRatMaze(Grid& grid, int curx, int cury);
void PrintSolution(const Grid& grid);


int main()
{
	vector<vector<GridState> > grid(BOARD_SIZE, vector<GridState>(BOARD_SIZE, White));
	for (int j = 1; j < BOARD_SIZE; ++j) grid[0][j] = Gray;
	grid[1][2] = Gray;
	grid[2][0] = Gray; grid[2][2] = Gray; grid[2][3] = Gray;

	// Place the init position
	grid[0][0] = Green;
	bool ok = SolveRatMaze(grid, 0, 0);
	if (ok)
	{
		cout << "Found Solution" << endl;
		PrintSolution(grid);
	}
	else
	{
		cout << "Solution does not exist" << endl;
	}

	return 0;
}


bool SolveRatMaze(Grid& grid, int curx, int cury)
{
	// base case
	if (curx == BOARD_SIZE - 1 && cury == BOARD_SIZE - 1) return true;

	// for every choice
	for (int i = 0; i <	DIRECTION_NUM; ++i)
	{
		int nextx = curx + dx[i];
		int nexty = cury + dy[i];
		if (IsSafe(grid, nextx, nexty))
		{
			// try a choice
			grid[nextx][nexty] = Green;
			// check whether lead to a solution
			bool success = SolveRatMaze(grid, nextx, nexty);
			// if yes, return true
			if (success) return true;
			// no, try an alternative choice, backtracking
			else grid[nextx][nexty] = White;
		}
	}

	// try every choice, still cannot find a solution
	return false;
}

bool IsSafe(Grid& grid, int x, int y)
{
	return grid[x][y] == White;
}

void PrintSolution(const Grid& grid)
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;
}
