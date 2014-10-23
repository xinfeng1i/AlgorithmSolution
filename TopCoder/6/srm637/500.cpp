#include <iostream>
#include <string>
#include <vector>
using namespace std;


int calc(vector<string> board)
{
	int n = board[0].size();
	int cnt1 = 200;
	int cnt2 = 200;

	if (board[0][0] == '.')
	{
		int j = 0;
		int i = 0;
		int cnt = 1;
		while (j < n-1)
		{
			if (board[i][j+1] == '.')
			{
				cnt++;
				j++;			
			}
			else if (board[1-i][j] == '.')
			{
				cnt++;
				i = 1 - i;
			}
			else if (board[1-i][j] == '#')
			{
				break;	
			}
		}

		if (j >= n-1)	 cnt1 = cnt;
	}


	if (board[1][0] == '.')
	{
		int j = 0;
		int i = 1;
		int cnt = 1;
		while (j < n-1)
		{
			if (board[i][j+1] == '.')
			{
				cnt++;
				j++;			
				//cout << "j :" << j << endl;
			}
			else
			{
				if (board[1-i][j] == '.')
				{
					cnt++;
					i = 1 - i;
					//cout  << "i:" << i << endl;
				}
				else if (board[1-i][j] == '#')
				{
					cout << "break" << endl;
					break;	
				}
			}
		}

		if (j >= n-1)	 cnt2 = cnt;
	}


	int cntsharp = 0;
	for (int i = 0; i < n; ++i)
	{
		if (board[0][i] == '#') cntsharp++;
		if (board[1][i] == '#') cntsharp++;
	}

	if (cnt1 != 200 && cnt2 != 200)
	{
		return 2 * n - cntsharp - min(cnt1, cnt2);
	}
	else if (cnt1 != 200)
	{
		return 2 * n - cntsharp - cnt1;
	}
	else if (cnt2 != 200)
	{
		return 2 * n - cntsharp - cnt2;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int n = 5;
	vector<string> board(2);
	cin >> board[0];
	cin >> board[1];
	int ans = calc(board);
	cout << ans << endl;
}
