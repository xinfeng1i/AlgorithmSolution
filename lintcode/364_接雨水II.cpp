//
//  364_接雨水II.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/9/16.
//

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

/* 定义 Item 结构类型 */
struct Item {
    int _i;
    int _j;
    int _height;
    
    Item(int i, int j, int height) {
        _i = i;
        _j = j;
        _height = height;
    }
};

/* 定义 Item 比较函数对象，注意 priority_queue 默认为大根堆（对应于小于运算符) */
struct CmpItem {
    bool operator()(const Item& lhs, const Item& rhs) const {
        return lhs._height > rhs._height;
    }
};

/* 判断给定的位置坐标 (i, j) 是否在合法边界内 */
inline bool isValid(int i, int j, int m, int n) {
    return i >= 0 && i < m && j >= 0 && j < n;
}

/*
 * 小根堆算法解决二维接雨水问题 （参考了其他人的答案）
 *
 * 基本思想：从四周开始建立小根堆，取出堆中最小的元素 top，比较其上下左右的四个邻居元素
 * 如果比 top 小，则可以接雨水，且接雨水后与 top 高度相同；否则，不能接雨水
 *
 * 直观可视化理解算法：https://www.youtube.com/watch?v=cJayBq38VYw
 *
 * 时间复杂度：m * n * log(m*n)
 * 空间复杂度：O(m * n)
 */
int trapRainWater(vector<vector<int>> &v) {
    if (v.size() <= 1) return 0;
    if (v[0].size() <= 1) return 0;
    
    int ans = 0;
    
    int m = (int) v.size();
    int n = (int) v[0].size();
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    // init
    vector<vector<int>> visited;
    for (int i = 0; i < m; ++i) {
        vector<int> tmp(n, 0);
        visited.push_back(tmp);
    }
    
    // init min_heap with four side elements
    priority_queue<Item, vector<Item>, CmpItem> q;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                Item item(i, j, v[i][j]);
                q.push(item);
                visited[i][j] = 1;
            }
        }
    }
    
    while (!q.empty()) {
        Item cur = q.top(); // O(1)
        q.pop(); // O(logN)
        
        for (int k = 0; k < 4; ++k) {
            int newI = cur._i + dx[k];
            int newJ = cur._j + dy[k];
            if (isValid(newI, newJ, m, n) && !visited[newI][newJ]) {
                if (v[newI][newJ] < cur._height) {
                    ans += cur._height - v[newI][newJ];
                    visited[newI][newJ] = 1;
                    q.push(Item(newI, newJ, cur._height));  // O(logN)
                } else {
                    visited[newI][newJ] = 1;
                    q.push(Item(newI, newJ, v[newI][newJ]));
                }
            }
        }
    }
    
    return ans;
}



#if 1
int main() {
    vector<int> row1 = {12,13,0,12};
    vector<int> row2 = {13,4,13,12};
    vector<int> row3 = {13,8,10,12};
    vector<int> row4 = {12,13,12,12};
    vector<int> row5 = {13,13,13,13};
    
//    vector<int> row1 = {2,2,2,2};
//    vector<int> row2 = {2,2,3,4};
//    vector<int> row3 = {3,3,3,1};
//    vector<int> row4 = {2,3,4,5};
    
    vector<vector<int>> heights;
    heights.push_back(row1);
    heights.push_back(row2);
    heights.push_back(row3);
    heights.push_back(row4);
    heights.push_back(row5);
    
    int result = trapRainWater(heights);  // expected: 14
    
    printf("water: %d\n", result);
    return 0;
}
#endif // 0
