#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

string reverseString(string s) {
	string ans(s);
	int i = 0;
	int j = int(ans.size()) - 1;
	for ( ; i < j; ++i, --j) {
		swap(ans[i], ans[j]);
	}
	return ans;
}

#if 0
int main()
{
	cout << reverseString("Hello") << endl;
	return 0;
}
#endif //0