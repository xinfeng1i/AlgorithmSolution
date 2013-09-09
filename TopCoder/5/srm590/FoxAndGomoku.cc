#include <iostream>
#include <string>
#include <vector>
using namespace std;
class FoxAndGomoku
{
public:
string win(vector<string> board)
{
    int n = board.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j + 4 < n && board[i][j] == 'o'
                          && board[i][j+1] == 'o'
                          && board[i][j+2] == 'o'
                          && board[i][j+3] == 'o'
                          && board[i][j+4] == 'o')
            {
                return "found";
            }

            if (i + 4 < n && board[i][j] == 'o'
                          && board[i+1][j] == 'o'
                          && board[i+2][j] == 'o'
                          && board[i+3][j] == 'o'
                          && board[i+4][j] == 'o')
            {
                return "found";
            }

            if (i + 4 < n && j + 4 < n
                && board[i][j] == 'o'
                && board[i+1][j+1] == 'o'
                && board[i+2][j+2] == 'o'
                && board[i+3][j+3] == 'o'
                && board[i+4][j+4] == 'o')
            {
                return "found";
            }

            if (i + 4 < n && j - 4 >= 0
                && board[i][j] == 'o'
                && board[i+1][j-1] == 'o'
                && board[i+2][j-2] == 'o'
                && board[i+3][j-3] == 'o'
                && board[i+4][j-4] == 'o')
            {
                return "found";
            }
        }
    }
    return "not found";
}
};
