#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


int Sum_Solution(int n) {
	int ans = n;
	ans && (ans+=Sum_Solution(n-1));
	return ans;
}

int main()
{
	cout << Sum_Solution(3) << endl;
	return 0;
}
