#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

#if 1
int numTreesRecursion(int n) {
    if (n == 0) return 1;
    else if (n == 1) return 1;
        
    int ans = 0;
    for (int k = 1; k <= n; ++k)
    {
        ans += numTreesRecursion(k-1) * numTreesRecursion(n-k);
    }
        
    return ans;
}
#endif //0

vector<int> cnt(1000, -1);
int numTrees(int n) {
	if (n == 0) {cnt[0] = 1; return 1;}
	else if (n == 1) {cnt[1] = 1; return 1;}
	else if (cnt[n] != -1) return cnt[n];
        
    int ans = 0;
    for (int k = 1; k <= n; ++k)
    {
        ans += numTrees(k-1) * numTrees(n-k);
    }
    
	cnt[n] = ans;
    return ans;
}

int main()
{
	int n;
	cin >> n;
	clock_t stime = clock();
	cout << numTrees(n) << endl;
	clock_t etime = clock();
	cout << "n=" << n << ", cost time:" << double(etime-stime)/CLOCKS_PER_SEC << endl;


	clock_t stime2 = clock();
	cout << numTreesRecursion(n) << endl;
	clock_t etime2 = clock();
	cout << "n=" << n << ", Recursion time:" << double(etime2-stime2)/CLOCKS_PER_SEC << endl;

	return 0;
}