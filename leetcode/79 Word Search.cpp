#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool exist(vector<vector<char> >& board, vector<vector<bool> >&visited, int i,
           int j, string word)
{
	if (word.empty()) return true;
	int m = board.size();
	int n = board[0].size();

	if (i == -1 && j == -1) {
		for (int ii = 0; ii < m; ++ii) {
			for (int jj = 0; jj < n; ++jj) {
				if (word[0] == board[ii][jj] && visited[ii][jj] == false) {
					visited[ii][jj] = true;
					if (exist(board, visited,  ii, jj, word.substr(1)))
						return true;
					visited[ii][jj] = false;
				}
			}
		}
		return false;
	}


	int ch = word[0];
	if (i + 1 < m) {
		if (board[i+1][j] == ch && visited[i+1][j] == false) {
			visited[i+1][j] = true;
			if (exist(board, visited,  i+1, j, word.substr(1))) return true;
			visited[i+1][j] = false;
		}
	}
	if (i - 1 >= 0) {
		if (board[i-1][j] == ch && visited[i-1][j] == false) {
			visited[i-1][j] = true;
			if (exist(board, visited,  i-1, j, word.substr(1))) return true;
			visited[i-1][j] = false;
		}
	}

	if (j + 1 < n) {
		if (board[i][j+1] == ch && visited[i][j+1] == false) {
			visited[i][j+1] = true;
			if (exist(board, visited,  i, j+1, word.substr(1))) return true;
			visited[i][j+1] = false;
		}
	}

	if (j - 1 >= 0) {
		if (board[i][j-1] == ch && visited[i][j-1] == false) {
			visited[i][j-1] = true;
			if (exist(board, visited,  i, j-1, word.substr(1))) return true;
			visited[i][j-1] = false;
		}
	}

	return false;

}

bool exist(vector<vector<char> >& board, string word)
{
	int m = board.size();
	int n = board[0].size();
	vector<vector<bool> > visited(m, vector<bool>(n, false));
	return exist(board, visited,  -1, -1, word);
}

int main()
{
	vector<char> s;
	s.push_back('a');
	s.push_back('a');
	vector<vector<char> > board;
	board.push_back(s);

	cout << exist(board, "aaa");
	return 0;

}


