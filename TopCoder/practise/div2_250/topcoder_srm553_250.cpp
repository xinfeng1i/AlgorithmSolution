#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// AC code: 236pts;
class PlatypusDuckAndBeaver
{
public:
    int minimumAnimals(int webbedFeet, int duckBills, int beaverTails)
    {
    
        int x = (webbedFeet - 4 * beaverTails) / 2;
        int z = duckBills - x;
        int y = beaverTails - z;

        return x + y + z;
    }
};
