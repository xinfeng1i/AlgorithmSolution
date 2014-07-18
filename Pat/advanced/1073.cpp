#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

int main()
{
	bool flag;
	string zhengPart;
	string xiaoPart;
	string EPart;
	bool Eflag;

	string s;
	cin >> s;
	int zhengStart = 0;
	if (s[0] == '+' || s[0] == '-')
	{
		zhengStart += 1;
		if (s[0] == '+') flag = true;
		else if (s[0] == '-') flag = false;
	}

	int dianPos = zhengStart;
	while (s[dianPos] != '.') dianPos++;
	zhengPart = s.substr(zhengStart, dianPos - zhengStart);

	int xiaoPos = dianPos + 1;
	int EPos = xiaoPos;
	while (s[EPos] != 'E') EPos++;
	xiaoPart = s.substr(xiaoPos, EPos - xiaoPos);

	if (s[EPos+1] == '-') Eflag = false;
	else if (s[EPos+1] == '+') Eflag = true;
	EPart = s.substr(EPos+2);

	int ExpPart = atoi(EPart.c_str());
	if (Eflag == false) ExpPart = -ExpPart;	

	if (!flag) cout << "-";
	if (ExpPart > 0)
	{
		if (ExpPart < xiaoPart.size())
		{
			zhengPart += xiaoPart.substr(0, ExpPart);
			xiaoPart = xiaoPart.substr(ExpPart);
			cout << zhengPart << "." << xiaoPart << endl;
			return 0;
		}
		else
		{
			int nZero = ExpPart - xiaoPart.size();
			string zero(nZero, '0');
			cout << zhengPart << xiaoPart << zero << endl;
			return 0;
		}
	}
	else
	{
		int myexp = abs(ExpPart);
		if (myexp == 0)
		{
			cout << zhengPart << "." << xiaoPart << endl;
			return 0;
		}
		else
		{
			assert(myexp >= 1);
			int nZero = myexp - 1;
			xiaoPart = string(nZero, '0') + zhengPart + xiaoPart;
			cout << "0." << xiaoPart << endl;
			return 0;
		}
	}

	return 0;
}
