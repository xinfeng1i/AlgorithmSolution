#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	int cnt = 0;
	int cur = 0;
	int next = 0;
	while (v[cur] != 1 && cur < n) cur++;

	if (cur >= n)
	{
		cout << 0 << endl;
		return 0;
	}
	
	cnt += 1;
	next = cur + 1;
	
	while (cur < n)
	{
		while (next < n && v[next] != 1) next++;

		if (next < n)
		{
			if (next - cur == 1)
			{
				cnt += 1;
			}
			else if (next - cur >= 2)
			{
				cnt += 2;
			}
			cur = next;
			next = cur + 1;
		}
		else
		{
			break;
		}
	}
	
	cout << cnt << endl;
	return 0;
}
