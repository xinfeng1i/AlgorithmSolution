#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

void PrintMatrix(const vector<vector<int> >& matrix)
{
    size_t i, j;
    for (i = 0; i < matrix.size(); ++i) {
        for (j = 0; j < matrix[i].size(); ++j) {
            if (j == 0) cout << matrix[i][j];
            else cout << " " << matrix[i][j];
        }
        cout << endl;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int N, m, n, i;
    cin >> N;
    vector<int> v(N, 0);
    for (i = 0; i < N; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    // calculate m, n such that m * n == N && m >= n && m - n minimum
    int mid = (int)sqrt(double(N));
    int j;
    m = N; n = 1;
    int diff = m - n;
    for (j = N; j >= mid; j--) {
        if (N % j == 0) {
            i = N / j;
            if (j >= i && j - i < diff) {
                diff = j - i;
                m = j;
                n = i;
            }

        }
    }
    
    // fill the matrix with spiral order
    vector<vector<int> > matrix(m, vector<int>(n, 0));
    int idx = 0;
    int left = 0; int right = n - 1;
    int upper = 0; int down = m - 1;
    while (idx < N) {
        // first row
        for (j = left; j <= right; ++j) matrix[upper][j] = v[idx++];
        // last column
        for (i = upper + 1; i <= down; ++i) matrix[i][right] = v[idx++];

        if (upper < down) {
            // last row
            for (j = right - 1; j >= left; --j) matrix[down][j] = v[idx++];
        }

        if (left < right) {
            // first column
            for (i = down - 1; i >= upper + 1; --i) matrix[i][left] = v[idx++];
        }

        left += 1; right -= 1;
        upper += 1; down -= 1;
    }

    PrintMatrix(matrix);

    return 0;
}
