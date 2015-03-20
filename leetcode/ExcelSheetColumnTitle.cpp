#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Main idea:
 * 1. convert into binary convert problem, find all the remainders
 * 2. check the digit when its number is zero, since we have never
 *    a zero symbol, then zero number digit keep max and change its
 *    adjacent digit
 * 3. when output backwards, attention about the leading zeros
 */
string convertToTitle(int n)
{
	if (n <= 0) return "";
	
	const int MAX_SYM = 26;
	vector<int> v;
	while (n != 0)
	{
		int r = n % 26;
		v.push_back(r);
		n /= 26;
	}

	for (size_t i = 0; i < v.size(); ++i)
	{
		if (v[i] == 0 && i + 1 < v.size())
		{
			v[i] = MAX_SYM;
			v[i+1] -= 1;
		}
	}

	string ans = "";
	for (auto it = v.rbegin(); it != v.rend(); ++it)
	{
		if (*it != 0)
		{
			ans.push_back(*it - 1 + 'A');
		}
	}

	return ans;
}

#if 0
int main()
{
	for (int i = 1; i < 100; ++i)
	{
		cout << i << "\t->\t" << convertToTitle(i) << endl;
	}
	return 0;
}
#endif //0