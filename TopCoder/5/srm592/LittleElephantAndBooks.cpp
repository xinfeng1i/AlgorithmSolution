#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
class LittleElephantAndBooks
{
public:
	int getNumber(vector<int> pages, int number)
	{
		//int N = pages.size();
		sort(pages.begin(), pages.end());
		int smallest = accumulate(pages.begin(), pages.begin() + number, 0);
		return smallest - pages[number - 1] + pages[number];	
	}
};
