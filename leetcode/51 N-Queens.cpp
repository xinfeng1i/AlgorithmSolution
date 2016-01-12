#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsSafe(int row, int col, vector<string>& grid)
{
    int n = grid.size();
    // check column
    for (int i = 0; i < row; ++i) {
        if (grid[i][col] == 'Q')
            return false;
    }
    
    // check left-up diag
    for (int i = row-1, j = col-1; i>=0 && j>=0; i--,j--) {
        if (grid[i][j] == 'Q')
            return false;
    }
    
    // check right-up diag
    for (int i = row-1, j = col+1; i>=0 && j<n; i--, j++) {
        if (grid[i][j] == 'Q') {
            return false;
        }
    }
    
    return true;
}

void NQueensRecursive(int row, vector<string>& grid, vector<vector<string> >& result)
{
    int n = grid.size();
    if (row >= n) {
        result.push_back(grid);
        return;
    }
    
    for (int j = 0; j < n; ++j) {
        if(IsSafe(row, j, grid)) {
            // try a choice
            grid[row][j] = 'Q';
            NQueensRecursive(row+1, grid, result);
            // backtracking
            grid[row][j] = '.';
        }
    }
    return;
}

vector<vector<string> > solveNQueens(int n) {
	vector<string> grid(n, string(n, '.'));
	vector<vector<string> > result;
	NQueensRecursive(0, grid, result);
	return result;
}

int main()
{
	int n = 4;
	vector<vector<string> > result = solveNQueens(n);
	for (size_t i = 0; i < result.size(); ++i) {
		vector<string> temp = result[i];
		for (size_t j = 0; j < temp.size(); ++j) {
			cout << temp[j] << endl;
		}
	}
    return 0;
}
