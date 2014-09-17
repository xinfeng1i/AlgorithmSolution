#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> draw(int n)
{
	vector<string> ans(n, string(n, ' '));
	int mid = (n + 1) / 2;

	int cur = 0;
	int flag = 1;
	while (cur < mid)
	{
		for (int j = cur; j < n-cur; ++j)
		{
			if (flag == 1) ans[cur][j] = '#';
			else ans[cur][j] = ' ';

			if (flag == 1) ans[n-1-cur][j] = '#';
			else ans[n-1-cur][j] = ' ';
		}

		for (int i = cur; i < n-cur; ++i)
		{
			if (flag == 1) ans[i][cur] = '#';
			else ans[i][cur] = ' ';

			if (flag == 1) ans[i][n-1-cur] = '#';
			else ans[i][n-1-cur] = ' ';
			
		}
		cur = cur + 1;
		flag = 1 - flag;
	}

	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<string> v = draw(n);
	for (int i = 0; i < n; ++i)
	{
		cout << v[i] << endl;
	}
	cout << endl;
	return 0;
}
