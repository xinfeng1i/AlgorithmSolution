#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cctype>
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
	scanf("%d\n", &n);

	string line;
	for (int i = 0; i < n; ++i)
	{
		getline(cin, line);	
		
		int curPos = 0;
		int lsz = line.size();

		set<string> curLineTopics;
		while (curPos < lsz)
		{
			int pos1 = curPos;
			while (pos1 < lsz && line[pos1] != '#') pos1++;
			int pos2 = pos1 + 1;
			while (pos2 < lsz && line[pos2] != '#') pos2++;
			if (pos1 >= lsz || pos2 >= lsz)
			{
				break;
			}

			string topic = line.substr(pos1+1, pos2 - pos1 - 1);
			string finalTopic;
			finalTopic.reserve(topic.size());
			for (size_t i = 0; i < topic.size(); ++i)
			{
				if (isalpha(topic[i]) || isdigit(topic[i]) || isspace(topic[i]))
				{
					finalTopic.push_back(tolower(topic[i]));
				}
				if (topic[i] == '@')
				{
					finalTopic.push_back(' ');
				}
			}
			//cout << "final topic:" << finalTopic << endl;
			if (finalTopic.size() > 40) finalTopic = finalTopic.substr(0, 40);
			
			curLineTopics.insert(finalTopic);
			
			//table[finalTopic]++;

			curPos = pos2 + 1;
		}

		for (auto it = curLineTopics.begin(); it != curLineTopics.end(); ++it)
		{
			table[*it]++;
		}
	}

	vector<pair<string, int> > v;
	for (auto it = table.begin(); it != table.end(); ++it)
	{
		v.push_back(*it);
	}

	sort(v.begin(), v.end(), cmpItem());
	string t = v[0].first;
	if (islower(t[0])) t[0] = toupper(t[0]);
	cout << t << endl;
	cout << v[0].second << endl;

	int cnt = 0;
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i].second == v[0].second) cnt++;
	}
	if (cnt != 0) cout << "And " << cnt << " more ..." << endl;

	return 0;

}
