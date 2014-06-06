#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

// AC code: 358pts
// So easy
class CatAndRat
{
public:
	const double PI = 3.141592653589793;
	double getTime(int R, int T, int Vrat, int Vcat)
	{
		if (Vcat <= Vrat) return -1.0;
		double halfCircle = PI * R;
		double dist = Vrat * T;

		dist = min(dist, halfCircle);

		return dist / (Vcat - Vrat);
	}
};