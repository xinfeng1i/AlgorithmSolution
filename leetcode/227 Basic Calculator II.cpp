#include <iostream>
#include <string>
#include <stack>
using namespace std;

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 0;
    else return 1;
}

int calculate(string s) {
    size_t n = s.size();
    size_t i = 0;

    stack<int> nums;
    stack<char> sign;
    while (i < n) {
        while (i < n && s[i] == ' ') i++; // skip leading spaces
        if (i >= n) break;

        if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*') {
            while (!sign.empty() && precedence(sign.top()) >= precedence(s[i])) {
                int ch = sign.top(); sign.pop();
                int num2 = nums.top(); nums.pop();
                int num1 = nums.top(); nums.pop();
                if (ch == '+') nums.push(num1+num2);
                else if (ch == '-') nums.push(num1-num2);
                else if (ch == '*') nums.push(num1*num2);
                else nums.push(num1/num2);
            }
            sign.push(s[i]);
            i++;
        } else if (s[i] >= '0' && s[i] <= '9') {
            int num = 0;
            int j = i;
            while (j < n && (s[j] >= '0' && s[j] <= '9')) {
                num = num * 10 + (s[j] - '0');
                j++;
            }
            nums.push(num);
            i = j;
        }
    }

    while (!sign.empty()) {
        int ch = sign.top(); sign.pop();
        int num2 = nums.top(); nums.pop();
        int num1 = nums.top(); nums.pop();
        if (ch == '+') nums.push(num1+num2);
        else if (ch == '-') nums.push(num1-num2);
        else if (ch == '*') nums.push(num1*num2);
        else nums.push(num1/num2);
    }

    return nums.top();

}

int main()
{
    cout << calculate("1") << endl;
    return 0;

}
