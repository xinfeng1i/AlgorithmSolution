//
//  Leetcode22_括号生成.cpp
//  HelloXcode
//
//  Created by xinfengli on 2022/7/1.
//

#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;


bool isEmpty(const vector<string>& remain) {
    return remain[0].empty() && remain[1].empty();
}


bool isValidKuohao(string str) {
    int n = (int) str.size();
    stack<char> S;
    for (int i = 0; i < n; ++i) {
        if (str[i] == '(') {
            S.push(str[i]);
        } else {
            if (S.empty()) {
                return false;
            } else {
                S.pop();
            }
        }
    }
    return S.empty();
}


void kuohaoPair(string sofar, vector<string> remain, vector<string>& globalAns) {
    if (isEmpty(remain)) {
        if (isValidKuohao(sofar)) {
            globalAns.push_back(sofar);
        }
        return;
    }
    
    for (size_t i = 0; i < remain.size(); ++i) {
        if(!remain[i].empty()) {
            // 1. try a choice
            char temp = remain[i].back();
            sofar += temp;
            remain[i].pop_back();
            
            // 2. check recursively whether it will lead to a solution.
            kuohaoPair(sofar, remain, globalAns);
            
            // 3. trackback
            sofar.pop_back();
            remain[i].push_back(temp);
            
        }
    }
    return;
}


vector<string> generateParenthesis(int n) {
    string s1 = string(n, '(');
    string s2 = string(n, ')');
    vector<string> remain;
    remain.push_back(s1);
    remain.push_back(s2);
    
    string sofar = "";
    
    vector<string> ans;
    kuohaoPair(sofar, remain, ans);
    
    return ans;
}


#if 0
int main() {
    int n = 3;

    vector<string> result = generateParenthesis(n);
    for (string x: result) {
        cout << x << endl;
    }
    
    return 0;
}
#endif // 0
