#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

int main()
{
	string line;
	getline(cin, line);
	for (size_t i = 0; i < line.size(); ++i)
	{
		if(!isalpha(line[i]) && !isdigit(line[i]))
		{
			line[i] = ' ';
		}
		else if (line[i] >= 'A' && line[i] <= 'Z')
		{
			line[i] = tolower(line[i]);
		}
	}
	
	istringstream iss(line);
	string word;
	map<string, int> cnt;
	while ( (iss >> word) )
	{
		cnt[word]++;	
	}

	string ansWord;
	int ansCnt = 0;
	for (map<string, int>::iterator it = cnt.begin(); it != cnt.end(); ++it)
	{
		if (it->second > ansCnt)
		{
			ansWord = it->first;
			ansCnt = it->second;
		}
	}

	cout << ansWord << " " << ansCnt << endl;
	return 0;
}
