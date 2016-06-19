#include <iostream>
#include <string>
#include <vector>
using namespace std;


inline string maxCommonPrefix(const string& a, const string& b) {
    size_t n1 = a.size(); size_t n2 = b.size();
    size_t i = 0;
    while (i < n1 && i < n2 && a[i] == b[i]) {
        i++;
    }
    return a.substr(0, i);
}

bool isInterleave(string s1, string s2, string s3) {
    if (s1.empty()) return s2 == s3;
    if (s2.empty()) return s1 == s3;
    if (s3.size() != s1.size() + s2.size()) return false;
    
    string common_str1 = maxCommonPrefix(s3, s1);
    //cout << common_str1 << endl;
    for (size_t i = 1; i <= common_str1.size(); ++i) {
        string next_s1 = s1.substr(i);
        string next_s3 = s3.substr(i);
        bool ok = isInterleave(next_s1, s2, next_s3);
        if (ok) {
            return true;
        }
    }
    
    string common_str2 = maxCommonPrefix(s3, s2);
    for (size_t i = 1; i <= common_str2.size(); ++i) {
        string next_s2 = s2.substr(i);
        string next_s3 = s3.substr(i);
        bool ok = isInterleave(s1, next_s2, next_s3);
        if (ok) {
            return true;
        }
    }
    return false;
}

int main()
{
	string s1 = "a";
	string s2 = "b";
	string s3 = "ab";
	cout << isInterleave(s1, s2, s3) << endl;
	return 0;
}
