#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int cmpStr(const string& a, const string& b)
{
	assert(a.length() == b.length());
	int n = a.length();
	
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] != b[i]) cnt++;
	}
	return cnt;
}

int minimize(string A, string B)
{
	int alen = A.length();
	int blen = B.length();
	if (alen == blen)
	{
		return cmpStr(A, B);
	}

	assert(alen < blen);

	int ans = alen;
	for (int i = 0; i <= blen - alen; ++i)
	{
		ans = min(ans, cmpStr(A, B.substr(i, alen)));
	}

	return ans;
}

