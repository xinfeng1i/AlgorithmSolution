#include <iostream>
#include <vector>
using namespace std;

string ableToGet(int x, int y, vector<int> jumpLengths)
{
	if (jumpLengths.size() == 1)
	{
		int d1 = x * x + y * y;
		int d2 = jumpLengths[0];
		if (d1 == d2) return "Able";
		else return "Not able";
	}

	if (jumpLengths.size() == 2)
	{
		int d1 = x * x + y * y;
		int d2 = jumpLengths[0] + jumpLengths[1];
		if (d1 <= d2) return "Able";
		else return "Nota able";
	}


}
