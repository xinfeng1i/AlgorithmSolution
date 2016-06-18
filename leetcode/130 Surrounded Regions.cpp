#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;

// DFS flood will cause stack overflow with too deep recursion
// need to use the BFS to avoid such cases
void DFS(vector<vector<char>>& board, int i, int j, char ch1, char flag)
{
	int m = board.size();
	int n = board[0].size();
	board[i][j] = flag; // visit current node
	if (i-1>=0 && board[i-1][j]==ch1) DFS(board, i-1, j, ch1, flag);
	if (i+1< m && board[i+1][j]==ch1) DFS(board, i+1, j, ch1, flag);
	if (j-1>=0 && board[i][j-1]==ch1) DFS(board, i, j-1, ch1, flag);
	if (j+1< n && board[i][j+1]==ch1) DFS(board, i, j+1, ch1, flag);
}

void BFS(vector<vector<char>>& board, int i, int j, char ch1, char flag) {
	int m = board.size();
	int n = board[0].size();
	queue<pair<int, int> > q;
	board[i][j] = flag; // visit current node and push current node
	q.push(make_pair(i, j));
	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		if (row-1>=0 && board[row-1][col] == ch1) {
			board[row-1][col] = flag;
			q.push(make_pair(row-1, col));
		}
		if (row+1<m && board[row+1][col] == ch1) {
			board[row+1][col] = flag;
			q.push(make_pair(row+1, col));
		}
		if (col-1>=0 && board[row][col-1] == ch1) {
			board[row][col-1] = flag;
			q.push(make_pair(row, col-1));
		}
		if (col+1<n && board[row][col+1] == ch1) {
			board[row][col+1] = flag;
			q.push(make_pair(row, col+1));
		}
	}
	

}

void solve(vector<vector<char>>& board) {
	if (board.empty()) return;
	int m = (int) board.size();
	int n = (int) board[0].size();

	// mark all the 'O' adjacent to the board to be '1' first
	for (int j = 0; j < n; ++j) {
		if (board[0][j] == 'O') {
			BFS(board, 0, j, 'O', '1');
		}
	}
	for (int j = 0; j < n; ++j) {
		if (board[m-1][j] == 'O') {
			BFS(board, m-1, j, 'O', '1');
		}
	}
	for (int i = 0; i < m; ++i) {
		if (board[i][0] == 'O') {
			BFS(board, i, 0, 'O', '1');
		}
	}
	for (int i = 0; i < m; ++i) {
		if (board[i][n-1] == 'O') {
			BFS(board, i, n-1, 'O', '1');
		}
	}

	// mask all the 'O' in the remaining board to be 'X'
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 'O') {
				board[i][j] = 'X';
			}
		}
	}

	// mask all the '1' adjacent to the board back to be 'O'
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == '1') {
				board[i][j] = 'O';
			}
		}
	}
}