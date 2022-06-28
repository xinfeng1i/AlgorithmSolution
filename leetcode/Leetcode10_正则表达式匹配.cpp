#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

/*************************************************************************
 * �������̫ţ�ˣ���ȫ���Լ����뷨ʵ����ȷ��ţ��ѽ��by 2022-06-28 0:57 a.m.
 *
 * ״̬���壺dp[i][j] ����Ϊi��s�볤��Ϊj��p�Ƿ�ƥ��
 * Ŀ��״̬: dp[m][n]
 * ״̬ת�ƣ�ö��p�����һ��char��������ĸ����ţ������Ǻţ������������ת��
 *
 ************************************************************************/
bool isMatch(string s, string p) {
    int m = (int)s.size();
    int n = (int)p.size();

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    // �ر�ע������ĳ�ʼ��������
    // 1. ���s��p��Ϊ�գ�����Ϊmatch
    // 2. ��sΪ�գ�����p��Ϊ��ʱ��������� (a*)(b*)(.*) ����������ż��ģʽ���ǿ���ƥ��մ���
    dp[0][0] = true;
    if (n >= 2 && p[0] != '*' && p[1] == '*') dp[0][2] = true;
    for (int len = 2; len <= n; len += 2) {
        if (dp[0][len - 2] && p[len - 1] == '*' && p[len - 2] != '*') dp[0][len] = true;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] >= 'a' && p[j - 1] <= 'z') {
                if (p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = false;
                }
            }
            else if (p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                bool flag1 = false;
                bool flag2 = false;
                if (j - 2 >= 0 && dp[i][j - 2]) flag1 = true;
                if (j - 2 >= 0 && (p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j]) flag2 = true;
                dp[i][j] = flag1 || flag2;
            }
        }
    }

    return dp[m][n];
}


int main() {
    string s = "aab";
    string p = "c*a*b";
    bool ans = isMatch(s, p);
    cout << "ans: " << ans << endl;

    return 0;
}


