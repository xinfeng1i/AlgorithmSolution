#include <iostream>
#include <vector>
#include <string>
using namespace std;

int makeProgram(vector<int> A, vector<int> B)
{
	int n = A.size();
	
	bool a = true;
	bool b = true;
	bool maxw = true;
	bool minw = true;
	for (int i = 0;i < n; ++i)
	{
		a = a && (wanted[i] == A[i]);
		b = b && (wanted[i] == B[i]);
		maxw = maxw && (wanted[i] == max(A[i], B[i]));
		minw = minw && (wanted[i] == min(A[i], B[i]));
	}

	if (a || b)
	{
		return 1;
	}
	else if (maxw || minw)
	{
		return 7;
	}
	else
	{
		return -1;
	}
}
