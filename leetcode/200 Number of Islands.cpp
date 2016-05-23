#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <assert.h>
using namespace std;

void flood(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
    visited[i][j] = true;
    int n1 = grid.size();
    int n2 = grid[0].size();
    if (i-1>=0 && grid[i-1][j] == '1' && !visited[i-1][j]) flood(grid, visited, i-1, j);
    if (i+1<n1 && grid[i+1][j] == '1' && !visited[i+1][j]) flood(grid, visited, i+1, j);
    if (j-1>=0 && grid[i][j-1] == '1' && !visited[i][j-1]) flood(grid, visited, i, j-1);
    if (j+1<n2 && grid[i][j+1] == '1' && !visited[i][j+1]) flood(grid, visited, i, j+1);
        
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    if (grid[0].empty()) return 0;
        
    int n1 = (int)grid.size();
    int n2 = (int)grid[0].size();
        
    vector<vector<bool>> visited(n1, vector<bool>(n2, false));
        
    int cnt = 0;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                flood(grid, visited, i, j);
                cnt++;
            }
        }
    }
        
    return cnt;
}