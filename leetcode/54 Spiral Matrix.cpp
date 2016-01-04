#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix) {
    vector<int> result;
    if (matrix.size() == 0) return result;
    
    int m = matrix.size();
    int n = matrix[0].size();
    
    result.reserve(m * n);
    int rowMin = 0; int rowMax = m - 1;
    int colMin = 0; int colMax = n - 1;
    
    while (rowMin < rowMax && colMin < colMax) {        
        // first row
        for (int j = colMin; j <= colMax; ++j) {
            result.push_back(matrix[rowMin][j]);
        }
        // last col
        for (int i = rowMin + 1; i <= rowMax - 1; i++) {
            result.push_back(matrix[i][colMax]);
        }
        // last row
        for (int j = colMax; j >= colMin; --j) {
            result.push_back(matrix[rowMax][j]);
        }
        // first col
        for (int i = rowMax - 1; i >= rowMin + 1; --i) {
            result.push_back(matrix[i][colMin]);
        }
        rowMin += 1;
        rowMax -= 1;
        colMin += 1;
        colMax -= 1;
    }
    
    if (rowMin == rowMax && colMin == colMax) {
        result.push_back(matrix[rowMin][colMin]);
    } else if (rowMin == rowMax) {
        for (int j = colMin; j <= colMax; ++j) {
            result.push_back(matrix[rowMin][j]);
        }
    } else if (colMin == colMax) {
        for (int i = rowMin; i <= rowMax; ++i) {
            result.push_back(matrix[i][colMin]);
        }
    }
    return result;
}

void PrintMatrix(const vector<vector<int> >& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
}

void PrintVec(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int> > matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = i * n + j + 1;
        }
    }
    
    PrintMatrix(matrix);
    
    vector<int> ans = spiralOrder(matrix);
    cout << "after spiral: " << endl;
    PrintVec(ans);
    
    return 0;
}
