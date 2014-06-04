#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n, k, p;
	cin >> n >> k >> p;

	vector<int> v(n);
	queue<int> evens;
	queue<int> odds;
	long long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i]; 
		sum += v[i];
		if (v[i] % 2 == 0) evens.push(v[i]);
		else odds.push(v[i]);
	}


	if ( ((k-p) % 2 == 0 && sum % 2 == 1) ||
		 ((k-p) % 2 == 1 && sum % 2 == 0) )
	{
		cout << "NO" << endl;
		return 0;
	}
	else
	{
		if ( (k-p) > odds.size() )
		{
			cout << "NO" << endl;
			return 0;
		}
		else
		{
			cout << "YES" << endl;

			for (int i = 0; i < k-p; ++i)
			{
				cout << 1 <<" "<< odds.front() << endl;
				odds.pop();
			}

			if (odds.size() / 2 >= p)
			{
				for (int i = 0; i < p - 1; ++i)
				{
					cout << 2;
					cout << " " << odds.front();
					odds.pop();
					cout << " " << odds.front() << endl;
					odds.pop();
				}

				// last line
				cout << odds.size() + evens.size();
				while (!odds.empty())
				{
					cout << " " << odds.front();
					odds.pop();
				}

				while (!evens.empty())
				{
					cout << " " << evens.front();
					evens.pop();
				}
				cout << endl;
				return 0;
			}
			else
			{
				while (!odds.empty())
				{
					cout << 2;
					cout << " " << odds.front();
					odds.pop();
					cout << " " << odds.front() << endl;
					odds.pop();
					p--;
				}
				
				for (int i = 0; i < p-1; ++i)
				{
					cout << 1 << " " << evens.front() << endl;
					evens.pop();
				}

				// last line
				cout << evens.size();
				while (!evens.empty())
				{
					cout << " " << evens.front();
					evens.pop();
				}
				cout << endl;
				
				return 0;

			}


		}

	}
	
	return 0;
}
