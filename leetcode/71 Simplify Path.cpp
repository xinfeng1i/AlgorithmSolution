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

// stack application
string simplifyPath(string path) {
    int n = (int) path.size();
        
    stack<string> s;
        
    int i = 0;
    while (i < n) {
        // find a sub-dir between [i+1, j)
        int j = i + 1;
        while (j < n && path[j] != '/') j++;
            
        // not found
        if (j == i + 1) {
            i = j;
            continue;
        } 
            
        // found
        string temp = path.substr(i+1, j-i-1);
        if (temp != "." && temp != "..") {
            s.push(temp);
        } else if (temp == ".") {
            ;
        } else if (temp == "..") {
            if (s.empty()) {
                ;
            } else {
                s.pop();
            }
        }
            
        i= j;
    }
        
    if (s.empty()){
        return "/";
    } else {
        string ans = "";
        while (!s.empty()) {
            ans = "/" + s.top() + ans;
            s.pop();
        }
        return ans;
    }
        
}