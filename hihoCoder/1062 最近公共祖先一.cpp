#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

map<string, string> tb;

void PrintList(list<string>& L) {
	for (list<string>::iterator it = L.begin(); it != L.end(); ++it) {
		cout << " " << *it;
	}
	cout << endl;
}

list<string> GetParentList(string name) {
	list<string> ans;
	while (tb.find(name) != tb.end()) {
		ans.push_front(name);
		name = tb[name];
	}
	ans.push_front(name);
	return ans;
}

string GetCommonParent(const list<string>& L1, const list<string>& L2) {
	if (L1.empty() || L2.empty()) return "-1";
	list<string>::const_iterator p1 = L1.begin();
	list<string>::const_iterator p2 = L2.begin();
	string last = "-1";
	while (p1 != L1.end() && p2 != L1.end() && (*p1 == *p2)) {
		last = *p1;
		p1++;
		p2++;
	}
	return last;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	string father, son;
	for (int i = 0; i < n; ++i) {
		cin >> father >> son;
		tb[son] = father;
	}
	
	int m;
	cin >> m;
	string name1, name2;
	for (int i = 0; i < m; ++i) {
		cin >> name1 >> name2;
		list<string> L1 = GetParentList(name1);
		list<string> L2 = GetParentList(name2);
		//PrintList(L1);
		//PrintList(L2);
		string ans = GetCommonParent(L1, L2);
		cout << ans << endl;
	}
	return 0;
}
