#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countAlarms(vector<int> volume, int S)
{
    int n = volume.size();
    int cnt = 0;
    while (S > 0)
    {
        S -= volume[cnt % n]; 
        cnt++;
    }

    return cnt;
}

