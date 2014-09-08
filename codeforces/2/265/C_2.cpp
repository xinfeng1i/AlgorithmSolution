#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int n, p;
string s;
// 返回x位置上不与前面位置冲突的最小字符，如果没有则返回0
// 如果存在长度>=2的回文，则必然有s[i] == s[i-1] || s[i] == s[i-2]，没有这样的回文
// 则没有冲突
int check(int x)
{
	for (char ch = s[x] + 1; ch <= 'a' + p - 1; ++ch)
	{
		if (x == 0 || (x == 1 && ch != s[0]) ||(x >= 2 && ch != s[x-1] && ch != s[x-2]))
		{
			return ch;
		}
	}
	return 0;
}

int main()
{
	cin >> n >> p;
	cin >> s;
	int i;
	for (i = n - 1; i >= 0; --i)
	{
		int tmpch = check(i);
		if (tmpch != 0)
		{
			s[i] = tmpch;
			break;
		}
	}

	//找不到不冲突的位置
	if (i == -1)
	{
		printf("NO\n");
		return 0;
	}

	// 找到在第i为不冲突，则从第i+1开始，从'a'开始赋值为不冲突的最小字符
	for (int j = i + 1; j < n; ++j)
	{
		s[j] = 'a' - 1;
		s[j] = check(j);
	}

	cout << s << endl;
	return 0;
}
