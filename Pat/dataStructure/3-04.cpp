#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	map<int, int> m1;
	map<int, int> m2;
	int n1, n2;
	int coeff, exps;

	scanf("%d", &n1);
	for (int i = 0; i < n1; ++i)
	{
		scanf("%d %d", &coeff, &exps);
		m1[exps] = coeff;
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; ++i)
	{
		scanf("%d %d", &coeff, &exps);
		m2[exps] = coeff;
	}

	map<int, int> ans_plus, ans_multi;
	for (auto it1 = m1.begin(); it1 != m1.end(); ++it1)
	{
		for (auto it2 = m2.begin(); it2 != m2.end(); ++it2)
		{
			if (it1->first == it2->first)
			{
				ans_plus[it1->first] = it1->second + it2->second;
			}

			ans_multi[it1->first + it2->first] += it1->second * it2->second;
		}
	}

	bool isFirst1 = true;
	int nOutput1 = 0;
	for (auto it = ans_multi.rbegin(); it != ans_multi.rend(); ++it)
	{
		if (it->second != 0)
		{
			if (!isFirst1) printf(" ");
			printf("%d %d", it->second, it->first);
			isFirst1 = false;
			nOutput1++;
		}
	}
	if (nOutput1 == 0) printf("0 0");
	printf("\n");

	bool isFirst2 = true;
	int nOutput2 = 0;
	for (auto it = ans_plus.rbegin(); it != ans_plus.rend(); ++it)
	{
		if (it->second != 0)
		{
			if (!isFirst2) printf(" ");
			printf("%d %d", it->second, it->first);
			isFirst2 = false;
			nOutput2++;
		}
	}
	if (nOutput2 == 0) printf("0 0");
	printf("\n");

	return 0;
}
