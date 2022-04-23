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
using namespace std;

struct Node {
    int x;
    int y;
    int height;

    Node(int _x, int _y, int _h) : x(_x), y(_y), height(_h) {};
    bool operator<(const Node& other) const {
        if (height != other.height) {
            return height > other.height;
        }
        else if (x != other.x) {
            return x > other.x;
        }
        else {
            return y > other.y;
        }
    }
};

void printMat(const vector<vector<bool>>& mat) {
    for (size_t i = 0; i < mat.size(); ++i) {
        for (size_t j = 0; j < mat[i].size(); ++j) {
            cout << " " << mat[i][j];
        }
        cout << endl;
    }
}

// Method:
//   start from the 4 board edge with min value first, using priority queue
//   time: O(mn*log(mn)), pop from priority cost O(log(mn)) time.
//   space: O(m * n)
int trapRainWater(vector<vector<int>>& mat) {
    if (mat.empty()) return 0;
    if (mat.size() <= 2) return 0;
    int m = (int) mat.size();
    int n = (int) mat[0].size();

    priority_queue<Node, vector<Node>> Q;
    vector<vector<bool>> visited;
    for (int i = 0; i < m; ++i) {
        vector<bool> temp = vector<bool>(n, false);
        visited.push_back(temp);
    }

    for (int j = 0; j < n; ++j) {
        // first row
        Node node1 = Node(0, j, mat[0][j]);
        Q.push(node1);
        visited[0][j] = true;

        // last row
        Node node2 = Node(m - 1, j, mat[m - 1][j]);
        Q.push(node2);
        visited[m - 1][j] = true;
    }

    for (int i = 1; i < m - 1; ++i) {
        Node node1 = Node(i, 0, mat[i][0]);
        Q.push(node1);
        visited[i][0] = true;

        Node node2 = Node(i, n - 1, mat[i][n - 1]);
        Q.push(node2);
        visited[i][n - 1] = true;
    }

    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {-1, 0, 1, 0};

    int ans = 0;
    while (!Q.empty()) {
        Node cur = Q.top(); Q.pop();
        for (int k = 0; k < 4; ++k) {
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];
            if (next_x >= 0
                && next_x < m
                && next_y >= 0
                && next_y < n
                && !visited[next_x][next_y]) {
                if (mat[next_x][next_y] < cur.height) {
                    ans += cur.height - mat[next_x][next_y];
                    mat[next_x][next_y] = cur.height;
                }
                Node next_node = Node(next_x, next_y, mat[next_x][next_y]);
                visited[next_x][next_y] = true;
                Q.push(next_node);
            }
        }
    }

    return ans;
}

#if 0
int main() {
    vector<int> a1 = { 1,4,3,1,3,2 };
    vector<int> a2 = { 3,2,1,3,2,4 };
    vector<int> a3 = { 2,3,3,2,3,1 };
    vector<vector<int>> mat1;
    mat1.push_back(a1);
    mat1.push_back(a2);
    mat1.push_back(a3);

    cout << trapRainWater(mat1) << endl;

    vector<int> b1 = { 3,3,3,3,3 };
    vector<int> b2 = { 3,2,2,2,3 };
    vector<int> b3 = { 3,2,1,2,3 };
    vector<int> b4 = { 3,2,2,2,3 };
    vector<int> b5 = { 3,3,3,3,3 };
    vector<vector<int>> mat2;
    mat2.push_back(b1);
    mat2.push_back(b2);
    mat2.push_back(b3);
    mat2.push_back(b4);
    mat2.push_back(b5);

    cout << trapRainWater(mat2) << endl;

    return 0;
}
#endif // 0

