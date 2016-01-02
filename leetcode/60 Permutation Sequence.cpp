#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string getPermutation(int n, int k) {
	long long frac = 1;
	for (int i = 1; i <= n; ++i) {
		frac *= i;
	}
	long long numInOneGroup = frac / n;
	int startNum = 1;
	int curCnt = numInOneGroup;
	while (curCnt < k) {
		curCnt += numInOneGroup;
		startNum += 1;
	}
	
	string s;
	s += startNum + '0';
	for (int i = 1; i <= n; ++i) {
		if (i != startNum) {
			s+= i + '0';
		}
	}
    
    int i = curCnt - numInOneGroup + 1;
    while (i < k) {
        next_permutation(s.begin(), s.end());
        i++;
    }
    return s;
}

int main() 
{
    int n = 3;
    int k = 6;
    cout << getPermutation(n, k) << endl;
    return 0;
}
