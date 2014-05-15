#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct MyName
{
	int level;
	string name;
};

struct Node
{
	MyName levelName;
	vector<Node*> pChildren;
	Node(MyName aname)
	{
		levelName.level = aname.level;
		levelName.name = aname.name;
	}
};




int main()
{
	freopen("input.txt", "r", stdin);
	int n, m;
	scanf("%d %d\n", &n, &m);
	
	string line, name;
	MyName myname;
	for (int i = 0; i < n; ++i)
	{
		getline(cin, line);
		int nspace = 0;
		for (int k = 0; k < line.size(); ++k)
		{
			if (line[k] == ' ') nspace++;
			else break;
		}
		name = line.substr(nspace);
		myname.level = nspace / 2;
		myname.name = name;
		//cout << "My Name:" << myname.level << " " << myname.name << endl;
	}

	string nameX, isword, aword, nameY, ofword, relation;
	for (int i = 0; i < m; ++i)
	{
		getline(cin, line);
		istringstream iss(line);
		iss >> nameX >> isword >> aword >> relation >> ofword >> nameY;
		//cout << nameX << " " << nameY << " " << relation << endl;
	}

	return 0;
}
