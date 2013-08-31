#include <iostream>
#include <string>
using namespace std;
class GearsDiv2
{
public:
int getmin(string Directions)
{
    int n = Directions.size();
    if (Directions[0] == Directions[n - 1])
    {
        string Directions1 = Directions;
        int remove1 = 0;
        Directions1[0] = '*';
        remove1++;
        for (int i = 1; i < n; i++)
        {
            if(Directions1[i] == Directions1[i-1] && Directions1[i - 1] != '*')
            {
                Directions1[i] = '*';
                remove1++;
            }
        }

        string Directions2 = Directions;
        int remove2 = 0;
        Directions2[n-1] = '*';
        remove2++;
        for (int i = n - 2; i >= 0; i--)
        {
            if (Directions2[i] == Directions2[i+1] && Directions2[i+1] != '*')
            {
                Directions2[i] = '*';
                remove2++;
            }
        }

        return remove1 < remove2 ? remove1 : remove2;
    }

    else
    {
        string dir1 = Directions;
        int re1 = 0;
        for (int i = 1; i < n; i++)
        {
            if (dir1[i] == dir1[i-1] && dir1[i - 1] != '*')
            {
                dir1[i] = '*';
                re1++;
            }
        }

        string dir2 = Directions;
        int re2 = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            if (dir2[i] == dir2[i+1] && dir2[i+1] != '*')
            {
                dir2[i] = '*';
                re2++;
            }
        }

        return re1 < re2 ? re1 : re2;
        
    }
}
};
