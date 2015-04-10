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

const int STATE_NUM = 7;
vector<string> table(10);

#if 1
int main()
{

	freopen("A-large-practice.in", "r", stdin);
	freopen("A-large-practice.out", "w", stdout);

	table[0] = "1111110";
	table[1] = "0110000";
	table[2] = "1101101";
	table[3] = "1111001";
	table[4] = "0110011";
	table[5] = "1011011";
	table[6] = "1011111";
	table[7] = "1110000";
	table[8] = "1111111";
	table[9] = "1111011";

	int T = 0;
	cin >> T;

	for (int k = 1; k <= T; ++k)
	{
		// N strs in one line
		int N = 0;
		cin >> N;

		// read N strs in each line
		vector<string> states(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> states[i];
		}

		int totalFail = 0;
		string totalAns;
	
		vector<int> maybeBrokenPos(STATE_NUM, -1);
		for (int beginNum = 0; beginNum < 10; ++beginNum)
		{
			// from beginNum
			// Compute every str represent num
			int fail = 0;
	
			vector<int> nums(N, 0);
			for (int i = 0; i < N; ++i)	nums[i] = (beginNum - (i % 10) + 10) % 10; 


			// 初始，所有位置都有可能是坏的
			// 记 0 - 坏, 1 - 好
			maybeBrokenPos.clear();
			maybeBrokenPos.resize(STATE_NUM, -1);
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < STATE_NUM; ++j)
				{
					if (states[i][j] == '1')
					{
						// 说明该位置没有坏
						maybeBrokenPos[j] = 1;
					}
				}
			}

			for (int i = 0; i < N; ++i)
			{
				int tmpNum = nums[i];
				string tableStr = table[tmpNum];
				for (int j = 0; j < STATE_NUM; ++j)
				{
					if (states[i][j] == '1')
					{
						// 1 0
						if (tableStr[j] == '0')
						{
							fail = 1; break;
						}
						else //  1 1
						{
							if (maybeBrokenPos[j] == 0) { fail = 1; break;}
							else if (maybeBrokenPos[j] == 1) {}
							else if (maybeBrokenPos[j] == -1) { maybeBrokenPos[j] = 1;}
						}
					}
					else // states[i][j] == '0' 
					{
						if (tableStr[j] == '1')  // 0 1
						{							
							if (maybeBrokenPos[j] == 1) { fail = 1; break;} // 该位是好的
							else if (maybeBrokenPos[j] == 0) {}
							else if (maybeBrokenPos[j] == -1) { maybeBrokenPos[j] = 0; }
						}
						else // 0 0
						{}
					}
					
				}
				if (fail == 1) break;
			}


			if (fail == 0)
			{
				int ansNum = (beginNum - (N % 10) + 10) % 10;
				//cout << "ansNum:" << ansNum << endl;
				string tmpAns(STATE_NUM, '0');
				for (int j = 0; j < STATE_NUM; ++j)
				{
					if (table[ansNum][j] == '1')
					{
						// KEY POINT: 如果当前位置应该亮，但是却不能确定该位置的状态，Fail
						if (maybeBrokenPos[j] == -1) { totalFail = 1; break; }
						else if (maybeBrokenPos[j] == 0) {}
						else if (maybeBrokenPos[j] == 1) { tmpAns[j] = '1'; }
					}
				}
				//cout << "  ansStr : " << tmpAns << endl;

				if (totalAns.size() == 0 || tmpAns == totalAns)
				{
					totalAns = tmpAns;
				}
				else 
				{
					totalFail = 1;
				}

			}

		}

		if (totalAns.size() == 0) totalFail = 1;

		cout << "Case #" << k <<": ";
		if (totalFail == 1) cout << "ERROR!" << endl;
		else cout << totalAns << endl;

	}

	return 0;
}
#endif //0