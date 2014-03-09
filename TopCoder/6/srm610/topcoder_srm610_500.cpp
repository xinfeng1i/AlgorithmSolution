#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

bool isAdjacentMatrix(vector<string> board)
{
    char first = board[0][0];
    string pattern(board[0].size(), first);
    for (int i = 0; i < pattern.size(); ++i)
    {
        if (i % 2 == 1)
        {
            pattern[i] = '1' - first + '0';
        }
    }

    string reversePattern(board[0].size(), '1' - first + '0');
    {
        for (int i = 0; i < reversePattern.size(); ++i)
        {
            if (i % 2 == 1)
            {
                reversePattern[i] = first;
            }
        }
    }

    int n = board.size();
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            if (board[i] != pattern)
            {
                return false;
            }
        }
        else
        {
            if (board[i] != reversePattern)
            {
                return false;
            }
        }
    }
    return true;
}

int MaxArea(vector<string> board)
{
    int max = 0;

    int rn = board.size();
    int cn = board[0].size();
    for (int i = 0; i < rn; ++i)
    {
        for (int j = 0; j < cn; ++j)
        {
            for (int rowLength = 1; rowLength <= rn - i; ++rowLength)
            {
                for (int colLength = 1; colLength <= cn - j; ++colLength)
                {
                    vector<string> subboard;
                    for (int k = i; k < i + rowLength; ++k)
                    {
                        subboard.push_back(board[k].substr(j, colLength));
                    }
                    if (isAdjacentMatrix(subboard) && rowLength * colLength > max)
                    {
                        max = rowLength * colLength;
                    }
                }
            }
        }
    }

    return max;
}
#if 1
int main()
{
    vector<string> test;
    int n;
    cin >> n;
    string tmp;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        test.push_back(tmp);
    }

    cout << "ans:" << MaxArea(test) << endl;
}
#endif //0