#include <iostream>
#include <string>
using namespace std;

string convert(string s, int nRows)
{
	// can not even fill the first col, just return
	if (s.size() <= nRows) return s;
	// NOTE: if there is only one row, then 2 * n - 2 will be 0,
	//       then there may goto the dead loop
	//       the problems occurs j += sth, sth must > 0, or the j
	//       will stay in the original position
	if (nRows <= 1) return s;

	string ans;
	ans.reserve(s.size());
	for (int i = 0; i < nRows; ++i)
	{
		if (i == 0 || i == nRows - 1)
		{
			for (int j = i; j < s.size(); j += (2 * nRows - 2))
			{
				ans.push_back(s[j]);
			}
		}
		else
		{
			bool flag = true;
			for (int j = i; j < s.size();)
			{
				if (flag == true)
				{
					ans.push_back(s[j]);
					j += 2 * nRows - 2 - 2 * i;
					flag = false;
				}
				else
				{
					ans.push_back(s[j]);
					j += 2 * i;
					flag = true;
				}
			}
		}
	}
	return ans;
}

#if 0
int main()
{
	string s;
	int n;
	cin >> s;
	cin >> n;
	cout << convert(s, n) << endl;
	return 0;
}
#endif //0