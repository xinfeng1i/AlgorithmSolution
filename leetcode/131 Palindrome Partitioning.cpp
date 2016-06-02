bool IsPalindrome(string s) {
    if (s.size() <= 1) return true;
    int n = int(s.size());
    for (int i = 0, j = n-1; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

void PartitionPalindromeRecursively(string cur_str, vector<string>& cur_partition, vector<vector<string>>& tot_partition) {
    // base case
    if (cur_str.empty()) {
        tot_partition.push_back(cur_partition);
        return;
    }

    int sz = (int)cur_str.size();
    for (int len = 1; len <= sz; ++len) {
        string temp = cur_str.substr(0, len);
        if (!IsPalindrome(temp)) {
            continue;
        } else {
            cur_partition.push_back(temp);
            PartitionPalindromeRecursively(cur_str.substr(len), cur_partition, tot_partition);
            cur_partition.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<string> cur_ans;
    vector<vector<string>> tot_ans;
    PartitionPalindromeRecursively(s, cur_ans, tot_ans);
    return tot_ans;
}
