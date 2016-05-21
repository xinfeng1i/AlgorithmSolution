#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/**
 *@param A: A list of integers
 *@param elem: An integer
 *@return: The new length after remove
 */
int removeElement(vector<int> &A, int elem) {
    // write your code here
    if (A.empty()) return 0;

    int pos = -1;
    for (size_t i = 0; i < A.size(); ++i) {
        if (A[i] != elem) {
            pos += 1;
            A[pos] = A[i];
        }
    }

    return pos + 1;
}
