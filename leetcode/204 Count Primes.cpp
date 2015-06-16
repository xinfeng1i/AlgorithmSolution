#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

int countPrimes(int n)
{
	if (n <= 1) return 0;
	int cnt = 0;
	
	bool* marked = new bool[n];
	for (int i = 0; i < n; ++i) marked[i] = false;
	//memset(marked, false, sizeof(bool)*n);
	//vector<bool> marked(n, false);
	
	int mid = sqrt(n);
	for (int i = 2; i <= mid; ++i)
	{
		if (!marked[i])
		{
			//cout << "i = " <<  i << endl;
			for (int p = i * i; p < n; p += i)
			{
				marked[p] = true;
				//cout << "p = " << p << endl;		
			}
		}
	}
	
	for (int i = 2; i < n; ++i)
	{
		if (!marked[i]) cnt++;
	}
	
	delete[] marked;
	return cnt; 
}

int main()
{
	cout << countPrimes(1500000) << endl;
	//cout << sizeof(bool) << endl;
	return 0;
}
