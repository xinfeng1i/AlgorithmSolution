#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isEqual(vector<int> A, vector<int> B)
{
	int n = A.size();

	bool flag = true;
	for (int i = 0; i < n; ++i)
	{
		if (A[i] != B[i])
		{
			flag = false;
			break;
		}
	}

	return flag;
}

vector<int> maxElem(vector<int> A, vector<int> B)
{
	int n = A.size();
	vector<int> ans(n);
	for (int i = 0;i < n; ++i)
	{
		ans[i] = max(A[i], B[i]);
	}

	return ans;
}


vector<int> minElem(vector<int> A, vector<int> B)
{
	int n = A.size();
	vector<int> ans(n);
	for (int i = 0;i < n; ++i)
	{
		ans[i] = min(A[i], B[i]);
	}

	return ans;
}

int makeProgram(vector<int> A, vector<int> B, vector<int> wanted)
{
	int n = A.size();
	
	if (isEqual(A, wanted) || isEqual(B, wanted))
	{
		return 1;
	}
	
	if (isEqual(wanted, maxElem(A, B)) ||
		isEqual(wanted, minElem(A, B)))
	{
		return 7;
	}

	return -1;
}

int main()
{
	return 0;
}
