#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int BOARD_SIZE = 8;
const int NUM_MOVE = 8;
const int dx[NUM_MOVE] = {1, 2, -1, -2, -2, -1,  1,  2};
const int dy[NUM_MOVE] = {2, 1, -2, -1,  1,  2, -1, -2};
typedef vector<vector<int> > Board;


bool FullBoard(Board& board);
bool IsSafe(Board& board, int x, int y);
void MakeTour(Board& board, int x, int y, int stepCnt);
void UnMakeTour(Board& board, int x, int y);
bool KnightTour(Board& board, int curx, int cury, int curStepCnt);
void PrintSolution(const Board& board);

int main()
{
	vector<vector<int> > board(BOARD_SIZE, vector<int>(BOARD_SIZE, -1));
	
	// make the first step
	board[0][0] = 0;

	if (KnightTour(board, 0, 0, 0))
	{
		cout << "Find Solution !" << endl;
		PrintSolution(board);
	}
	else
	{
		cout << "Solution does not exist !" << endl;
	}

	return 0;
}


bool KnightTour(Board& board, int curx, int cury, int curStepCnt)
{
	// Base Case
	if (curStepCnt == BOARD_SIZE * BOARD_SIZE)
		return true;

	for (int i = 0; i < NUM_MOVE; ++i)
	{
		int nextx = curx + dx[i];
		int nexty = cury + dy[i];
		if (IsSafe(board, nextx, nexty))
		{
			// try a choice
			MakeTour(board, nextx, nexty, curStepCnt+1);
			bool success = KnightTour(board, nextx, nexty, curStepCnt+1);
			// if the choice lead to a solution, return true
			if (success) return true;
			// otherwise, unmake the choice,backtracking, try an alternative choice
			else UnMakeTour(board, nextx, nexty);
		}
	}

	return false;
}


bool IsSafe(Board& board, int x, int y)
{
	return (x >= 0 && x < BOARD_SIZE && 
			y >= 0 && y < BOARD_SIZE &&
		    board[x][y] == -1);
}

void MakeTour(Board& board, int x, int y, int stepCnt)
{
	board[x][y] = stepCnt;
}


void UnMakeTour(Board& board, int x, int y)
{
	board[x][y] = -1;
}


void PrintSolution(const Board& board)
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
