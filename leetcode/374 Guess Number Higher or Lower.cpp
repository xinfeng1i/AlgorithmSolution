#include <iostream>
#include <string>
#include <vector>
using namespace std;

int guess(int x) {
	if (x == 6) return 0;
	else if (x < 6) return -1;
	else return 1;
}

int guessNumber(int n) {
	int lo = 1;
	int hi = n;
	int ans = -1;
	while (lo <= hi) {
		int mid = lo + (hi-lo)/2;
		int cmp = guess(mid);
		if (cmp == 0) {
			ans = mid;
			break;
		} else if (cmp == -1) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	return ans;
}

int main()
{
	cout << guessNumber(10) << endl;
	return 0;
}
