#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;


void printMat(const vector<vector<int>>& mat) {
    for (size_t i = 0; i < mat.size(); ++i) {
        cout << "row i = " << i << endl;
        for (size_t j = 0; j < mat[i].size(); ++j) {
            cout << "  " << mat[i][j];
        }
        cout << endl;
    }
}


vector<int> findOrder(int n, vector<vector<int>> prev) {
    vector<int> ans;
    
    // statistic the indegree of all the nodes
    vector<int> indegree(n, 0);
    
    // find all the after nodes from prev nodes
    vector<vector<int>> after(n);
    for (int i = 0; i < n; ++i) {
        vector<int> temp;
        after.push_back(temp);
    }
    for (size_t i = 0; i < prev.size(); ++i) {
        int a = prev[i][0];
        int b = prev[i][1];
        after[b].push_back(a);
        indegree[a] += 1;
    }
    
    // all the nodes with indegree=0 can be output directly.
    queue<int> Q;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            Q.push(i);
            visited[i] = true;
        }
    }
    
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        ans.push_back(u);
        for (size_t i = 0; i < after[u].size(); ++i) {
            int v = after[u][i];
            indegree[v]--;
            if (!visited[v] && indegree[v] == 0) {
                Q.push(v);
                visited[v] = true;
            }
        }
    }
    
    // find loop, if the output elements is less than the course num.
    if ((int) ans.size() < n) {
        ans.clear();
    }
    
    return ans;
}



int main() {
    // example 1
    int n1 = 2;
    vector<vector<int>> mat1;
    vector<int> a1 = { 1, 0 };
    mat1.push_back(a1);
    
    // example 2
    vector<vector<int>> mat2;
    vector<int> b1 = {1, 0};
    vector<int> b2 = {2, 0};
    vector<int> b3 = {3, 1};
    vector<int> b4 = {3, 2};
    mat2.push_back(b1);
    mat2.push_back(b2);
    mat2.push_back(b3);
    mat2.push_back(b4);
    
    // example 3
    vector<vector<int>> mat3;
    
    // example 4
    vector<int> d1 = { 1, 0 };
    vector<int> d2 = { 1, 2 };
    vector<int> d3 = { 0, 1 };
    vector<vector<int>> mat4;
    mat4.push_back(d1);
    mat4.push_back(d2);
    mat4.push_back(d3);
    
    vector<int> ans = findOrder(3, mat4);
    for (int x: ans) {
        cout <<  " " << x;
    }
    cout << endl;
    
    return 0;
}
