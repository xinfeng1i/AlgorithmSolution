#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

class HappyLetterDiv2
{

public:
char getHappyLetter(string letters)
{
	vector<int> cnt(26, 0);

	int n = letters.size();
	for (int i = 0; i < n; ++i)
	{
		char ch = letters[i];
		cnt[ch - 'a']++;
	}

	//int max_cnt = 0;
	char max_char = '.';
	for (int i = 0; i < 26; ++i)
	{
		if (cnt[i] > n / 2)
		{
			//max_cnt = cnt[i];
			max_char = 'a' + i;
		}
	}

	return max_char;
}

};
