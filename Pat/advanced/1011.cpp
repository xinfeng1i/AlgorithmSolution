#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

pair<char, double> maxBet(double a, double b, double c)
{
    double max_ratio = a;
    char ch = 'W';
    if (b > max_ratio)
    {
        max_ratio = b;
        ch = 'T';
    }
    if (c > max_ratio)
    {
        max_ratio = c;
        ch = 'L';
    }

    return pair<char, double>(ch, max_ratio);
}

int main()
{
    pair<char, double> game[3];
    double a, b, c;
    for (int i = 0; i < 3; ++i)
    {
        cin >> a >> b >> c;
        game[i] = maxBet(a, b, c); 
    }
    double profit = (game[0].second * game[1].second * game[2].second
                                    * 0.65 - 1) * 2;
    cout << game[0].first << " " << game[1].first << " " << game[2].first;
    printf(" %0.2f", profit);
    cout << endl;

    return 0;
}
