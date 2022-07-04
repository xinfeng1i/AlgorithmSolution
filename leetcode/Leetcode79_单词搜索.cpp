//
//  Leetcode79_单词搜索.cpp
//  HelloXcode
//
//  Created by xinfengli on 2022/7/4.
//

#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;


vector<pair<int, int>> getFirstCharCandidate(vector<vector<char>>& grid, string& word) {
    assert(!word.empty());
    
    int m = (int) grid.size();
    int n = (int) grid[0].size();
    vector<pair<int, int>> ans;
    char ch = word[0];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            char x = grid[i][j];
            if (x == ch) {
                ans.push_back(make_pair(i, j));
            }
        }
    }
    return ans;
}


void printGrid(const vector<vector<int>>& visited) {
    for (size_t i = 0; i < visited.size(); ++i) {
        for (size_t j = 0; j < visited[i].size(); ++j) {
            cout << " " << visited[i][j];
        }
        cout << endl;
    }
}


bool solveWordSearch(vector<vector<char>>& grid, vector<vector<int>>& visited, string& word, int startRow, int startCol, int idx) {
    int sz = (int) word.size();
    if (idx == sz - 1) {
        bool flag = grid[startRow][startCol] == word[idx];
        if (flag) {
            visited[startRow][startCol] = 1;
        }
        return flag;
    }
    
    char thisChar = word[idx];
    if (thisChar != grid[startRow][startCol]) return false;
    
    int m = (int) grid.size();
    int n = (int) grid[0].size();
    visited[startRow][startCol] = 1;
    vector<int> dx = { -1, 0, 1,  0 };
    vector<int> dy = { 0,  1, 0, -1 };
    for (int i = 0; i < 4; ++i) {
        int newRow = startRow + dx[i];
        int newCol = startCol + dy[i];
        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && visited[newRow][newCol] == 0) {
            bool ok = solveWordSearch(grid, visited, word, newRow, newCol, idx+1);
            if (ok) return true;
        }
    }
    
    visited[startRow][startCol] = 0;
    return false;
}


bool exist(vector<vector<char>>& board, string word) {
    int m = (int) board.size();
    int n = (int) board[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    
    vector<pair<int, int>> candPos = getFirstCharCandidate(board, word);
    for (pair<int, int> p: candPos) {
        bool ok = solveWordSearch(board, visited, word, p.first, p.second, 0);
        if (ok) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<char> v1 = { 'A','B','C','E' };
    vector<char> v2 = { 'S','F','C','S' };
    vector<char> v3 = { 'A','D','E','E' };
    vector<vector<char>> board;
    board.push_back(v1);
    board.push_back(v2);
    board.push_back(v3);
    
    
    //string word = "ABCCED";
    string word = "SEE";
    //string word = "ABCB";
    
//    vector<char> v1 = { 'A' };
//    vector<vector<char>> board;
//    board.push_back(v1);
//    string word = "A";
    
    bool ans = exist(board, word);
    cout << "ans: " << ans << endl;
    
    return 0;
}
