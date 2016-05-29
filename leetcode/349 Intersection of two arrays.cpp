// 数组排序，二分查找 
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    
    vector<int> ans;
    for (size_t i = 0; i < nums1.size(); ++i) {
        if (i == 0 || nums1[i] != nums1[i-1]) {
            bool ok = binary_search(nums2.begin(), nums2.end(), nums1[i]);
            if (ok) {
                ans.push_back(nums1[i]);
            }
        }
    }
    return ans;
}
