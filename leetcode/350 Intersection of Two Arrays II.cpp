// Êı×éÅÅĞò+Ë«Ö¸Õë 
vector<int> intersect(vector<int>& A1, vector<int>& A2) {
    sort(A1.begin(), A1.end());
    sort(A2.begin(), A2.end());
    int n1 = (int) A1.size();
    int n2 = (int) A2.size();
    
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (A1[i] < A2[j]) {
            i++;
        } else if (A1[i] > A2[j]) {
            j++;
        } else {
            ans.push_back(A1[i]);
            i++;
            j++;
        }
    }
    
    return ans;

