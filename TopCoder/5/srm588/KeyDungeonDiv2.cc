#include <iostream>
#include <string>
#include <vector>
using namespace std;
class KeyDungeonDiv2
{
public:
int countDoors(vector<int> doorR, vector<int> doorG, vector<int> keys)
{
    int numOpen = 0;
    for (int i = 0; i < doorR.size(); i++)
    {
        int numR = doorR[i];
        int numG = doorG[i];
        if (keys[0] >= numR && keys[1] >= numG)
        {
            numOpen++;
        }
        if (keys[0] >= numR && keys[1] < numG)
        {
            if (keys[1] + keys[2] >= numG)
            {
            	numOpen++;
            }
        }
        if (keys[0] < numR && keys[1] >= numG)
        {
        	if (keys[0] + keys[2] >= numR)
        	{
        		numOpen++;
        	}    
        }
       	if (keys[0] < numR && keys[1] < numG)
        {
           	if (numR - keys[0] + numG - keys[1] <= keys[2])
           	{
           		numOpen++;
           	}
        }
    }   
    return numOpen;
}
};
