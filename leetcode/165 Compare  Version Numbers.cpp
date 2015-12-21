#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* 子版本可能有多个例如: a.b.c.e.d
 * 此函数将字符串的版本序列转换为一个整数数组
 */
vector<int> ConvertVersion(string version) {
    vector<int> v;
    int i = 0, j = 0, n = version.size();
    while (i < n) {
        j = i + 1;
        while (j < n && version[j] != '.') j++;
        string temp = version.substr(i, j-i);
        v.push_back(atoi(temp.c_str()));
        i = j+1;
    }
    return v;
}

int compareVersion(string version1, string version2) {
    vector<int> v1 = ConvertVersion(version1);
    vector<int> v2 = ConvertVersion(version2);
    int minLen = min(v1.size(), v2.size());
    int i = 0;
    for (i = 0; i < minLen; ++i) {
        if (v1[i] == v2[i]) {
            continue;
        } else if (v1[i] > v2[i]) {
            return 1;
        } else {
            return -1;
        }
    }
    
    // 注意边界情况，如果a序列比b序列长，但是其结尾版本数为
    // 0， 那么其版本号实际是相等的。如 1.0 == 1
    // 此部分判断多余的尾部是否全不为零，如果是，则相等
    // 否则，则长的版本号较大
	if (v1.size() == v2.size()) {
		return 0;
	} else if (v1.size() > v2.size()) {
		for (int j = minLen; j < v1.size(); ++j) {
			if (v1[j] > 0) return 1;
		}
		return 0;
	} else {
        for (int j = minLen; j < v2.size(); ++j) {
            if (v2[j] > 0) return -1;
        }
        return 0;
	}
}

int main()
{
	string v1 = "1.0.1";
	string v2 = "1.0";
	cout << compareVersion(v1, v2) << endl;
 	return 0;
}

