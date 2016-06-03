// Every Time remove one row or one column
// So the time complexity is O(m+n)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int n1 = (int) matrix.size();
    int n2 = (int) matrix[0].size();
    int row_s = 0; int row_e = n1 - 1;
    int col_s = 0; int col_e = n2 - 1;
    while (row_s <= row_e && col_s <= col_e) {
        if (matrix[row_e][col_s] == target) {
            return true;
        } else if (matrix[row_e][col_s] < target) {
            col_s++;
        } else if (matrix[row_e][col_s] > target) {
            row_e--;
        }
    }
    return false;
}
