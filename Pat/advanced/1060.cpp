#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

string scitificNotation(const string& a, int m)
{
	int firstNoneZeroDigit = 0;
	bool found = false;
	for (firstNoneZeroDigit = 0; firstNoneZeroDigit < a.size(); ++firstNoneZeroDigit)
	{
		if (a[firstNoneZeroDigit] >= '1' && a[firstNoneZeroDigit] <= '9')
		{
			found = true;
			break;
		}
	}

	if (found)
	{
		string ansDigits; int cnt = 0;
		ansDigits.push_back(a[firstNoneZeroDigit]); cnt++;
		for (int i = firstNoneZeroDigit+1; i < a.size() && cnt < m; ++i)
		{
			if (a[i] >= '0' && a[i] <= '9')
			{
				ansDigits.push_back(a[i]);
				cnt++;
			}
		}

		if (cnt < m)
		{
			ansDigits += string(m-cnt, '0');
		}

		int pointPos = 0;
		bool findPoint = false;
		for (pointPos = 0; pointPos < a.size(); ++pointPos)
		{
			if (a[pointPos] == '.')
			{
				findPoint = true;
				break;
			}
		}
		if (!findPoint) pointPos = a.size();

		int expnum = 0;
		if (pointPos > firstNoneZeroDigit) expnum = pointPos - firstNoneZeroDigit;
		else expnum = pointPos - firstNoneZeroDigit + 1;

		return "0."+ansDigits+"*10^"+to_string(expnum);

	}
	else
	{
		return "0."+string(m,'0')+"*10^0";
	}

}

int main()
{
	int m = 0;
	string a, b;
	cin >> m >> a >> b;
	string ansa = scitificNotation(a, m);
	string ansb = scitificNotation(b, m);
	if (ansa == ansb)
		cout << "YES " << ansa << endl;
	else
		cout << "NO " << ansa << " " << ansb << endl;

	return 0;
}
