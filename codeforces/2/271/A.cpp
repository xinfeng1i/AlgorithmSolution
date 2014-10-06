#include <iostream>
#include <string>
using namespace std;

const string keystring = "qwertyuiopasdfghjkl;zxcvbnm,./";

int main()
{
	char ch;
	cin >> ch;
	string tmp;
	cin >> tmp;
	string ans;
	if (ch == 'R')
	{
		for (size_t i = 0; i < tmp.size(); ++i)
		{
			int pos = keystring.find(tmp[i]);
			ans.push_back(keystring[pos-1]);
		}
	}
	else if (ch == 'L')
	{
		for (size_t i = 0; i < tmp.size(); ++i)
		{
			int pos = keystring.find(tmp[i]);
			ans.push_back(keystring[pos+1]);
		}
		
	}
	cout << ans << endl;
	return 0;
}
