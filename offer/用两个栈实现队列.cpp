#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

class Solution
{
public:
    void push(int val) {
    	while (!st2.empty()) {
    		int x = st2.top();
    		st2.pop();
    		st1.push(x);
		}
		st1.push(val);
    }

    int pop() {
    	while (!st1.empty()) {
    		int x = st1.top();
    		st1.pop();
    		st2.push(x);
		}
        
        int ans = st2.top();
        st2.pop();
        return ans;
    }

private:
    stack<int> st1;
    stack<int> st2;
};
