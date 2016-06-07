#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

#if 0
// Method 1:
// Using backtracking: TLE for large case
bool isValidRecursion(vector<string> v) {
    if (v.size() % 2 == 0) return false;
    if (v.size() == 1) {
        if (v[0] == "#") return true;
        else return false;
    }

    int maxLen = (v.size() - 1);
    for (int len = 1; len < maxLen; len += 2) {
        vector<string> left(v.begin()+1, v.begin()+1+len);
        vector<string> right(v.begin()+1+len, v.end());
        if (isValidRecursion(left) && isValidRecursion(right)) {
            return true;
        }
    }
    return false;
}

bool isValidSerialization(string preorder) {
    for (size_t i = 0; i < preorder.size(); ++i) {
        if (preorder[i] == ',') preorder[i] = ' ';
    }

    vector<string> v;
    istringstream iss(preorder);
    string temp;
    while (iss >> temp) {
        v.push_back(temp);
    }

    return isValidRecursion(v);
}
#endif //0

// Method 2
bool isValidSerialization(string preorder) {
    for (size_t i = 0; i < preorder.size(); ++i) {
        if (preorder[i] == ',') preorder[i] = ' ';
    }
    
    vector<string> v;
    istringstream iss(preorder);
    string temp;
    while (iss >> temp) {
        v.push_back(temp);
    }
    
    int n = (int) v.size();
    int null_cnt = 0;
    int node_cnt = 0;
    for (int i = 0; i < n; ++i) {
        cout << v[i] << endl;
        if (v[i] == "#") {
            null_cnt++;
        } else {
            node_cnt++;
        }
        if (null_cnt >= node_cnt+1 && i != n-1) return false;
    }
    return null_cnt == node_cnt+1;
}

int main()
{
    string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    isValidSerialization(s);
    return 0;
}

