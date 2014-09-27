#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<long long> ComputeLongestPrefixSuffix(const vector<long long>& pat)
{
	long long m = pat.size();
	vector<long long> lps(m, 0);
	long long len = 0;
	lps[0] = 0;

	long long i = 1;
	while (i < m)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else // pat[i] != pat[len]
		{
			if (len > 0)
			{
				len = lps[len-1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}

	return lps;
}

long long KMP(const vector<long long>& pat, const vector<long long>& txt)
{
	long long n = txt.size();
	long long m = pat.size();

	long long matchCnt = 0;
	vector<long long> lps = ComputeLongestPrefixSuffix(pat);

	long long i = 0;
	long long j = 0;
	while (i < n)
	{
		if (txt[i] == pat[j])
		{
			i++;
			j++;
			if (j == m)
			{
				//cout << "Find pattern at index " << i - j << endl;
				matchCnt += 1;
				j = lps[j-1];
			}
		}
		else // txt[i] != pat[j]
		{
			if (j > 0) { j = lps[j-1]; }
			else { i++; }
		}
	}

	return matchCnt;
}

int main()
{
	long long n, m;
	cin >> n >> m;
	vector<long long> a(n, 0);
	vector<long long> b(m, 0);
	for (long long i = 0; i < n; ++i) cin >> a[i];
	for (long long i = 0; i < m; ++i) cin >> b[i];

	// special case, b has only one element
	if (m == 1)
	{
		cout << n << endl;
		return 0;
	}

	vector<long long> txt(n-1, 0);
	for (long long i = 0; i < n - 1; ++i) txt[i] = a[i+1] - a[i];
	vector<long long> pat(m-1, 0);
	for (long long i = 0; i < m - 1; ++i) pat[i] = b[i+1] - b[i];

	long long ans = KMP(pat, txt);
	cout << ans << endl;
	return 0;
}
