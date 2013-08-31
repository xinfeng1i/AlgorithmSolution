#include <iostream>
#include <string>

using namespace std;

const int K_MAX = 15;
const int N_MAX = 15;
class ShorterSuperSum
{
public:
	ShorterSuperSum()
	{
        for (int j = 0; j < N_MAX; j++)
        {
            dp[0][j] = j;
        }
	}

	~ShorterSuperSum()
	{}

	int calculate(int k, int n)
	{
		for (int i = 1; i < K_MAX; i++)
		{
			for (int j = 1; j < N_MAX; j++)
			{
				dp[i][j] = 0;
				for (int p = 1; p <= j; p++)
				{
					dp[i][j] += dp[i-1][p];
				}
			}
		}
		return dp[k][n];
	}
private:
	long dp[K_MAX][N_MAX];
};
