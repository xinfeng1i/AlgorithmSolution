// backtracking:
// A = [1,2,3,4,5,6,7,8,9]
// [left, right] indicates choose k numbers from A[left] to A[right] from A
void helper(int n, int k, const vector<int>& A, int left, int right, vector<int>& curAns, vector<vector<int>>& totAns) {
	// base case: remain number is less than k
	if (right-left+1 < k) {
		return;
	}

	// base case
	if (k == 1) {
		bool ok = binary_search(A.begin()+left, A.begin()+right+1, n);
		if (ok) {
			curAns.push_back(n);
			totAns.push_back(curAns);
			curAns.pop_back();
		}
		return;
	}

	// for every choice
	for (int i = left; i <= right; ++i) {
		curAns.push_back(A[i]);    // try a choice
		helper(n-A[i], k-1, A, i+1, right, curAns, totAns); // recursively check the solution
		curAns.pop_back(); // backtracking
	}
}


vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> totAns;
	vector<int> curAns;

	vector<int> A(9, 0);
	for (int i = 0; i < 9; ++i) A[i] = i+1;

	helper(n, k, A, 0, 8, curAns, totAns);

	return totAns;
}
