#include <iostream>
#include <string>
using namespace std;
class InsertZ
{
public:
	string canTransform(string init, string goal)
	{
		string delete_z_goal("");
		for (size_t i = 0; i < goal.size(); i++)
		{
			if (goal[i] != 'z')
			{
				delete_z_goal.push_back(goal[i]);
			}
		}
		if (init == delete_z_goal)
		{
			return string("Yes");
		}
		else
		{
			return string("No");
		}
	}
};
