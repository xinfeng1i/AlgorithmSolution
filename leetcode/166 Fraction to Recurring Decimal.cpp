#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;

string fractionToDecimal(int a, int b) {
	if (b == 0) return "";
	int flag = (static_cast<long long>(a) * static_cast<long long>(b) >= 0) ? 1 : -1;
	long long x = abs((long long) (a));
	long long y = abs((long long) (b));
	string ans;
	ans = to_string(x/y); // int part
	if (x % y != 0) {     // if remainder != 0, we have decimal parts
		ans += ".";
		x = x % y;
		unordered_map<long long, size_t> tb;	
		while (x != 0) {	              // remainder is not equal to zeros
			if (tb.find(x) != tb.end()) { // whether the remainder has ocuured before
				ans.insert(tb[x], "(");   // if it is, we have found the recurring decimal
				ans.push_back(')');
				break;
			}
			
			tb[x] = ans.size();           // if it is not, remember the position where it is
			x *= 10;                      // remainder *= 10
			ans += to_string(x/y);        // push_back (remainder / y)
			x %= y;                       // update remainder %= y as new remainder
		}

	}
	if (flag == -1) {
		ans = "-" + ans;
	}
	return ans;
}

int main()
{
	int a = -2147483648;
	int b = 1;
	cout << fractionToDecimal(a, b) << endl;
	return 0;
}
