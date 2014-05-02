#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	map<long long, string> table;
	string command;
	long long account; 
	string strPwd;

	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i)
	{
		//scanf("%c %lld %s", &command, &account, pwd); 
		cin >> command >> account >> strPwd;
		if (command == "N")
		{
			if (table.count(account) > 0)
			{
				printf("ERROR: Exist\n");
			}
			else
			{
				table.insert(make_pair(account, strPwd));
				printf("New: OK\n");
			}
		}
		else
		{
			if (table.count(account) == 0)
			{
				printf("ERROR: Not Exist\n");
			}
			else
			{
				if (strPwd == table[account]) printf("Login: OK\n");
				else printf("ERROR: Wrong PW\n");
			}
		}
	}

	return 0;
}
