#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution
{
public:
	bool isValidSudoku(vector<vector<char> >& board)
	{
		int n = board.size();
		// check each row
		for (int i = 0; i < n; ++i)
		{
			deque<bool> visited(10, false);
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] >= '1' && board[i][j] <= '9')
				{
					if (visited[board[i][j]-'0'] == true) return false;
					else visited[board[i][j]-'0'] = true;
				}
				else if (board[i][j] == '.')
				{
					continue;	
				}
				else
				{
					return false;
				}
			}
		}
		// check each col
		for (int j = 0; j < n; ++j)
		{
			deque<bool> visited(10, false);
			for (int i = 0; i < n; ++i)
			{
				if (board[i][j] >= '1' && board[i][j] <= '9')
				{
					if (visited[ board[i][j] - '0'] == true) return false;
					else visited[ board[i][j] - '0'] = true;
				}
				else if (board[i][j] == '.')
				{
					continue;	
				}
				else
				{
					return false;
				}
			}
		}
		// check each 3 x 3 grid
		for (int i = 0; i < n; i += 3)
		{
			for (int j = 0; j < n; j += 3)
			{
				vector<char> temp;
				temp.push_back(board[i][j]);
				temp.push_back(board[i][j+1]);
				temp.push_back(board[i][j+2]);
				temp.push_back(board[i+1][j]);
				temp.push_back(board[i+1][j+1]);
				temp.push_back(board[i+1][j+2]);
				temp.push_back(board[i+2][j]);
				temp.push_back(board[i+2][j+1]);
				temp.push_back(board[i+2][j+2]);
				deque<bool> visited(10, false);
				for (size_t k = 0; k < temp.size(); k++)
				{//NOTE: use temp.size() to avoid checking size
					char ch = temp[k];
					if (ch >= '1' && ch <= '9')
					{
						if (visited[ch-'0'] == false) visited[ch-'0'] = true;
						else return false;
					}
					else if (ch == '.')
					{
						continue;
					}
					else
					{
						return false;
					}
				}
			}
		}

		return true;
	}
};

