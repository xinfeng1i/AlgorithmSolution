#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

#define VERSION1 0
#define VERSION2 0
#define VERSION3 0


#if VERSION1
/*****************************************************
 * VERSION1
 * brute force. Everything is Ok, but last sample TLE.
 *****************************************************/
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



#endif // VERSION1

/*********************************************************
 * VERSION2
 * Editorial: O(n^4) algorithm
 *********************************************************/
#if VERSION2
int MaxArea(vector<string> board)
{
    int ans = 0;
    int h = board.size();
    int w = board[0].size();
    // fix j1, j2 two columns
    for (int j1 = 0; j1 < w; ++j1)
    {
        for (int j2 = j1; j2 < w; ++j2)
        {
            // for each row, flag the row with 1, 0 , -1
            // 0 represent the 010101... row
            // 1 represent the 101010... row
            // -1 represent all the other patterns
            vector<int> flag(h, -1);
            for (int k = 0; k < h; ++k)
            {
                bool rowflag = true;
                for (int j = j1 + 1; j <= j2; ++j)
                {
                    if (board[k][j] == board[k][j-1])
                    {
                        rowflag = false;
                        break;
                    }
                }

                if (rowflag == true)
                {
                    flag[k] = board[k][j1] - '0';
                }                
            }

            // trick
            // find the max height between the alternative 0 or 1 rows
            int diff = -1, cur = 0;
            for (int i = 0; i < h; ++i)
            {
                if (flag[i] == -1)
                {
                    cur = 0;
                }
                else if (cur > 0 && flag[i] != flag[i-1])
                {
                    cur++;
                }
                else
                {
                    cur = 1;
                }
                diff = max(diff, cur);
            }
            
            // update ans
            ans = max(ans, diff * (j2 - j1 + 1));
        }
    }
    
    return ans;
}
#endif //VERSION2

/*******************************************************
 * VERSION3
 * Editorial O(n^3) algorithm
 *******************************************************/
int MaxArea(vector<string> board)
{
    int ans = 0;
    int h = board.size();
    int w = board[0].size();

    // fix j1, j2 column
    for (int j1 = 0; j1 < w; ++j1)
    {
        vector<int> flag(h, -1);
        for (int j2 = j1; j2 < w; ++j2)
        {
            // init, if there is only one column, init the flag[]
            if (j2 == j1)
            {
                for (int i = 0; i < h; ++i)
                {
                    flag[i] = board[i][j1];
                }
            }
            else
            {
                // when the j2 is expanding, update the flag[] depending
                // on whether the latter column is equal to the former column.
                for (int i = 0; i < h; ++i)
                {
                    if (board[i][j2] == board[i][j2-1])
                    {
                        flag[i] = -1;
                    }
                }
            }

            // this process is same with O(n^4) algorithm.
            int cur = 0; 
            int diff = 0;
            for (int k = 0; k < h; ++k)
            {
                if (flag[k] == -1)
                {
                    cur = 0;
                }
                else if (cur > 0 && flag[k] != flag[k-1])
                {
                    cur++;
                }
                else
                {
                    cur = 1;
                }
                diff = max(diff, cur);
            }

            // update the ans
            ans = max(ans, diff * (j2 - j1 + 1));
        }
    }

    return ans;
}


#if 0
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