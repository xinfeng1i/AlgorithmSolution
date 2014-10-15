#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

int firstPos;
int choice_num = 0;

int Pos(string s)
{
	int ans = 0;
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] == '+') ans++;
		else if (s[i] == '-') ans--;
	}
	return ans;
}

// backtracking
void computeTheSecondPos(string s, int cur)
{	
	// base case
	if (cur == s.size())
	{
		if (Pos(s) == firstPos)
		{
			choice_num += 1;
		}
		return;
	}
	
	if (s[cur] == '+' || s[cur] == '-')
	{
		computeTheSecondPos(s, cur+1);
	}
	else
	{
		s[cur] = '+';
		computeTheSecondPos(s, cur+1);
		s[cur] = '-';
		computeTheSecondPos(s, cur+1);
	}
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	firstPos = Pos(s1);
	//cout << "pos 1:" << firstPos << endl;
	computeTheSecondPos(s2, 0);

	int nquestion = 0;
	for (size_t i = 0; i < s2.size(); ++i)
	{
		if (s2[i] == '?') nquestion++;	
	}

	//cout << "choice num:" << choice_num << endl;
	double ans = (double)choice_num / (double)pow(2.0f, nquestion);
	//cout << ans << endl;
	printf("%.12f\n", ans);
	return 0;
}
