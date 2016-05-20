#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;

// 贪心算法：如果从A不能到达B，则从(A,B)之间的任何位置也必然不能到达B
// 从而能够跳跃式跃进，将O(N^2)的算法降低为O(N)的算法
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    if (gas.empty() || cost.empty()) return -1;
        
    int n = gas.size();
    vector<int> diff(n, 0);
    for (int i = 0; i < n; ++i) diff[i] = gas[i] - cost[i];
        
    for (int start = 0; start < n; ) {
        if (diff[start] < 0) {
            start++;
        } else {
            int r = diff[start];
            int j = (start + 1) % n;
            while (j != start && r + diff[j] >= 0 ) {
                r += diff[j];
                j = (j+1) % n;
            }
                
            if (j == start) {
                return start;
            } else {
                start = (j < start ? n : j); // 如果下一个位置在start前面，由于已经判断过不行，所以直接令start=n，否则start < j,则start = j;
            }
                
        }
    }
    return -1;      
}