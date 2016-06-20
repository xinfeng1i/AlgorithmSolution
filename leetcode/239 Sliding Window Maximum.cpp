#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;

// Using Multiset to mimic Heap to store the element
// Note Delete Only ONE element
vector<int> maxSlidingWindow(vector<int>& A, int k) {
    vector<int> ans;
    multiset<int, greater<int>> s;
    for (size_t i = 0; i < A.size(); ++i) {
        s.insert(A[i]);
        if (s.size() == k) {
            ans.push_back(*s.begin());
			// s.erase(A[i-k+1]) will remove all the duplicates
			// which is not what we want, we only need to delete one element
			auto it = s.find(A[i-k+1]);
			if (it != s.end()) s.erase(it);
        }
    }
    return ans;
}

int main()
{
	int a[] = {1, 3, 1, 2, 0, 5};
	vector<int> v(a, a+6);
	vector<int> ans = maxSlidingWindow(v, 3);
	return 0;
}