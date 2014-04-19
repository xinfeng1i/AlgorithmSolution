#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	long m, n;
	cin >> m >> n;
	vector<vector<int> > v(m, vector<int>(n, 0) );
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &v[i][j]);
		}
	}


}
