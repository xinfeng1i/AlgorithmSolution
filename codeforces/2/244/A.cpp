#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int ans = 0;
	int curPolice = 0;
	int tmp = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		if (tmp > 0) 
		{	
			curPolice += tmp;
		}
		else 
		{
			if (curPolice > 0) 
			{
				curPolice--;
			}
			else
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
