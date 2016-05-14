#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

bool isOperator(string token) {
	if (token == "+" || token == "-" || token == "/" || token == "*")
        return true;
	else
		return false;
}

int evalRPN(vector<string>& tokens) {
	stack<int> s;
	
	for (size_t i = 0; i < tokens.size(); ++i) {
		string token = tokens[i];
		if (!isOperator(token)) {
			s.push(atoi(token.c_str()));
		} else {
			int num2 = s.top(); s.pop();
			int num1 = s.top(); s.pop();
			int temp = 0;
			if (token == "+") {
				temp = num1 + num2;
			} else if (token == "-") {
				temp = num1 - num2;
			} else if (token == "*") {
				temp = num1 * num2;
			} else if (token == "/") {
				temp = num1 / num2;
			}
			s.push(temp);
		}
	}
	return s.top();
}

