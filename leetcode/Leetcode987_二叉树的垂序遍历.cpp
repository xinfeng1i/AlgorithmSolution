#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
#include <string>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct Point {
    int val;
    int row;
    int col;
    Point(int _val, int _row, int _col) : val(_val), row(_row), col(_col) {}
};


void preorderTraversal(TreeNode* root, int row, int col, vector<Point>& v) {
    if (root == NULL) return;
    Point p = Point(root->val, row, col);
    v.push_back(p);

    preorderTraversal(root->left, row + 1, col - 1, v);
    preorderTraversal(root->right, row + 1, col + 1, v);
}

bool cmp(const Point& x, const Point& y) {
    if (x.col != y.col) {
        return x.col < y.col;
    }
    else if (x.row != y.row) {
        return x.row < y.row;
    }
    else {
        return x.val < y.val;
    }
}


vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<Point> v;
    preorderTraversal(root, 0, 0, v);

    sort(v.begin(), v.end(), cmp);

    vector<vector<int>> result;
    vector<int> thisCol;
    int prevColIndex = -1;
    bool isInit = false;
    for (size_t i = 0; i < v.size(); ++i) {
        Point p = v[i];
        if (!isInit) {
            prevColIndex = p.col;
            isInit = true;
        }

        if (p.col == prevColIndex) {
            thisCol.push_back(p.val);
        }
        else {
            result.push_back(thisCol);

            thisCol.clear();
            thisCol.push_back(p.val);
            prevColIndex = p.col;
        }
    }
    if (!thisCol.empty()) {
        result.push_back(thisCol);
    }

    return result;
}


int main() {
    // TreeNode* root = new TreeNode(3);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = verticalTraversal(root);
    cout << "result size: " << result.size() << endl;
    for (size_t i = 0; i < result.size(); ++i) {
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << " " << result[i][j];
        }
        cout << endl;
    }


    return 0;
}


