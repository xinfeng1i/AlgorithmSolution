#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void PrintMatrix(const vector<vector<int>>& A) {
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[i].size(); ++j) {
            cout << " " << A[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &A) {
        if (!A.empty()) {
            int m = (int) A.size();
            int n = (int) A[0].size();
            acc_matrix.resize(m);
            for (int i = 0; i < m; ++i) acc_matrix[i].resize(n, 0);
            
            // first row
            for (int j = 0; j < n; ++j) {
                if (j == 0) acc_matrix[0][j] = A[0][j];
                else acc_matrix[0][j] = acc_matrix[0][j-1] + A[0][j];
            }
            
            // first col
            for (int i = 1; i < m; ++i) {
                acc_matrix[i][0] = acc_matrix[i-1][0] + A[i][0];
            }
            
            // others
            for (int i = 1; i < m; ++i) {
                for (int j = 1; j < n; ++j) {
                    acc_matrix[i][j] = acc_matrix[i-1][j] + acc_matrix[i][j-1] - acc_matrix[i-1][j-1] + A[i][j];
                }
            }
        }
    }
    

    int sumRegion(int i1, int j1, int i2, int j2) {
        int temp1 =  acc_matrix[i2][j2];
        int temp2 = (i1-1 >= 0 ? acc_matrix[i1-1][j2] : 0);
        int temp3 = (j1-1 >= 0 ? acc_matrix[i2][j1-1] : 0);
        int temp4 = ((i1-1 >= 0 && j1-1 >= 0) ? acc_matrix[i1-1][j1-1] : 0);
        return temp1-temp2-temp3+temp4;
    }
private:
    vector<vector<int>> acc_matrix;
};



int main()
{
    vector<int> v1 = {3, 0, 1, 4, 2};
    vector<int> v2 = {5, 6, 3, 2, 1};
    vector<int> v3 = {1, 2, 0, 1, 5};
    vector<int> v4 = {4, 1, 0, 1, 7};
    vector<int> v5 = {1, 0, 3, 0, 5};
    vector<vector<int>> m;
    m.push_back(v1);
    m.push_back(v2);
    m.push_back(v3);
    m.push_back(v4);
    m.push_back(v5);
    
    NumMatrix numMatrix(m);
    int an1 = numMatrix.sumRegion(2, 1, 4, 3);
    int an2 = numMatrix.sumRegion(1, 1, 2, 2);
    int an3 = numMatrix.sumRegion(1, 2, 2, 4);
    
    cout << an1 << endl;
    cout << an2 << endl;
    cout << an3 << endl;
    
    return 0;
    
}
