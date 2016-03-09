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

// queue simulation problem
// NOTE that: the traction starting time before 17:00
// i.e., if some customer starting at time 16:58, finishing
// at time 17:05 is also legal, should prinf 17:05

struct Customer {
	int ID;
	int costTime;
	Customer(int id, int t) : ID(id), costTime(t) {}
};

struct Window {
	int curTime;
	queue<Customer> q;
};

const int MAXN = 1010;
int T[MAXN]; // record every one's traction time

unordered_map<int, int> Simulation(int n, int m, int k, vector<Window> &windows, 
	queue<Customer> &waitingLine)
{
	unordered_map<int, int> ans; // map id and finish time
	int nFinishedCustomer = 0;

	while (nFinishedCustomer < k) {
		// choose the least time window
		int leastTime = INT_MAX;
		int tickTime = -1;
		int idx = -1;
		for (int i = 0; i < n; ++i) {
			if (windows[i].q.empty()) continue;
			int temp = windows[i].curTime + windows[i].q.front().costTime;
			if (temp < leastTime) {
				leastTime = temp;
				tickTime = windows[i].q.front().costTime;
				idx = i;
			}
		}

		// every window tick such time
		for (int i = 0; i < n; ++i) {
			windows[i].curTime += tickTime;

			if (windows[i].q.empty()) continue;
			windows[i].q.front().costTime -= tickTime;
			if (windows[i].q.front().costTime == 0) {
				// this customer has finished, pop()
				Customer thisCustomer = windows[i].q.front();
				ans[thisCustomer.ID] = windows[i].curTime;
				windows[i].q.pop();
				nFinishedCustomer += 1;
				//cout << "Customer " << i << ": finished in window " << i
				//	 << "; at time:" << windows[i].curTime << endl;

				// push one customer from the backup line
				if (!waitingLine.empty()) {
					Customer cus = waitingLine.front();
					waitingLine.pop();
					windows[i].q.push(cus);
				}
			}
		}
	}

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n = 0, m = 0, k = 0, q = 0;
	scanf("%d %d %d %d", &n, &m, &k, &q);

	vector<Window> windows(n);
	queue<Customer> waitingLine;

	int id = 0, t = 0;
	for (int i = 0; i < k; ++i) {
		id = i + 1;
		scanf("%d", &t);
		Customer temp(id, t);
		T[id] = t;
		if (i < n * m) {
			int pos = i % n;
			windows[pos].q.push(temp);
		} else {
			waitingLine.push(temp);
		}
	}

	// init
	for (int i = 0; i < n; ++i) {
		windows[i].curTime = 0;
	}

	// Simulation
	unordered_map<int, int> ans = Simulation(n, m, k, windows, waitingLine);

	for (int i = 0; i < q; ++i) {
		scanf("%d", &id);
		int t = ans[id];
		int hh = t / 60 + 8;
		int mm = t % 60;
		if (t > 540) {
			// starting at 16:59 fininshing at 17:01
			if (t - T[id] < 540) printf("%02d:%02d\n", hh, mm); 
			else printf("Sorry\n");
		} else {
			printf("%02d:%02d\n", hh, mm);
		}
	}

	return 0;
}