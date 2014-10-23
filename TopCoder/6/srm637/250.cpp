#include <iostream>
#include <string>
#include <vector>
using namespace std;

int calc(vector<int> snuke, vector<int> sothe)
{
	int n = snuke.size();
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (snuke[i] > sothe[i]) cnt++;
	}
	return cnt;
}
