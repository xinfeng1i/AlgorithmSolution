// Bit Manipulation:
// mark the low 26 bits with word
// when letter ch occurs, marks low (ch-'a') with 1
// for example: acc -->  101
// suppose we have n words and average Length of every word is L
int maxProduct(vector<string>& words) {
    // time complexity O(nL)
    vector<int> vals(words.size(), 0);
    for (size_t i = 0; i < words.size(); ++i) {
        vals[i] = 0;
        string w = words[i];
        for (size_t k = 0; k < w.size(); ++k) {
            vals[i] |= (1 << (w[k] - 'a'));
        }
    }

    // time complexity O(n^2)
    size_t ans = 0;
    for (size_t i = 0; i < words.size(); ++i) {
        for (size_t j = i + 1; j < words.size(); ++j) {
            if ((vals[i] & vals[j]) == 0) {
                ans = max(ans, words[i].size() * words[j].size());
            }
        }
    }
    return ans;

}
