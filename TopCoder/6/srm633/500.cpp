#include <iostream>
#include <vector>
using namespace std;

// Every time, the reachable points set is the ring with
// radius in [a, b], very time we have a step length r, we
// update the [a, b]
// the maximum is always b + r;
// the minimum depends the relaitonship between r and a, b
// if  a > r; a = a - r;
// a <= r && r < b; a = 0;
// r > b; a = b - r;
string ableToGet(int x, int y, vector<int> jumpLengths)
{
	int a = 0;
	int b = 0;
	for (size_t i = 0; i < jumpLengths.size(); ++i)
	{
		int r = jumpLengths[i];
		if (r < a)
		{
			a = a - r;
		}
		else if (r <= b)
		{
			a = 0;
		}
		else if (r > b)
		{
			a = r - b;
		}

		b += r;
	}

	int dist = x * x + y * y;
	if (dist >= a * a && dist <= b * b) return "Able";
	else return "Not able";
}

int main()
{
	return 0;
}
