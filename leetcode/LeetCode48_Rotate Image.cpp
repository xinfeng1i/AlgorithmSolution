#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

void rotate(vector<vector<int>>& mat) {
    int n = (int)mat.size();
    int start = 0;
    int end = n - 1;
    while (start < end) {
        for (int j = start; j < end; ++j) {
            int original = mat[start][j];
            int originalRow = start;
            int originalCol = j;
            for (int cnt = 0; cnt < 4; ++cnt) {
                int nextRow = originalCol;
                int nextCol = n - 1 - originalRow;
                int temp = mat[nextRow][nextCol];
                mat[nextRow][nextCol] = original;

                originalRow = nextRow;
                originalCol = nextCol;
                original = temp;
            }
        }
        start++;
        end--;
    }
    return;
}

vector<vector<int>> buildMat3() {
    vector<int> v1 = { 1,2,3 };
    vector<int> v2 = { 4,5,6 };
    vector<int> v3 = { 7,8,9 };

    vector<vector<int>> mat;
    mat.push_back(v1);
    mat.push_back(v2);
    mat.push_back(v3);

    return mat;
}


vector<vector<int>> buildMat4() {
    vector<int> v1 = { 1,2,3,4 };
    vector<int> v2 = { 5,6,7,8 };
    vector<int> v3 = { 9,10,11,12 };
    vector<int> v4 = { 13,14,15,16 };

    vector<vector<int>> mat;
    mat.push_back(v1);
    mat.push_back(v2);
    mat.push_back(v3);
    mat.push_back(v4);

    return mat;
}


vector<vector<int>> buildMat5() {
    vector<int> v1 = { 1,2,3,4,5 };
    vector<int> v2 = { 6,7,8,9,10 };
    vector<int> v3 = { 11,12,13,14,15 };
    vector<int> v4 = { 16,17,18,19,20 };
    vector<int> v5 = { 21,22,23,24,25 };

    vector<vector<int>> mat;
    mat.push_back(v1);
    mat.push_back(v2);
    mat.push_back(v3);
    mat.push_back(v4);
    mat.push_back(v5);

    return mat;
}

void printMat(vector<vector<int>> mat) {
    int n = mat.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << " " << mat[i][j];
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> mat3 = buildMat5();
    printMat(mat3);

    cout << "after rotate:" << endl;
    rotate(mat3);
    printMat(mat3);

    return 0;
}
