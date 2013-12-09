#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int matrix[9][9];

void initMatrix()
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            matrix[i][j] = 0;
        }
    }

}

void printMatrix()
{
    cout << "matrix: " << endl;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// flood-fill algorithm
// This is my own way
// a more decent way is:
//*************************************************************
// if (matrix[x][y] == 1)   // base case
// {
//      return;
// }
//
// matrix[x][y] = 1;
// flood[][] // left
// flood[][] // right
// flood[][] // up
// flood[][] // down
// ************************************************************
void flood(int x, int y)
{
    matrix[x][y] = 1;
    // up
    if (x + 1 < 9 && y + 1 < 9 && matrix[x+1][y+1] == 0)
    {
        flood(x + 1, y + 1);
    }

    // down
    if (x - 1 > 0 && y - 1 > 0 && matrix[x-1][y-1] == 0)
    {
        flood(x - 1, y - 1);
    }

    // left
    if (x + 1 < 9 && y - 1 > 0 && matrix[x+1][y-1] == 0)
    {
        flood(x + 1, y - 1);
    }

    // right
    if  (x - 1 > 0 && y + 1 < 9 && matrix[x-1][y+1] == 0)
    {
        flood(x - 1, y + 1);
    }
}

int main()
{
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    // rook
    if (r1 == r2 || c1 == c2)
    {
        cout << 1 << " ";
    }
    else
    {
        cout << 2 << " ";
    }

    // bishop
    if (abs(c2 - c1) == abs(r2 - r1))
    {
        cout << 1 << " ";
    }
    else
    {
        initMatrix();
        flood(r1, c1);
        if (matrix[r2][c2] == 1)
        {
            cout << 2 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
        //printMatrix();
    }

    // king
    cout << max(abs(r1 - r2), abs(c1 - c2)) << endl;

    return 0;

}
