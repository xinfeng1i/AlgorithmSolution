#include <iostream>
#include <string>
#include <cstring>
#include <tuple>
#include <algorithm>
#include <vector>
using namespace std;

class FoxAndGo{
private:
	vector<string> board;
	int n;
	bool visited[50][50];
public:
void dfs(int x, int y)
{
    if (!visited[x][y])
    {
        visited[x][y] = true;
        int dx = 1;
        int dy = 0;
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (board[nx][ny] == 'o')
                {
                    dfs(nx, ny);
                }
            }

            tie(dx, dy) = make_tuple(dy, -dx);
        }
    }
}

int scoreit()
{
    memset(visited, 0, sizeof(visited));
    int score = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == '.')
            {
                dfs(i, j);
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!visited[i][j] && board[i][j] == 'o')
            {
                score++;
            }
        }
    }

    return score;

}

int maxKill(vector<string> board__)
{
    n = board__.size();
    board = board__;
    int max_score = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == '.')
            {
                board[i][j] = 'x';
                max_score = max(scoreit(), max_score);
                board[i][j] = '.';
            }
        }
    }
    return max_score;
}
};

// After Reading the solution, rewrite the code
// need more efforts on graphs
