#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

#if 1
// calculate all the factors (NOT INCLUDED 1) of n
vector<int> GetFactors(int n) {
	set<int> s;
	int mid = (int)sqrt(double(n));
	for (int i = 1; i <= mid; ++i) {
		if (n % i == 0) {
			s.insert(i);
			s.insert(n/i);
		}
	}

	if (s.find(1) != s.end()) s.erase(1);
	vector<int> ans(s.begin(), s.end());
	return ans;
}

void PrintVector(const vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		cout << " " << v[i];
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;

	vector<int> factors = GetFactors(n);

	//cout << "factors : " << endl;
	//PrintVector(factors);

	int len = int(factors.size());
	int minIndex = 0; int maxIndex = 0;
	int diffNumber = maxIndex - minIndex + 1;
	int i = 0;
	while (i < len) {
		long long temp = factors[i];
		int j = i + 1;
		while (j < len && factors[j] == factors[j-1] + 1 && 
			(temp = temp * factors[j]) <= n && n % temp == 0) {
			j++;
		}

		if (j - i > diffNumber) {
			diffNumber = j - i;
			minIndex = i;
			maxIndex = j - 1;
		}

		// NOTICE: update step, only can step one, since 11*12*13*14*... may
		// can not be divide, but 12*13*14*15*... can
		i = i + 1; 
	}

	cout << diffNumber << endl;
	for (int k = minIndex; k <= maxIndex; ++k) {
		if (k == minIndex) cout << factors[k];
		else cout << "*" << factors[k];
	}
	cout << endl;

	return 0;
}
#endif //0