#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class GooseTattarrattatDiv2
{
public:
	GooseTattarrattatDiv2()
	{
		for(int i = 0; i < 26; i++)
		{
			charCnt[i] = 0;
		}
	}
	
	~GooseTattarrattatDiv2()
	{}
	
	int getmin(string S)
	{
		for(int i = 0; i < S.size(); i++)
		{
			charCnt[S[i]-'a']++;
		}
		
		sort(charCnt, charCnt + 26);
		
		int sum = 0;
		for (int i = 0; i < 25; i++)
		{
			sum += charCnt[i];
		}
		
		return sum;
	}
private:
	int charCnt[26];
};
