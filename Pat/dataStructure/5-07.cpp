#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct cmpItem
{
	bool operator()(const pair<string, int>& a, const pair<string, int>& b)
	{
		if (a.second != b.second) return a.second > b.second;
		else return a.first < b.first;
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	map<string, int> table;
	int n = 0;
	cin >> n;
	cin.ignore();

	string line;
	for (int i = 0; i < n; ++i)
	{
		getline(cin, line);	
		int pos1 = 0;
		while (line[pos1] != '#') pos1++;
		int pos2 = pos1 + 1;
		while (line[pos2] != '#') pos2++;
		string topic = line.substr(pos1+1, pos2 - pos1 - 1);
		cout << "topic:" << topic << endl;
		if (topic.size() > 40) topic = topic.substr(0, 40);
		table[topic]++;
	}

	vector<pair<string, int> > v;
	for (auto it = table.begin(); it != table.end(); ++it)
	{
		v.push_back(*it);
	}

	sort(v.begin(), v.end(), cmpItem());
	cout << v[0].first << endl;
	cout << v[0].second << endl;

	int cnt = 0;
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i].second == v[0].second) cnt++;
	}
	if (cnt != 0) cout << "And " << cnt << " more ..." << endl;

	return 0;

}
