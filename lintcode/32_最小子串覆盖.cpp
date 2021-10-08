#include <cstdio>
#include <cstdlib>
#include <climits>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;


/*
 * Method1: ������������
 * 1. �ƶ���ָ���ҵ���������������
 * 2. �ƶ���ָ����С���ڷ�Χ���ҵ���С������
 * 
 * ʱ�临�Ӷȣ�
 * �ռ临�Ӷȣ�O(C)������ C Ϊ�ַ�����С
 */
string minWindow(string& source, string& target) {
    if (target == "") return "";
    if (source == "") return "";
    if (source.size() < target.size()) return "";

    int n = (int)source.size();
    int m = (int)target.size();

    map<char, int> tmap;
    for (char ch : target) {
        if (tmap.find(ch) == tmap.end()) {
            tmap[ch] = 1;
        } else {
            tmap[ch] += 1;
        }
    }

    int matchCnt = 0;
    int minLength = INT_MAX;
    string ans = "";

    int i = 0;
    int j = 0;
    while (i < n) {
        /* ��ǰƥ���ַ���С��Ԥ�ڣ������ƶ��Ҳ�ָ������Χ */
        while (j < n && matchCnt < m) {
            if (tmap.find(source[j]) != tmap.end()) {
                if (tmap[source[j]] >= 1) { matchCnt++; }
                tmap[source[j]]--;
            }
            j++;
        }

        /* �����ҵ��� answer */
        if (matchCnt >= m) {
            int curLength = j - i;
            if (curLength < minLength) {
                minLength = curLength;
                ans = source.substr(i, curLength);
            }
        }

        /* �ƶ���ָ����С���ڷ�Χ */
        if (tmap.find(source[i]) != tmap.end()) {
            if (tmap[source[i]] >= 0) { matchCnt--; }
            tmap[source[i]]++;            
        }
        i++;
    }

    return ans;
}

int main() {
    // string s1 = "adobecodebanc";
    // string s2 = "abc";
    string s1 = "abc";
    string s2 = "aa";

    string ans = minWindow(s1, s2);
    printf("%s\n", ans.c_str());


    return 0;
}