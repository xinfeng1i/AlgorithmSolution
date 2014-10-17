#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const long long KMAX = 100000000000000;

bool IsWavyNumber(long long n)
{
	bool flag = true;
	string s = to_string(n);
	for (size_t i = 1; i + 1 < s.size(); ++i)
	{
		if ((s[i] > s[i-1] && s[i] > s[i+1]) || (s[i] < s[i-1] && s[i] < s[i+1]))
		{
			continue;
		}
		else
		{
			flag = false;
			break;
		}
	}
	return flag;
}

bool IsBadN(long long n)
{
	return (n%100==0 || n%1000==0 || n%10000==0 || n%100000==0 ||
			n%1000000==0 || n%10000000==0 || n%100000000 ||
			n%1000000000==0 || n%10000000000 == 0);
}

int main()
{
	long long n, k;
	cin >> n >> k;

	vector<long long> v;
	for (long long i = n; i <= KMAX; i += n)
	{
		//if (IsBadN(i)) break;
		if (IsWavyNumber(i)) v.push_back(i);	
		if (v.size() >= k) break;
	}

	if (v.size() >= k) cout << v[k-1] << endl;
	else cout << -1 << endl;
	return 0;
}
