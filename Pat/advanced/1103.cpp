#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
using namespace std;

// backtracking problem
// NOTE: the double pow func is too slow, using my own
// pow function

bool CmpVec(const vector<int>& v1, const vector<int>& v2) {
	int n1 = (int)v1.size();
	int n2 = (int)v2.size();
	for (int i = 0; i < min(n1, n2); i++) {
		if (v1[i] > v2[i]) return true;
		else if (v1[i] < v2[i]) return false;
	}
	return n1 > n2;
}

set<vector<int>> ans;
//set<vector<int>> gAns;
bool ok = false;
unordered_map<int, unordered_map<int, unordered_map<int, int>>> ht;


void solve(int n, int k, int p, vector<int>& cur)
{
	if (n < k) return;
	if (k > 0) {
		if (n <= 0) return;
	} else if (k <= 0) {
		if (n == 0) {
			ok = true;
			vector<int> temp(cur.begin(), cur.end());
			sort(temp.begin(), temp.end(), greater<int>());
			ans.insert(temp);
		}
		return;
	}

	int x = (int)pow(double(n), 1.0/(p));
	for (int j = 1; j <= x; j++) {
		int newn = n - (int)pow((double)j, (double)p);
		if (newn >= k-1) {
			cur.push_back(j);
			solve(newn, k-1, p, cur);
			cur.pop_back();
		} else {
			break;
		}
	}

}

void PrintVec(int n, int p, const vector<int>& v) {
	printf("%d = ", n);
	for (size_t i = 0; i < v.size(); ++i) {
		if (i == 0) printf("%d^%d", v[i], p);
		else printf(" + %d^%d", v[i], p);
	}
	printf("\n");
}

int mypow(int x, int y) {
	int ans = 1;
	while (y > 0) {
		if (y & 1) { ans *= x; y--;}
		else {x *= x; y /= 2;}
	}
	return ans;
}

void solve2(int idx, int n, int k, int p, vector<int> &A)
{
	if (n < k) return;
	if (idx >= (int)A.size()) {
		if (n == 0) {
			ok = true;
			vector<int> temp(A.begin(), A.end());
			sort(temp.begin(), temp.end(), greater<int>());
			ans.insert(temp);
		}
		return;
	}

	int x = n - k + 1;
	int uplimit = 1100;
	if (idx-1>=0) uplimit = min(uplimit, A[idx-1]);
	for (int i = 1; i <= min(x, uplimit); ++i) {
		A[idx] = i;
		//int nextn = n - (int)pow((double)i, (double)p);
		int nextn = n - mypow(i, p); // DOUBLE POW function is too slow, using my own pow func
		if (nextn < k-1) break;
		solve2(idx+1, nextn, k-1, p, A);
		A[idx] = 0;
	}
}



int main()
{
	int n = 0, k = 0, p = 0;
	scanf("%d %d %d", &n, &k, &p);

	//vector<int> cur;
	//solve(n, k, p, cur);

	vector<int> A(k, 0);
	solve2(0, n, k, p, A);

	if (!ok) {
		printf("Impossible\n");
	} else {
		vector<vector<int>> finalAns;
		int maxsum = 0;
		for (auto it = ans.begin(); it != ans.end(); it++) {
			int tmpsum = std::accumulate((*it).begin(), (*it).end(), 0);
			if (tmpsum > maxsum) {
				maxsum = tmpsum;
				finalAns.clear();
				finalAns.push_back(*it);
			} else if (tmpsum == maxsum) {
				finalAns.push_back(*it);
			}
		}

		vector<int> my_ans = *finalAns.rbegin();
		PrintVec(n, p, my_ans);
	}
	return 0;
}