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

const vector<int> dx = { -1, 0, 1,  0 };
const vector<int> dy = { 0,  1, 0, -1 };

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

/**
 *  检查从(i,j)开始是否可以搜索到word[idx...n]单词
 *  假设单词的长度为L，则时间复杂度为：
 *  时间复杂度：O((4^L)/3)
 */
bool solveWordSearch(vector<vector<char>>& grid, vector<vector<int>>& visited, string& word, int i, int j, int idx) {
    int sz = (int) word.size();
    if (idx == sz - 1) {
        return grid[i][j] == word[idx];
    }
    
    if (word[idx] != grid[i][j]) return false;
    
    int m = (int) grid.size();
    int n = (int) grid[0].size();
    visited[i][j] = 1;
    for (int d = 0; d < 4; ++d) {
        int newRow = i + dx[d];
        int newCol = j + dy[d];
        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && visited[newRow][newCol] == 0) {
            bool ok = solveWordSearch(grid, visited, word, newRow, newCol, idx+1);
            if (ok) return true;
        }
    }
    visited[i][j] = 0;
    return false;
}

/**
 * 由于每个grid都要执行一次search操作，因此总时间复杂度为：O(MN*4^L)
 * 其中M为grid的行数，N为grid的列数，L为待搜索单词的长度.
 */
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
