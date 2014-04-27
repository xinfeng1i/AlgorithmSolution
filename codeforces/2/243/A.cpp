#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> v(n, 0);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		sum += v[i];
	}

	if (sum <= m) printf("YES\n");
	else printf("NO\n");

	return 0;
}
