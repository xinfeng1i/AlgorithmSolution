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


	// 奇偶性检验
	if ( (k-p) % 2 != sum % 2 )
	{
		cout << "NO" << endl;
		return 0;
	}
	else
	{
		// 判断奇数组是否满足要求
		if ( (k-p) > odds.size() )
		{
			cout << "NO" << endl;
			return 0;
		}
		// 判断偶数组是否满足要求
		else if ( (odds.size() - (k-p)) / 2 + evens.size() < p)
		{
			cout << "NO" << endl;
			return 0;
		}
		else
		{
			cout << "YES" << endl;

			// 输出k-p个奇数组
			for (int i = 0; i < k-p; ++i)
			{
				cout << 1 <<" "<< odds.front() << endl;
				odds.pop();
			}

			// 奇数组已经可以满足要求，直接输出
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

				if (odds.size() + evens.size() == 0)
				{
					return 0;
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
				// 每两个数作为一组，输出
				int cur_odds_size = odds.size();
				for (int i = 0; i < cur_odds_size / 2; ++i)
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

				if (evens.size() + odds.size() == 0)
				{
					return 0;
				}
				// last line
				cout << evens.size() + odds.size();
				while (!evens.empty())
				{
					cout << " " << evens.front();
					evens.pop();
				}
				while (!odds.empty())
				{
					cout << " " << odds.front();
					odds.pop();
				}
				cout << endl;
				
				return 0;

			}
		}
	}
	
	return 0;
}

/*
 * 总结：多用assert减少调试难度
 *       如果证明不确定，增加断言保证准确性
 */
