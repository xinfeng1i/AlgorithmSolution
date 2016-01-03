#include <iostream>
#include <string>
#include <vector>
using namespace std;

void rotate(vector<vector<int> >& matrix) {
	int n = matrix.size();
    int ymin = 0;
    int ymax = n - 1;
    int xmin = 0;
    int xmax = n - 1;
    
    while (xmin < xmax) {
        int x = xmin;
        for (int y = ymin; y < ymax; y++) {
            int first = matrix[x][y];
            int second = matrix[y][-x+n-1];
            int third = matrix[-x+n-1][-y+n-1];
            int four = matrix[-y+n-1][x];

            matrix[x][y] = four;
            matrix[y][-x+n-1] = first;
            matrix[-x+n-1][-y+n-1] = second;
            matrix[-y+n-1][x] = third;
        }
        xmin += 1;
        xmax -= 1;
        ymin += 1;
        ymax -= 1;
    }
}

void PrintMatrix(const vector<vector<int> > & matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = n * i + j + 1;
        }
    }
    
    PrintMatrix(matrix);
    
    rotate(matrix);
    
    cout << "after rotation : " << endl;
    PrintMatrix(matrix);
    return 0;
}
