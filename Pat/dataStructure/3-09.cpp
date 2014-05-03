#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v(n, 0);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.end());

	bool isFirst = true;
	for (int i = 0; i < n; ++i)
	{
		if (isFirst) 
		{
			isFirst = false;
			printf("%d", v[i]);
		}
		else
		{
			printf(" %d", v[i]);
		}
		
	}
	printf("\n");
	return 0;

}
