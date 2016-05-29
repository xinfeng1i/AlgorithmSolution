struct S {
    int cnt;
    int elem;
    bool operator<(const S& other) const {
        if (cnt != other.cnt) {
            return cnt > other.cnt;
        } else {
            return elem < other.elem;
        }
    }
};
// ¹þÏ£±í+bucket sorting 
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> tb;
    for (int x: nums) {
        tb[x] += 1;
    }
    
    set<S> heap;
    S temp;
    for (auto it = tb.begin(); it != tb.end(); ++it) {
        temp.cnt = it->second;
        temp.elem = it->first;
        heap.insert(temp);
    }
    
    
    vector<int> ans;
    int cur_k = 0;
    for (auto it = heap.begin(); it != heap.end(); ++it) {
        ans.push_back(it->elem);
        cur_k++;
        if (cur_k == k) {
            break;
        }
    }
    
    return ans;
    
}
