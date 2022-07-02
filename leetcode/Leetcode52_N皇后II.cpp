//
//  Leetcode52_N皇后II.cpp
//  HelloXcode
//
//  Created by xinfengli on 2022/7/2.
//

#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <typeinfo>
#include <algorithm>
using namespace std;


bool isSafeGrid(const vector<string>& grid, int row, int col) {
    int n = (int)grid.size();
    
    // check row
    for (int j = 0; j < col; ++j) {
        if (grid[row][j] == 'Q') {
            return false;
        }
    }
    
    // check col
    for (int i = 0; i < n; ++i) {
        if (i != row) {
            if(grid[i][col] == 'Q') {
                return false;
            }
        }
    }
    
    // check y=x
    for (int d = -n; d <= n; ++d) {
        if (d != 0) {
            int newRow = row + d;
            int newCol = col + d;
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 'Q') {
                return false;
            }
        }
    }
    
    // check y = -x
    for (int d = -n; d <= n; ++d) {
        if (d != 0) {
            int dx = d;
            int dy = -d;
            int newRow = row + dx;
            int newCol = col + dy;
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 'Q') {
                return false;
            }
        }
    }
    
    return true;
}


void solveNQueen(vector<string>& grid, int col, int n, int& globalAns) {
    if (col == n) {
        globalAns++;
        return;
    }
    
    for (int i = 0; i < n; ++i) {
        if (isSafeGrid(grid, i, col)) {
            grid[i][col] = 'Q';
            solveNQueen(grid, col + 1, n, globalAns);
            grid[i][col] = '.';
        }
    }
}


int totalNQueens(int n) {
    vector<string> grid;
    string temp(n, '.');
    for (int i = 0; i < n; ++i) {
        grid.push_back(temp);
    }
    
    int ans = 0;
    solveNQueen(grid, 0, n, ans);
    
    return ans;
}



int main() {
    int ans = totalNQueens(4);
    cout << "ans: " << ans << endl;
    
    return 0;
}
