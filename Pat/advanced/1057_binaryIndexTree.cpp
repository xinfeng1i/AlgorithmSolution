#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

//
// Binary Indexed Tree
// solve the daynamic first sum[1...n] problem
//

const int MAXN = 100010;
int c[MAXN] = {0};
int a[MAXN] = {0};

int lowbit(int x) {
	return x & (-x);
}

int getsum(int pos) {
	int sum = 0;
	while (pos > 0) {
		sum += c[pos];
		pos = pos - lowbit(pos);
	}
	return sum;
}

void add(int pos, int diff) {
	while (pos <= MAXN) {
		c[pos] += diff;
		pos = pos + lowbit(pos);
	}
}

int findmid(int value, int low, int high) {
	while (low < high) {
		int mid = low + (high - low) / 2;
		int temp = getsum(mid);
		if (value <= temp) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return low;
}


void PrintC() {
	for (int i = 1; i < MAXN; ++i) {
		if (c[i] == 1) {
			cout << "c[" << i << "]=1" << endl;
		}
	}
}

stack<int> s;

int main()
{
	freopen("input.txt", "r", stdin);
	int n = 0;
	scanf("%d", &n);
	char word[128] = {'\0'};
	int num = 0;
	for (int i = 0; i < n; ++i) {
		memset(word, '\0', 128);
		scanf("%s", word);
		if (strcmp(word, "Push") == 0) {
			scanf("%d", &num);
			s.push(num);
			a[num] = 1;
			add(num, 1);			
		} else if (strcmp(word, "Pop") == 0) {
			if (s.empty()) {
				printf("Invalid\n");
			} else {
				int temp = s.top();
				s.pop();
				a[temp] = 0;	// here should be temp, not num
				add(temp, -1);
				printf("%d\n", temp);
			}
		} else if (strcmp(word, "PeekMedian") == 0) {
			if (s.empty()) {
				printf("Invalid\n");
			} else {
				int midIdx = (int(s.size()) + 1) / 2;
				int temp = findmid(midIdx, 1, MAXN-1);
				printf("%d\n", temp);
			}
		
		} else {
			printf("Invalid\n");
		}
	}
	return 0;
}