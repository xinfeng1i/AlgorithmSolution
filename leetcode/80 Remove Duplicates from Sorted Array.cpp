#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

int removeDuplicates(vector<int>& A) {
	int n = (int) A.size();
	int len = 0;
	
	int i = 0;
	int s = 0;  // new array start position
	while (i < n) {
		int j = i + 1;
		while (j < n && A[j] == A[i]) {
			j++;
		}
		
		if (j - i >= 2) {
			A[s] = A[i];
			A[s+1] = A[i];
			s += 2;
			len += 2;
		} else {
			A[s] = A[i];
			s += 1;
			len += 1;
		}
		
		i = j;
	}
	return len;
}

int main()
{
	int a[] = {1, 1, 1, 2, 2, 3};
	vector<int> A(a, a +6);
	cout << removeDuplicates(A) << endl;
	return 0;
}
