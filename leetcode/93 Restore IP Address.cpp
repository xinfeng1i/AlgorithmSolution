#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long toNumber(const string& s) {
    long long n = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}

void restoreIpAddressRecursive(string s, vector<string>& IP, int nGroup, vector<string>& result) {
    
    if (nGroup == 0 && !s.empty()) return;
    if (nGroup != 0 && s.empty()) return;
    if (nGroup == 0 && s.empty()) {
    	string tempIP = "";
        for (size_t i = 0; i < IP.size(); ++i) {
            tempIP += IP[i];
        }
        if (tempIP[int(tempIP.size())-1] == '.') tempIP = tempIP.substr(0, tempIP.size() - 1);
        result.push_back(tempIP);
        //cout << tempIP << endl;
        return;
    }
    
    int sz = s.size();
    for (int len = 1; len <= 3 && len <= sz; ++len) {
        // try a choice
        string temp = s.substr(0, len);
        // skip invalid group such as '010', '01'...
        if (temp[0] == '0' && temp.size() != 1) continue;

		int n = toNumber(temp);
        if (0 <= n && n <= 255) {
            IP.push_back(temp);;
            IP.push_back(".");
            restoreIpAddressRecursive(s.substr(len), IP, nGroup-1, result);
            
            // back tracking
            IP.pop_back();
            IP.pop_back();
        }
    }
}

vector<string> restoreIpAddresses(string s) {
	vector<string> result;
	vector<string> IP;
	restoreIpAddressRecursive(s, IP, 4, result);
	return result;
}



int main()
{
    string s = "010010";
    vector<string> result = restoreIpAddresses(s);
    for (size_t i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}
    return 0;
} 
