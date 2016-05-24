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
#include <assert.h>
using namespace std;

// Ì°ÐÄËã·¨£ºµÍÂò¸ßÂô
int maxProfit(vector<int>& A) {
    int n = (int) A.size();
    int i = 0; int j = 0;
    int sum = 0;
    while (i < n) {
        j = i + 1;
        while (j < n && A[j] >= A[j-1]) j++;
        sum += A[j-1] - A[i];
        i = j;
    }
    return sum;  
}