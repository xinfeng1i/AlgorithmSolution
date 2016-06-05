#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 


int maxCoins(vector<int>& A) {
    int n = (int) A.size();
	A.insert(A.begin(), 1);
    A.insert(A.end(), 1);
    
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
    // dp[i][j] = the coins only pop balls in the interval [i, j]
    
    // base case: the len = 1, i.e. coins got by popped only one ball
    for (int i = 1; i <= n; ++i) {
    	dp[i][i] = A[i-1] * A[i] * A[i+1];
	}
    
    for (int len = 2; len <= n; ++len) {
    	for (int start = 1; start <= n+1-len; ++start) {
    		int end = start + len - 1;
    		int max_coin = 0;
    		//cout << "start = " << start << "; end = " << end << endl;
    		for (int finalPos = start; finalPos <= end; ++finalPos) {
    			int cur_coin = A[finalPos] * A[start-1] * A[end+1]
    			               + dp[start][finalPos-1]
    			               + dp[finalPos+1][end];
    			max_coin = max(max_coin, cur_coin);
    			//cout << "\t pos = " << finalPos << "; coin = " << cur_coin << endl;
			}
			dp[start][end] = max_coin;
		}
	}
	
	//for (int i = 1; i <= n; ++i) {
	//	for (int j = 1; j <= n; ++j) {
	//		cout << " " << dp[i][j];
	//	}
	//	cout << endl;
	//}
	//cout << endl;
	
    return dp[1][n];
}

int main()
{
	int a[] = {3, 1, 5, 8};
	vector<int> v(a, a+4);
	cout << maxCoins(v) << endl;
	return 0;
}
