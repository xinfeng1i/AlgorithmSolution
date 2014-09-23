/*
 * Backtracking 回溯是一种通用的算法思想，它尝试所有可能的solution，直到
 * 找到一个solution.
 *
 * 适用于回溯算法的问题一般有如下特征：
 * 该问题可以通过遍历所有可能的configuration来解决，Naive的算法通过尝试
 * 所有的configuration判断是否满足条件，从而解决问题.
 * 回溯的算法则通过一种增量的方式来尝试不同的configuration，一般来说
 * 我们通过一个空的solution，每一次添加一个item(item的意义随问题的不同
 * 而不同）. 当我们增加一个item的时候，我们判断增加的item是否破坏了问题
 * 的约束条件？ 如果是，如果是我们remove这个item，换另一个item增加。
 * 如果不是，我们递归的增加items one byone，直到我们找到solution，或者
 * 返回找不到.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 8;
int dx[N] = {2, 1, -2, -1, -2, -1,  2,  1};
int dy[N] = {1, 2,  1,  2, -1, -2, -1, -2};

void PrintSolution(int sol[N][N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


bool isSafe(int x, int y, int sol[N][N])
{
    if (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1)
    {
        return true; 
    }
    
    return false;
}

// 当前在curx, cury位置，下一步步数是curCnt, 能够lead to a solution
bool solveUtil(int curx, int cury, int curCnt, int sol[N][N])
{
    if (curCnt == N * N)
    {
        return true;
    }

    for (int i = 0; i < N; ++i)
    {
        // 尝试增加一步
        int nextx = curx + dx[i];
        int nexty = cury + dy[i];

        if (isSafe(nextx, nexty, sol))
        {
            //如果尝试是安全的，赋值
            sol[nextx][nexty] = curCnt;

            if (solveUtil(nextx, nexty, curCnt+1, sol))
            {
                return true;
            }

            // 回溯
            sol[nextx][nexty] = -1;
        }
    }

    return false;
}

bool SolveKT()
{
    int sol[N][N];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            sol[i][j] = -1;
        }
    }

    sol[0][0] = 0;
    if (solveUtil(0, 0, 1, sol))
    {
        PrintSolution(sol);
        return false;
    }
    else
    {
        cout << "Solution does not exist" << endl;
    }

    return true;
}

int main()
{
    SolveKT();
    cout << "hello" << endl;
    return 0;
}
