#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	//freopen("data.in", "r", stdin);

	priority_queue<int, vector<int>, less<int> > heap;
	int N;
	scanf("%d\n", &N);

	string line;
	for (int i = 0; i < N; ++i)
	{
		getline(cin, line);
		if (line[0] == 'A')
		{
			istringstream iss(line);
			char ch;
			int w;
			iss >> ch >> w;
			heap.push(w);
		}
		else if (line[0] == 'T')
		{
			int ans = heap.top();
			heap.pop();
			cout << ans << endl;
		}
	}

	return 0;

}