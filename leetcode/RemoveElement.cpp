#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int removeElement(int A[], int n, int elem)
{
	int last = n - 1;
	int first = 0;
	while (first <= last)
	{
		if (A[first] == elem)
		{
			if (A[last] == elem)
			{
				last--;
				if (first > last) break;
			}
			else
			{
				swap(A[first], A[last]);
				first++;
				last--;
			}
		}
		else
		{
			first++;
		}
	}
	return first;
}

int main()
{
	int A[6] = {1, 2, 3, 4, 3, 4};
	int len = removeElement(A, 6, 4);
	for (int i = 0; i < len; ++i) cout << A[i] << endl;
	return 0;
}
