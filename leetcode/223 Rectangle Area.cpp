#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
{
	int dx1 = C - A;
	int dy1 = D - B;
	int dx2 = G - E;
	int dy2 = H - F;
	int area1 = dx1 * dy1;
	int area2 = dx2 * dy2;
	if (F >= D || H <= B)
	{
		return area1 + area2;
	}
	
	if (E >= C || G <= A)
	{
		return area1 + area2;
	}
	
	// overlap
	if ( (F < D && H > B) && 
	     (E < C && G > A) )
	{
		vector<int> x;
		x.push_back(A);
		x.push_back(E);
		x.push_back(C);
		x.push_back(G);
		
		sort(x.begin(), x.end());
		
		vector<int> y;
		y.push_back(F);
		y.push_back(B);
		y.push_back(H);
		y.push_back(D);
		
		sort(y.begin(), y.end());
		
		int overlap = (x[2] - x[1]) * (y[2] - y[1]);
		
		return area1 + area2 - overlap;
		
	}	
}

int main()
{
	int A = -3;
	int B = 0;
	int E = 0;
	int F = -1;
	int C = 3;
	int D = 4;
	int G = 9;
	int H = 2;
	
	int ans = computeArea(A, B, C, D, E, F, G, H);
	
	cout << ans << endl;
	
	return 0;
}
