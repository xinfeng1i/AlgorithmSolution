#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
	int k;
	scanf("%d", &k);
	vector<int> v;
	v.reserve(k);

	int tmp;
	while (true)
	{
		scanf("%d", &tmp);
		if (tmp < 0) break;
		v.push_back(tmp);
	}

	int n = v.size();
	//cout << "n=" << n << endl;
	//cout << "k=" << k << endl;
	if (n - k < 0) printf("NULL\n");
	else printf("%d\n", v[n-k]);
	
	return 0;
}
