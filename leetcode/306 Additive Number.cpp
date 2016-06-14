#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
bool valid(string s) {
    if (s.empty() || (s.size() > 1 && s[0] == '0')) return false;
    return true;
}


bool verify(string num1, string num2, string s) {
    if (num1.empty() || num2.empty() || s.empty()) return false;
    long long n1 = atoll(num1.c_str());
    long long n2 = atoll(num2.c_str());
    long long n3 = n1 + n2;
    string num3 = to_string(n3);
    if (s.size() < num1.size() + num2.size() + num3.size()) {
        return false;
    } else {
        string prefix = s.substr(num1.size() + num2.size(), num3.size());
        if (!prefix.empty() && prefix == num3) {
            if (s.size() == num1.size() + num2.size() + num3.size()) {
                return true;
            } else {
                return verify(num2, num3, s.substr(num1.size()));
            }
        }
        return false;
    }
}

bool isAdditiveNumber(string num) {
    if (num.size() < 3) return false;
    long long n = (long long) num.size();
    for (long long len1 = 1; len1 < n; ++len1) {
        string num1 = num.substr(0, len1);
        if (!num1.empty() && valid(num1)) {
            for (long long len2 = 1; len1 + len2 < n; ++len2) {
                string num2 = num.substr(len1, len2);
                if (!num2.empty() && valid(num2)) {
                    //cout << "here" << endl;
                    string remain = num.substr(len1+len2);
                    if (!remain.empty()) {
                        long long n1 = atoll(num1.c_str());
                        long long n2 = atoll(num2.c_str());
                        long long n3 = n1 + n2;
                        string num3 = to_string(n3);
                        if (remain.size() >= num3.size()) {
                            string prefix = remain.substr(0, num3.size());
                            if (prefix == num3) {
                                //cout << "num1 = " << num1 << endl;
                                //cout << "num2 = " << num2 << endl;
                                bool ok = verify(num1, num2, num);
                                if (ok) return true;
                            }
                        }
                    }
                }

            }
        }
    }
    return false;
}

int main()
{
    string s = "199100199";
    cout << isAdditiveNumber(s) << endl;
    return 0;
}
