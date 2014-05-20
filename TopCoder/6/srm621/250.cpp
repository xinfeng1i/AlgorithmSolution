#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;



// AC code :166pts
// Need to know 内部函数调用
class TwoWaysSorting
{
public:
	string sortingMethod(vector<string> stringList)
	{
		vector<string> logicString(stringList);
		vector<string> lengthString(stringList);
		sort(logicString.begin(), logicString.end(), [](string a , string b){return a < b;});
		sort(lengthString.begin(), lengthString.end(), [](string a, string b){return a.size() < b.size();});

		int n = stringList.size();
		bool isLogic = true;
		bool isLength = true;
		for (size_t i = 0; i < n; ++i)
		{
			if (stringList[i] != logicString[i])
			{
				isLogic = false;
				break;
			}
		}

		for (size_t i = 0; i < n; ++i)
		{
			if (stringList[i] != lengthString[i])
			{
				isLength = false;
				break;
			}
		}

		if (isLogic && isLength) return "both";
		else if (isLogic && !isLength) return "lexicographically";
		else if (!isLogic && isLength) return "lengths";
		else return "none";
	}
};
