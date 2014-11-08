#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b)
{
	int n1 = a.size();
	int n2 = b.size();
	string reverseA(a.rbegin(), a.rend());
	string reverseB(b.rbegin(), b.rend());
	string ans(n1 + n2, '0');
	for (size_t i = 0; i < reverseA.size(); ++i)
	{
		ans[i] = reverseA[i];
	}
	for (size_t i = 0; i < reverseB.size(); ++i)
	{
		ans[i] = (ans[i] - '0') + (reverseB[i] - '0') + '0';
	}
	// handle carry
	for (size_t i = 0; i < ans.size(); ++i)
	{
		if (ans[i] >= '2' && i + 1 < ans.size())
		{
			int num = ans[i] - '0';
			if (num >= 2)
			{
				ans[i] = (num % 2) + '0';
				ans[i+1] = num / 2 + (ans[i+1] - '0') + '0';
			}
		}
	}
	// take off the overhead and reverse back
	int i = n1 + n2 - 1;
	for (i = n1 + n2 - 1; i >= 0; --i)
	{
		if (ans[i] != '0') break;
	}
	string ans2;
	for (int j = i; j >= 0; j--)
	{
		ans2.push_back(ans[j]);
	}
	if (ans2 == "") ans2 = "0";		// NOTE: special case, cannot find leading 1s
	return ans2;
}

int main()
{
	string a, b;
	cin >> a >> b;
	cout << addBinary(a, b) << endl;
	return 0;
}
