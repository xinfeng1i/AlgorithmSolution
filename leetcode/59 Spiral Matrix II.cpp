#include <iostream>
#include <string>
#include <vector>
using namespace std;

void PrintMatrix(const vector<vector<int> >& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
}

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > ans;
    if (n <= 0) return ans;
    
    ans.resize(n);
    for (int i = 0; i < n; ++i) ans[i].resize(n, 0);
    
    int rowMin = 0; int rowMax = n - 1;
    int colMin = 0; int colMax = n - 1;
    int num = 1;
    while (rowMin < rowMax && colMin < colMax) {
        for (int j = colMin; j < colMax; ++j) {
            ans[rowMin][j] = num++;
        }
        
        for (int i = rowMin; i < rowMax; ++i) {
            ans[i][colMax] = num++;
        }
        
        for (int j = colMax; j > colMin; --j) {
            ans[rowMax][j] = num++;
        }
        
        for (int i = rowMax; i > rowMin; --i) {
            ans[i][colMin] = num++;
        }
        
        rowMin++;
        rowMax--;
        colMin++;
        colMax--;
    }
    
    if (rowMin == rowMax && colMin == colMax) {
        ans[rowMin][colMin] = num++;
    } else if (rowMin == rowMax) {
        for (int j = colMin; j <= colMax; ++j) {
            ans[rowMin][j] = num++;
        }
    } else if (colMin == colMax) {
        for (int i = rowMin; i <= rowMax; ++i) {
            ans[i][colMin] = num++;
        }
    }
     
    return ans;
} 




int main()
{
    int n;
    cin >> n;
    vector<vector<int> > matrix;
    matrix = generateMatrix(n);
    
    cout << "after spiral: " << endl;
    PrintMatrix(matrix);
    
    return 0;
}
