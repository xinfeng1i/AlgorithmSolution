#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
* @param n, m: positive integer (1 <= n ,m <= 100)
* @return an integer
*/
int uniquePaths(int m, int n) {
    vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
    for (size_t j = 1; j <= n; ++j) table[1][j] = 1;
    for (size_t i = 1; i <= m; ++i) table[i][1] = 1;
    for (size_t i = 2; i <= m; ++i) {
        for (size_t j = 2; j <= n; ++j) {
            table[i][j] = table[i - 1][j] + table[i][j - 1];
        }
    }
    return table[m][n];
}