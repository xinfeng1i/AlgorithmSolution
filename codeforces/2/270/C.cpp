#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

// if x is subsequence of y, return true; otherwise false;
bool isSubSequence(const vector<long>& x, const vector<long>& y)
{
	bool flag = true;
	vector<long>::const_iterator curPos = y.begin();
	for (size_t i = 0; i < x.size(); ++i)
	{
		long val = x[i];
		curPos = find(curPos, y.end(), val);
		if (curPos == y.end())
		{
			flag = false;
			break;
		}
	}
	return flag;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	long n;
	cin >> n;
	set<pair<string, long> > s;
	string firstname, lastname;
	for (long i = 0; i < n; ++i) 
	{
		cin >> firstname >> lastname;
		s.insert(make_pair(firstname, i + 1));
		s.insert(make_pair(lastname, i + 1));
	}

	vector<long> v;
	v.reserve(2*n);
	set<pair<string, long> >::iterator it;
	for (it = s.begin(); it != s.end(); ++it)
	{
		v.push_back(it->second);	
	}

	/*
	for (long i = 0; i < 2*n; ++i)
	{
		cout << " " << v[i] << endl;
	}
	*/

	vector<long> p(n, 0);
	for (long i = 0; i < n; ++i) cin >> p[i];

	if (isSubSequence(p, v)) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}
