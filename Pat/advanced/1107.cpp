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
using namespace std;

// Union-Find Problem
// Find all the connected components and count the number of
// nodes in each components

#if 0
const int MAXN = 1010;
struct Person {
	int ID;
	int k;
	vector<int> hobby;
};

Person person[MAXN];
int parent[MAXN];

void Init() {
	for (int i = 0; i < MAXN; ++i) {
		parent[i] = i;
	}
}

int FindRoot(int i) {
	if (parent[i] == i) return i;
	else return FindRoot(parent[i]);
}

void UnionPerson(int i, int j) {
	int rootI = FindRoot(i);
	int rootJ = FindRoot(j);
	if (rootI != rootJ) {
		parent[rootJ] = rootI;
	}
}

bool HasSameHobby(int i, int j) {
	vector<int> v1 = person[i].hobby;
	vector<int> v2 = person[j].hobby;
	for (size_t i = 0; i < v1.size(); ++i) {
		for (size_t j = 0; j < v2.size(); ++j) {
			if (v1[i] == v2[j])
				return true;
		}
	}
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		int m = -1;
		int h = -1;
		scanf("%d:", &m);
		person[i].ID = i;
		person[i].k = m;
		for (int j = 0; j < m; ++j) {
			scanf("%d", &h);
			person[i].hobby.push_back(h);
		}
	}

	Init();

	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (HasSameHobby(i, j)){
				UnionPerson(i, j);
			}
		}
	}

	map<int, int> rootMapCnt;
	for (int i = 1; i <= n; ++i) {
		int rootI = FindRoot(i);
		if (rootMapCnt.find(rootI) == rootMapCnt.end()) {
			rootMapCnt[rootI] = 1;
		} else {
			rootMapCnt[rootI] += 1;
		}
	}

	vector<int> ans;
	for (auto it = rootMapCnt.begin(); it != rootMapCnt.end(); ++it) {
		ans.push_back(it->second);
	}

	sort(ans.begin(), ans.end(), greater<int>());

	printf("%d\n", ans.size());
	for(size_t i = 0; i < ans.size(); ++i) {
		if (i == 0) printf("%d", ans[i]);
		else printf(" %d", ans[i]);
	}
	printf("\n");

	return 0;
}
#endif //