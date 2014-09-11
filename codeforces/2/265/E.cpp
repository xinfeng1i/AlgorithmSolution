#include <iostream>
#include <string>
#include <vector>
using namespace std;


const long long MOD = 1000000000 + 7;
long long value[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
long long myexp[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};

string s;
int n;
int main()
{
	cin >> s >> n;
	vector<string> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	for (int i = n-1; i >= 0; --i)
	{
		long long ep = 1;
		long long ve = 0;
		for (int j = int(v[i].size())-1; j >= 3; --j)
		{
			int d = v[i][j] - '0';
			ve = (ve + value[d] * ep) % MOD;
			ep = (ep * myexp[d]) % MOD;
		}
		value[v[i][0]-'0'] = ve;
		myexp[v[i][0]-'0'] = ep;
		//cout <<  "value[" << v[i][0]-'0'<<"] =" << ve << endl;
		//cout <<  "myexp[" << v[i][0]-'0'<< "] =" << ep << endl;
	}

	long long ans = 0;
	long long ansexp = 1;
	for (int i = int(s.size()) - 1; i >= 0; --i)
	{
		int d = s[i] - '0';
		ans = (ans + value[d] * ansexp) % MOD;
		ansexp = (ansexp * myexp[d]) % MOD;
	}
	cout << ans << endl;
	return 0;
}
