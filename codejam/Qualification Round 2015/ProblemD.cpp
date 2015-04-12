#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;


#if 0
int main()
{
	//freopen("data.in", "r", stdin);
	//freopen("D-small-attempt0.in", "r", stdin);
	//freopen("D-small-attempt0.out", "w", stdout);
	int T = 0;
	cin >> T;
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		int X, R, C;
		cin >> X >> R >> C;

		cout << "Case #" << nCase << ": ";
		if (X == 1)
		{
			cout << "GABRIEL" << endl;
			continue;
		}
		else if (X == 2)
		{
			if (R % 2 == 0 || C % 2 == 0)
			{
				cout << "GABRIEL" << endl;
				continue;
			}
			else
			{
				cout << "RICHARD" << endl;
				continue;
			}
		}
		else if (X == 3)
		{
			int a = min(R, C);
			int b = max(R, C);
			if ( (a == 2 && b == 3) ||
				 (a == 3 && b == 3) ||
				 (a == 3 && b == 4) )
			{
				cout << "GABRIEL" << endl;
				continue;
			}
			else
			{
				cout << "RICHARD" << endl;
				continue;	
			}


		}
		else if (X == 4)
		{
			int a = min(R, C);
			int b = max(R, C);
			if ( (a == 3 && b == 4) ||
				 (a == 4 && b == 4) )
			{
				cout << "GABRIEL" << endl;
				continue;
			}
			else
			{	
				cout << "RICHARD" << endl;
				continue;	
			}
		}
	}

	return 0;
}
#endif //0