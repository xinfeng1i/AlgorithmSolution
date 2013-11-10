#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string newMember(vector<string> existingNames, string newName)
{
    // not find
    if (find(existingNames.begin(), existingNames.end(), newName)
        == existingNames.end())
    {
        return newName;
    }
    else
    {
        // find, append ingeter, search again, until not find
        for (int i = 1; i <= 50; ++i)
        {
            if (find(existingNames.begin(), existingNames.end(),
                        newName + to_string(i)) == existingNames.end())
            {
                return newName + to_string(i);
            }
        }
    }
}

