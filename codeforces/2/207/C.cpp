#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Fight
{
    long ll;
    long rr;
    long x;
};

int main()
{
    long n, m;
    cin >> n >> m;

    vector<long> players(n + 1, -1);
    vector<Fight> round(m + 1);
    
    for (long i = 1; i <= m; ++i)
    {
        cin >> round[i].ll >> round[i].rr >> round[i].x; 
    }
   
    players[round[m].x] = 0;
    for (long k = m - 1; k >= 1; --k)
    {
        if (players[round[k].x] == -1)
        {
            players[round[k].x] = round[k + 1].x;
        }
    }

    for (long k = 1; k <= m; ++k)
    {
        for (long i = round[k].ll; i <= round[k].rr; ++i)
        {
            if (players[i] == -1)
            {
                players[i] = round[k].x;
            }
        }
    }
    
    cout << players[1];
    for (long i = 2; i <= n; ++i)
    {
        cout << " " << players[i];
    }
    cout << endl;
    return 0;

}
