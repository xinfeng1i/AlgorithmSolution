//
//  Leetcode37_解数独.cpp
//  HelloXcode
//
//  Created by xinfengli on 2022/6/29.
//

#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

typedef vector<vector<char>> Grid;


bool isSafe(Grid& grid, int row, int col, int num) {
    int n = (int) grid.size();
    for (int j = 0; j < n; ++j) {
        if (j == col) continue;
        if (grid[row][j] != '.' && grid[row][j] - '0' == num) {
            return false;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (i == row) continue;
        if (grid[i][col] != '.' && grid[i][col] - '0' == num) {
            return false;
        }
    }
    
    int offsetRowBlock = row / 3;
    int offsetColBlock = col / 3;
    int startRow = offsetRowBlock * 3;
    int startCol = offsetColBlock * 3;
    for (int i = startRow; i < startRow + 3; ++i) {
        for (int j = startCol; j < startCol + 3; ++j) {
            if (i == row && j == col) continue;
            if (grid[i][j] != '.' && grid[i][j] - '0' == num) {
                return false;
            }
        }
    }
    
    return true;
}


void placeNum(Grid& grid, int row, int col, int num) {
    grid[row][col] = num + '0';
}

void resetNum(Grid& grid, int row, int col) {
    grid[row][col] = '.';
}

pair<int, int> getNextEmptyPos(const Grid& grid) {
    int n = (int) grid.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '.') {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

bool solveSudoku(Grid& grid, int row, int col) {
    // Base Case
    if (row == -1 && col == -1) return true;
    for (int num = 1; num <= 9; ++num) {
        if (isSafe(grid, row, col, num)) {
            // 1. try a choice
            placeNum(grid, row, col, num);
            pair<int, int> p = getNextEmptyPos(grid);
            // 2. check recursively whether it leading to solution
            bool ok = solveSudoku(grid, p.first, p.second);
            if (ok) {
                return true;
            } else {
                // 3. otherwise, reset and try another choice
                resetNum(grid, row, col);
            }
        }
    }
    // 4. if all choice then have not got a solution, return false to trigger backtracking.
    return false;
}

void printGrid(const vector<vector<char>>& grid) {
    int n = (int)grid.size();
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    char a1[9] = {'5','3','.','.','7','.','.','.','.'};
    char a2[9] = {'6','.','.','1','9','5','.','.','.'};
    char a3[9] = {'.','9','8','.','.','.','.','6','.'};
    char a4[9] = {'8','.','.','.','6','.','.','.','3'};
    char a5[9] = {'4','.','.','8','.','3','.','.','1'};
    char a6[9] = {'7','.','.','.','2','.','.','.','6'};
    char a7[9] = {'.','6','.','.','.','.','2','8','.'};
    char a8[9] = {'.','.','.','4','1','9','.','.','5'};
    char a9[9] = {'.','.','.','.','8','.','.','7','9'};
    
    vector<char> b1(a1, a1 + 9);
    vector<char> b2(a2, a2 + 9);
    vector<char> b3(a3, a3 + 9);
    vector<char> b4(a4, a4 + 9);
    vector<char> b5(a5, a5 + 9);
    vector<char> b6(a6, a6 + 9);
    vector<char> b7(a7, a7 + 9);
    vector<char> b8(a8, a8 + 9);
    vector<char> b9(a9, a9 + 9);
    
    vector<vector<char>> grid;
    grid.push_back(b1);
    grid.push_back(b2);
    grid.push_back(b3);
    grid.push_back(b4);
    grid.push_back(b5);
    grid.push_back(b6);
    grid.push_back(b7);
    grid.push_back(b8);
    grid.push_back(b9);
    
    cout << "before find:" << endl;
    printGrid(grid);
    
    pair<int, int> p = getNextEmptyPos(grid);
    bool ok = solveSudoku(grid, p.first, p.second);
    if (ok) {
        cout << "we found a solution" << endl;
        printGrid(grid);
    }
    
    return 0;
}
