//
//  Leetcode17_电话号码的字母组合.cpp
//  HelloXcode
//
//  Created by xinfengli on 2022/7/2.
//

#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <string>
#include <iostream>
#include <typeinfo>
#include <algorithm>
using namespace std;


void digitCombinationRecur(string& sofar, string remain, unordered_map<char, vector<char>>& m, vector<string>& globalAns) {
    if (remain.empty()) {
        globalAns.push_back(sofar);
        return;
    }
    
    char digit = remain[0];
    vector<char> chars = m[digit];
    for (size_t i = 0; i < chars.size(); ++i) {
        // 1. try a choice
        char ch = chars[i];
        sofar += ch;
        // 2. recursion
        digitCombinationRecur(sofar, remain.substr(1), m, globalAns);
        // 3. backtracking
        sofar.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    unordered_map<char, vector<char>> digit2char;
    digit2char['2'] = {'a', 'b', 'c'};
    digit2char['3'] = {'d', 'e', 'f'};
    digit2char['4'] = {'g', 'h', 'i'};
    digit2char['5'] = {'j', 'k', 'l'};
    digit2char['6'] = {'m', 'n', 'o'};
    digit2char['7'] = {'p', 'q', 'r', 's'};
    digit2char['8'] = {'t', 'u', 'v'};
    digit2char['9'] = {'w', 'x', 'y', 'z'};
    
    string sofar = "";
    vector<string> ans;
    if (digits == "") return ans;
    digitCombinationRecur(sofar, digits, digit2char, ans);
    return ans;
}


int main() {
    string s = "23";
    vector<string> ans = letterCombinations(s);
    for (string x: ans) {
        cout << x << endl;
    }
    
    return 0;
}
