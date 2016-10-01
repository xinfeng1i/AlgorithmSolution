#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool IsPopOrder(vector<int> pushV,vector<int> popV) {
	int n = static_cast<int>(pushV.size());
	stack<int> st;
	int i = 0; int j = 0;
	while (j < n) {
		if (st.empty()) {
			if (i >= n) return false;
			else st.push(pushV[i++]);
		} else if (st.top() != popV[j]) {
			if (i >= n) return false;
			else st.push(pushV[i++]);
		} else if (st.top() == popV[j]) {
			st.pop();
			j++;
		}

	}
	return j >= n && st.empty();
}

int main()
{
	vector<int> u = {1, 2, 3, 4, 5};
	vector<int> v1 = {4, 5, 3, 2, 1};
	vector<int> v2 = {4, 3, 5, 1, 2};
	//for (size_t i = 0; i < u.size(); ++i) cout << u[i] << " ";
	//cout << endl;
	cout << IsPopOrder(u, v1) << endl;
	cout << IsPopOrder(u, v2) << endl;
	return 0;
}
