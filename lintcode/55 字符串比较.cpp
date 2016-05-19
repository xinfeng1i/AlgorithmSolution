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
#include <string.h>
using namespace std;

bool compareStrings(string A, string B) {
    // write your code here
    unordered_map<int, int> tb;
    for (size_t i = 0; i < A.size(); ++i) {
        if (tb.find(A[i]) == tb.end()) {
            tb[A[i]] = 1;
        } else {
            tb[A[i]] += 1;
        }
    }


    for (size_t i = 0; i < B.size(); ++i) {
        int ch = B[i];
        if (tb.find(ch) == tb.end()) {
            return false;
        } else {
            tb[ch] -= 1;
            if (tb[ch] == 0) {
                tb.erase(ch);
            }
        }
    }

    return true;
}
