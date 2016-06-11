vector<int> diffWaysToCompute(string input) {
    int n = (int) input.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
            cnt++;
        }
    }
    
    vector<int> ans;
    if (cnt == 0) {
        int temp = atoi(input.c_str());
        ans.push_back(temp);
        return ans;
    } else if (cnt == 1) {
        int j  = 0;
        while (j < n && input[j] != '+' && input[j] != '-' && input[j] != '*') j++;
        int num1 = atoi(input.substr(0, j).c_str());
        int num2 = atoi(input.substr(j+1).c_str());
        int temp = 0;
        if (input[j] == '+') temp = num1 + num2;
        else if (input[j] == '-') temp = num1 - num2;
        else if (input[j] == '*') temp = num1 * num2;
        ans.push_back(temp);
        return ans;
    }
    
    for (int i = 0; i  < n; ++i) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i+1));
            for (size_t k1 = 0; k1 < left.size(); ++k1) {
                for (size_t k2 = 0; k2 < right.size(); ++k2) {
                    int x = left[k1];
                    int y = right[k2];
                    int temp = 0;
                    if (input[i] == '+') temp = x + y;
                    else if (input[i] == '-') temp = x - y;
                    else if (input[i] == '*') temp = x * y;
                    ans.push_back(temp);
                }
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}
