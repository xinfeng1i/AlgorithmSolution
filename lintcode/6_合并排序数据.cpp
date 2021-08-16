//
//  6_合并排序数据.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/8/16.
//

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;


/*
 * Classical Merge:
 *
 * Time: O(m+n)
 * Space: O(1)
 */
vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
    if(A.empty()) {
        vector<int> result(B.begin(), B.end());
        return result;
    }
    
    if (B.empty()) {
        vector<int> result(A.begin(), A.end());
        return result;
    }
    
    int m = (int) A.size();
    int n = (int) B.size();
    vector<int> result;
    
    int i = 0;
    int j = 0;
    while (i < m && j < n) {
        if (A[i] <= B[j]) {
            result.push_back(A[i]);
            i++;
        } else {
            result.push_back(B[j]);
            j++;
        }
    }
    
    while (i < m) {
        result.push_back(A[i]);
        i++;
    }
    
    while (j < n) {
        result.push_back(B[j]);
        j++;
    }
    
    return result;
}


void printVec(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}


#if 0
int main() {
    vector<int> a;
    a.push_back(3);
    a.push_back(5);
    a.push_back(7);
    
    vector<int> b;
    b.push_back(2);
    b.push_back(8);
    b.push_back(9);
    b.push_back(13);
    
    vector<int> v = mergeSortedArray(a, b);
    printVec(v);
    
    return 0;
}
#endif // 0
