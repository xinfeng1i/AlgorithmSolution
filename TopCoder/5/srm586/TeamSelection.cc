#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class TeamsSelection
{
public:
	string simulate(vector<int> preference1, vector<int> preference2)
	{
		int size = preference1.size();
		string result(size, '0');
		while (preference1.size() > 0)
		{
			int player1 = preference1[0];
			if (result[player1 - 1] != '2')
			{
				result[player1 - 1] = '1';
				vector<int>::iterator p1 = find(preference1.begin(), preference1.end(), player1);
				preference1.erase(p1);
				vector<int>::iterator p2 = find(preference2.begin(), preference2.end(), player1);
				preference2.erase(p2);		
			
			}
			
			if (preference2.size() > 0)
			{
				int player2 = preference2[0];
				if (result[player2 - 1] != '1')
				{
					result[player2 - 1] = '2';
					vector<int>::iterator p1 = find(preference1.begin(), preference1.end(), player2);
					preference1.erase(p1);
					vector<int>::iterator p2 = find(preference2.begin(), preference2.end(), player2);
					preference2.erase(p2);						
				}
			}
		}
		
		return result;
	}
};
